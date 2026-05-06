// Fill out your copyright notice in the Description page of Project Settings.

#include "CodingTestActor.h"

// Sets default values
ACodingTestActor::ACodingTestActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACodingTestActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Hello World"));
	UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
	UE_LOG(LogTemp, Warning, TEXT("%.2f"), number2);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *name);
	UE_LOG(LogTemp, Warning, TEXT("%d"), isReady);
	UE_LOG(LogTemp, Warning, TEXT("Add result: %d"), AddCustom(number3, number4));

	if (number3 > 50)
	{
		UE_LOG(LogTemp, Warning, TEXT("number3 is greater than 50"));
	}
	else if (number3 == 50)
	{
		UE_LOG(LogTemp, Warning, TEXT("number3 is 50"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("number3 is less than 50"));
	}

	for (int32 i = 1; i <= 5; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Loop count: %d"), i);
	}
}

int32 ACodingTestActor::AddCustom(int32 a, int32 b)
{
	return a + b;
}

// Called every frame
void ACodingTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
