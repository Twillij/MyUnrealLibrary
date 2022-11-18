#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyFunctionLibrary.generated.h"

class UMySaveGame;
class UQuestSubsystem;

UCLASS()
class MYUNREALLIBRARY_API UMyFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static UMySaveGame* GetSaveGame(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static UQuestSubsystem* GetQuestSubsystem(const UObject* WorldContextObject);
};
