#include "SkillSystemComponent.h"
#include "Skill.h"
#include "../Ability/CharacterAttributeSet.h"
#include "../Character/PlayableCharacter.h"

TArray<USkill*> USkillSystemComponent::GetUnlockedSkills()
{
	TArray<USkill*> UnlockedSkills;

	for (int i = 0; i < Skills.Num(); ++i)
	{
		if (Skills[i]->IsSkillUnlocked())
		{
			UnlockedSkills.Add(Skills[i]);
		}
	}

	return UnlockedSkills;
}

USkill* USkillSystemComponent::GetSkillByClass(TSubclassOf<USkill> SkillClass)
{
	for (int i = 0; i < Skills.Num(); ++i)
	{
		if (Skills[i]->GetClass() == SkillClass)
		{
			return Skills[i];
		}	
	}

	return nullptr;
}

USkill* USkillSystemComponent::GetSkillByID(FName SkillID)
{
	for (int i = 0; i < Skills.Num(); ++i)
	{
		if (Skills[i]->SkillID == SkillID)
		{
			return Skills[i];
		}
	}

	return nullptr;
}

APlayableCharacter* USkillSystemComponent::GetOwningCharacter()
{
	if (!OwningCharacter)
		OwningCharacter = Cast<APlayableCharacter>(GetOwner());
	
	return OwningCharacter;
}

UCharacterAttributeSet* USkillSystemComponent::GetOwningCharacterAttributeSet()
{
	APlayableCharacter* Character = GetOwningCharacter();

	if (Character)
		return Character->GetCharacterAttributeSet();
	
	return nullptr;
}

bool USkillSystemComponent::CanUnlockSkill(USkill* Skill)
{
	if (!Skill)
		return false;

	UCharacterAttributeSet* AttributeSet = GetOwningCharacterAttributeSet();

	if (!AttributeSet)
		return false;

	if (AttributeSet->SkillPoints.GetBaseValue() < Skill->GetUnlockCostValue(ESkillUnlockCostType::SkillPoints))
		return false;

	if (AttributeSet->JobPoints.GetBaseValue() < Skill->GetUnlockCostValue(ESkillUnlockCostType::JobPoints))
		return false;

	if (!HasUnlockedPrerequisiteSkills(Skill))
		return false;

	return true;
}

bool USkillSystemComponent::HasUnlockedPrerequisiteSkills(USkill* Skill)
{
	if (!Skill)
		return false;

	TArray<FName> PrereqSkills = Skill->PrerequisiteSkillIDs;
	TArray<USkill*> UnlockedSkills = GetUnlockedSkills();

	for (int i = 0; i < PrereqSkills.Num(); ++i)
	{
		bool bFound = false;

		for (int j = 0; j < UnlockedSkills.Num(); ++i)
		{
			if (UnlockedSkills[i]->SkillID == PrereqSkills[i])
			{
				bFound = true;
				break;
			}
		}

		if (!bFound)
		{
			return false;
		}
	}

	return true;
}

void USkillSystemComponent::UnlockSkill(USkill* Skill, bool bCheckEligibility)
{
	if (!Skill || Skill->GetSkillSystemComponent() != this || Skill->IsSkillUnlocked())
		return;

	if (bCheckEligibility)
	{
		if (!CanUnlockSkill(Skill))
			return;
	}

	UCharacterAttributeSet* AttributeSet = GetOwningCharacterAttributeSet();

	if (!AttributeSet)
		return;

	AttributeSet->SetSkillPoints(AttributeSet->SkillPoints.GetBaseValue() - Skill->GetUnlockCostValue(ESkillUnlockCostType::SkillPoints));
	AttributeSet->SetJobPoints(AttributeSet->JobPoints.GetBaseValue() - Skill->GetUnlockCostValue(ESkillUnlockCostType::JobPoints));
}

void USkillSystemComponent::SetSkillEnabled(FName SkillID, bool bEnabled)
{
	USkill* Skill = GetSkillByID(SkillID);

	if (!Skill)
		return;

	// To do: perhaps refactor the bool getter
	bool bSuccess = Skill->SetSkillEnabled(bEnabled);

	if (!bSuccess)
		return;

	APlayableCharacter* Character = GetOwningCharacter();

	if (!Character)
		return;

	if (bEnabled)
	{
		Character->LearnAbility(Skill->AbilityClass, Character->GetCharacterAttributeSet()->GetLevel());
	}
	else
	{
		Character->ForgetAbility(Skill->AbilityClass);
	}

	OnSkillEnabledStateChanged.Broadcast(Skill, bEnabled);
}

void USkillSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// To do: if can read save data, then initialize from save data

	for (int i = 0; i < SkillSet.Num(); ++i)
	{
		USkill* NewSkill = NewObject<USkill>(this, SkillSet[i]);
		Skills.Add(NewSkill);
	}
}

void USkillSystemComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);

	// To do: handle the saving of the component data
}
