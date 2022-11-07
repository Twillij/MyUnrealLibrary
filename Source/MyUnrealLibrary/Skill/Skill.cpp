#include "Skill.h"
#include "SkillSystemComponent.h"
#include "../Character/PlayableCharacter.h"
#include "../Ability/CharacterAttributeSet.h"

#include "Abilities/GameplayAbility.h"

USkillSystemComponent* USkill::GetSkillSystemComponent()
{
	return Cast<USkillSystemComponent>(GetOuter());
}

float USkill::GetUnlockCostValue(ESkillUnlockCostType CostType)
{
	for (int i = 0; i < SkillUnlockCosts.Num(); ++i)
	{
		if (SkillUnlockCosts[i].CostType == CostType)
		{
			return SkillUnlockCosts[i].CostValue;
		}
	}

	return 0.0f;
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
