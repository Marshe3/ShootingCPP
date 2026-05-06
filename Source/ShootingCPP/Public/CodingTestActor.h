// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodingTestActor.generated.h"

UCLASS()
class SHOOTINGCPP_API ACodingTestActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACodingTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 number1 = 10;

	UPROPERTY(VisibleAnywhere)
	float number2 = 3.14f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 number3 = 30;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 number4 = 40;

	UPROPERTY(EditInstanceOnly)
	FString name = TEXT("HongGilDong");

	UPROPERTY(EditDefaultsOnly)
	bool isReady = false;

	UFUNCTION(BlueprintCallable)
	int32 AddCustom(int32 a, int32 b);
};
