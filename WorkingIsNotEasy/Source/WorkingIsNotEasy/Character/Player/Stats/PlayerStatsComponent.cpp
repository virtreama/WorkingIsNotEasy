#pragma region include project
#include "PlayerStatsComponent.h"
#include "../../../Actor/Shared/PlayerStatsDependent/PlayerStatsDependent.h"
#include "../PlayerPawn.h"
#pragma endregion

#pragma region include engine
#include "Kismet/GameplayStatics.h"
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

	// get all player stats dependent actors
	TArray<AActor*> foundPlayerStatsDependentActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStatsDependent::StaticClass(), foundPlayerStatsDependentActors);

	// add all found actors to list
	for (int i = 0; i < foundPlayerStatsDependentActors.Num(); i++)
		m_playerStatsDependentActors.Add((APlayerStatsDependent*)foundPlayerStatsDependentActors[i]);

	// set name if start name set
	m_name = string(TCHAR_TO_UTF8(*(StartName.Len() < 17 ? StartName : StartName.Left(16))));

	// set money if start money not 0
	m_money = StartMoney > 0 ? StartMoney : 0;

	// set starve if start starve set
	m_starve = StartStarve ? FMath::Min(10, FMath::Max(-10, (float)StartStarve)) : 0;

	// set fitness if start fitness set
	m_fitness = StartFitness ? FMath::Min(10, FMath::Max(-10, (float)StartFitness)) : 0;

	// update all stats from player stats dependent actors
	for (int i = 0; i < m_playerStatsDependentActors.Num(); i++)
		m_playerStatsDependentActors[i]->UpdateStats(this);
	
	// update player credit card
	m_player->UpdateCreditCard();
}
#pragma endregion