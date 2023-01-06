#pragma once

#pragma region include engine
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#pragma endregion

#pragma region include project
#include "PlayerPawn.generated.h"
#pragma endregion

#pragma region forward decleration
class AGameModeMain;
class UCameraComponent;
class UCapsuleComponent;
class UTextRenderComponent;
class UMotionControllerComponent;
class UPlayerStatsComponent;
class UPlayerInventoryComponent;
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
	/// <param name="DeltaSeconds">time since last frame</param>
	virtual void Tick(float DeltaSeconds) override;
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
	/// watch static mesh component
	/// </summary>
	UStaticMeshComponent* Watch = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// watch text component
	/// </summary>
	UTextRenderComponent* WatchText = nullptr;

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
	/// credit card static mesh component
	/// </summary>
	UStaticMeshComponent* CreditCard = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// credit card name text render component
	/// </summary>
	UTextRenderComponent* CreditCardName = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// credit card money text render component
	/// </summary>
	UTextRenderComponent* CreditCardMoney = nullptr;

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Pawn")
	/// <summary>
	/// player inventory component
	/// </summary>
	UPlayerInventoryComponent* Inventory = nullptr;
#pragma endregion

#pragma region public UFUNCTION
	UFUNCTION(BlueprintCallable, Category = "Player Pawn")
	/// <summary>
	/// set right and left trigger values
	/// </summary>
	/// <param name="RightLeftAxisValues">right (x) and left (y) trigger axis values</param>
	void SetTriggerValues(FVector2D RightLeftAxisValues);
#pragma endregion

#pragma region public function
	/// <summary>
	/// update credit card informations
	/// </summary>
	void UpdateCreditCard();

	/// <summary>
	/// update watch text
	/// </summary>
	void UpdateWatch();
#pragma endregion

protected:
#pragma region protected override function
	/// <summary>
	/// called at begin play
	/// </summary>
	virtual void BeginPlay() override;
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// right hand trigger axis value
	/// </summary>
	float m_rightHandTrigger = 0.0f;

	/// <summary>
	/// left hand trigger axis value
	/// </summary>
	float m_leftHandTrigger = 0.0f;
#pragma endregion

#pragma region private variable
	/// <summary>
	/// temporary vector for calculation etc that it is not allocated every frame
	/// </summary>
	FVector m_tempVector = FVector();
#pragma endregion

#pragma region private pointer
	/// <summary>
	/// main game mode reference
	/// </summary>
	AGameModeMain* m_pGameModeMain = nullptr;
#pragma endregion

#pragma region private function
	/// <summary>
	/// set location of right and left waist bag
	/// </summary>
	void SetLocationWaistBags();

	/// <summary>
	/// check distance of right and left hand to right and left waist bag
	/// </summary>
	void CheckDistanceHandsToWaistBags();
#pragma endregion
};