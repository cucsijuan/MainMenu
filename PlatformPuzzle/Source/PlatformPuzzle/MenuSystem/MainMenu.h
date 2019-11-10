// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

USTRUCT()
struct FServerData
{
	GENERATED_BODY()

	FString Name;
	uint16 CurrentPlayers;
	uint16 MaxPlayers;
	FString HostUsername;
};

/**
 * 
 */
UCLASS()
class PLATFORMPUZZLE_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()
public:
	UMainMenu(const FObjectInitializer & ObjectIntializer);

	void SetServerList(TArray<FServerData> ServerNames);

	void SelectIndex(uint32 Index);

protected:
	virtual bool Initialize() override;

private:
	TSubclassOf<class UUserWidget> ServerRowClass;

	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* ConfirmJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* ServerList;

	TOptional<uint32> SelectedIndex;

	UFUNCTION()
	void  HostServer();

	UFUNCTION()
	void  JoinServer();

	UFUNCTION()
	void  OpenJoinMenu();

	UFUNCTION()
	void  OpenMainMenu();

	UFUNCTION()
	void QuitPressed();
	
	void UpdateChildren();
};
