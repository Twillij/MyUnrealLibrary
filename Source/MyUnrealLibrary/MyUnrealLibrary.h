#pragma once

#include "CoreMinimal.h"
#include "MyUnrealLibrary.generated.h"

UENUM(BlueprintType)
enum class EAbilityInputID : uint8
{
	None,
};

UENUM(BlueprintType)
enum class EQuestState : uint8
{
	Locked,
	Unlocked,
	Started,
	Abandoned,
	Failed,
	Completed,
};

USTRUCT(BlueprintType)
struct FCharacterSaveData
{
	GENERATED_BODY()

public:
	FName CharacterID;
	TArray<FSkillSaveData> SkillSaveData;
};

USTRUCT(BlueprintType)
struct FSkillSaveData
{
	GENERATED_BODY()

public:
	FName SkillID = EName::None;
	bool bUnlocked = false;
	bool bEnabled = false;
};
