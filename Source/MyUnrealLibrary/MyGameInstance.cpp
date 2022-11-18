#include "MyGameInstance.h"
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"

UMyGameInstance::UMyGameInstance()
{
	//SaveGame = CreateDefaultSubobject<UMySaveGame>("SaveGameTest");
}

void UMyGameInstance::Init()
{
	Super::Init();

	// To do: slot name
	if (SaveGame = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("SaveGame", 0)))
	{
		// To do: woohoo
	}
}
