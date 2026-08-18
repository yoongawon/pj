#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyStar.generated.h"

UCLASS()
class PJ_API AMyStar : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyStar();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyStar|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyStar|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MyStar|Properties")
	float RotationSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MyStar|Properties")
	float MoveSpeed = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MyStar|Properties")
	float MaxRange = 200.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyStar|Properties")
	FVector StartLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyStar|Properties")
	float MoveDirection = 1.0f;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "MyStar|Actionds")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category = "MyStar|Properties")
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "MyStar|Event")
	void OnMyStarPickedUP();
};
