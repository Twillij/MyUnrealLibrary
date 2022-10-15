#include "MyCharacter.h"
#include "CharacterAttributeSet.h"

#include "AbilitySystemComponent.h"

AMyCharacter::AMyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	CharacterAttributeSet = CreateDefaultSubobject<UCharacterAttributeSet>("CharacterAttributeSet");
}
