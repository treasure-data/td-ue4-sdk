// Copyright 2017 Treasure Data, Inc. All Rights Reserved.

#pragma once
#include "Interfaces/IAnalyticsProvider.h"
#include "Http.h"

class FAnalyticsProviderTreasureData :
  public IAnalyticsProvider
{
public:

	enum FAnalyticsRegion { US02, AP01, AP02, AP03, EU01 };

private:

    /** Treasure Data */
    FString ApiKey;
    FString Database;

	FAnalyticsRegion Region;

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
                                   const FString DBName,
								   FAnalyticsRegion Region);

public:
  static TSharedPtr<IAnalyticsProvider> Create(const FString Key,
                                               const FString DBName,
	                                           FAnalyticsRegion Region)
    {
         if (!Provider.IsValid())
         {
           Provider = TSharedPtr<IAnalyticsProvider>(new FAnalyticsProviderTreasureData(Key, DBName, Region));
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

	inline FAnalyticsRegion GetRegion()
	{
		return Region;
	}

	inline FString GetAPIURL()
	{
		switch (GetRegion())
		{
		case US02:
			return TEXT("https://in.treasuredata.com/postback/v3/event/");
		case AP01:
			return TEXT("https://tokyo.in.treasuredata.com/postback/v3/event/");
		case AP02:
			return TEXT("https://ap02.in.treasuredata.com/postback/v3/event/");
		case AP03:
			return TEXT("https://ap03.in.treasuredata.com/postback/v3/event/");
		case EU01:
			return TEXT("https://eu01.in.treasuredata.com/postback/v3/event/");
		default:
			// Default is US02 collection endpoint
			return TEXT("https://in.treasuredata.com/postback/v3/event/");
		}
	}
};
