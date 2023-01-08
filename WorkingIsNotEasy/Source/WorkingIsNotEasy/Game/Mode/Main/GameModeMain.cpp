#pragma region include project
#include "GameModeMain.h"
#include "../../Instance/GameInstanceMain.h"
#include "../../../Character/Player/PlayerPawn.h"
#include "../../../Actor/Shared/GameModeDateDependent/GameModeDateDependent.h"
#include "../../../Actor/Shared/GameModeTimeDependent/GameModeTimeDependent.h"
#pragma endregion

#pragma region include engine
#include "Kismet/GameplayStatics.h"
#pragma endregion

#pragma region public override function
// update every frame
void AGameModeMain::Tick(float DeltaTime)
{
	// parent update every frame
	Super::Tick(DeltaTime);

	// increase time counter with time scale
	m_timeCounter += DeltaTime * TimeScale;

	// update current time
	UpdateTime();
}

// called at begin destroy
void AGameModeMain::BeginDestroy()
{
	// parent begin destroy
	Super::BeginDestroy();

	// call main instance to update time
	m_pGameInstanceMain->UpdateTime();
}
#pragma endregion

#pragma region protected override function
// called at begin play
void AGameModeMain::BeginPlay()
{
	// parent begin play
	Super::BeginPlay();

	// get main game instance reference
	m_pGameInstanceMain = (UGameInstanceMain*)(UGameplayStatics::GetGameInstance(GetWorld()));

	// set main game mode reference at main game instance
	m_pGameInstanceMain->SetGameModeMain(this);

	// get all date dependent actors
	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGameModeDateDependent::StaticClass(), foundActors);

	// add all found actors to list
	for (int i = 0; i < foundActors.Num(); i++)
		m_dateDependentActors.Add((AGameModeDateDependent*)foundActors[i]);

	// get all time dependent actors
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGameModeTimeDependent::StaticClass(), foundActors);

	// add all found actors to list
	for (int i = 0; i < foundActors.Num(); i++)
		m_timeDependentActors.Add((AGameModeTimeDependent*)foundActors[i]);

	// get starting time from main game instance
	GetStartingTime();
}
#pragma endregion

#pragma region private function
// get starting time from main game instance
void AGameModeMain::GetStartingTime()
{
	// set current time to last saved time
	m_year = m_pGameInstanceMain->GetLastSavedYear();
	m_day = m_pGameInstanceMain->GetLastSavedDay();
	m_month = m_pGameInstanceMain->GetLastSavedMonth();
	m_hour = m_pGameInstanceMain->GetLastSavedHour();
	m_minute = m_pGameInstanceMain->GetLastSavedMinute();
	m_second = m_pGameInstanceMain->GetLastSavedSecond();
}

// update current time depending on time counter
void AGameModeMain::UpdateTime()
{
	// while time counter is more than 1
	while (m_timeCounter >= 1.0f)
	{
		// decrease time counter by 1
		m_timeCounter--;

		// increase current second by 1
		m_second++;
	}

	// while current second is more than 60
	while (m_second >= 60)
	{
		// decrease current second by 60
		m_second -= 60;

		// increase current minute by 1
		m_minute++;

		// update player watch
		m_pPlayer->UpdateWatch();

		// update all time from time dependent actors
		for (int i = 0; i < m_timeDependentActors.Num(); i++)
			m_timeDependentActors[i]->UpdateTime(this);

		// if current minute is 60
		if (m_minute == 60)
		{
			// reset current minute
			m_minute = 0;

			// increase current hour by 1
			m_hour++;

			// if current hour is 24
			if (m_hour == 24)
			{
				// reset hour
				m_hour = 0;

				// if last day of the month
				if (IsLastDayOfMonth())
				{
					// set day to 1
					m_day = 1;

					// increase month by 1
					m_month++;

					// if month is 13
					if (m_month == 13)
					{
						// set month to 1
						m_month = 1;

						// increase year by 1
						m_year++;
					}
				}

				// if not last day of the month
				else
				{
					// increase current day by 1
					m_day++;
				}

				// update all date from date dependent actors
				for (int i = 0; i < m_dateDependentActors.Num(); i++)
					m_dateDependentActors[i]->UpdateDate(this);
			}
		}
	}
}

// get if current day is last day of the month
bool AGameModeMain::IsLastDayOfMonth()
{
	// if current day is 28 and month is 2
	if (m_day == 28 && m_month == 2)
		return true;

	// if current day is 30
	if (m_day == 30)
		// return true if month is 4, 6, 9 or 11
		return m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11;
	
	// if current day is 31
	if (m_day == 31)
		// return true if month is 1, 3, 5, 7, 8, 10 or 12
		return m_month == 1 || m_month == 3 || m_month == 5 || m_month == 7 || m_month == 8 || m_month == 10 || m_month == 12;

	// if not last day of the month return false
	return false;
}
#pragma endregion