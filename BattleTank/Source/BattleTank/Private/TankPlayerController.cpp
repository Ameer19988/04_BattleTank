// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if ( !ControlledTank )
	{
		UE_LOG( LogTemp, Warning, TEXT( "%s not possesing a tank" ), *( this->GetName() ) )
	}
	else
	{
		UE_LOG( LogTemp, Warning, TEXT( "%s possessing: %s" ), *( this->GetName() ),*( ControlledTank->GetName() ) )
	}

}

// Called every frame
void ATankPlayerController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
	//UE_LOG( LogTemp, Warning, TEXT( "tick !" ))
}
 
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn() );
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if ( !GetControlledTank() ) { return; }

	// Get world location if linetrace through crosshair
	// If it hits the landscape
	// Tell controlled tank to aim at this point
}