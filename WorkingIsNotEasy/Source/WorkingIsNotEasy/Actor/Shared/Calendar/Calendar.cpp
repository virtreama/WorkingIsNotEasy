#pragma region include project
#include "Calendar.h"
#include "../../../Game/Mode/Main/GameModeMain.h"
#pragma endregion

#pragma region constructor
// constructor
ACalendar::ACalendar()
{

}
#pragma endregion

#pragma region protected override function
// update date
void ACalendar::UpdateDate(AGameModeMain* _pGameModeMain)
{
	// get day, month and year from game mode main
	Day = _pGameModeMain->GetCurrentDay();
	Month = _pGameModeMain->GetCurrentMonth();
	Year = _pGameModeMain->GetCurrentYear();

	// update calendar
	UpdateCalendar();
}
#pragma endregion