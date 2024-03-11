// Personnage de base qui peut bouger attaquer et se défendre 
class ICharacter {
public:
    virtual void Move() = 0;
    virtual void Attack() = 0;
    virtual void Defend() = 0;
};

// Classe pour le joueur
class PlayerCharacter : public ICharacter {
public:
    void Move() override {
        // Le joueur se déplace
    }

    void Attack() override {
        // Le joueur attaque
    }

    void Defend() override {
        // Le joueur se défends
    }
};

// Interface unique qui va gérer les personnages (comme un serveur par exemple)
void HandleCharacter(ICharacter* character) {
    character->Move();
    character->Attack();
    character->Defend();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Changement du principe I

// Exemple de ségrégation d'interface correcte.
// Interface pour le déplacement
class IMovable {
public:
    virtual void Move() = 0;
};

// Interface pour l'attaque
class IAttackable {
public:
    virtual void Attack() = 0;
};

// Interface pour la défense
class IDefendable {
public:
    virtual void Defend() = 0;
};

// Création d'un joueur avec plusieurs interfaces
class PlayerCharacter : public IMovable, public IAttackable, public IDefendable {
public:
    void Move() override {
        // Le joueur se déplace
    }

    void Attack() override {
        // Le joueur attaque
    }

    void Defend() override {
        // Le joueur se défends
    }
};

// Fonction prenant en charge les personnages avec des interfaces spécifiques
void HandleCharacter(IMovable* movableCharacter, IAttackable* attackableCharacter, IDefendable* defendableCharacter) {
    movableCharacter->Move();
    attackableCharacter->Attack();
    defendableCharacter->Defend();
}
