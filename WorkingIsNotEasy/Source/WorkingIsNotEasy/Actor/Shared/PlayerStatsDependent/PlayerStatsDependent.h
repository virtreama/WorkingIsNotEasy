#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#pragma endregion

#pragma region include project
#include "PlayerStatsDependent.generated.h"
#pragma endregion

#pragma region forward decleration
class UPlayerStatsComponent;
#pragma endregion

UCLASS()
/// <summary>
/// abstract class has function to update stats in inherit classes
/// </summary>
class WORKINGISNOTEASY_API APlayerStatsDependent : public AActor
{
	GENERATED_BODY()
	
public:	
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	APlayerStatsDependent() {}
#pragma endregion

#pragma region public function
	/// <summary>
	/// update stats
	/// </summary>
	virtual void UpdateStats(UPlayerStatsComponent* _pPlayerStats) {};
#pragma endregion
};