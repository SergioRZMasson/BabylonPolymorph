/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <CoreUtils/Platform.h>
#include <unordered_map>
#include <PluginSDK/FractionalProgressCallback.h>

namespace Babylon
{
    namespace Transcoder
    {
        class Asset3D;
        class IResourceServer;

        std::shared_ptr<Asset3D> ImportUSD(
            const std::string& filename,
            IResourceServer* resourceServer,
            FractionalProgressCallback progress = nullptr,
            Babylon::Framework::ICancellationTokenPtr cancellationToken = nullptr,
            const std::unordered_map<std::string, std::string>& options = {},
            uint64_t* streamSize = nullptr);
    }
}
