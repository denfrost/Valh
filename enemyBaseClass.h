// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "enemyHandler.h"
#include "enemyBaseClass.generated.h"

UCLASS()
class VALH_API AenemyBaseClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AenemyBaseClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Handler")
		AenemyHandler* theHandler;

	UFUNCTION(BlueprintCallable, Category = "Management")
		void OnSpawn(AenemyHandler* theOne);

	void DamageTarget(float damage);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseStats")
		int globalIdentifier;

	UFUNCTION(BlueprintCallable, Category = "BaseStats")
		void SetGlobalID(int ID);

	UFUNCTION()
		void EnemyPushBack();

	UFUNCTION()
		void DeathDrop();

	UPROPERTY(EditAnywhere, Category = Mesh)
		class USkeletalMeshComponent* MeshBody;

	UPROPERTY(EditAnywhere, Category = capsule)
		class UCapsuleComponent* capsule;

};
