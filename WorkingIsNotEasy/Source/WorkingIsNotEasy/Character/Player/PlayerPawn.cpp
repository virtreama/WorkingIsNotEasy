#pragma region include project
#include "PlayerPawn.h"
#include "Stats/PlayerStatsComponent.h"
#include "Inventory/PlayerInventoryComponent.h"
#pragma endregion

#pragma region include engine
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
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

	// create player inventory component
	Inventory = CreateDefaultSubobject<UPlayerInventoryComponent>(TEXT("Inventory"));
}
#pragma endregion

#pragma region public override function
// update every frame
void APlayerPawn::Tick(float DeltaTime)
{
	// parent update every frame
	Super::Tick(DeltaTime);
}
#pragma endregion

#pragma region protected override function
// called at begin play
void APlayerPawn::BeginPlay()
{
	// parent begin play
	Super::BeginPlay();
}
#pragma endregion