// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Menu/TDMCH_WidgetBase.h"
#include "TDMCH_WidgetMainMenu.generated.h"

/**
 *
 */
UCLASS()
class TDMCH_TOOLS_API UTDMCH_WidgetMainMenu : public UTDMCH_WidgetBase
{
    GENERATED_BODY()

protected:
    virtual void CloseCurrentWidget() override;
};
