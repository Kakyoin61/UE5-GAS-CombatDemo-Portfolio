// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
// 添加下面这一行来解决“类型不完整”的报错
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.generated.h"

/**
 * 
 */

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
	
UCLASS()
class P01_GAS_DEMO_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	// 生命值
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")
	FGameplayAttributeData HP;	
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, HP);
	
	// 额外生命值（护盾值）
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")
	FGameplayAttributeData ExHP;	
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ExHP);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")
	FGameplayAttributeData MaxHP;	
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHP);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")
	FGameplayAttributeData MP;	
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MP);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")
	FGameplayAttributeData MaxMP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxMP);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Strength);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseAttributeSet")
	FGameplayAttributeData MaxStrength;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxStrength);
	
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data) override;
};
