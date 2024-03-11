#pragma once

// Problèmes de responsabilité unique

class PlayerCharacter {
public:
    void MoveForward(float Value) {
        // Le personnage avance 
    }

    void FireWeapon() {
        // Le personnage tire
    }

    void TakeDamage(int Amount) {
        // Le personnage prends des dégats 
    }
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Changement pour correction du principe S

// Classe PlayerCharacter avec une responsabilité unique pour le déplacement
class PlayerCharacter {
public:
    void MoveForward(float Value) {
        // Logique de déplacement vers l'avant
    }
};

// Classe Weapon avec une responsabilité unique pour le tir d'arme
class Weapon {
public:
    void Fire() {
        // L'arme tire
    }
};

// Classe Damageable avec une responsabilité unique pour la gestion des dégâts
class Damageable {
public:
    void TakeDamage(int Amount) {
        // L'entité prends des degats
    }
};
