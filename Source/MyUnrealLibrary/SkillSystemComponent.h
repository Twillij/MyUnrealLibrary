#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SkillSystemComponent.generated.h"

class USkill;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSkillStateUpdated, USkill*, Skill, bool, NewState);

UCLASS()
class MYUNREALLIBRARY_API USkillSystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<USkill>> UnlockableSkillClasses;

	UPROPERTY(BlueprintAssignable)
	FOnSkillStateUpdated OnSkillEnabled;

protected:
	virtual void BeginPlay() override;
};
