// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TDMCH_Tools/PlayerPawns/TDMCH_CharacterBase.h"
#include "TDMCH_CharacterTopDown.generated.h"

/**
 *
 */
UCLASS()
class TDMCH_TOOLS_API ATDMCH_CharacterTopDown : public ATDMCH_CharacterBase
{
    GENERATED_BODY()

protected:
    void virtual Move(const FInputActionValue& Value) override;
};
