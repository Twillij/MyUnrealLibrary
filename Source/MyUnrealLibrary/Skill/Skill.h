#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Skill.generated.h"

class APlayableCharacter;
class USkillSystemComponent;

UCLASS()
class MYUNREALLIBRARY_API USkill : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	FName SkillID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SkillDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SkillDescription;

protected:
	bool bSkillUnlocked = false;
	bool bSkillEnabled = false;

	USkillSystemComponent* OwningSkillComponent;

public:
	UFUNCTION(BlueprintPure)
	bool IsSkillUnlocked() { return bSkillUnlocked; }

	UFUNCTION(BlueprintPure)
	bool IsSkillEnabled() { return bSkillEnabled; }

	UFUNCTION(BlueprintCallable)
	void SetSkillUnlocked(bool bUnlocked);

	UFUNCTION(BlueprintCallable)
	void SetSkillEnabled(bool bEnabled);

	// To do: OnSkillEnabled... BP Event, BP Native, or Delegate?
};
