// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawns/TDMCH_PlayerControllerBase.h"

#include "EnhancedInputSubSystems.h"
#include "EnhancedInputComponent.h"

#include "TDMCH_Tools/PlayerPawns/TDMCH_CharacterBase.h"
#include "TDMCH_Tools/PlayerPawns/TDMCH_Character2D.h"
#include "TDMCH_Tools/PlayerPawns/TDMCH_Character3D.h"
#include "TDMCH_Tools/PlayerPawns/TDMCH_CharacterTopDown.h"

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
    if (UEnhancedInputComponent* EnhancedInputComponent =
            CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(
            PauseIA, ETriggerEvent::Completed, this, &ThisClass::Pause);
        EnhancedInputComponent->BindAction(
            MoveIA, ETriggerEvent::Triggered, this, &ThisClass::Move);
        EnhancedInputComponent->BindAction(
            LookIA, ETriggerEvent::Triggered, this, &ThisClass::Look);
    }
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
    PlayerPawn = CastChecked<ATDMCH_CharacterBase>(GetPawn());

    if (!PlayerPawn) return;

    CharacterInterface = Cast<ITDMCH_CharacterInterface>(Cast<ATDMCH_Character3D>(PlayerPawn));

    if (!CharacterInterface)
        CharacterInterface = Cast<ITDMCH_CharacterInterface>(Cast<ATDMCH_Character2D>(PlayerPawn));
    if (!CharacterInterface)
        CharacterInterface =
            Cast<ITDMCH_CharacterInterface>(Cast<ATDMCH_CharacterTopDown>(PlayerPawn));
    if (!CharacterInterface)
        CharacterInterface =
            Cast<ITDMCH_CharacterInterface>(Cast<ATDMCH_CharacterBase>(PlayerPawn));
}
