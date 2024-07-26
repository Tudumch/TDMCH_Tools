#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"

#include "TDMCH_PlayerControllerBase.generated.h"

UCLASS()
class TDMCH_TOOLS_API ATDMCH_PlayerControllerBase : public APlayerController
{
    GENERATED_BODY()

protected:
    class ATDMCH_CharacterBase* PlayerPawn;
    class ITDMCH_CharacterInterface* CharacterInterface;
    class UEnhancedInputComponent* EnhancedInputComponent;

    UPROPERTY (EditAnywhere, Category = "Input")
        class UInputMappingContext* InputMappingContext;

    UPROPERTY (EditAnywhere, Category = "Input")
        class UInputAction* PauseIA;
    UPROPERTY (EditAnywhere, Category = "Input")
        UInputAction* LookIA;
    UPROPERTY (EditAnywhere, Category = "Input")
        UInputAction* MoveIA;

    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
    virtual void Pause();

    virtual void Look(const FInputActionValue& Value);
    virtual void Move(const FInputActionValue& Value);

private:
    void DefineCoreVariables();
};
