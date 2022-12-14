#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class MYUNREALLIBRARY_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Level;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Level);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData JobPoints;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, JobPoints);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData SkillPoints;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, SkillPoints);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MaxHealth);
};
