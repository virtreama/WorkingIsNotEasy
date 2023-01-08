#pragma region include project
#include "Clock.h"
#include "../../../Game/Mode/Main/GameModeMain.h"
#pragma endregion

#pragma region constructor
// constructor
AClock::AClock()
{

}
#pragma endregion

#pragma region protected override function
// update time
void AClock::UpdateTime(AGameModeMain* _pGameModeMain)
{
	// get hour and minute from game mode main
	Hour = _pGameModeMain->GetCurrentHour();
	Minute = _pGameModeMain->GetCurrentMinute();

	// update clock
	UpdateClock();
}
#pragma endregion