#pragma once

#include "CoreMinimal.h"
#include "../DataObject.h"
#include "../MyUnrealLibrary.h"
#include "Quest.generated.h"

UCLASS()
class MYUNREALLIBRARY_API UQuest : public UDataObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName QuestID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Information")
	FText QuestDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User Information")
	FText QuestDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlock Requirements")
	int MinimumLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlock Requirements")
	TArray<FName> PrerequisiteQuestIDs;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EQuestState QuestState;

	UPROPERTY(BlueprintReadOnly)
	UQuest* ParentQuest = nullptr;

	UPROPERTY(BlueprintReadOnly)
	TArray<UQuest*> ChildQuests;

public:
	UFUNCTION(BlueprintCallable)
	void SetQuestState(EQuestState NewState);

	bool CheckUnlockRequirements();
};
