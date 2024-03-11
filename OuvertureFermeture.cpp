// Représentation du principe OuvertureFermeture
//Ici, tout ajout qui pourrait être fait pour ajouter une méthode de déplacement doit modifier la fonction de base ci-dessous.
class PlayerCharacter {
public:
    void MoveForward(float Value) {
        if (Value > 0.0f) {
            // Avancer
        }
        else {
            // Stop
        }
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Correction du principe O
class CharacterMovement {
public:
    virtual void MoveForward(float Value) = 0;
};

// On implémente le déplacement classique
class NormalMovement : public CharacterMovement {
public:
    void MoveForward(float Value) override {
        // Avancer
    }
};

// Implémentation de CharacterMovement pour le sprint
class SprintMovement : public CharacterMovement {
public:
    void MoveForward(float Value) override {
        // Logique de sprint vers l'avant
    }
};

// Ici On défini le déplacement du joueur grâce à la fonction setMovement qui permet d'appeler une autre fonction qui va définir la manière de se déplacer
// On peut imaginer un sprint, ramper, etc...
class PlayerCharacter {
private:
    std::unique_ptr<CharacterMovement> Movement;

public:
    void SetMovement(std::unique_ptr<CharacterMovement> NewMovement) {
        Movement = std::move(NewMovement);
    }

    void MoveForward(float Value) {
        Movement->MoveForward(Value);
    }
};
