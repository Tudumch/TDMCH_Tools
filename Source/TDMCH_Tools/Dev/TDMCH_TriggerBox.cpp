// Fill out your copyright notice in the Description page of Project Settings.

#include "Dev/TDMCH_TriggerBox.h"
#include "Components/BoxComponent.h"

// Sets default values
ATDMCH_TriggerBox::ATDMCH_TriggerBox()
{
    PrimaryActorTick.bCanEverTick = true;

    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    CollisionBox->SetCollisionProfileName("Trigger");
    RootComponent = CollisionBox;

    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
    CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ATDMCH_TriggerBox::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ATDMCH_TriggerBox::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATDMCH_TriggerBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
    const FHitResult& SweepResult)
{
}

void ATDMCH_TriggerBox::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}
