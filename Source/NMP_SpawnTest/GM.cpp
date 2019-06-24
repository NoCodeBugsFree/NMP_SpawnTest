// Fill out your copyright notice in the Description page of Project Settings.


#include "GM.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"

AActor* AGM::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName /*= TEXT("")*/)
{
	TArray<AActor*> OutActors;

	/** find all player start actors  */
	UGameplayStatics::GetAllActorsOfClass(this, APlayerStart::StaticClass(), OutActors);

	TArray<AActor*> WithPlayTag;

	for (AActor* TestActor : OutActors)
	{
		if (APlayerStart* PlayerStart = Cast<APlayerStart>(TestActor))
		{
			if (PlayerStart->PlayerStartTag == FName(TEXT("SelectCharacter")))
			{
				/** but use only with 'SelectCharacter' Tag  */
				WithPlayTag.Add(PlayerStart);
			}
		}
	}

	/** return random player start from collected  */
	if (WithPlayTag.Num() > 0)
	{
		int32 RandInteger = FMath::RandHelper(WithPlayTag.Num());
		if (WithPlayTag.IsValidIndex(RandInteger))
		{
			return WithPlayTag[RandInteger];
		}
	}

	/** error  */
	UE_LOG(LogTemp, Error, TEXT("No Player start actor marked with SelectCharacter tag. Set player start tag to SelectCharacter "));
	return Super::FindPlayerStart(Player, IncomingName);
}
