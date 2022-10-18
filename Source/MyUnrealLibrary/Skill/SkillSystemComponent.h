#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillSystemComponent.generated.h"

class APlayableCharacter;
class USkill;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSkillStateChanged, USkill*, Skill, bool, bNewState);

UCLASS()
class MYUNREALLIBRARY_API USkillSystemComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<USkill>> SkillSet;

	UPROPERTY(BlueprintAssignable)
	FOnSkillStateChanged OnSkillEnabledStateChanged;

protected:
	UPROPERTY()
	TArray<USkill*> Skills;

public:
	UFUNCTION(BlueprintPure)
	TArray<USkill*> GetAllSkills() { return Skills; }

	UFUNCTION(BlueprintPure)
	TArray<USkill*> GetUnlockedSkills();

	UFUNCTION(BlueprintPure)
	USkill* GetSkillByClass(TSubclassOf<USkill> SkillClass, bool bExactMatching);

	UFUNCTION(BlueprintPure)
	USkill* GetSkillByID(FName SkillID);

	UFUNCTION(BlueprintPure)
	APlayableCharacter* GetOwningCharacter();

	UFUNCTION(BlueprintPure)
	bool HasPrerequisiteSkills(TArray<FName> PrereqSkills);

	UFUNCTION(BlueprintCallable)
	void SetSkillEnabled(FName SkillID, bool bEnabled);

protected:
	virtual void BeginPlay() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
};
