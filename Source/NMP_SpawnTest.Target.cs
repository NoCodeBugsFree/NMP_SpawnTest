// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class NMP_SpawnTestTarget : TargetRules
{
	public NMP_SpawnTestTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "NMP_SpawnTest" } );
	}
}
