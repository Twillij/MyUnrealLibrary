#include "MyCharacter.h"
#include "../Ability/CharacterAttributeSet.h"

#include "AbilitySystemComponent.h"

AMyCharacter::AMyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	CharacterAttributeSet = CreateDefaultSubobject<UCharacterAttributeSet>("CharacterAttributeSet");
}

void AMyCharacter::LearnAbility(TSubclassOf<UGameplayAbility> Ability, int AbilityLevel)
{
	if (!AbilitySystemComponent)
		return;

	AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, AbilityLevel, -1, this));
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AMyCharacter::ForgetAbility(TSubclassOf<UGameplayAbility> Ability)
{
	if (!AbilitySystemComponent)
		return;

	FGameplayAbilitySpec* Spec = AbilitySystemComponent->FindAbilitySpecFromClass(Ability);
	AbilitySystemComponent->ClearAbility(Spec->Handle);
}
