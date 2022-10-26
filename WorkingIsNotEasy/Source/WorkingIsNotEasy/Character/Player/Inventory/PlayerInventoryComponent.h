#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#pragma endregion

#pragma region include project
#include "../../../Utility/Enums.h"
#include "PlayerInventoryComponent.generated.h"
#pragma endregion

#pragma region forward decleration
class UGameInstanceMain;
#pragma endregion

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
/// <summary>
/// player inventory actor component class
/// </summary>
class WORKINGISNOTEASY_API UPlayerInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	UPlayerInventoryComponent();
#pragma endregion

protected:
#pragma region protected override function
	/// <summary>
	/// called at begin play
	/// </summary>
	virtual void BeginPlay() override;
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// current apartment of player
	/// </summary>
	EApartment m_apartment = EApartment::HOMELESS;

	/// <summary>
	/// array of tuple with id and transform of all apartment objects owned by the player
	/// </summary>
	TArray<TTuple<int, FTransform>> m_apartmentObjects;

	/// <summary>
	/// array of tuple with id and amount of all inventory objects owned by the player
	/// </summary>
	TArray<TTuple<int, int>> m_inventoryObjects;
#pragma endregion

#pragma region private pointer
	/// <summary>
	/// main game instance reference
	/// </summary>
	UGameInstanceMain* m_pGameInstanceMain = nullptr;
#pragma endregion
};