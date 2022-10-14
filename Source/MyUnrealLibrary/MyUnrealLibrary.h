#pragma once

#include "CoreMinimal.h"

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

//USTRUCT(BlueprintType)
//struct FCharacterData
//{
//	GENERATED_BODY()
//
//public:
//	FName CharacterID;
//	TArray<FSkillData> SkillSetData;
//};
//
//USTRUCT(BlueprintType)
//struct FSkillData
//{
//	GENERATED_BODY()
//
//public:
//	FName SkillID = EName::None;
//	bool bUnlocked = false;
//	bool bEnabled = false;
//};
