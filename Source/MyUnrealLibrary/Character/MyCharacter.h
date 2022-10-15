#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "MyCharacter.generated.h"

class UCharacterAttributeSet;

UCLASS()
class MYUNREALLIBRARY_API AMyCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMyCharacter();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, Category = "Abilities")
	UCharacterAttributeSet* CharacterAttributeSet;

public:
	UFUNCTION(BlueprintPure, Category = "Abilities")
	UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }

	UFUNCTION(BlueprintPure, Category = "Abilities")
	UCharacterAttributeSet* GetCharacterAttributeSet() { return CharacterAttributeSet; }
};
