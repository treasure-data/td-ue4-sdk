// Copyright 2017 Treasure Data, Inc. All Rights Reserved.

#pragma once
#include "IAnalyticsProvider.h"
#include "Http.h"

class FAnalyticsProviderTreasureData :
  public IAnalyticsProvider
{
    /** Treasure Data */
    FString ApiKey;
    FString Database;

    /** Tracks whether we need to start the session or restart it */
    bool bHasSessionStarted;

    /** Whether an event was written before or not */
    bool bHasWrittenFirstEvent;

    /** Id representing the user the analytics are recording for */
    FString UserId;

    /** Unique Id representing the session the analytics are recording for */
    FString SessionId;

    /** Holds the Age if set */
    int32 Age;

    /** Holds the Location of the user if set */
    FString Location;

    /** Holds the Gender of the user if set */
    FString Gender;

    /** Holds the build info if set */
    FString BuildInfo;

    /** Events associated when StartSession and EndSession are triggered */
    TArray<FAnalyticsEventAttribute> EventAttributes;

    static TSharedPtr<IAnalyticsProvider> Provider;
    FAnalyticsProviderTreasureData(const FString Key,
                                   const FString DBName);

public:
  static TSharedPtr<IAnalyticsProvider> Create(const FString Key,
                                               const FString DBName)
    {
         if (!Provider.IsValid())
         {
           Provider = TSharedPtr<IAnalyticsProvider>(new FAnalyticsProviderTreasureData(Key, DBName));
         }
             return Provider;
       }

	static void Destroy()
	{
          Provider.Reset();
	}

	static TSharedPtr<FAnalyticsProviderTreasureData> GetProvider() {
		return StaticCastSharedPtr<FAnalyticsProviderTreasureData>(Provider);
	}

    virtual ~FAnalyticsProviderTreasureData();

    virtual bool StartSession(const TArray<FAnalyticsEventAttribute>& Attributes) override;
    virtual void EndSession() override;
    virtual void FlushEvents() override;

    virtual void SetUserID(const FString& InUserID) override;
    virtual FString GetUserID() const override;

    virtual FString GetSessionID() const override;
    virtual bool SetSessionID(const FString& InSessionID) override;

    virtual void RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes) override;

    virtual void RecordItemPurchase(const FString& ItemId, const FString& Currency, int PerItemCost, int ItemQuantity) override;

    virtual void RecordCurrencyPurchase(const FString& GameCurrencyType, int GameCurrencyAmount, const FString& RealCurrencyType, float RealMoneyCost, const FString& PaymentProvider) override;

    virtual void RecordCurrencyGiven(const FString& GameCurrencyType, int GameCurrencyAmount) override;

    virtual void SetBuildInfo(const FString& InBuildInfo) override;
    virtual void SetGender(const FString& InGender) override;
    virtual void SetLocation(const FString& InLocation) override;
    virtual void SetAge(const int32 InAge) override;

    virtual void RecordItemPurchase(const FString& ItemId, int ItemQuantity, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;
    virtual void RecordCurrencyPurchase(const FString& GameCurrencyType, int GameCurrencyAmount, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;
    virtual void RecordCurrencyGiven(const FString& GameCurrencyType, int GameCurrencyAmount, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;
    virtual void RecordError(const FString& Error, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;
    virtual void RecordProgress(const FString& ProgressType, const FString& ProgressHierarchy, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;
    void EventRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

    void AddEventAttribute(const FString& EventName, const FString& EventValue);
    void ClearEventAttributes();

};
