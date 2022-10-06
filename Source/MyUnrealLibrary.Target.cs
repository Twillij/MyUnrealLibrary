using UnrealBuildTool;
using System.Collections.Generic;

public class MyUnrealLibraryTarget : TargetRules
{
	public MyUnrealLibraryTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "MyUnrealLibrary" } );
	}
}
