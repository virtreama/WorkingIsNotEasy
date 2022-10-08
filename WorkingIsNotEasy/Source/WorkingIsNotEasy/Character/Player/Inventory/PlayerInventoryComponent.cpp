#pragma region include project
#include "PlayerInventoryComponent.h"
#pragma endregion

#pragma region include engine
#include "Kismet/GameplayStatics.h"
#pragma endregion

#pragma region constructor
// constructor
UPlayerInventoryComponent::UPlayerInventoryComponent()
{
	// disable update every frame
	PrimaryComponentTick.bCanEverTick = false;
}
#pragma endregion

#pragma region protected override function
// called at begin play
void UPlayerInventoryComponent::BeginPlay()
{
	// parent begin play
	Super::BeginPlay();

	// get main game instance reference
	m_pGameInstanceMain = (UGameInstanceMain*)(UGameplayStatics::GetGameInstance(GetOwner()->GetWorld()));
}
#pragma endregion