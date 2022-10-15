#include "Skill.h"
#include "../Character/PlayableCharacter.h"

void USkill::SetSkillUnlocked(bool bUnlocked)
{
	if (bSkillUnlocked)
		return;

	// To do: check can pay skill cost
	// To do: call on skill unlocked

	bSkillUnlocked = bUnlocked;
}

void USkill::SetSkillEnabled(bool bEnabled)
{
	if (!bSkillUnlocked)
		return;

	// To do: call on skill enabled or something

	bSkillEnabled = bEnabled;
}
