#include "MyFunctionLibrary.h"
#include "Quest/QuestSubsystem.h"
#include "Kismet/GameplayStatics.h"

UQuestSubsystem* UMyFunctionLibrary::GetQuestSubsystem(const UObject* WorldContextObject)
{
	return UGameplayStatics::GetGameInstance(WorldContextObject)->GetSubsystem<UQuestSubsystem>();
}
