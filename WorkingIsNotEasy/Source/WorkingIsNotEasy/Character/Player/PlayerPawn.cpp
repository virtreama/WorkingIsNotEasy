#pragma region include project
#include "PlayerPawn.h"
#include "../../Game/Mode/Main/GameModeMain.h"
#include "Stats/PlayerStatsComponent.h"
#include "Inventory/PlayerInventoryComponent.h"
#pragma endregion

#pragma region include engine
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/TextRenderComponent.h"
#include "MotionControllerComponent.h"
#include "Kismet/GameplayStatics.h"
#pragma endregion

#pragma region constructor
// constructor
APlayerPawn::APlayerPawn()
{
	// enable update every frame
	PrimaryActorTick.bCanEverTick = true;

	// create root scene component
	USceneComponent* pRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = pRoot;

	// create camera component and attach to root
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(pRoot);

	// create capsule component and  attach to root
	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	Collision->SetupAttachment(pRoot);

	// create IK skeletal mesh component and attach to root
	IK = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("IK"));
	IK->SetupAttachment(pRoot);

	// create head skeletal mesh component and attach to IK
	Head = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(IK);

	// create arms skeletal mesh component and attach to IK
	Arms = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Arms"));
	Arms->SetupAttachment(IK);

	// create watch static mesh component and attach to arms
	Watch = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Watch"));
	Watch->SetupAttachment(Arms);

	// create watch text render component and attach to watch
	WatchText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("WatchText"));
	WatchText->SetupAttachment(Watch);

	// create left hand static mesh component and attach to arms
	LeftHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftHand"));
	LeftHand->SetupAttachment(Arms);

	// create right hand static mesh component and attach to arms
	RightHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightHand"));
	RightHand->SetupAttachment(Arms);

	// create wallet static mesh component and attach to arms
	CreditCard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CreditCard"));
	CreditCard->SetupAttachment(Arms);

	// create credit card name text render component and attach to credit card
	CreditCardName = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CreditCardName"));
	CreditCardName->SetupAttachment(CreditCard);

	// create credit card money text render component and attach to credit card
	CreditCardMoney = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CreditCardMoney"));
	CreditCardMoney->SetupAttachment(CreditCard);

	// create body skeletal mesh component and attach to IK
	Body = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(IK);

	// create left hand motion controller component and attach to root
	LeftHandMotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftMotionController"));
	LeftHandMotionController->SetupAttachment(pRoot);

	// create right hand motion controller component and attach to root
	RightHandMotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightMotionController"));
	RightHandMotionController->SetupAttachment(pRoot);

	// create left waist bag component and attach to root
	LeftWaistBag = CreateDefaultSubobject<USceneComponent>(TEXT("LeftWaistBag"));
	LeftWaistBag->SetupAttachment(pRoot);

	// create right waist bag component and attach to root
	RightWaistBag = CreateDefaultSubobject<USceneComponent>(TEXT("RightWaistBag"));
	RightWaistBag->SetupAttachment(pRoot);

	// create player stats component
	Stats = CreateDefaultSubobject<UPlayerStatsComponent>(TEXT("Stats"));
	Stats->SetPlayer(this);

	// create player inventory component
	Inventory = CreateDefaultSubobject<UPlayerInventoryComponent>(TEXT("Inventory"));
}
#pragma endregion

#pragma region public override function
// update every frame
void APlayerPawn::Tick(float DeltaSeconds)
{
	// parent update every frame
	Super::Tick(DeltaSeconds);

	Move();
	SetLocationWaistBags();
	CheckDistanceHandsToWaistBags();
}
#pragma endregion

#pragma region public UFUNCTION
// set right and left trigger values
void APlayerPawn::SetTriggerValues(FVector2D RightLeftAxisValues)
{
	m_rightHandTrigger = RightLeftAxisValues.X;
	m_leftHandTrigger = RightLeftAxisValues.Y;
}
#pragma endregion

#pragma region public function
// update credit card informations
void APlayerPawn::UpdateCreditCard()
{
	// set credit card name and money text
	CreditCardName->SetText(FText::FromString(("Card Holder:\n" + Stats->GetPlayerName()).c_str()));
	CreditCardMoney->SetText(FText::FromString((FString::FromInt(Stats->GetMoney()) + "$")));
}

// update watch text
void APlayerPawn::UpdateWatch()
{
	// if hour is more than 12
	if (m_pGameModeMain->GetCurrentHour() > 12)
	{
		// if hour is 12 it is am
		if (m_pGameModeMain->GetCurrentHour() == 12)
		{
			// set watch text
			WatchText->SetText(FText::FromString(
				(m_pGameModeMain->GetCurrentHour() - 12 < 10 ? "0" : "") +
				FString::FromInt(m_pGameModeMain->GetCurrentHour() - 12) +
				":" + (m_pGameModeMain->GetCurrentMinute() < 10 ? "0" : "") +
				FString::FromInt(m_pGameModeMain->GetCurrentMinute()) +
				"\nam"
			));
		}

		// if hour is lower than 12 it is pm
		else
		{
			// set watch text
			WatchText->SetText(FText::FromString(
				(m_pGameModeMain->GetCurrentHour() - 12 < 10 ? "0" : "") +
				FString::FromInt(m_pGameModeMain->GetCurrentHour() - 12) +
				":" + (m_pGameModeMain->GetCurrentMinute() < 10 ? "0" : "") +
				FString::FromInt(m_pGameModeMain->GetCurrentMinute()) +
				"\npm"
			));
		}
	}

	// if hour is under 12
	else
	{
		// if hour is 12 it is pm
		if (m_pGameModeMain->GetCurrentHour() == 12)
		{
			// set watch text
			WatchText->SetText(FText::FromString(
				(m_pGameModeMain->GetCurrentHour() < 10 ? "0" : "") +
				FString::FromInt(m_pGameModeMain->GetCurrentHour()) +
				":" + (m_pGameModeMain->GetCurrentMinute() < 10 ? "0" : "") +
				FString::FromInt(m_pGameModeMain->GetCurrentMinute()) +
				"\npm"
			));
		}

		// if hour is 0 it is am but the hour is 12
		else if (m_pGameModeMain->GetCurrentHour() == 0)
		{
			// set watch text
			WatchText->SetText(FText::FromString(FString::FromInt(12) +
				":" + (m_pGameModeMain->GetCurrentMinute() < 10 ? "0" : "") +
				FString::FromInt(m_pGameModeMain->GetCurrentMinute()) +
				"\nam"
			));
		}

		// if hour is between 1 and 11 it is am
		else
		{
			// set watch text
			WatchText->SetText(FText::FromString(
				(m_pGameModeMain->GetCurrentHour() < 10 ? "0" : "") +
				FString::FromInt(m_pGameModeMain->GetCurrentHour()) +
				":" + (m_pGameModeMain->GetCurrentMinute() < 10 ? "0" : "") +
				FString::FromInt(m_pGameModeMain->GetCurrentMinute()) +
				"\nam"
			));
		}
	}
}
#pragma endregion

#pragma region protected override function
// called at begin play
void APlayerPawn::BeginPlay()
{
	// parent begin play
	Super::BeginPlay();

	// get main game mode reference and set player
	m_pGameModeMain = (AGameModeMain*)(UGameplayStatics::GetGameMode(GetWorld()));
	m_pGameModeMain->SetPlayer(this);

	// hide credit card and texts
	CreditCard->SetVisibility(false);
	CreditCardName->SetVisibility(false);
	CreditCardMoney->SetVisibility(false);

	// set watch text
	WatchText->SetText(FText::FromString("12:00\nam"));
}
#pragma endregion

#pragma region private function
// set location of right and left waist bag
void APlayerPawn::SetLocationWaistBags()
{
	// set temp vector to camera forward without Z axis
	m_tempVector = FVector(1.0f, 1.0f, 0.0f) * Camera->GetForwardVector();
	m_tempVector.Normalize();

	// set waist bags to camera relative location
	RightWaistBag->SetRelativeLocation(Camera->GetRelativeLocation());
	LeftWaistBag->SetRelativeLocation(Camera->GetRelativeLocation());

	// set waist bags location forward relative to camera
	RightWaistBag->AddRelativeLocation(m_tempVector * (-30.0f));
	LeftWaistBag->AddRelativeLocation(m_tempVector * (-30.0f));

	// set temp vector to camera right without Z axis
	m_tempVector = FVector(1.0f, 1.0f, 0.0f) * Camera->GetRightVector();
	m_tempVector.Normalize();

	// set waist bags location right relative to camera
	RightWaistBag->AddRelativeLocation(m_tempVector * 25.0f);
	LeftWaistBag->AddRelativeLocation(m_tempVector * (-25.0f));

	// set waist bags location up relative to camera
	RightWaistBag->AddRelativeLocation(FVector::UpVector * (-70.0f));
	LeftWaistBag->AddRelativeLocation(FVector::UpVector * (-70.0f));
}

// check distance of right and left hand to right and left waist bag
void APlayerPawn::CheckDistanceHandsToWaistBags()
{
	// if credit card not visible
	if (!CreditCard->IsVisible())
	{
		// if distance from right motion controller to right waist bag is lower than 10cm
		if ((RightWaistBag->GetRelativeLocation() - RightHandMotionController->GetRelativeLocation()).SquaredLength() <= 200.0f)
		{
			// if right trigger axis is higher than 0.75
			if (m_rightHandTrigger >= 0.75f)
			{
				// show credit card and texts
				CreditCard->SetVisibility(true);
				CreditCardName->SetVisibility(true);
				CreditCardMoney->SetVisibility(true);
			}
		}
	}

	// if credit card is visible
	else
	{
		// if right trigger axis is lower than 0.75
		if (m_rightHandTrigger < 0.75f)
		{
			// hide credit card and texts
			CreditCard->SetVisibility(false);
			CreditCardName->SetVisibility(false);
			CreditCardMoney->SetVisibility(false);
		}
	}
}

// move player
void APlayerPawn::Move()
{
	// set temp vector to camera location
	m_tempVector = Camera->GetRelativeLocation();
	m_tempVector.Z += -164.0f;

	// set player meshes to camera location horizontal
	IK->SetRelativeLocation(m_tempVector);

	// set temp vector to camera forward horizontal only
	m_tempVector = Camera->GetForwardVector();
	m_tempVector.Z = 0.0f;
	m_tempVector.Normalize();

	// rotate player meshes to camera rotation horizontal
	IK->SetWorldRotation(m_tempVector.Rotation());
}
#pragma endregion