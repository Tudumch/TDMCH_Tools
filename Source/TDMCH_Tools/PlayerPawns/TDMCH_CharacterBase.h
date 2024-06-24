// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "TDMCH_CharacterInterface.h"

#include "TDMCH_CharacterBase.generated.h"

class UInputAction;

UCLASS()
class TDMCH_TOOLS_API ATDMCH_CharacterBase : public ACharacter, public ITDMCH_CharacterInterface
{
    GENERATED_BODY()

public:
    ATDMCH_CharacterBase();

protected:
    APlayerController* PlayerController;

    UPROPERTY (EditAnywhere, BlueprintReadWrite)
        class USpringArmComponent* SpringArm;
    UPROPERTY (EditAnywhere, BlueprintReadWrite)
        class UCameraComponent* Camera;

    UPROPERTY (EditAnywhere, Category = "Input")
        UInputAction* MoveIA;

    virtual void BeginPlay() override;
    virtual void Move(const FInputActionValue& Value);
    virtual void Look(const FInputActionValue& Value);
};
