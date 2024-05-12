// Fill out your copyright notice in the Description page of Project Settings.

#include "Dev/TDMCH_TriggerSphere.h"
#include "Components/SphereComponent.h"

// Sets default values
ATDMCH_TriggerSphere::ATDMCH_TriggerSphere()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if
    // you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    CollisionSphere->SetCollisionProfileName("Trigger");
    RootComponent = CollisionSphere;

    CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
    CollisionSphere->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ATDMCH_TriggerSphere::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ATDMCH_TriggerSphere::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATDMCH_TriggerSphere::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
    const FHitResult& SweepResult)
{
}

void ATDMCH_TriggerSphere::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}
