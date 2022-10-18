#include "Skill.h"
#include "SkillSystemComponent.h"
#include "../Character/PlayableCharacter.h"
#include "../Ability/CharacterAttributeSet.h"

#include "Abilities/GameplayAbility.h"

USkillSystemComponent* USkill::GetSkillSystemComponent()
{
	return Cast<USkillSystemComponent>(GetOuter());
}

bool USkill::SetSkillUnlocked(bool bUnlocked)
{
	// To do: check can pay skill cost
	// To do: call on skill unlocked

	bSkillUnlocked = bUnlocked;
	return true;
}

bool USkill::SetSkillEnabled(bool bEnabled)
{
	if (!AbilityClass || !bSkillUnlocked || bSkillEnabled == bEnabled)
	{
		return false;
	}

	bSkillEnabled = bEnabled;
	return true;
}

bool USkill::CanCharacterUnlockSkill_Implementation(APlayableCharacter* Character)
{
	UCharacterAttributeSet* AttributeSet = Character->GetCharacterAttributeSet();
	USkillSystemComponent* SkillSysComp = GetSkillSystemComponent();

	if (!AttributeSet || !SkillSysComp)
		return false;

	if (AttributeSet->JobPoints.GetBaseValue() < JobPointsCost ||
		AttributeSet->SkillPoints.GetBaseValue() < SkillPointsCost)
	{
		return false;
	}

	if (!SkillSysComp->HasPrerequisiteSkills(PrerequisiteSkills))
	{
		return false;
	}

	return true;
}
