#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#pragma endregion

#pragma region include project
#include "GameModeTimeDependent.generated.h"
#pragma endregion

#pragma region forward decleration
class AGameModeMain;
#pragma endregion

UCLASS()
/// <summary>
/// abstract class has function to update time in inherit classes
/// </summary>
class WORKINGISNOTEASY_API AGameModeTimeDependent : public AActor
{
	GENERATED_BODY()
	
public:	
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	AGameModeTimeDependent() {};
#pragma endregion

#pragma region public function
	/// <summary>
	/// update time
	/// </summary>
	/// <param
	virtual void UpdateTime(AGameModeMain* _pGameModeMain) {};
#pragma endregion
};