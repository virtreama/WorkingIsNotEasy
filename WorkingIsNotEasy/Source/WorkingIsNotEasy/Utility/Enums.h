#pragma once

#pragma region include project
#include "CoreMinimal.h"
#pragma endregion

#pragma region character
UENUM(BlueprintType)
/// <summary>
/// type of job
/// </summary>
enum class EJobType : uint8
{
	HOMELESS			= 0		UMETA(DisplayName = "Homeless"),
	SPACE_ENGINEER		= 1		UMETA(DisplayName = "Space Engineer"),
	TRAIN_COORDINATOR	= 2		UMETA(DisplayName = "Train Coordinator"),
	PUBLIC_SERVANT		= 3		UMETA(DisplayName = "Public Servant"),
	FARMER				= 4		UMETA(DisplayName = "Farmer"),
	DOCKWORKER			= 5		UMETA(DisplayName = "Dockworker"),
	CLEANER				= 6		UMETA(DisplayName = "Cleaner"),
	SELLER				= 7		UMETA(DisplayName = "Seller"),
	OFFICE_ADMIN		= 8		UMETA(DisplayName = "Office Admin")
};

UENUM(BlueprintType)
/// <summary>
/// title of job
/// </summary>
enum class EJobTitle : uint8
{
	TRAINEE		= 0		UMETA(DisplayName = "Trainee"),
	INTERNSHIP	= 1		UMETA(DisplayName = "Internship"),
	JUNIOR		= 2		UMETA(DisplayName = "Junior"),
	EXPERIENCED	= 3		UMETA(DisplayName = "Experienced"),
	SENIOR		= 4		UMETA(DisplayName = "Senior"),
	LEAD		= 5		UMETA(DisplayName = "Lead"),
	MANAGER		= 6		UMETA(DisplayName = "Manager")
};
#pragma endregion