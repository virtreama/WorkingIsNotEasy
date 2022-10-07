#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#pragma endregion

#pragma region include project
#include "PlayerPawn.generated.h"
#pragma endregion

#pragma region forward decleration
class UCameraComponent;
class UCapsuleComponent;
class UMotionControllerComponent;
class UPlayerStatsComponent;
#pragma endregion

UCLASS()
/// <summary>
/// player class
/// </summary>
class WORKINGISNOTEASY_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	APlayerPawn();
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="DeltaTime">time since last frame</param>
	virtual void Tick(float DeltaTime) override;
#pragma endregion

#pragma region public UPROPERTY
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// main camera component
	/// </summary>
	UCameraComponent* Camera = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// collision capsule component
	/// </summary>
	UCapsuleComponent* Collision = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// IK target skeletal mesh component
	/// </summary>
	USkeletalMeshComponent* IK = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// head visual skeletal mesh component
	/// </summary>
	USkeletalMeshComponent* Head = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// arms visual skeletal mesh component
	/// </summary>
	USkeletalMeshComponent* Arms = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// left hand visual skeletal mesh component
	/// </summary>
	USkeletalMeshComponent* LeftHand = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// right hand visual skeletal mesh component
	/// </summary>
	USkeletalMeshComponent* RightHand = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// body visual skeletal mesh component
	/// </summary>
	USkeletalMeshComponent* Body = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// left hand motion controller component
	/// </summary>
	UMotionControllerComponent* LeftHandMotionController = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// right hand motion controller component
	/// </summary>
	UMotionControllerComponent* RightHandMotionController = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// left waist bag location component
	/// </summary>
	USceneComponent* LeftWaistBag = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// right waist bag location component
	/// </summary>
	USceneComponent* RightWaistBag = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// player stats component
	/// </summary>
	UPlayerStatsComponent* Stats = nullptr;
#pragma endregion

protected:
#pragma region protected override function
	/// <summary>
	/// called at begin play
	/// </summary>
	virtual void BeginPlay() override;
#pragma endregion
};