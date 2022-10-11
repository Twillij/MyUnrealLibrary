#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Skill.generated.h"

UCLASS()
class MYUNREALLIBRARY_API USkill : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SkillDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SkillDescription;

public:

};
