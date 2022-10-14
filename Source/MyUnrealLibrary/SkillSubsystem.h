#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SkillSubsystem.generated.h"

class USkill;

USTRUCT(BlueprintType)
struct FSkillSetData
{
	GENERATED_BODY()

public:

};

UCLASS()
class MYUNREALLIBRARY_API USkillSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

};
