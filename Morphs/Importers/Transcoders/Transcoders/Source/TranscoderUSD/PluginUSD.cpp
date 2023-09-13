/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <CoreUtils/Platform.h>
#include <PluginUSD/PluginUSD.h>
#include <CoreUtils/StreamUtils.h>
#include <PluginSDK/IResourceServer.h>
#include <PluginSDK/UpdateReporter.h>

#include "ImporterUSD.h"
#include "TranscoderException.h"

#include <sstream>

using namespace Babylon::Transcoder;

std::shared_ptr<Asset3D> Babylon::Transcoder::ImportUSD(
    const std::string& filename,
    IResourceServer* resourceServer,
    FractionalProgressCallback progress,
    Babylon::Framework::ICancellationTokenPtr cancellationToken,
    const std::unordered_map<std::string, std::string>& /*options*/,
    uint64_t* streamSize)
{    
    UpdateReporter percentageReporter;
    percentageReporter.SetProgressReporter(progress);
    percentageReporter.SetWeights(1.0f, 0.0f);

    if (cancellationToken == nullptr)
    {
        cancellationToken = Babylon::Framework::MakeNullCancellationToken();
    }

    ImporterUSD importer;
    auto asset3d = importer.ImportToAsset3D(resourceServer->GetFullFilePath(filename), &percentageReporter, cancellationToken);

    return asset3d;
}
