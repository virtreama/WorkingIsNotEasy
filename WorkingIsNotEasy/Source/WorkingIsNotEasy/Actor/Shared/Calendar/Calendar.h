#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#pragma endregion

#pragma region include project
#include "../GameModeDateDependent/GameModeDateDependent.h"
#include "Calendar.generated.h"
#pragma endregion

UCLASS()
/// <summary>
/// calendar class to visualize the calendar
/// </summary>
class WORKINGISNOTEASY_API ACalendar : public AGameModeDateDependent
{
	GENERATED_BODY()

public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	ACalendar();
#pragma endregion

#pragma region public UPROPERTY
	UPROPERTY(BlueprintReadOnly, Category = "Calendar")
	/// <summary>
	/// current day
	/// </summary>
	int Day = 1;

	UPROPERTY(BlueprintReadOnly, Category = "Calendar")
	/// <summary>
	/// current month
	/// </summary>
	int Month = 1;

	UPROPERTY(BlueprintReadOnly, Category = "Calendar")
	/// <summary>
	/// current year
	/// </summary>
	int Year = 1;
#pragma endregion

#pragma region public UFUNCTION
	UFUNCTION(BlueprintImplementableEvent)
	/// <summary>
	/// update calendar visuals
	/// </summary>
	void UpdateCalendar();
#pragma endregion

protected:
#pragma region protected override function
	/// <summary>
	/// update calendar
	/// </summary>
	virtual void UpdateDate(AGameModeMain* _pGameModeMain) override;
#pragma endregion
};