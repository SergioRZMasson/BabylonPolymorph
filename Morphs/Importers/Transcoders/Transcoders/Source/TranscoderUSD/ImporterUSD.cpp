#include "TranscodersPch.h"
#include "ImporterUSD.h"

#include <CoreUtils/Platform.h>

#include <Asset3D/Asset3D.h>
#include <Asset3D/MaterialDescriptor.h>
#include <Asset3D/TextureDescriptor.h>
#include <CoreUtils/Memory.h>
#include <CoreUtils/StreamUtils.h>
#include <CoreUtils/Trace.h>

#include <PluginUSD/PluginUSD.h>

#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/usdGeom/sphere.h>
#include <pxr/usd/ar/defaultResolver.h>
#include <pxr/base/plug/plugin.h>
#include <pxr/base/plug/registry.h>
#include <pxr/usd/usd/prim.h>
#include <pxr/usd/usd/primRange.h>
#include <pxr/usd/usdGeom/mesh.h>
#include <pxr/usd/usdGeom/primVar.h>

#include <filesystem>
#include <winrt/base.h>
#include <tuple>
#include <stack>

using namespace Babylon::Transcoder;
using namespace Babylon::Utils;

DEFINE_TRACE_AREA(ImporterUSD, 0);

namespace fs = std::filesystem;

std::filesystem::path GetModulePath()
{
    WCHAR modulePath[4096];
    DWORD result = GetModuleFileNameW(nullptr, modulePath, ARRAYSIZE(modulePath));
    winrt::check_bool(result != 0 && result != std::size(modulePath));
    return std::filesystem::path{ modulePath }.parent_path();
}

ImporterUSD::~ImporterUSD()
{
}

static std::shared_ptr<Babylon::Transcoder::MaterialDescriptor> g_materialDescriptor = std::make_shared<Babylon::Transcoder::MaterialDescriptor>();

void TranslatePrimToNode(const pxr::UsdPrim& prim, Babylon::Transcoder::SceneNode* node) 
{
    auto xform = pxr::UsdGeomXform::Get(prim.GetStage(), prim.GetPath());

    if (prim.IsA<pxr::UsdGeomXformable>()) 
    {
        auto xformable = pxr::UsdGeomXformable{ prim };
        pxr::GfMatrix4d transform;
        bool resetStack = false;
        xformable.GetLocalTransformation(&transform, &resetStack, 0);                
        Babylon::Utils::Math::Matrix localTransform{};
        localTransform.m[0][0] = transform[0][0];
        localTransform.m[0][1] = transform[0][1];
        localTransform.m[0][2] = transform[0][2];
        localTransform.m[0][3] = transform[0][3];

        localTransform.m[1][0] = transform[1][0];
        localTransform.m[1][1] = transform[1][1];
        localTransform.m[1][2] = transform[1][2];
        localTransform.m[1][3] = transform[1][3];

        localTransform.m[2][0] = transform[2][0];
        localTransform.m[2][1] = transform[2][1];
        localTransform.m[2][2] = transform[2][2];
        localTransform.m[2][3] = transform[2][3];

        localTransform.m[3][0] = transform[3][0];
        localTransform.m[3][1] = transform[3][1];
        localTransform.m[3][2] = transform[3][2];
        localTransform.m[3][3] = transform[3][3];

        auto localBounds = xformable.ComputeLocalBound(0);
        auto range = localBounds.ComputeAlignedBox();
        
        std::vector<Babylon::Utils::Math::Vector3> positions{};

        for (size_t i = 0; i < 8; i++)
        {
            auto corner = range.GetCorner(i);
            positions.push_back(Babylon::Utils::Math::Vector3(corner[0], corner[1], corner[2]));
        }

        Babylon::Transcoder::BoundingBox boundingBox{ positions };
        node->SetBoundingBoxAndTransform(boundingBox,localTransform);
    }

    if (prim.IsA<pxr::UsdGeomMesh>()) 
    {
        auto geomMesh = pxr::UsdGeomMesh{prim};

        Babylon::Transcoder::Geometry geometry{ g_materialDescriptor };
       
        auto pointsAtt = geomMesh.GetPointsAttr();
        
        pxr::VtArray<pxr::GfVec3f> pointsData;
        pointsAtt.Get(&pointsData, 0);

        for (size_t i = 0; i < pointsData.size(); i++)
        {
            geometry.AddPosition(Babylon::Utils::Math::Vector3(pointsData[i][0], pointsData[i][1], pointsData[i][2]));
        }

        auto vertexIndices = geomMesh.GetFaceVertexIndicesAttr();
        pxr::VtArray<int> indices{};
        vertexIndices.Get(&indices);

        for (size_t i = 0; i < indices.size(); i++)
        {
            geometry.AddIndex(indices[i]);
        }

        auto normalsAtt = geomMesh.GetNormalsAttr();

        pxr::VtArray<pxr::GfVec3f> normalsData;
        normalsAtt.Get(&normalsData, 0);

        for (size_t i = 0; i < normalsData.size(); i++)
        {
            geometry.AddNormal(Babylon::Utils::Math::Vector3(normalsData[i][0], normalsData[i][1], normalsData[i][2]));
        }

        auto mesh = node->CreateMesh();
        mesh->AddGeometry(std::move(geometry));
    }
}

// Build an Asset3d from a SketchUp model (buffer data)
std::shared_ptr<Asset3D> ImporterUSD::ImportToAsset3D(const std::string& filename, UpdateReporter* progress, Babylon::Framework::ICancellationTokenPtr cancellationToken)
{
    auto currentPath = GetModulePath().string();
    std::replace(currentPath.begin(), currentPath.end(), '\\', '/');
    currentPath += "/usd/";
    auto plugins = pxr::PlugRegistry::GetInstance().RegisterPlugins(currentPath);

    auto stage = pxr::UsdStage::Open(filename);
    
    // Create the root of the asset3d object
    auto asset3d = std::make_shared<Asset3D>();
    auto primStack = std::stack<std::tuple<pxr::UsdPrim, std::shared_ptr<Babylon::Transcoder::SceneNode>>>();

    auto rootNode = asset3d->CreateChildNode();
    rootNode->SetName("Root");

    for (const pxr::UsdPrim& prim : stage->TraverseAll()) 
    {
        Babylon::Transcoder::SceneNode* parentNode = nullptr;

        while (!primStack.empty()) 
        {
            auto parent = prim.GetParent();
            auto stackFront = primStack.top();
            auto frontPrim = std::get<0>(stackFront);
            auto frontNode = std::get<1>(stackFront);

            if (parent == frontPrim)
            {
                parentNode = frontNode.get();
                break;
            }

            primStack.pop();
        }         

        if (parentNode == nullptr) 
        {
            parentNode = rootNode.get();
        }

        auto node = parentNode->CreateChildNode();
        node->SetName(prim.GetDisplayName());
        TRACE_WARN(ImporterUSD, "Parsing %s ", prim.GetPath().GetString().c_str());
        TranslatePrimToNode(prim, node.get());
        primStack.push(std::make_tuple(prim, node));
    }

    // Set the Asset3D system unit
    asset3d->SetSystemUnit(1);

    return asset3d;
}