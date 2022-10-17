#include "Skill.h"
#include "SkillSystemComponent.h"
#include "../Character/PlayableCharacter.h"

#include "Abilities/GameplayAbility.h"

USkillSystemComponent* USkill::GetSkillSystemComponent()
{
	return Cast<USkillSystemComponent>(GetOuter());
}

bool USkill::CanCharacterUnlockSkill_Implementation(APlayableCharacter* Character)
{
	// To do: do the code
	return false;
}

void USkill::SetSkillUnlocked(bool bUnlocked, bool& bSuccess)
{
	// To do: check can pay skill cost
	// To do: call on skill unlocked

	bSkillUnlocked = bUnlocked;
}

void USkill::SetSkillEnabled(bool bEnabled, bool& bSuccess)
{
	if (!AbilityClass || !bSkillUnlocked || bSkillEnabled == bEnabled)
	{
		bSuccess = false;
		return;
	}

	bSkillEnabled = bEnabled;
	bSuccess = true;
}
