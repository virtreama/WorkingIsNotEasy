#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#pragma endregion

#pragma region include project
#include "../../Shared/PlayerStatsDependent/PlayerStatsDependent.h"
#include "Resume.generated.h"
#pragma endregion

UCLASS()
/// <summary>
/// resume class to visualize the resume of the player
/// </summary>
class WORKINGISNOTEASY_API AResume : public APlayerStatsDependent
{
	GENERATED_BODY()
	
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	AResume();
#pragma endregion

#pragma region public UFUNCTION
	UFUNCTION(BlueprintImplementableEvent)
	/// <summary>
	/// update resume visuals
	/// </summary>
	void UpdateResume();
#pragma endregion

#pragma region public UPROPERTY
	UPROPERTY(BlueprintReadOnly, Category = "Player Resume")
	/// <summary>
	/// name of the player
	/// </summary>
	FString PlayerName = "";
#pragma endregion

protected:
#pragma region protected override function
	/// <summary>
	/// update stats
	/// </summary>
	virtual void UpdateStats(UPlayerStatsComponent* _pPlayerStats) override;
#pragma endregion
};