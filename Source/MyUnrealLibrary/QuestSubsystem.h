#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyUnrealLibrary.h"
#include "QuestSubsystem.generated.h"

class UQuest;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestUpdated, UQuest*, Quest);

UCLASS()
class MYUNREALLIBRARY_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnQuestUpdated OnQuestUpdated;

public:
	UFUNCTION(BlueprintPure)
	TArray<UQuest*> GetQuestsByState(EQuestState State);

	//UFUNCTION(BlueprintPure)
	//bool AreQuests
};
