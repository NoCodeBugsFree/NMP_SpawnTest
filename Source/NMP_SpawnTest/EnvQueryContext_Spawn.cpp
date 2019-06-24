// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvQueryContext_Spawn.h"
#include "Kismet/GameplayStatics.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "GameFramework/PlayerStart.h"

void UEnvQueryContext_Spawn::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	if (AActor* Actor = Cast<AActor>((QueryInstance.Owner).Get()))
	{
		TArray<AActor*> OutActors;
		
		/** find all player start actors  */
		UGameplayStatics::GetAllActorsOfClass(Actor, APlayerStart::StaticClass(), OutActors);

		TArray<AActor*> WithPlayTag;

		for (AActor* TestActor : OutActors)
		{
			if(APlayerStart* PlayerStart = Cast<APlayerStart>(TestActor))
			{
				if (PlayerStart->PlayerStartTag == FName(TEXT("Play")))
				{
					/** but use only with 'Play' Tag  */
					WithPlayTag.Add(PlayerStart);
				}
			}
		}
		
		if (WithPlayTag.Num() == 0)
		{
			UE_LOG(LogTemp, Error, TEXT("No Player start actor marked with Play tag. Set player start tag to Play "));
		} 
		
		UEnvQueryItemType_Actor::SetContextHelper(ContextData, WithPlayTag);
	}
}
