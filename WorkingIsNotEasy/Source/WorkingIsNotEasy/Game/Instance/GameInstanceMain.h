#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#pragma endregion

#pragma region include project
#include "GameInstanceMain.generated.h"
#pragma endregion

#pragma region forward decleration
class AGameModeMain;
#pragma endregion

UCLASS()
/// <summary>
/// main game instance class
/// </summary>
class WORKINGISNOTEASY_API UGameInstanceMain : public UGameInstance
{
	GENERATED_BODY()

public:
#pragma region public UPROPERTY
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player inventory")
	/// <summary>
	/// array of tuple with name and subclass of every apartment object
	/// </summary>
	TArray<TSubclassOf<AActor>> ApartmentObjects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player inventory")
	/// <summary>
	/// array of tuple with name and subclass of every inventory object
	/// </summary>
	TArray<TSubclassOf<AActor>> InventoryObjects;
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// set main game mode reference
	/// </summary>
	/// <param name="_pGameModeMain">main game mode reference</param>
	inline void SetGameModeMain(AGameModeMain* _pGameModeMain) { m_pGameModeMain = _pGameModeMain; }

	/// <summary>
	/// get last saved year
	/// </summary>
	/// <returns>last saved year</returns>
	inline uint8_t GetLastSavedYear() { return m_year; }

	/// <summary>
	/// get last saved month
	/// </summary>
	/// <returns>last saved month</returns>
	inline uint8_t GetLastSavedMonth() { return m_month; }

	/// <summary>
	/// get last saved day of the month
	/// </summary>
	/// <returns>last saved day of the month</returns>
	inline uint8_t GetLastSavedDay() { return m_day; }

	/// <summary>
	/// get last saved hour
	/// </summary>
	/// <returns>last saved hour</returns>
	inline uint8_t GetLastSavedHour() { return m_hour; }

	/// <summary>
	/// get last saved minute
	/// </summary>
	/// <returns>last saved minute</returns>
	inline uint8_t GetLastSavedMinute() { return m_minute; }

	/// <summary>
	/// get last saved second
	/// </summary>
	/// <returns>last saved second</returns>
	inline uint8_t GetLastSavedSecond() { return m_second; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// update current time from game mode
	/// </summary>
	void UpdateTime();
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// last saved year from game mode
	/// </summary>
	uint8_t m_year = 1;

	/// <summary>
	/// last saved month from game mode
	/// </summary>
	uint8_t m_month = 1;

	/// <summary>
	/// last saved day of the month from game mode
	/// </summary>
	uint8_t m_day = 1;

	/// <summary>
	/// last saved hour from game mode
	/// </summary>
	uint8_t m_hour = 0;

	/// <summary>
	/// last saved minute from game mode
	/// </summary>
	uint8_t m_minute = 0;

	/// <summary>
	/// last saved second from game mode
	/// </summary>
	uint8_t m_second = 0;
#pragma endregion

#pragma region private pointer
	/// <summary>
	/// main game mode reference
	/// </summary>
	AGameModeMain* m_pGameModeMain = nullptr;
#pragma endregion
};