#pragma once

#include "CoreMinimal.h"
#include "../DataObject.h"
#include "Skill.generated.h"

class APlayableCharacter;
class UGameplayAbility;
class USkillSystemComponent;

UCLASS()
class MYUNREALLIBRARY_API USkill : public UDataObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	FName SkillID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SkillDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SkillDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> AbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlock Requirements", meta = (ClampMin = "0"))
	int JobPointsCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlock Requirements", meta = (ClampMin = "0"))
	int SkillPointsCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlock Requirements")
	TArray<TSubclassOf<USkill>> PrerequisiteSkills;

protected:
	bool bSkillUnlocked = false;
	bool bSkillEnabled = false;

public:
	UFUNCTION(BlueprintPure)
	bool IsSkillUnlocked() { return bSkillUnlocked; }

	UFUNCTION(BlueprintPure)
	bool IsSkillEnabled() { return bSkillEnabled; }

	UFUNCTION(BlueprintPure)
	USkillSystemComponent* GetSkillSystemComponent();

	UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	bool CanCharacterUnlockSkill(APlayableCharacter* Character);
	
	void SetSkillUnlocked(bool bUnlocked, bool& bSuccess);
	void SetSkillEnabled(bool bEnabled, bool& bSuccess);

	// To do: OnSkillEnabled... BP Event, BP Native, or Delegate?
};
