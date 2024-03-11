#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor()
    {
        PrimaryActorTick.bCanEverTick = false;
    }

    UPROPERTY(EditAnywhere)
    int32 MyProperty;

    UFUNCTION(BlueprintCallable)
    void MyFunction()
    {
        UE_LOG(LogTemp, Warning, TEXT("MyFunction called"));
    }
};

UCLASS()
class MYPROJECT_API AMyOtherActor : public AActor
{
    GENERATED_BODY()

public:
    AMyOtherActor()
    {
        PrimaryActorTick.bCanEverTick = false;
    }

    UPROPERTY(EditAnywhere)
    float MyOtherProperty;

    UFUNCTION(BlueprintCallable)
    void MyOtherFunction()
    {
        UE_LOG(LogTemp, Warning, TEXT("MyOtherFunction called"));
    }
};

void TestReflection()
{
    AMyActor* Actor = NewObject<AMyActor>();
    
    // Accéder à la propriété MyProperty de l'objet Actor
    UProperty* Property = FindField<UProperty>(AMyActor::StaticClass(), TEXT("MyProperty"));
    if (Property)
    {
        int32 Value = Property->Get<int32>(Actor);
        UE_LOG(LogTemp, Warning, TEXT("MyProperty value: %d"), Value);
    }

    // Appeler la fonction MyFunction de l'objet Actor
    UFunction* Function = AMyActor::StaticClass()->FindFunctionByName(TEXT("MyFunction"));
    if (Function)
    {
        Actor->ProcessEvent(Function, nullptr);
    }
}

