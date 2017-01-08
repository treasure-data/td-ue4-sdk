// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TreasureDataPrivatePCH.h"

DEFINE_LOG_CATEGORY_STATIC(LogAnalytics, Display, All);
IMPLEMENT_MODULE( FAnalyticsTreasureData, TreasureData )

void FAnalyticsTreasureData::StartupModule()
{
    TreasureDataProvider = MakeShareable(new FAnalyticsProviderTreasureData());
}


void FAnalyticsTreasureData::ShutdownModule()
{
    if (TreasureDataProvider.IsValid()) {
        TreasureDataProvider->EndSession();
    }
}

TSharedPtr<IAnalyticsProvider> FAnalyticsTreasureData::CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate& GetConfigValue) const
{
    return TreasureDataProvider;
}

// Provider
FAnalyticsProviderTreasureData::FAnalyticsProviderTreasureData()
{
  //FileArchive = nullptr;
	//AnalyticsFilePath = FPaths::GameSavedDir() + TEXT("Analytics/");
  //	UserId = FPlatformMisc::GetUniqueDeviceId();
}

FAnalyticsProviderTreasureData::~FAnalyticsProviderTreasureData()
{
  //if (bHasSessionStarted)
  //	{
		EndSession();
                //	}
}

bool FAnalyticsProviderTreasureData::StartSession(const TArray<FAnalyticsEventAttribute>& Attributes)
{
  UE_LOG(LogAnalytics, Display, TEXT("[TD] Session Started"));

  return true;
}

void FAnalyticsProviderTreasureData::EndSession()
{
  UE_LOG(LogAnalytics, Display, TEXT("[TD] Session Ended"));
}

void FAnalyticsProviderTreasureData::FlushEvents()
{
}


void FAnalyticsProviderTreasureData::SetUserID(const FString& InUserID)
{
}

FString FAnalyticsProviderTreasureData::GetUserID() const
{
	return UserId;
}


FString FAnalyticsProviderTreasureData::GetSessionID() const
{
	return SessionId;
}

bool FAnalyticsProviderTreasureData::SetSessionID(const FString& InSessionID)
{
        return true;
}

void FAnalyticsProviderTreasureData::RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes)
{
}

void FAnalyticsProviderTreasureData::RecordItemPurchase(const FString& ItemId, const FString& Currency, int PerItemCost, int ItemQuantity)
{
}

void FAnalyticsProviderTreasureData::RecordCurrencyPurchase(const FString& GameCurrencyType, int GameCurrencyAmount, const FString& RealCurrencyType, float RealMoneyCost, const FString& PaymentProvider)
{
}

void FAnalyticsProviderTreasureData::RecordCurrencyGiven(const FString& GameCurrencyType, int GameCurrencyAmount)
{
}

void FAnalyticsProviderTreasureData::SetAge(int InAge)
{
	Age = InAge;
}

void FAnalyticsProviderTreasureData::SetLocation(const FString& InLocation)
{
	Location = InLocation;
}

void FAnalyticsProviderTreasureData::SetGender(const FString& InGender)
{
	Gender = InGender;
}

void FAnalyticsProviderTreasureData::SetBuildInfo(const FString& InBuildInfo)
{
	BuildInfo = InBuildInfo;
}

void FAnalyticsProviderTreasureData::RecordError(const FString& Error, const TArray<FAnalyticsEventAttribute>& Attributes)
{
}

void FAnalyticsProviderTreasureData::RecordProgress(const FString& ProgressType, const FString& ProgressName, const TArray<FAnalyticsEventAttribute>& Attributes)
{
}

void FAnalyticsProviderTreasureData::RecordItemPurchase(const FString& ItemId, int ItemQuantity, const TArray<FAnalyticsEventAttribute>& Attributes)
{
}


void FAnalyticsProviderTreasureData::RecordCurrencyPurchase(const FString& GameCurrencyType, int GameCurrencyAmount, const TArray<FAnalyticsEventAttribute>& Attributes)
{
}


void FAnalyticsProviderTreasureData::RecordCurrencyGiven(const FString& GameCurrencyType, int GameCurrencyAmount, const TArray<FAnalyticsEventAttribute>& Attributes)
{
}
