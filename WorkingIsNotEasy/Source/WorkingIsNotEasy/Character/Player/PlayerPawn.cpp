#pragma region include project
#include "PlayerPawn.h"
#include "Stats/PlayerStatsComponent.h"
#include "Inventory/PlayerInventoryComponent.h"
#pragma endregion

#pragma region include engine
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/TextRenderComponent.h"
#include "MotionControllerComponent.h"
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

	// create left hand skeletal mesh component and attach to IK
	LeftHand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LeftHand"));
	LeftHand->SetupAttachment(IK);

	// create right hand skeletal mesh component and attach to IK
	RightHand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RightHand"));
	RightHand->SetupAttachment(IK);

	// create wallet static mesh component and attach to right hand
	CreditCard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CreditCard"));
	CreditCard->SetupAttachment(RightHand);

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
#pragma endregion

#pragma region protected override function
// called at begin play
void APlayerPawn::BeginPlay()
{
	// parent begin play
	Super::BeginPlay();

	// hide credit card and texts
	CreditCard->SetVisibility(false);
	CreditCardName->SetVisibility(false);
	CreditCardMoney->SetVisibility(false);
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
#pragma endregion