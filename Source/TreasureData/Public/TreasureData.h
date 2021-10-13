// Copyright 2017 Treasure Data, Inc. All Rights Reserved.

#pragma once

#include "Interfaces/IAnalyticsProviderModule.h"
#include "Modules/ModuleManager.h"

class IAnalyticsProvider;

class FAnalyticsTreasureData : public IAnalyticsProviderModule
{
	TSharedPtr<IAnalyticsProvider> Provider;

 public:
	 // Treasure Data Constants
	 static inline FAnalyticsTreasureData& Get()
	 {
		 return FModuleManager::LoadModuleChecked< FAnalyticsTreasureData >("TreasureData");
	 }

 public:
	virtual TSharedPtr<IAnalyticsProvider> CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate& GetConfigValue) const override;

 private:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
