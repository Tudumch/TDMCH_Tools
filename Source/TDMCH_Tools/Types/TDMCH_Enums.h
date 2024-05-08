// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class EMatchState : uint8
{
    WaitingToStart = 0,
    InProgress,
    Pause,
    GameOver
};
