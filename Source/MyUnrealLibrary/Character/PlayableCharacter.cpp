#include "PlayableCharacter.h"
#include "../Skill/SkillSystemComponent.h"

APlayableCharacter::APlayableCharacter()
{
	SkillSystemComponent = CreateDefaultSubobject<USkillSystemComponent>("SkillSystemComponent");
}
