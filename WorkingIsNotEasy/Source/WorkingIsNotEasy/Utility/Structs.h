#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#pragma endregion

#pragma region include project
#include "Enums.h"
#include "Structs.generated.h"
#pragma endregion

#pragma region character
USTRUCT(BlueprintType)
/// <summary>
/// job experience
/// </summary>
struct FJobExperience
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Experience")
	/// <summary>
	/// job type
	/// </summary>
	EJobType Job = EJobType::HOMELESS;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Experience")
	/// <summary>
	/// title in the job
	/// </summary>
	EJobTitle Title = EJobTitle::TRAINEE;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Experience")
	/// <summary>
	/// duration in this job in working days
	/// </summary>
	int Duration = 0;
};
#pragma endregion