// Copyright 2017 Treasure Data, Inc. All Rights Reserved.

#pragma once

#include "IAnalyticsProviderModule.h"
#include "Core.h"

class IAnalyticsProvider;

class FAnalyticsTreasureData :
        public IAnalyticsProviderModule
{
        TSharedPtr<IAnalyticsProvider> Provider;

 public:
        /** Treasure Data Constants */
        static FString GetAPIURL() { return TEXT("https://in.treasuredata.com/postback/v3/event/"); }
	static inline FAnalyticsTreasureData& Get()
	{
          return FModuleManager::LoadModuleChecked< FAnalyticsTreasureData >( "TreasureData" );
	}

 public:
	virtual TSharedPtr<IAnalyticsProvider> CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate& GetConfigValue) const override;

 private:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
