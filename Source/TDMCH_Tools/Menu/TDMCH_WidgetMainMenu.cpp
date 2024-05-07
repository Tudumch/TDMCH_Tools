// Fill out your copyright notice in the Description page of Project Settings.

#include "Menu/TDMCH_WidgetMainMenu.h"
#include "Kismet/KismetSystemLibrary.h"

void UTDMCH_WidgetMainMenu::CloseCurrentWidget()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}
