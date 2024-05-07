// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TDMCH_WidgetBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FOnOpeningNextWidget, TSubclassOf<UTDMCH_WidgetBase>, Widget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FOnCloseCurrentWidget, class UTDMCH_WidgetBase*, Widget);

class UButton;

UCLASS()
class TDMCH_TOOLS_API UTDMCH_WidgetBase : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual bool Initialize() override;

    UPROPERTY (EditAnywhere)
        TSubclassOf<UTDMCH_WidgetBase> NextMenuWidgetClass;

    UPROPERTY (BlueprintAssignable)
        FOnOpeningNextWidget OnOpeningNextWidget;
    UPROPERTY (BlueprintAssignable)
        FOnCloseCurrentWidget OnCloseCurrentWidget;

    UPROPERTY (meta = (BindWidget))
        UButton* NextButton;
    UPROPERTY (meta = (BindWidget))
        UButton* PreviousButton;

protected:
    virtual void NativeOnInitialized() override;

    UFUNCTION ()
        virtual void OpenNextWidget();
    UFUNCTION ()
        virtual void CloseCurrentWidget();
};
