// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InputActionValue.h"

#include "TDMCH_CharacterInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTDMCH_CharacterInterface : public UInterface
{
    GENERATED_BODY()
};

// Interface with methods for handling player input commands
class TDMCH_TOOLS_API ITDMCH_CharacterInterface
{
    GENERATED_BODY()

public:
    UFUNCTION ()
        virtual void Move(const FInputActionValue& Value) = 0;
    UFUNCTION ()
        virtual void Look(const FInputActionValue& Value) = 0;
};
