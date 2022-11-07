#pragma once

#include "CoreMinimal.h"
#include "../DataObject.h"
#include "Skill.generated.h"

class APlayableCharacter;
class UGameplayAbility;
class USkillSystemComponent;

UENUM(BlueprintType)
enum class ESkillUnlockCostType : uint8
{
	SkillPoints,
	JobPoints
};

USTRUCT(BlueprintType)
struct FSkillUnlockCost
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESkillUnlockCostType CostType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0"))
	float CostValue;
};

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlock Requirements")
	TArray<FSkillUnlockCost> SkillUnlockCosts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlock Requirements")
	TArray<FName> PrerequisiteSkillIDs;

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

	UFUNCTION(BlueprintPure)
	float GetUnlockCostValue(ESkillUnlockCostType CostType);

	//UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	bool CanSkillBeUnlocked() { return false; }
	
	bool SetSkillUnlocked(bool bUnlocked);
	bool SetSkillEnabled(bool bEnabled);

	// To do: OnSkillEnabled... BP Event, BP Native, or Delegate?
};
