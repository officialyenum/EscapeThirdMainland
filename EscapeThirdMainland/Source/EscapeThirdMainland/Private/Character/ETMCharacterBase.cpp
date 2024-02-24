// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ETMCharacterBase.h"

// Sets default values
AETMCharacterBase::AETMCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    

    // Create a first person camera component.
    FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    check(FPSCameraComponent != nullptr);

    // Attach the camera component to our capsule component.
    FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

    // Position the camera slightly above the eyes.
    FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

    // Enable the pawn to control camera rotation.
    FPSCameraComponent->bUsePawnControlRotation = true;

    // Create a first person mesh component for the owning player.
    FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
    check(FPSMesh != nullptr);

    // Only the owning player sees this mesh.
    FPSMesh->SetOnlyOwnerSee(true);

    // Attach the FPS mesh to the FPS camera.
    FPSMesh->SetupAttachment(FPSCameraComponent);

    // Disable some environmental shadows to preserve the illusion of having a single mesh.
    FPSMesh->bCastDynamicShadow = false;
    FPSMesh->CastShadow = false;

    // The owning player doesn't see the regular (third-person) body mesh.
    GetMesh()->SetOwnerNoSee(true);

}

// Called when the game starts or when spawned
void AETMCharacterBase::BeginPlay()
{
    Super::BeginPlay();

    check(GEngine != nullptr);

    // Display a debug message for five seconds. 
    // The -1 "Key" value argument prevents the message from being updated or refreshed.
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using AETMCharacterBase."));
	
}

// Called every frame
void AETMCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AETMCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Set up "movement" bindings.
    PlayerInputComponent->BindAxis("MoveForward", this, &AETMCharacterBase::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AETMCharacterBase::MoveRight);

    // Set up "look" bindings.
    PlayerInputComponent->BindAxis("Turn", this, &AETMCharacterBase::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &AETMCharacterBase::AddControllerPitchInput);

    // Set up "action" bindings.
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AETMCharacterBase::StartJump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &AETMCharacterBase::StopJump);
}

void AETMCharacterBase::OnFire()
{
}

void AETMCharacterBase::StartJump()
{
    bPressedJump = true;
}

void AETMCharacterBase::StopJump()
{
    bPressedJump = false;
}

void AETMCharacterBase::MoveForward(float Value)
{
}

void AETMCharacterBase::MoveRight(float Value)
{
}


