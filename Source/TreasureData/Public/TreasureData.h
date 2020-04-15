// Copyright 2017 Treasure Data, Inc. All Rights Reserved.

#pragma once

#include "Interfaces/IAnalyticsProviderModule.h"
#include "Modules/ModuleManager.h"

class IAnalyticsProvider;

class FAnalyticsTreasureData : public IAnalyticsProviderModule
{
 public:

	static enum FAnalyticsRegion { US02, AP01, AP02, EU01 };
 
 private:

	TSharedPtr<IAnalyticsProvider> Provider;

	static FAnalyticsRegion Region;

 public:
	 /** Treasure Data Constants */
	 static FString GetAPIURL()
	 {
		 switch (GetRegion())
		 {
		 case US02:
			 return TEXT("https://in.treasuredata.com/postback/v3/event/");
		 case AP01:
			 return TEXT("https://tokyo.in-development.treasuredata.com/postback/v3/event/");
		 case AP02:
			 return TEXT("https://ap02.in.treasuredata.com/postback/v3/event/");
		 case EU01:
			 return TEXT("https://eu01.in.treasuredata.com/postback/v3/event/");
		 default:
			 // Default is US02 collection endpoint
			 return TEXT("https://in.treasuredata.com/postback/v3/event/");
		 }
	 }

	 static inline FAnalyticsTreasureData& Get()
	 {
		 return FModuleManager::LoadModuleChecked< FAnalyticsTreasureData >("TreasureData");
	 }

	 static inline FAnalyticsRegion GetRegion()
	 {
		 return FAnalyticsTreasureData::Region;
	 }

	 static inline void SetRegion(FAnalyticsRegion NewRegion)
	 {
		 FAnalyticsTreasureData::Region = NewRegion;
	 }

 public:
	virtual TSharedPtr<IAnalyticsProvider> CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate& GetConfigValue) const override;

 private:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
