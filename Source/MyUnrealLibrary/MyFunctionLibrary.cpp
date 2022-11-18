#include "MyFunctionLibrary.h"
#include "MyGameInstance.h"
#include "Quest/QuestSubsystem.h"
#include "Kismet/GameplayStatics.h"

UMySaveGame* UMyFunctionLibrary::GetSaveGame(const UObject* WorldContextObject)
{
	return Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(WorldContextObject))->SaveGame;
}

UQuestSubsystem* UMyFunctionLibrary::GetQuestSubsystem(const UObject* WorldContextObject)
{
	return UGameplayStatics::GetGameInstance(WorldContextObject)->GetSubsystem<UQuestSubsystem>();
}
