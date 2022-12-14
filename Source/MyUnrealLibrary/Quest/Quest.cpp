#include "Quest.h"
#include "QuestSubsystem.h"
#include "../MyFunctionLibrary.h"

void UQuest::SetQuestState(EQuestState NewState)
{
	QuestState = NewState;
	UMyFunctionLibrary::GetQuestSubsystem(this)->OnQuestUpdated.Broadcast(this);
}

bool UQuest::CheckUnlockRequirements()
{
	UMyFunctionLibrary::GetQuestSubsystem(this)->GetQuestsByState(EQuestState::Completed);
	return false;
}
