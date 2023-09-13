/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <CoreUtils/Platform.h>
#include <PluginSKP/PluginSKP.h>
#include <Asset3D/Asset3D.h>
#include <CoreUtils/Math/SimpleMath.h>
#include <PluginSDK/UpdateReporter.h>
#include <string>

namespace Babylon
{
    namespace Transcoder
    {
        class ImporterUSD
        {
        public:
            ~ImporterUSD();

            std::shared_ptr<Asset3D> ImportToAsset3D(const std::string& filename, UpdateReporter* progress, Babylon::Framework::ICancellationTokenPtr cancellationToken);
        };
    }
}