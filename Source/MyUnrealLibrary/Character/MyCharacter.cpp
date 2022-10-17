#include "MyCharacter.h"
#include "CharacterAttributeSet.h"

#include "AbilitySystemComponent.h"

AMyCharacter::AMyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	CharacterAttributeSet = CreateDefaultSubobject<UCharacterAttributeSet>("CharacterAttributeSet");
}

void AMyCharacter::GainAbility(TSubclassOf<UGameplayAbility> Ability, int AbilityLevel)
{
	if (!AbilitySystemComponent)
		return;

	AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, AbilityLevel, -1, this));
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
