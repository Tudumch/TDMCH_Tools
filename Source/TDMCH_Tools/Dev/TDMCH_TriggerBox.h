// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDMCH_TriggerBox.generated.h"

UCLASS()
class TDMCH_TOOLS_API ATDMCH_TriggerBox : public AActor
{
    GENERATED_BODY()

public:
    ATDMCH_TriggerBox();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY (EditAnywhere, BlueprintReadWrite)
        class UBoxComponent* CollisionBox;

    virtual void Tick(float DeltaTime) override;

    // Function to simplify access to the ComponentBeginOverlap-event from the code
    UFUNCTION ()
        void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
            const FHitResult& SweepResult);
    // Function to simplify access to the ComponentEndOverlap-event from the code
    UFUNCTION ()
        void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
