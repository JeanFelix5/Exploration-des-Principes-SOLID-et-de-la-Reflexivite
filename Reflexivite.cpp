#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

// Déclaration de la classe Actor (avec les conventions Unreal engine 5 c++)
UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    //ici le tick n'est pas important
    AMyActor()
    {
        PrimaryActorTick.bCanEverTick = false;
    }

    // Déclaration de la propriété spécifique de la classe
    UPROPERTY(EditAnywhere)
        int32 MyProperty;

    // Déclaration d'une fonction callable depuis Blueprint
    UFUNCTION(BlueprintCallable)
        void MyFunction()
    {
        UE_LOG(LogTemp, Warning, TEXT("MyFunction called"));
    }
};

// Déclaration de la classe OtherActor (toujours avec la nommenclature adéquoite) 
UCLASS()
class MYPROJECT_API AMyOtherActor : public AActor
{
    GENERATED_BODY()

public:
    //Ici le tick n'est pas important
    AMyOtherActor()
    {
        PrimaryActorTick.bCanEverTick = false;
    }

    // Déclaration de la propriété spécifique de la classe
    UPROPERTY(EditAnywhere)
        float MyOtherProperty;

    // Déclaration d'une fonction que l'on peut appeller depuis l'éditeur du moteur unreal engine 
    UFUNCTION(BlueprintCallable)
        void MyOtherFunction()
    {
        UE_LOG(LogTemp, Warning, TEXT("MyOtherFunction called"));
    }
};

// Fonction de test pour la réflexion
void TestReflection()
{
    // Création d'un objet du premier type d'acteur
    AMyActor* Actor = NewObject<AMyActor>();

    // Accès à la propriété MyProperty de l'objet Actor
    UProperty* Property = FindField<UProperty>(AMyActor::StaticClass(), TEXT("MyProperty"));
    // Si la propriété existe ...
    if (Property)
    {
        // Ici on l'affiche sur la console
        int32 Value = Property->Get<int32>(Actor);
        UE_LOG(LogTemp, Warning, TEXT("MyProperty value: %d"), Value);
    }

    // Recherche de la fonction MyFunction de l'objet Actor
    UFunction* Function = AMyActor::StaticClass()->FindFunctionByName(TEXT("MyFunction"));
    if (Function)
    {
        // Appel de la fonction MyFunction de l'objet Actor
        Actor->ProcessEvent(Function, nullptr);
    }
}
