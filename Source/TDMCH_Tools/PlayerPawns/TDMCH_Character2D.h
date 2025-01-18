// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TDMCH_Tools/PlayerPawns/TDMCH_CharacterBase.h"
#include "PlayerPawns/TDMCH_CharacterInterface.h"
#include "TDMCH_Character2D.generated.h"

UCLASS()
class TDMCH_TOOLS_API ATDMCH_Character2D : public ATDMCH_CharacterBase
{
    GENERATED_BODY()

protected:
    void virtual Move(const FInputActionValue& Value) override;
};
