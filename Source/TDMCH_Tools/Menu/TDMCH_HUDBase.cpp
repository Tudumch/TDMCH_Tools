// Fill out your copyright notice in the Description page of Project Settings.

#include "Menu/TDMCH_HUDBase.h"
#include "Menu/TDMCH_WidgetBase.h"
#include "Blueprint/UserWidget.h"

void ATDMCH_HUDBase::BeginPlay()
{
    Super::BeginPlay();

    AddWidget(InitialWidgetClass);
}

void ATDMCH_HUDBase::AddWidget(TSubclassOf<UTDMCH_WidgetBase> WidgetClass)
{
    if (!WidgetClass) return;

    // Remove current active widget
    if (OpenedWidgetsArray.Num() > 0)
    {
        UTDMCH_WidgetBase* CurrentActiveWidget = OpenedWidgetsArray.Last();
        CurrentActiveWidget->RemoveFromParent();
    }

    // Add new widget
    UTDMCH_WidgetBase* Widget = CreateWidget<UTDMCH_WidgetBase>(GetWorld(), WidgetClass);

    Widget->AddToViewport();
    OpenedWidgetsArray.Add(Widget);

    Widget->OnOpeningNextWidget.AddDynamic(this, &ThisClass::AddWidget);
    Widget->OnCloseCurrentWidget.AddDynamic(this, &ThisClass::RemoveWidget);
}

void ATDMCH_HUDBase::RemoveWidget(UTDMCH_WidgetBase* Widget)
{
    if (OpenedWidgetsArray.Num() > 1)
    {
        Widget->RemoveFromParent();
        OpenedWidgetsArray.Remove(Widget);

        UTDMCH_WidgetBase* PreviousWidget = OpenedWidgetsArray.Last();
        PreviousWidget->AddToViewport();
    }
}
