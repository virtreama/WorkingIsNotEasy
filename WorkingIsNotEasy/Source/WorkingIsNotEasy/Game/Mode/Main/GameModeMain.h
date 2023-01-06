#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#pragma endregion

#pragma region include project
#include "GameModeMain.generated.h"
#pragma endregion

#pragma region forward decleration
class UGameInstanceMain;
class APlayerPawn;
#pragma endregion

UCLASS()
/// <summary>
/// main game mode class
/// </summary>
class WORKINGISNOTEASY_API AGameModeMain : public AGameModeBase
{
	GENERATED_BODY()
	
public:
#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="DeltaTime">time since last frame</param>
	virtual void Tick(float DeltaTime) override;

	/// <summary>
	/// called at begin destroy
	/// </summary>
	virtual void BeginDestroy() override;
#pragma endregion

#pragma region public UPROPERTY
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main Game Mode")
	/// <summary>
	/// scale of time in game world
	/// </summary>
	int TimeScale = 30;
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get current year
	/// </summary>
	/// <returns>current year</returns>
	inline uint8_t GetCurrentYear() { return m_year; }

	/// <summary>
	/// get current month
	/// </summary>
	/// <returns>current month</returns>
	inline uint8_t GetCurrentMonth() { return m_month; }

	/// <summary>
	/// get current day of the month
	/// </summary>
	/// <returns>current day of the month</returns>
	inline uint8_t GetCurrentDay() { return m_day; }

	/// <summary>
	/// get current hour
	/// </summary>
	/// <returns>current hour</returns>
	inline uint8_t GetCurrentHour() { return m_hour; }

	/// <summary>
	/// get current minute
	/// </summary>
	/// <returns>current minute</returns>
	inline uint8_t GetCurrentMinute() { return m_minute; }

	/// <summary>
	/// get current second
	/// </summary>
	/// <returns>current second</returns>
	inline uint8_t GetCurrentSecond() { return m_second; }

	/// <summary>
	/// set player
	/// </summary>
	/// <param name="_pPlayer">player reference</param>
	inline void SetPlayer(APlayerPawn* _pPlayer) { m_pPlayer = _pPlayer; }
#pragma endregion

protected:
#pragma region protected override function
	/// <summary>
	/// called at begin play
	/// </summary>
	virtual void BeginPlay() override;
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// current year
	/// </summary>
	uint8_t m_year = 1;

	/// <summary>
	/// current month
	/// </summary>
	uint8_t m_month = 1;

	/// <summary>
	/// current day of the month
	/// </summary>
	uint8_t m_day = 1;

	/// <summary>
	/// current hour
	/// </summary>
	uint8_t m_hour = 0;

	/// <summary>
	/// current minute
	/// </summary>
	uint8_t m_minute = 0;

	/// <summary>
	/// current second
	/// </summary>
	uint16_t m_second = 0;

	/// <summary>
	/// time counter for increase milliseconds
	/// </summary>
	float m_timeCounter = 0.0f;
#pragma endregion

#pragma region private pointer
	/// <summary>
	/// main game instance reference
	/// </summary>
	UGameInstanceMain* m_pGameInstanceMain = nullptr;

	/// <summary>
	/// player reference
	/// </summary>
	APlayerPawn* m_pPlayer = nullptr;
#pragma endregion

#pragma region private function
	/// <summary>
	/// get starting time from main game instance
	/// </summary>
	void GetStartingTime();

	/// <summary>
	/// update current time depending on time counter
	/// </summary>
	void UpdateTime();

	/// <summary>
	/// get if current day is last day of the month
	/// </summary>
	/// <returns>true if current day is last day of month</returns>
	bool IsLastDayOfMonth();
#pragma endregion
};