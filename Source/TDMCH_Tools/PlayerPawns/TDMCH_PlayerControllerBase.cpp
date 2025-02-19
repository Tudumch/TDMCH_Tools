// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawns/TDMCH_PlayerControllerBase.h"

#include "EnhancedInputSubSystems.h"
#include "EnhancedInputComponent.h"

#include "TDMCH_Tools/PlayerPawns/TDMCH_Character2D.h"

void ATDMCH_PlayerControllerBase::BeginPlay()
{
    Super::BeginPlay();

    DefineCoreVariables();
}

void ATDMCH_PlayerControllerBase::SetupInputComponent()
{
    Super::SetupInputComponent();

    // MappingContext setup
    if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubSystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        EnhancedInputSubSystem->AddMappingContext(InputMappingContext, 2);
    }

    // InputActions setup
    EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
    if (!EnhancedInputComponent) return;

    EnhancedInputComponent->BindAction(PauseIA, ETriggerEvent::Completed, this, &ThisClass::Pause);
    EnhancedInputComponent->BindAction(MoveIA, ETriggerEvent::Triggered, this, &ThisClass::Move);
    EnhancedInputComponent->BindAction(LookIA, ETriggerEvent::Triggered, this, &ThisClass::Look);
}

void ATDMCH_PlayerControllerBase::Pause()
{
    IsPaused() ? SetPause(false) : SetPause(true);
}

void ATDMCH_PlayerControllerBase::Look(const FInputActionValue& Value)
{
    if (!CharacterInterface) return;

    CharacterInterface->Look(Value);
}

void ATDMCH_PlayerControllerBase::Move(const FInputActionValue& Value)
{
    if (!CharacterInterface) return;

    CharacterInterface->Move(Value);
}

void ATDMCH_PlayerControllerBase::DefineCoreVariables()
{
    PlayerPawn = GetPawn();
    CharacterInterface = Cast<ITDMCH_CharacterInterface>(PlayerPawn);
}
