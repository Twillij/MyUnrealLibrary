#include "SkillSystemComponent.h"
#include "Skill.h"
#include "../Character/PlayableCharacter.h"
#include "../Character/CharacterAttributeSet.h"

USkill* USkillSystemComponent::GetSkill(FName SkillID)
{
	for (int i = 0; i < Skills.Num(); ++i)
	{
		if (Skills[i]->SkillID == SkillID)
		{
			return Skills[i];
		}
	}

	return nullptr;
}

APlayableCharacter* USkillSystemComponent::GetOwningCharacter()
{
	return Cast<APlayableCharacter>(GetOwner());
}

void USkillSystemComponent::SetSkillEnabled(FName SkillID, bool bEnabled)
{
	USkill* Skill = GetSkill(SkillID);

	if (!Skill)
		return;

	bool bSuccess;
	Skill->SetSkillEnabled(bEnabled, bSuccess);

	if (!bSuccess)
		return;

	APlayableCharacter* Character = GetOwningCharacter();

	if (!Character)
		return;

	if (bEnabled)
	{
		Character->GainAbility(Skill->AbilityClass, Character->GetCharacterAttributeSet()->GetLevel());
	}
	else
	{
		// To do: lose ability
	}

	OnSkillEnabledStateChanged.Broadcast(Skill, bEnabled);
}

void USkillSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// To do: if can read save data, then initialize from save data

	for (int i = 0; i < SkillSet.Num(); ++i)
	{
		USkill* NewSkill = NewObject<USkill>(this, SkillSet[i]);
		Skills.Add(NewSkill);
	}
}

void USkillSystemComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);

	// To do: handle the saving of the component data
}
