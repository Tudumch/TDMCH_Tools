// Fill out your copyright notice in the Description page of Project Settings.

#include "Menu/TDMCH_WidgetBase.h"
#include "Components/Button.h"

bool UTDMCH_WidgetBase::Initialize()
{
    if (!Super::Initialize())
    {
        return false;
    }

    return true;
}

void UTDMCH_WidgetBase::NativeOnInitialized()
{
    if (NextButton) NextButton->OnClicked.AddDynamic(this, &ThisClass::OpenNextWidget);
    if (PreviousButton) PreviousButton->OnClicked.AddDynamic(this, &ThisClass::CloseCurrentWidget);
}

void UTDMCH_WidgetBase::OpenNextWidget()
{
    if (OnOpeningNextWidget.IsBound())
    {
        OnOpeningNextWidget.Broadcast(NextMenuWidgetClass);
    }
}

void UTDMCH_WidgetBase::CloseCurrentWidget()
{
    if (OnCloseCurrentWidget.IsBound())
    {
        OnCloseCurrentWidget.Broadcast(this);
    }
}
