#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#pragma endregion

#pragma region include project
#include "../GameModeTimeDependent/GameModeTimeDependent.h"
#include "Clock.generated.h"
#pragma endregion

UCLASS()
/// <summary>
/// clock class to visualize the clock
/// </summary>
class WORKINGISNOTEASY_API AClock : public AGameModeTimeDependent
{
	GENERATED_BODY()
	
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	AClock();
#pragma endregion

#pragma region public UPROPERTY
	UPROPERTY(BlueprintReadOnly, Category = "Clock")
	/// <summary>
	/// current hour
	/// </summary>
	int Hour = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Clock")
	/// <summary>
	/// current minute
	/// </summary>
	int Minute = 0;
#pragma endregion

#pragma region public UFUNCTION
	UFUNCTION(BlueprintImplementableEvent)
	/// <summary>
	/// update clock visuals
	/// </summary>
	void UpdateClock();
#pragma endregion

protected:
#pragma region protected override function
	/// <summary>
	/// update time
	/// </summary>
	virtual void UpdateTime(AGameModeMain* _pGameModeMain) override;
#pragma endregion
};