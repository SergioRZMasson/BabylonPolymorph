/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CanvasTexPch.h"

#include "FormatConversion.h"

#include <CanvasTex/Format.h>

#include <dxgi.h>

namespace CanvasTex
{
namespace Internal
{

DXGI_FORMAT TextureFormatToDxgiFormat(TextureFormat format)
{
    switch (format)
    {
    case TextureFormat::Unknown:
        return DXGI_FORMAT_UNKNOWN;
    case TextureFormat::R32g32b32a32Typeless:
        return DXGI_FORMAT_R32G32B32A32_TYPELESS;
    case TextureFormat::R32g32b32a32Float:
        return DXGI_FORMAT_R32G32B32A32_FLOAT;
    case TextureFormat::R32g32b32a32Uint:
        return DXGI_FORMAT_R32G32B32A32_UINT;
    case TextureFormat::R32g32b32a32Sint:
        return DXGI_FORMAT_R32G32B32A32_SINT;
    case TextureFormat::R32g32b32Typeless:
        return DXGI_FORMAT_R32G32B32_TYPELESS;
    case TextureFormat::R32g32b32Float:
        return DXGI_FORMAT_R32G32B32_FLOAT;
    case TextureFormat::R32g32b32Uint:
        return DXGI_FORMAT_R32G32B32_UINT;
    case TextureFormat::R32g32b32Sint:
        return DXGI_FORMAT_R32G32B32_SINT;
    case TextureFormat::R16g16b16a16Typeless:
        return DXGI_FORMAT_R16G16B16A16_TYPELESS;
    case TextureFormat::R16g16b16a16Float:
        return DXGI_FORMAT_R16G16B16A16_FLOAT;
    case TextureFormat::R16g16b16a16Unorm:
        return DXGI_FORMAT_R16G16B16A16_UNORM;
    case TextureFormat::R16g16b16a16Uint:
        return DXGI_FORMAT_R16G16B16A16_UINT;
    case TextureFormat::R16g16b16a16Snorm:
        return DXGI_FORMAT_R16G16B16A16_SNORM;
    case TextureFormat::R16g16b16a16Sint:
        return DXGI_FORMAT_R16G16B16A16_SINT;
    case TextureFormat::R32g32Typeless:
        return DXGI_FORMAT_R32G32_TYPELESS;
    case TextureFormat::R32g32Float:
        return DXGI_FORMAT_R32G32_FLOAT;
    case TextureFormat::R32g32Uint:
        return DXGI_FORMAT_R32G32_UINT;
    case TextureFormat::R32g32Sint:
        return DXGI_FORMAT_R32G32_SINT;
    case TextureFormat::R32g8x24Typeless:
        return DXGI_FORMAT_R32G8X24_TYPELESS;
    case TextureFormat::D32FloatS8x24Uint:
        return DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
    case TextureFormat::R32FloatX8x24Typeless:
        return DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS;
    case TextureFormat::X32TypelessG8x24Uint:
        return DXGI_FORMAT_X32_TYPELESS_G8X24_UINT;
    case TextureFormat::R10g10b10a2Typeless:
        return DXGI_FORMAT_R10G10B10A2_TYPELESS;
    case TextureFormat::R10g10b10a2Unorm:
        return DXGI_FORMAT_R10G10B10A2_UNORM;
    case TextureFormat::R10g10b10a2Uint:
        return DXGI_FORMAT_R10G10B10A2_UINT;
    case TextureFormat::R11g11b10Float:
        return DXGI_FORMAT_R11G11B10_FLOAT;
    case TextureFormat::R8g8b8a8Typeless:
        return DXGI_FORMAT_R8G8B8A8_TYPELESS;
    case TextureFormat::R8g8b8a8Unorm:
        return DXGI_FORMAT_R8G8B8A8_UNORM;
    case TextureFormat::R8g8b8a8UnormSrgb:
        return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
    case TextureFormat::R8g8b8a8Uint:
        return DXGI_FORMAT_R8G8B8A8_UINT;
    case TextureFormat::R8g8b8a8Snorm:
        return DXGI_FORMAT_R8G8B8A8_SNORM;
    case TextureFormat::R8g8b8a8Sint:
        return DXGI_FORMAT_R8G8B8A8_SINT;
    case TextureFormat::R16g16Typeless:
        return DXGI_FORMAT_R16G16_TYPELESS;
    case TextureFormat::R16g16Float:
        return DXGI_FORMAT_R16G16_FLOAT;
    case TextureFormat::R16g16Unorm:
        return DXGI_FORMAT_R16G16_UNORM;
    case TextureFormat::R16g16Uint:
        return DXGI_FORMAT_R16G16_UINT;
    case TextureFormat::R16g16Snorm:
        return DXGI_FORMAT_R16G16_SNORM;
    case TextureFormat::R16g16Sint:
        return DXGI_FORMAT_R16G16_SINT;
    case TextureFormat::R32Typeless:
        return DXGI_FORMAT_R32_TYPELESS;
    case TextureFormat::D32Float:
        return DXGI_FORMAT_D32_FLOAT;
    case TextureFormat::R32Float:
        return DXGI_FORMAT_R32_FLOAT;
    case TextureFormat::R32Uint:
        return DXGI_FORMAT_R32_UINT;
    case TextureFormat::R32Sint:
        return DXGI_FORMAT_R32_SINT;
    case TextureFormat::R24g8Typeless:
        return DXGI_FORMAT_R24G8_TYPELESS;
    case TextureFormat::D24UnormS8Uint:
        return DXGI_FORMAT_D24_UNORM_S8_UINT;
    case TextureFormat::R24UnormX8Typeless:
        return DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
    case TextureFormat::X24TypelessG8Uint:
        return DXGI_FORMAT_X24_TYPELESS_G8_UINT;
    case TextureFormat::R8g8Typeless:
        return DXGI_FORMAT_R8G8_TYPELESS;
    case TextureFormat::R8g8Unorm:
        return DXGI_FORMAT_R8G8_UNORM;
    case TextureFormat::R8g8Uint:
        return DXGI_FORMAT_R8G8_UINT;
    case TextureFormat::R8g8Snorm:
        return DXGI_FORMAT_R8G8_SNORM;
    case TextureFormat::R8g8Sint:
        return DXGI_FORMAT_R8G8_SINT;
    case TextureFormat::R16Typeless:
        return DXGI_FORMAT_R16_TYPELESS;
    case TextureFormat::R16Float:
        return DXGI_FORMAT_R16_FLOAT;
    case TextureFormat::D16Unorm:
        return DXGI_FORMAT_D16_UNORM;
    case TextureFormat::R16Unorm:
        return DXGI_FORMAT_R16_UNORM;
    case TextureFormat::R16Uint:
        return DXGI_FORMAT_R16_UINT;
    case TextureFormat::R16Snorm:
        return DXGI_FORMAT_R16_SNORM;
    case TextureFormat::R16Sint:
        return DXGI_FORMAT_R16_SINT;
    case TextureFormat::R8Typeless:
        return DXGI_FORMAT_R8_TYPELESS;
    case TextureFormat::R8Unorm:
        return DXGI_FORMAT_R8_UNORM;
    case TextureFormat::R8Uint:
        return DXGI_FORMAT_R8_UINT;
    case TextureFormat::R8Snorm:
        return DXGI_FORMAT_R8_SNORM;
    case TextureFormat::R8Sint:
        return DXGI_FORMAT_R8_SINT;
    case TextureFormat::A8Unorm:
        return DXGI_FORMAT_A8_UNORM;
    case TextureFormat::R1Unorm:
        return DXGI_FORMAT_R1_UNORM;
    case TextureFormat::R9g9b9e5Sharedexp:
        return DXGI_FORMAT_R9G9B9E5_SHAREDEXP;
    case TextureFormat::R8g8B8g8Unorm:
        return DXGI_FORMAT_R8G8_B8G8_UNORM;
    case TextureFormat::G8r8G8b8Unorm:
        return DXGI_FORMAT_G8R8_G8B8_UNORM;
    case TextureFormat::Bc1Typeless:
        return DXGI_FORMAT_BC1_TYPELESS;
    case TextureFormat::Bc1Unorm:
        return DXGI_FORMAT_BC1_UNORM;
    case TextureFormat::Bc1UnormSrgb:
        return DXGI_FORMAT_BC1_UNORM_SRGB;
    case TextureFormat::Bc2Typeless:
        return DXGI_FORMAT_BC2_TYPELESS;
    case TextureFormat::Bc2Unorm:
        return DXGI_FORMAT_BC2_UNORM;
    case TextureFormat::Bc2UnormSrgb:
        return DXGI_FORMAT_BC2_UNORM_SRGB;
    case TextureFormat::Bc3Typeless:
        return DXGI_FORMAT_BC3_TYPELESS;
    case TextureFormat::Bc3Unorm:
        return DXGI_FORMAT_BC3_UNORM;
    case TextureFormat::Bc3UnormSrgb:
        return DXGI_FORMAT_BC3_UNORM_SRGB;
    case TextureFormat::Bc4Typeless:
        return DXGI_FORMAT_BC4_TYPELESS;
    case TextureFormat::Bc4Unorm:
        return DXGI_FORMAT_BC4_UNORM;
    case TextureFormat::Bc4Snorm:
        return DXGI_FORMAT_BC4_SNORM;
    case TextureFormat::Bc5Typeless:
        return DXGI_FORMAT_BC5_TYPELESS;
    case TextureFormat::Bc5Unorm:
        return DXGI_FORMAT_BC5_UNORM;
    case TextureFormat::Bc5Snorm:
        return DXGI_FORMAT_BC5_SNORM;
    case TextureFormat::B5g6r5Unorm:
        return DXGI_FORMAT_B5G6R5_UNORM;
    case TextureFormat::B5g5r5a1Unorm:
        return DXGI_FORMAT_B5G5R5A1_UNORM;
    case TextureFormat::B8g8r8a8Unorm:
        return DXGI_FORMAT_B8G8R8A8_UNORM;
    case TextureFormat::B8g8r8x8Unorm:
        return DXGI_FORMAT_B8G8R8X8_UNORM;
    case TextureFormat::R10g10b10XrBiasA2Unorm:
        return DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM;
    case TextureFormat::B8g8r8a8Typeless:
        return DXGI_FORMAT_B8G8R8A8_TYPELESS;
    case TextureFormat::B8g8r8a8UnormSrgb:
        return DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
    case TextureFormat::B8g8r8x8Typeless:
        return DXGI_FORMAT_B8G8R8X8_TYPELESS;
    case TextureFormat::B8g8r8x8UnormSrgb:
        return DXGI_FORMAT_B8G8R8X8_UNORM_SRGB;
    case TextureFormat::Bc6hTypeless:
        return DXGI_FORMAT_BC6H_TYPELESS;
    case TextureFormat::Bc6hUf16:
        return DXGI_FORMAT_BC6H_UF16;
    case TextureFormat::Bc6hSf16:
        return DXGI_FORMAT_BC6H_SF16;
    case TextureFormat::Bc7Typeless:
        return DXGI_FORMAT_BC7_TYPELESS;
    case TextureFormat::Bc7Unorm:
        return DXGI_FORMAT_BC7_UNORM;
    case TextureFormat::Bc7UnormSrgb:
        return DXGI_FORMAT_BC7_UNORM_SRGB;
    case TextureFormat::Ayuv:
        return DXGI_FORMAT_AYUV;
    case TextureFormat::Y410:
        return DXGI_FORMAT_Y410;
    case TextureFormat::Y416:
        return DXGI_FORMAT_Y416;
    case TextureFormat::Nv12:
        return DXGI_FORMAT_NV12;
    case TextureFormat::P010:
        return DXGI_FORMAT_P010;
    case TextureFormat::P016:
        return DXGI_FORMAT_P016;
    case TextureFormat::Opaque420:
        return DXGI_FORMAT_420_OPAQUE;
    case TextureFormat::Yuy2:
        return DXGI_FORMAT_YUY2;
    case TextureFormat::Y210:
        return DXGI_FORMAT_Y210;
    case TextureFormat::Y216:
        return DXGI_FORMAT_Y216;
    case TextureFormat::Nv11:
        return DXGI_FORMAT_NV11;
    case TextureFormat::Ai44:
        return DXGI_FORMAT_AI44;
    case TextureFormat::Ia44:
        return DXGI_FORMAT_IA44;
    case TextureFormat::P8:
        return DXGI_FORMAT_P8;
    case TextureFormat::A8p8:
        return DXGI_FORMAT_A8P8;
    case TextureFormat::B4g4r4a4Unorm:
        return DXGI_FORMAT_B4G4R4A4_UNORM;
    case TextureFormat::P208:
        return DXGI_FORMAT_P208;
    case TextureFormat::V208:
        return DXGI_FORMAT_V208;
    case TextureFormat::V408:
        return DXGI_FORMAT_V408;
    default:
        return DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
    }
}

TextureFormat DxgiFormatToTextureFormat(DXGI_FORMAT format)
{
    switch (format)
    {
    case DXGI_FORMAT_UNKNOWN:
        return TextureFormat::Unknown;
    case DXGI_FORMAT_R32G32B32A32_TYPELESS:
        return TextureFormat::R32g32b32a32Typeless;
    case DXGI_FORMAT_R32G32B32A32_FLOAT:
        return TextureFormat::R32g32b32a32Float;
    case DXGI_FORMAT_R32G32B32A32_UINT:
        return TextureFormat::R32g32b32a32Uint;
    case DXGI_FORMAT_R32G32B32A32_SINT:
        return TextureFormat::R32g32b32a32Sint;
    case DXGI_FORMAT_R32G32B32_TYPELESS:
        return TextureFormat::R32g32b32Typeless;
    case DXGI_FORMAT_R32G32B32_FLOAT:
        return TextureFormat::R32g32b32Float;
    case DXGI_FORMAT_R32G32B32_UINT:
        return TextureFormat::R32g32b32Uint;
    case DXGI_FORMAT_R32G32B32_SINT:
        return TextureFormat::R32g32b32Sint;
    case DXGI_FORMAT_R16G16B16A16_TYPELESS:
        return TextureFormat::R16g16b16a16Typeless;
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
        return TextureFormat::R16g16b16a16Float;
    case DXGI_FORMAT_R16G16B16A16_UNORM:
        return TextureFormat::R16g16b16a16Unorm;
    case DXGI_FORMAT_R16G16B16A16_UINT:
        return TextureFormat::R16g16b16a16Uint;
    case DXGI_FORMAT_R16G16B16A16_SNORM:
        return TextureFormat::R16g16b16a16Snorm;
    case DXGI_FORMAT_R16G16B16A16_SINT:
        return TextureFormat::R16g16b16a16Sint;
    case DXGI_FORMAT_R32G32_TYPELESS:
        return TextureFormat::R32g32Typeless;
    case DXGI_FORMAT_R32G32_FLOAT:
        return TextureFormat::R32g32Float;
    case DXGI_FORMAT_R32G32_UINT:
        return TextureFormat::R32g32Uint;
    case DXGI_FORMAT_R32G32_SINT:
        return TextureFormat::R32g32Sint;
    case DXGI_FORMAT_R32G8X24_TYPELESS:
        return TextureFormat::R32g8x24Typeless;
    case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
        return TextureFormat::D32FloatS8x24Uint;
    case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
        return TextureFormat::R32FloatX8x24Typeless;
    case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
        return TextureFormat::X32TypelessG8x24Uint;
    case DXGI_FORMAT_R10G10B10A2_TYPELESS:
        return TextureFormat::R10g10b10a2Typeless;
    case DXGI_FORMAT_R10G10B10A2_UNORM:
        return TextureFormat::R10g10b10a2Unorm;
    case DXGI_FORMAT_R10G10B10A2_UINT:
        return TextureFormat::R10g10b10a2Uint;
    case DXGI_FORMAT_R11G11B10_FLOAT:
        return TextureFormat::R11g11b10Float;
    case DXGI_FORMAT_R8G8B8A8_TYPELESS:
        return TextureFormat::R8g8b8a8Typeless;
    case DXGI_FORMAT_R8G8B8A8_UNORM:
        return TextureFormat::R8g8b8a8Unorm;
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
        return TextureFormat::R8g8b8a8UnormSrgb;
    case DXGI_FORMAT_R8G8B8A8_UINT:
        return TextureFormat::R8g8b8a8Uint;
    case DXGI_FORMAT_R8G8B8A8_SNORM:
        return TextureFormat::R8g8b8a8Snorm;
    case DXGI_FORMAT_R8G8B8A8_SINT:
        return TextureFormat::R8g8b8a8Sint;
    case DXGI_FORMAT_R16G16_TYPELESS:
        return TextureFormat::R16g16Typeless;
    case DXGI_FORMAT_R16G16_FLOAT:
        return TextureFormat::R16g16Float;
    case DXGI_FORMAT_R16G16_UNORM:
        return TextureFormat::R16g16Unorm;
    case DXGI_FORMAT_R16G16_UINT:
        return TextureFormat::R16g16Uint;
    case DXGI_FORMAT_R16G16_SNORM:
        return TextureFormat::R16g16Snorm;
    case DXGI_FORMAT_R16G16_SINT:
        return TextureFormat::R16g16Sint;
    case DXGI_FORMAT_R32_TYPELESS:
        return TextureFormat::R32Typeless;
    case DXGI_FORMAT_D32_FLOAT:
        return TextureFormat::D32Float;
    case DXGI_FORMAT_R32_FLOAT:
        return TextureFormat::R32Float;
    case DXGI_FORMAT_R32_UINT:
        return TextureFormat::R32Uint;
    case DXGI_FORMAT_R32_SINT:
        return TextureFormat::R32Sint;
    case DXGI_FORMAT_R24G8_TYPELESS:
        return TextureFormat::R24g8Typeless;
    case DXGI_FORMAT_D24_UNORM_S8_UINT:
        return TextureFormat::D24UnormS8Uint;
    case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
        return TextureFormat::R24UnormX8Typeless;
    case DXGI_FORMAT_X24_TYPELESS_G8_UINT:
        return TextureFormat::X24TypelessG8Uint;
    case DXGI_FORMAT_R8G8_TYPELESS:
        return TextureFormat::R8g8Typeless;
    case DXGI_FORMAT_R8G8_UNORM:
        return TextureFormat::R8g8Unorm;
    case DXGI_FORMAT_R8G8_UINT:
        return TextureFormat::R8g8Uint;
    case DXGI_FORMAT_R8G8_SNORM:
        return TextureFormat::R8g8Snorm;
    case DXGI_FORMAT_R8G8_SINT:
        return TextureFormat::R8g8Sint;
    case DXGI_FORMAT_R16_TYPELESS:
        return TextureFormat::R16Typeless;
    case DXGI_FORMAT_R16_FLOAT:
        return TextureFormat::R16Float;
    case DXGI_FORMAT_D16_UNORM:
        return TextureFormat::D16Unorm;
    case DXGI_FORMAT_R16_UNORM:
        return TextureFormat::R16Unorm;
    case DXGI_FORMAT_R16_UINT:
        return TextureFormat::R16Uint;
    case DXGI_FORMAT_R16_SNORM:
        return TextureFormat::R16Snorm;
    case DXGI_FORMAT_R16_SINT:
        return TextureFormat::R16Sint;
    case DXGI_FORMAT_R8_TYPELESS:
        return TextureFormat::R8Typeless;
    case DXGI_FORMAT_R8_UNORM:
        return TextureFormat::R8Unorm;
    case DXGI_FORMAT_R8_UINT:
        return TextureFormat::R8Uint;
    case DXGI_FORMAT_R8_SNORM:
        return TextureFormat::R8Snorm;
    case DXGI_FORMAT_R8_SINT:
        return TextureFormat::R8Sint;
    case DXGI_FORMAT_A8_UNORM:
        return TextureFormat::A8Unorm;
    case DXGI_FORMAT_R1_UNORM:
        return TextureFormat::R1Unorm;
    case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:
        return TextureFormat::R9g9b9e5Sharedexp;
    case DXGI_FORMAT_R8G8_B8G8_UNORM:
        return TextureFormat::R8g8B8g8Unorm;
    case DXGI_FORMAT_G8R8_G8B8_UNORM:
        return TextureFormat::G8r8G8b8Unorm;
    case DXGI_FORMAT_BC1_TYPELESS:
        return TextureFormat::Bc1Typeless;
    case DXGI_FORMAT_BC1_UNORM:
        return TextureFormat::Bc1Unorm;
    case DXGI_FORMAT_BC1_UNORM_SRGB:
        return TextureFormat::Bc1UnormSrgb;
    case DXGI_FORMAT_BC2_TYPELESS:
        return TextureFormat::Bc2Typeless;
    case DXGI_FORMAT_BC2_UNORM:
        return TextureFormat::Bc2Unorm;
    case DXGI_FORMAT_BC2_UNORM_SRGB:
        return TextureFormat::Bc2UnormSrgb;
    case DXGI_FORMAT_BC3_TYPELESS:
        return TextureFormat::Bc3Typeless;
    case DXGI_FORMAT_BC3_UNORM:
        return TextureFormat::Bc3Unorm;
    case DXGI_FORMAT_BC3_UNORM_SRGB:
        return TextureFormat::Bc3UnormSrgb;
    case DXGI_FORMAT_BC4_TYPELESS:
        return TextureFormat::Bc4Typeless;
    case DXGI_FORMAT_BC4_UNORM:
        return TextureFormat::Bc4Unorm;
    case DXGI_FORMAT_BC4_SNORM:
        return TextureFormat::Bc4Snorm;
    case DXGI_FORMAT_BC5_TYPELESS:
        return TextureFormat::Bc5Typeless;
    case DXGI_FORMAT_BC5_UNORM:
        return TextureFormat::Bc5Unorm;
    case DXGI_FORMAT_BC5_SNORM:
        return TextureFormat::Bc5Snorm;
    case DXGI_FORMAT_B5G6R5_UNORM:
        return TextureFormat::B5g6r5Unorm;
    case DXGI_FORMAT_B5G5R5A1_UNORM:
        return TextureFormat::B5g5r5a1Unorm;
    case DXGI_FORMAT_B8G8R8A8_UNORM:
        return TextureFormat::B8g8r8a8Unorm;
    case DXGI_FORMAT_B8G8R8X8_UNORM:
        return TextureFormat::B8g8r8x8Unorm;
    case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
        return TextureFormat::R10g10b10XrBiasA2Unorm;
    case DXGI_FORMAT_B8G8R8A8_TYPELESS:
        return TextureFormat::B8g8r8a8Typeless;
    case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
        return TextureFormat::B8g8r8a8UnormSrgb;
    case DXGI_FORMAT_B8G8R8X8_TYPELESS:
        return TextureFormat::B8g8r8x8Typeless;
    case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
        return TextureFormat::B8g8r8x8UnormSrgb;
    case DXGI_FORMAT_BC6H_TYPELESS:
        return TextureFormat::Bc6hTypeless;
    case DXGI_FORMAT_BC6H_UF16:
        return TextureFormat::Bc6hUf16;
    case DXGI_FORMAT_BC6H_SF16:
        return TextureFormat::Bc6hSf16;
    case DXGI_FORMAT_BC7_TYPELESS:
        return TextureFormat::Bc7Typeless;
    case DXGI_FORMAT_BC7_UNORM:
        return TextureFormat::Bc7Unorm;
    case DXGI_FORMAT_BC7_UNORM_SRGB:
        return TextureFormat::Bc7UnormSrgb;
    case DXGI_FORMAT_AYUV:
        return TextureFormat::Ayuv;
    case DXGI_FORMAT_Y410:
        return TextureFormat::Y410;
    case DXGI_FORMAT_Y416:
        return TextureFormat::Y416;
    case DXGI_FORMAT_NV12:
        return TextureFormat::Nv12;
    case DXGI_FORMAT_P010:
        return TextureFormat::P010;
    case DXGI_FORMAT_P016:
        return TextureFormat::P016;
    case DXGI_FORMAT_420_OPAQUE:
        return TextureFormat::Opaque420;
    case DXGI_FORMAT_YUY2:
        return TextureFormat::Yuy2;
    case DXGI_FORMAT_Y210:
        return TextureFormat::Y210;
    case DXGI_FORMAT_Y216:
        return TextureFormat::Y216;
    case DXGI_FORMAT_NV11:
        return TextureFormat::Nv11;
    case DXGI_FORMAT_AI44:
        return TextureFormat::Ai44;
    case DXGI_FORMAT_IA44:
        return TextureFormat::Ia44;
    case DXGI_FORMAT_P8:
        return TextureFormat::P8;
    case DXGI_FORMAT_A8P8:
        return TextureFormat::A8p8;
    case DXGI_FORMAT_B4G4R4A4_UNORM:
        return TextureFormat::B4g4r4a4Unorm;
    case DXGI_FORMAT_P208:
        return TextureFormat::P208;
    case DXGI_FORMAT_V208:
        return TextureFormat::V208;
    case DXGI_FORMAT_V408:
        return TextureFormat::V408;
    default:
        return TextureFormat::Unknown;
    }
}

}  // namespace Internal
}  // namespace CanvasTex
