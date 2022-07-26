// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"


class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	// Sets default values for this tank's properties
	ATank();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void HandleDestruction();
	APlayerController* GetTankPlayerController() const { return TankPlayerController; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool bAlive = true;

private:
	UPROPERTY(VisibleAnywhere, Category = "Tank Properties", BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Tank Properties", BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	UCameraComponent* Camera;
	void Move(float Value);
	void Turn(float Value);
	UPROPERTY(EditAnywhere, Category = "Tank Properties", BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	float Speed = 400;
	UPROPERTY(EditAnywhere, Category = "Tank Properties", BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	float RotationSpeed = 200;
	APlayerController* TankPlayerController;
};
