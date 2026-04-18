// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayEffectTypes.h"
#include "BaseGameplayAbility.h"
#include "BaseCharacter.generated.h"


class UBaseGameplayAbility;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangeEvent, float, NewValue);
UCLASS()
class P01_GAS_DEMO_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(BlueprintAssignable,Category="Ability")
	FOnHealthChangeEvent HPChangeEvent;
	
	UPROPERTY(BlueprintAssignable,Category="Ability")
	FOnHealthChangeEvent MPChangeEvent;
	
	UPROPERTY(BlueprintAssignable,Category="Ability")
	FOnHealthChangeEvent StrengthChangeEvent;
	
	void OnHealthAttributeChanged(const struct FOnAttributeChangeData& Data);
	
	void OnMPAttributeChanged(const struct FOnAttributeChangeData& Data);
	
	void OnStrengthAttributeChanged(const struct FOnAttributeChangeData& Data);
	
	UFUNCTION(BlueprintCallable, Category="BaseCharacter")
	FGameplayAbilityInfo GameplayAbilityInfo(TSubclassOf<UBaseGameplayAbility>AbilityClass,int Level);
};

