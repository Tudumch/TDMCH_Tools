// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawns/TDMCH_Character3D.h"

void ATDMCH_Character3D::Move(const FInputActionValue& Value)
{
    const FVector2D MovementVector = Value.Get<FVector2D>();
    const FRotator Rotation = GetControlRotation();
    const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    AddMovementInput(ForwardDirection, MovementVector.X);

    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
    AddMovementInput(RightDirection, MovementVector.Y);
}

void ATDMCH_Character3D::Look(const FInputActionValue& Value)
{
    const FVector2D LookAxisValue = Value.Get<FVector2D>();
    PlayerController->AddYawInput(LookAxisValue.X);
    PlayerController->AddPitchInput(LookAxisValue.Y);
}
