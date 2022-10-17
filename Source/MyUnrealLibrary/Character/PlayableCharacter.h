#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "PlayableCharacter.generated.h"

class USkill;
class USkillSystemComponent;

UCLASS()
class MYUNREALLIBRARY_API APlayableCharacter : public AMyCharacter
{
	GENERATED_BODY()
	
public:
	APlayableCharacter();
	
	UPROPERTY(VisibleAnywhere, Category = "Skills")
	USkillSystemComponent* SkillSystemComponent;

public:
	UFUNCTION(BlueprintPure, Category = "Skills")
	USkillSystemComponent* GetSkillSystemComponent() { return SkillSystemComponent; }
};
