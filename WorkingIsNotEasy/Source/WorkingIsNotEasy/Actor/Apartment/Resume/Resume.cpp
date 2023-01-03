#pragma region include project
#include "Resume.h"
#include "../../../Character/Player/Stats/PlayerStatsComponent.h"
#pragma endregion

#pragma region constructor
// constructor
AResume::AResume()
{

}
#pragma endregion

#pragma region protected override function
// update stats
void AResume::UpdateStats(UPlayerStatsComponent* _pPlayerStats)
{
	// set resume player name
	PlayerName = UTF8_TO_TCHAR(_pPlayerStats->GetPlayerName().c_str());

	// update resume visuals
	UpdateResume();
}
#pragma endregion