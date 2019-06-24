// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GM.generated.h"

/**
 * 
 */
UCLASS()
class NMP_SPAWNTEST_API AGM : public AGameMode
{
	GENERATED_BODY()
	
public:

	//~ Begin AGameModeBase Interface
	AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName = TEXT("")) override;
	//~ End AGameModeBase Interface

	/** called to find unoccupied location to teleport the player  */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "AAA")
	void FindValidLocationToStart(class APlayerController* PC);

};
