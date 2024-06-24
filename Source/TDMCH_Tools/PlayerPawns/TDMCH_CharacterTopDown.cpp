// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawns/TDMCH_CharacterTopDown.h"

void ATDMCH_CharacterTopDown::Move(const FInputActionValue& Value)
{
    const FVector2D MovementVector = Value.Get<FVector2D>();
    AddMovementInput(FVector(0, -1, 0), MovementVector.X);
    AddMovementInput(FVector(1, 0, 0), MovementVector.Y);
}
