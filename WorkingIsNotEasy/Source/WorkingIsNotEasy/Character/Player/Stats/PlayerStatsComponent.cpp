#pragma region include project
#include "PlayerStatsComponent.h"
#pragma endregion

#pragma region constructor
// constructor
UPlayerStatsComponent::UPlayerStatsComponent()
{
	// disable update every frame
	PrimaryComponentTick.bCanEverTick = false;
}
#pragma endregion

#pragma region protected override function
// called at begin play
void UPlayerStatsComponent::BeginPlay()
{
	// parent begin play
	Super::BeginPlay();

	// set name if start name set
	m_name = StartName.Len() ? string(TCHAR_TO_UTF8(*(StartName.Len() < 17 ? StartName : StartName.Left(16)))) : "";

	// set money if start money not 0
	m_money = StartMoney > 0 ? StartMoney : 0;

	// set starve if start starve set
	m_starve = StartStarve ? FMath::Min(10, FMath::Max(-10, (float)StartStarve)) : 0;

	// set fitness if start fitness set
	m_fitness = StartFitness ? FMath::Min(10, FMath::Max(-10, (float)StartFitness)) : 0;
}
#pragma endregion