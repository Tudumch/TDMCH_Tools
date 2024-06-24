// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawns/TDMCH_Character2D.h"

void ATDMCH_Character2D::Move(const FInputActionValue& Value)
{
    const FVector2D MovementVector = Value.Get<FVector2D>();
    AddMovementInput(FVector(1, 0, 0), MovementVector.Y);
}
