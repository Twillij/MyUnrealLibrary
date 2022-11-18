#pragma once

#include "CoreMinimal.h"
#include "Skill.h"
#include "TestSkill.generated.h"

UCLASS()
class MYUNREALLIBRARY_API UTestSkill : public USkill
{
	GENERATED_BODY()

public:
	UTestSkill() {}

public:
	bool CheckAdditionalUnlockConditions_Implementation() override { return true; }
};
