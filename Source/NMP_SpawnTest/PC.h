// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC.generated.h"

/**
 * 
 */
UCLASS()
class NMP_SPAWNTEST_API APC : public APlayerController
{
	GENERATED_BODY()
	
public:



protected:

private:

	/* called when player asks server to teleport him to the game location */
	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "AAA")
	void ServerTeleportToUnoccupiedLocaiton();
	bool ServerTeleportToUnoccupiedLocaiton_Validate(){ return true; }
	void ServerTeleportToUnoccupiedLocaiton_Implementation();

public:
	
};
