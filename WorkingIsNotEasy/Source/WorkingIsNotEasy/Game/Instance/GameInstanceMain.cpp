#pragma region include project
#include "GameInstanceMain.h"
#include "../Mode/Main/GameModeMain.h"
#pragma endregion

#pragma region public function
// update current time from game mode
void UGameInstanceMain::UpdateTime()
{
	// this needs to be valid in case of starting the game
	if (!this)
		return;

	// if main game mode reference null return
	if (!m_pGameModeMain)
		return;

	// get and save current time variables from main game mode
	m_year = m_pGameModeMain->GetCurrentYear();
	m_month = m_pGameModeMain->GetCurrentMonth();
	m_day = m_pGameModeMain->GetCurrentDay();
	m_hour = m_pGameModeMain->GetCurrentHour();
	m_minute = m_pGameModeMain->GetCurrentMinute();
	m_second = m_pGameModeMain->GetCurrentSecond();
}
#pragma endregion