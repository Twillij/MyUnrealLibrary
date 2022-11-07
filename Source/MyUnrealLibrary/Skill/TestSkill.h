#pragma once

#include "CoreMinimal.h"
#include "Skill.h"
#include "TestSkill.generated.h"

UCLASS()
class MYUNREALLIBRARY_API UTestSkill : public USkill
{
	GENERATED_BODY()

public:
	UTestSkill();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlock Requirements", meta = (ClampMin = "0"))
	int JobPointsCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlock Requirements")
	bool bAlternativeCost;



public:
	// To do: overrides
	// CanUnlockSkill, UnlockSkill
};
