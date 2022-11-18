#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

class UMySaveGame;

UCLASS()
class MYUNREALLIBRARY_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMyGameInstance();

	UPROPERTY(BlueprintReadWrite)
	UMySaveGame* SaveGame;

public:
	void Init() override;
};
