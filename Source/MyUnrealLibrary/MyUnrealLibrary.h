#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EQuestState : uint8
{
	Locked,
	Unlocked,
	Started,
	Abandoned,
	Failed,
	Completed,
};
