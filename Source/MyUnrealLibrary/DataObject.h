#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataObject.generated.h"

UCLASS(Blueprintable, BlueprintType)
class MYUNREALLIBRARY_API UDataObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual UWorld* GetWorld() const override;

protected:
	UFUNCTION(BlueprintImplementableEvent, DisplayName = "BeginPlay")
	void BP_BeginPlay();

	virtual void PostInitProperties() override;
	virtual void BeginPlay() {}
};
