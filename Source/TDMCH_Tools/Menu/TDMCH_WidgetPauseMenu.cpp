// Fill out your copyright notice in the Description page of Project Settings.

#include "Menu/TDMCH_WidgetPauseMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UTDMCH_WidgetPauseMenu::NativeOnInitialized()
{
    if (ResumeButton) ResumeButton->OnClicked.AddDynamic(this, &ThisClass::ResumeGame);
    if (MainMenuButton) MainMenuButton->OnClicked.AddDynamic(this, &ThisClass::ReturnToMainMenu);
}

void UTDMCH_WidgetPauseMenu::ResumeGame()
{
    if (OnResumeButtonPressed.IsBound())
    {
        OnResumeButtonPressed.Broadcast();
    }
}

void UTDMCH_WidgetPauseMenu::ReturnToMainMenu()
{
    if (MainMenuLevel == "") return;

    UGameplayStatics::OpenLevel(this, MainMenuLevel);
}
