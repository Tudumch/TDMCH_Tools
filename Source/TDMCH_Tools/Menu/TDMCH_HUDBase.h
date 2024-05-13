// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TDMCH_HUDBase.generated.h"

class UUserWidget;
class UTDMCH_WidgetBase;

UCLASS()
class TDMCH_TOOLS_API ATDMCH_HUDBase : public AHUD
{
    GENERATED_BODY()

public:
    UPROPERTY (EditAnywhere)
        TSubclassOf<UTDMCH_WidgetBase> InitialWidgetClass;

    virtual void BeginPlay() override;

protected:
    AGameModeBase* Gamemode;
    APlayerController* PlayerController;

    UPROPERTY ()
        TArray<UTDMCH_WidgetBase*> OpenedWidgetsArray = {};

    UFUNCTION ()
        void AddWidget(TSubclassOf<UTDMCH_WidgetBase> WidgetClass);
    UFUNCTION ()
        void RemoveWidget(UTDMCH_WidgetBase* Widget);
};
