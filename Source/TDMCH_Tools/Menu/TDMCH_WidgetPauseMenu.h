// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TDMCH_WidgetPauseMenu.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnResumeGameButtonPressed);

class UButton;

UCLASS()
class TDMCH_TOOLS_API UTDMCH_WidgetPauseMenu : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY (BlueprintReadWrite, meta = (BindWidget))
        UButton* ResumeButton;
    UPROPERTY (BlueprintReadWrite, meta = (BindWidget))
        UButton* MainMenuButton;

    UPROPERTY (BlueprintAssignable)
        FOnResumeGameButtonPressed OnResumeButtonPressed;

protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY (EditAnywhere)
        FName MainMenuLevel;

    UFUNCTION ()
        virtual void ResumeGame();
    UFUNCTION ()
        virtual void ReturnToMainMenu();
};
