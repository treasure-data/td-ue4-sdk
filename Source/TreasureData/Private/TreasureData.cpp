// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TreasureDataPrivatePCH.h"


class FTreasureData : public ITreasureData
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FTreasureData, TreasureData )



void FTreasureData::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FTreasureData::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}
