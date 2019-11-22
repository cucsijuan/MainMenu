// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformPuzzleGameMode.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMPUZZLE_API ALobbyGameMode : public APlatformPuzzleGameMode
{
	GENERATED_BODY()
	
public:
	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void Logout(AController* Exiting) override;

private:
	UPROPERTY()
	FTimerHandle GameStartTimer;

	uint32 NumberOfPlayers = 0;

	void StartGame();
};
