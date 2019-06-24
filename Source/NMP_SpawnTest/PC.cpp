// Fill out your copyright notice in the Description page of Project Settings.


#include "PC.h"
#include "GM.h"

void APC::ServerTeleportToUnoccupiedLocaiton_Implementation()
{
	if (AGM* GM = GetWorld()->GetAuthGameMode<AGM>())
	{
		GM->FindValidLocationToStart(this);
	}
}
