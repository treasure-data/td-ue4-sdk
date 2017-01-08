// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IAnalyticsProviderModule.h"
#include "Core.h"

//#include "ModuleManager.h"

class IAnalyticsProvider;

class FAnalyticsTreasureData : public IAnalyticsProviderModule
{
	TSharedPtr<IAnalyticsProvider> TreasureDataProvider;

 public:
	static inline FAnalyticsTreasureData& Get()
	{
          return FModuleManager::LoadModuleChecked< FAnalyticsTreasureData >( "TreasureData" );
	}

 public:
	virtual TSharedPtr<IAnalyticsProvider> CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate& GetConfigValue) const override;

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
