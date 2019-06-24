// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvQueryContext_Pawns.h"
#include "Kismet/GameplayStatics.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"

void UEnvQueryContext_Pawns::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	if (AActor* Actor = Cast<AActor>((QueryInstance.Owner).Get()))
	{
		TArray<AActor*> OutActors;

		/** avoid each pawn in the world  */
		UGameplayStatics::GetAllActorsOfClass(Actor, APawn::StaticClass(), OutActors);

		UEnvQueryItemType_Actor::SetContextHelper(ContextData, OutActors);
	}
}
