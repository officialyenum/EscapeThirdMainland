// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ETMGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPETHIRDMAINLAND_API AETMGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;
};
