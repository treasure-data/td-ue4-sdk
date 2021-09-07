// Copyright 2017 Treasure Data, Inc. All Rights Reserved.

#pragma once
#include "Interfaces/IAnalyticsProvider.h"
#include "Http.h"

/**
 * Treasure Data Unreal Engine Analytics Provider plugin.
 */
class FAnalyticsProviderTreasureData :
  public IAnalyticsProvider
{
public:

  /**
   * Account Site / Endpoint. 
   * Check your organization settings to verify correct choice.
   */
  enum FAnalyticsRegion { 
    /// USA - in.treasuredata.com
    US02, 
    /// Japan - tokyo.in.treasuredata.com
    AP01, 
    /// Korea - ap02.in.treasuredata.com
    AP02, 
    /// Internal - ap03.in.treasuredata.com
    AP03, 
    /// Europe - eu01.in.treasuredata.com
    EU01 };

private:

    FString ApiKey;
    FString Database;

    FAnalyticsRegion Region;

    /// Tracks whether we need to start the session or restart it 
    bool bHasSessionStarted;

    /// Whether an event was written before or not
    bool bHasWrittenFirstEvent;

    /// Id representing the user the analytics are recording for
    FString UserId;

    /// Unique Id representing the session the analytics are recording for 
    FString SessionId;

    /// Holds the Age if set 
    int32 Age;

    /// Holds the Location of the user if set 
    FString Location;

    /// Holds the Gender of the user if set 
    FString Gender;

    /// Holds the build info if set 
    FString BuildInfo;

    /// Events associated when StartSession and EndSession are triggered 
    TArray<FAnalyticsEventAttribute> EventAttributes;

    static TSharedPtr<IAnalyticsProvider> Provider;
    FAnalyticsProviderTreasureData(const FString Key,
                                   const FString DBName,
                   FAnalyticsRegion Region);

public:
  /**
   * Create Treasure Data Instance. 
   * All events will be recorded to two tables, `Sessions` and `Events`. 
   * @param Key Write only API Key
   * @param DBName Database Name to log data to. Maximum length of 120 characters.
   * @param Region TD Account Region
   * @return TD Analytics Provider Instance
   */
  static TSharedPtr<IAnalyticsProvider> Create(const FString Key,
                                               const FString DBName,
                                             FAnalyticsRegion Region)
    {
      if (!Provider.IsValid()){
        Provider = TSharedPtr<IAnalyticsProvider>(new FAnalyticsProviderTreasureData(Key, DBName, Region));
      }
      return Provider;
    }

  /**
   * Remove all configuration data from the Treasure Data instance. 
   */
  static void Destroy(){
    Provider.Reset();
  }

  static TSharedPtr<FAnalyticsProviderTreasureData> GetProvider() {
    return StaticCastSharedPtr<FAnalyticsProviderTreasureData>(Provider);
  }

    virtual ~FAnalyticsProviderTreasureData();

    /**
     * Start the session
     * @param Additional event attributes
     * @return bool todo description
     */
    virtual bool StartSession(const TArray<FAnalyticsEventAttribute>& Attributes) override;
    
    /**
     * End the session
     */
    virtual void EndSession() override;
    
    /**
     * todo description
     */
    virtual void FlushEvents() override;

    /**
     * Set the ID of the User
     * @param InUserID String representing the User ID. Preferably Unique.
     */
    virtual void SetUserID(const FString& InUserID) override;
    
    /**
     * Get the ID of the User
     * @return FString string representing the User ID
     */
    virtual FString GetUserID() const override;

    /**
     * Get the current session ID
     * @return FString string representing the current session ID
     */
    virtual FString GetSessionID() const override;
    
    /**
     * Set the Session ID of the User
     * @param InSessionID session id as a string
     * @return bool todo description
     */
    virtual bool SetSessionID(const FString& InSessionID) override;

    /**
     * Record an event
     * @param EventName Name of Event
     * @param Attributes Attributes as an array
     */
    virtual void RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes) override;

    
    /**
     * Record an item purchase
     * @param ItemId string representing ID of item
     * @param Currency string representing ID of currency
     * @param PerItemCost integer cost of item
     * @param ItemQuantity number of items
     */
    virtual void RecordItemPurchase(const FString& ItemId, const FString& Currency, int PerItemCost, int ItemQuantity) override;

    /**
     * Record purchse of currency
     * @param GameCurrencyType Type of currency as a string
     * @param GameCurrencyAmount Amount of currency as a integer
     * @param RealCurrencyType Currency type as a string
     * @param RealMoneyCost Cost in Real dollas as a float
     * @param PaymentProvider Payment Provider as a string
     */
    virtual void RecordCurrencyPurchase(const FString& GameCurrencyType, int GameCurrencyAmount, const FString& RealCurrencyType, float RealMoneyCost, const FString& PaymentProvider) override;

    /**
     * Record the currency given to the user
     * @param GameCurrencyType Type of in-game currency as a string
     * @param GameCurrencyAmount Amount of in-game currency as an integer
     */
    virtual void RecordCurrencyGiven(const FString& GameCurrencyType, int GameCurrencyAmount) override;

    /**
     * Set the build information
     * @param InBuildInfo Build information as a string
     */
    virtual void SetBuildInfo(const FString& InBuildInfo) override;
    
    /**
     * Set the Gender of the User
     * @param InGender String representing the gender
     */
    virtual void SetGender(const FString& InGender) override;
    
    /**
     * Set the Location of the User
     * @param InLocation String representing the location of the user
     */
    virtual void SetLocation(const FString& InLocation) override;
    
    /**
     * Set the Age of the User
     * @param InAge Integer representing the age of the user
     */
    virtual void SetAge(const int32 InAge) override;

    /**
     * Record the purchase of an in-game item
     * @param ItemId ID of the item as a string
     * @param ItemQuantity Number of items as an integer
     * @param EventAttrs Additional event attributes
     */
    virtual void RecordItemPurchase(const FString& ItemId, int ItemQuantity, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;
    
    /**
     * Record purchase of in-game currency
     * @param GameCurrencyType Type of currency in game as a string
     * @param GameCurrencyAmount Amount of currency as an integer
     * @param EventAttrs Additional event attributes
     */
    virtual void RecordCurrencyPurchase(const FString& GameCurrencyType, int GameCurrencyAmount, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;
    
    /**
     * Record currency given to user in-game
     * @param GameCurrencyType Type of currency
     * @param GameCurrencyAmount Amount of currency
     * @param EventAttrs Additional event attributes
     */
    virtual void RecordCurrencyGiven(const FString& GameCurrencyType, int GameCurrencyAmount, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;
    
    /**
     * When things go wrong, record an error
     * @param Error Error event name
     * @param EventAttrs Error event attributes
     */
    virtual void RecordError(const FString& Error, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;
    
    /**
     * Record progress of user
     * @param ProgressType Type of progress as a string
     * @param ProgressHierarchy Hierarchy of progress as a string
     * @param EventAttrs Additional event attributes
     */
    virtual void RecordProgress(const FString& ProgressType, const FString& ProgressHierarchy, const TArray<FAnalyticsEventAttribute>& EventAttrs) override;
    
    /**
     * todo description
     * @param HttpRequest todo description
     * @param HttpResponse todo description
     * @param bSucceeded todo description
     */
    void EventRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

    /**
     * Add basic event with value
     * @param EventName Name of Event
     * @param EventValue Value of event
     */
    void AddEventAttribute(const FString& EventName, const FString& EventValue);
    
    /**
     * Clear event attributes
     */
    void ClearEventAttributes();

  /**
   * Return the {@link FAnalyticsRegion} currently set for the object instance.
   */
  inline FAnalyticsRegion GetRegion()
  {
    return Region;
  }

  /**
   * Convenience function to transform API Endpoint enumerations into postback API address string.
   */
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
