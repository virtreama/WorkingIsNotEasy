#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#pragma endregion

#pragma region include project
#include "../../../Utility/Structs.h"
#include "PlayerStatsComponent.generated.h"
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

#pragma region forward decleration
class APlayerStatsDependent;
class APlayerPawn;
#pragma endregion

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
/// <summary>
/// player stats actor component class
/// </summary>
class WORKINGISNOTEASY_API UPlayerStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	UPlayerStatsComponent();
#pragma endregion

#pragma region UPROPERTY
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Start Stats")
	/// <summary>
	/// start name
	/// </summary>
	FString StartName = "";

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Start Stats",
		meta = (ClampMin = "0", ClampMax = "4294967295", UIMin = "0", UIMax = "4294967295"))
	/// <summary>
	/// start money value
	/// </summary>
	int StartMoney = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Start Stats",
		meta = (ClampMin = "-10", ClampMax = "10", UIMin = "-10", UIMax = "10"))
	/// <summary>
	/// start starve value
	/// </summary>
	int StartStarve = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Start Stats",
		meta = (ClampMin = "-10", ClampMax = "10", UIMin = "-10", UIMax = "10"))
	/// <summary>
	/// start fitness value
	/// </summary>
	int StartFitness = 0;
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get player name
	/// </summary>
	/// <returns>player name</returns>
	inline string GetPlayerName() { return m_name; }

	/// <summary>
	/// get player money
	/// </summary>
	/// <returns>player money value</returns>
	inline uint32_t GetMoney() { return m_money; }

	/// <summary>
	/// get player starve value
	/// </summary>
	/// <returns>player starve value from -10 to +10</returns>
	inline char GetStarve() { return m_starve; }

	/// <summary>
	/// get player fitness value
	/// </summary>
	/// <returns>player fitness value from -10 to +10</returns>
	inline char GetFitness() { return m_fitness; }

	/// <summary>
	/// get player job experiences
	/// </summary>
	/// <returns>array of all player job experiences</returns>
	inline TArray<FJobExperience> GetJobExperiences() { return m_jobExperiences; }

	/// <summary>
	/// set player
	/// </summary>
	/// <param name="_pPlayer">player reference</param>
	inline void SetPlayer(APlayerPawn* _pPlayer) { m_player = _pPlayer; }
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
	/// player name
	/// </summary>
	string m_name = "";

	/// <summary>
	/// player money value
	/// </summary>
	uint32_t m_money = 0;

	/// <summary>
	/// player starve value
	/// </summary>
	float m_starve = 0.0f;

	/// <summary>
	/// player fitness value
	/// </summary>
	float m_fitness = 0.0f;
#pragma endregion

#pragma region private variable
	/// <summary>
	/// actors that are dependent on the player stats
	/// </summary>
	TArray<APlayerStatsDependent*> m_playerStatsDependentActors;

	/// <summary>
	/// player job experiences
	/// </summary>
	TArray<FJobExperience> m_jobExperiences;
#pragma endregion

#pragma region private pointer
	/// <summary>
	/// player reference
	/// </summary>
	APlayerPawn* m_player = nullptr;
#pragma endregion
};