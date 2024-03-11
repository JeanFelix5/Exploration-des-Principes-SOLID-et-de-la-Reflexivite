// Classe pour le personnage de base
class Character {
public:
    virtual void Attack() {
        // Attaque par défaut 
    }
};

// Classe dérivié du personnage de base
class PlayerCharacter : public Character {
public:
    void Attack() override {
        // Attaque du joueur
    }
};

// Utilisation de l'attaque du joueur
void PerformAttack(Character* character) {
    character->Attack();
}

int main() {
    PlayerCharacter player;
    PerformAttack(&player);
    return 0;
}

// Il y a une ambiguité sur le contenu de la Classe d'attaque du personnage. L'override peut créer des problème suite à la définition de la fonction PerformAttack

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Changement du principe L

// Classe pour le personnage de base
class Character {
public:
    virtual void Attack() {
        // Attaque par défaut 
    }
};

// Classe dérivé du personnage de base
class PlayerCharacter : public Character {
public:
    void Attack() override {
        // Attaque du joueur
    }
};

// Utilisation de l'attaque du joueur
void PerformAttack(Character* character) {
    // Polymorphisme
    character->Attack();
}

int main() {
    Character* player = new PlayerCharacter();
    PerformAttack(player); // Utilisation d'un objet de type PlayerCharacter via un pointeur de type Character
    delete player;
    return 0;
}

