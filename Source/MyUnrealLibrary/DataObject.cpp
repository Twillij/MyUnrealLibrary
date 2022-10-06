#include "DataObject.h"

UWorld* UDataObject::GetWorld() const
{
	// If this is a CDO, then return nullptr instead of calling Outer->GetWorld() to fool UObject::ImplementsGetWorld().
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return nullptr;
	}

	UObject* Outer = GetOuter();

	// Follow the outer chain to find a valid World.
	while (Outer)
	{
		UWorld* World = Outer->GetWorld();

		if (World)
		{
			return World;
		}

		Outer = Outer->GetOuter();
	}

	// If there is no valid world, return null.
	return nullptr;
}

void UDataObject::PostInitProperties()
{
	Super::PostInitProperties();

	if (GetWorld())
	{
		BeginPlay();
		BP_BeginPlay();
	}
}
