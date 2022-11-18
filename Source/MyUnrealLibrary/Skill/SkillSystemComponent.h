#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillSystemComponent.generated.h"

class APlayableCharacter;
class USkill;

UCLASS()
class MYUNREALLIBRARY_API USkillSystemComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	// An array of skill classes that gets instantiated on BeginPlay
	TArray<TSubclassOf<USkill>> SkillSet;

protected:
	UPROPERTY()
	// An array of all the instantiated skills
	TArray<USkill*> Skills;

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
	// Returns the cast result of this component's owner.
	APlayableCharacter* GetOwningCharacter();

	UFUNCTION(BlueprintPure)
	// Returns the attribute set of GetOwningCharacter().
	UCharacterAttributeSet* GetOwningCharacterAttributeSet();

	UFUNCTION(BlueprintPure, Category = "Skill Unlocking")
	// Returns true if the owning character has unlocked all of the prerequisites of the given skill.
	bool HasUnlockedPrerequisiteSkills(USkill* Skill);

	UFUNCTION(BlueprintPure, BlueprintNativeEvent, Category = "Skill Unlocking")
	// A native function that is meant to be overridden in the derived classes.
	// Return should be true when the conditions are fulfilled.
	// Default implementation always returns true.
	bool CheckAdditionalUnlockConditions(USkill* Skill);

	UFUNCTION(BlueprintPure, Category = "Skill Unlocking")
	// Returns true if the owning character is eligible to unlock the given skill.
	bool CanUnlockSkill(USkill* Skill);

	UFUNCTION(BlueprintCallable, Category = "Skill Unlocking")
	// To do: Comment
	bool TryUnlockSkill(USkill* Skill, bool bAutoEnable = true);

	UFUNCTION(BlueprintCallable)
	// Enables the given skill for the owning character.
	void EnableSkill(USkill* Skill);

	UFUNCTION(BlueprintCallable)
	// Disables the given skill for the owning character.
	void DisableSkill(USkill* Skill);

protected:
	virtual void BeginPlay() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
};
