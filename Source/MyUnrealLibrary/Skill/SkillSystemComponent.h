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
	// An array of skill classes that gets instantiated on BeginPlay
	TArray<TSubclassOf<USkill>> SkillSet;

	UPROPERTY(BlueprintAssignable)
	FOnSkillStateChanged OnSkillEnabledStateChanged;

protected:
	UPROPERTY()
	// An array of all the instantiated skills
	TArray<USkill*> Skills;

	// Cached reference to the owning character of this component
	APlayableCharacter* OwningCharacter;

public:
	UFUNCTION(BlueprintPure)
	// Returns a copy of the instantiated skills array.
	TArray<USkill*> GetAllSkills() { return Skills; }

	UFUNCTION(BlueprintPure)
	// Returns an array of currently unlocked skills.
	TArray<USkill*> GetUnlockedSkills();

	UFUNCTION(BlueprintPure)
	// Returns the first skill in the array that has the exact matching class.
	USkill* GetSkillByClass(TSubclassOf<USkill> SkillClass);

	UFUNCTION(BlueprintPure)
	// Returns the first skill in the array that has a matching skill ID.
	USkill* GetSkillByID(FName SkillID);

	UFUNCTION(BlueprintPure)
	// Returns the cached reference of the owning character, or the cast result of this component's outer.
	APlayableCharacter* GetOwningCharacter();

	UFUNCTION(BlueprintPure)
	// Returns the attribute set of GetOwningCharacter().
	UCharacterAttributeSet* GetOwningCharacterAttributeSet();

	UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	// Returns true if the owning character is eligible to unlock the given skill.
	bool CanUnlockSkill(USkill* Skill);

	UFUNCTION(BlueprintPure)
	// Returns true if the owning character has unlocked all of the prerequisites of the given skill.
	bool HasUnlockedPrerequisiteSkills(USkill* Skill);

	UFUNCTION(BlueprintCallable)
	// Sets the skill as unlocked and grants the owning character the associated ability with the skill.
	void UnlockSkill(USkill* Skill, bool bCheckEligibility = true);

	UFUNCTION(BlueprintCallable)
	void SetSkillEnabled(FName SkillID, bool bEnabled);

protected:
	virtual void BeginPlay() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
};
