#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "PlayableCharacter.generated.h"

class USkillSystemComponent;

UCLASS()
class MYUNREALLIBRARY_API APlayableCharacter : public AMyCharacter
{
	GENERATED_BODY()
	
public:
	APlayableCharacter();
	
	UPROPERTY(VisibleAnywhere)
	USkillSystemComponent* SkillSystemComponent;
};
