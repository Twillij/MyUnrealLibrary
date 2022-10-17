#include "PlayableCharacter.h"
#include "../Skill/SkillSystemComponent.h"

#include "AbilitySystemComponent.h"

APlayableCharacter::APlayableCharacter()
{
	SkillSystemComponent = CreateDefaultSubobject<USkillSystemComponent>("SkillSystemComponent");
}
