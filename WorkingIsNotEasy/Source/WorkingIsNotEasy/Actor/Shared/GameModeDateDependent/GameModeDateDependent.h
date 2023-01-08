#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#pragma endregion

#pragma region include project
#include "GameModeDateDependent.generated.h"
#pragma endregion

#pragma region forward decleration
class AGameModeMain;
#pragma endregion

UCLASS()
/// <summary>
/// abstract class has function to update date in inherit classes
/// </summary>
class WORKINGISNOTEASY_API AGameModeDateDependent : public AActor
{
	GENERATED_BODY()
	
public:	
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	AGameModeDateDependent() {};
#pragma endregion

#pragma region public function
	/// <summary>
	/// update date
	/// </summary>
	virtual void UpdateDate(AGameModeMain* _pGameModemMain) {};
#pragma endregion
};