// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawns/TDMCH_CharacterBase.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"

ATDMCH_CharacterBase::ATDMCH_CharacterBase()
{
    PrimaryActorTick.bCanEverTick = false;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

    SpringArm->SetupAttachment(RootComponent);
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void ATDMCH_CharacterBase::BeginPlay()
{
    Super::BeginPlay();

    PlayerController = Cast<APlayerController>(GetController());
}

void ATDMCH_CharacterBase::Move(const FInputActionValue& Value) {}

void ATDMCH_CharacterBase::Look(const FInputActionValue& Value) {}
