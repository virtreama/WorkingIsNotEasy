#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#pragma endregion

#pragma region include project
#include "GameInstanceMain.generated.h"
#pragma endregion

UCLASS()
/// <summary>
/// main game instance class
/// </summary>
class WORKINGISNOTEASY_API UGameInstanceMain : public UGameInstance
{
	GENERATED_BODY()

public:
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
};