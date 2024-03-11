// Superclasse qui va gérer la classe player
class PlayerManager {
private:
    PlayerCharacter playerCharacter;

public:
    void HandleInput() {
        // On va gérer les contrôles du personage
        playerCharacter.ProcessInput();
    }
};

// Classe gérée par le player Manager
class PlayerCharacter {
public:
    void ProcessInput() {
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Changement du principe D

// Interface qui gère le joueur
class IPlayerCharacter {
public:
    virtual void ProcessInput() = 0;
};

// Superclasse qui va gérer la classe player
class PlayerManager {
private:
    std::unique_ptr<IPlayerCharacter> playerCharacter;

public:
    PlayerManager(std::unique_ptr<IPlayerCharacter> character) : playerCharacter(std::move(character)) {}

    void HandleInput() {
        // Gérer les inputs des joueurs
        playerCharacter->ProcessInput();
    }
};

// Classe gérée par le player Manager
class PlayerCharacter : public IPlayerCharacter {
public:
    void ProcessInput() override {
        // Logique de traitement des entrées du joueur
    }
};
