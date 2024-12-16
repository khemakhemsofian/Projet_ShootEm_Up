// Player.cpp
#include "Player.h"
#include "Game.h"
#include <iostream>

Player::Player(RenderWindow& win) : window(win) {
    loadResources();
}

void Player::loadResources() {
    
    if (!playerTexture.loadFromFile("Assets/Image/Player/IdleFrames/Idle1.png")) {
        throw runtime_error("Erreur de chargement du sprite du personnage");
    }
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f); 
    playerSprite.setScale(6.f, 6.f); 


    sf::Texture texture;
    for (int i = 1; i <= 6; ++i) {
<<<<<<< HEAD
        Texture texture;
=======
>>>>>>> 6caf13f44c2358f8946dd118b191636d37fadc4b
        if (!texture.loadFromFile("Assets/Image/Player/IdleFrames/Idle" + to_string(i) + ".png")) {
            throw runtime_error("Erreur de chargement du sprite Idle" + to_string(i));
        }
        idleTextures.push_back(texture);    
    }
    cout << idleTextures.size();
    if (!projectileTexture.loadFromFile("Assets/Image/Player/Weapon/Projectile.png")) {
        throw runtime_error("Erreur de chargement du sprite des projectiles");
    }

    for (int i = 1; i <= 8; ++i) {
        if (!texture.loadFromFile("Assets/Image/Player/WalkFrames/Walk" + to_string(i) + ".png")) {
            throw runtime_error("Erreur de chargement du sprite Walk" + to_string(i));
        }
        walkTextures.push_back(texture);
    }

    walkFrame = 0;
    walkFrameTime = 0.1f;  
    walkFrameTimer = 0.0f;
  
    idleFrame = 0;
    idleFrameTime = 0.2f;
    idleFrameTimer = 0.0f;
<<<<<<< HEAD
    

=======
>>>>>>> 6caf13f44c2358f8946dd118b191636d37fadc4b

}

void Player::Events(const Event& event) {
 
    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        shootProjectile();
    }
  
}

void Player::update(float deltaTime) {
    idleFrameTimer += deltaTime;
    walkFrameTimer += deltaTime;

    // Gérer l'animation idle
    if (!isMoving()) {
        // Animation de repos (idle)
        if (idleFrameTimer >= idleFrameTime) {
            idleFrameTimer -= idleFrameTime;
            idleFrame = (idleFrame + 1) % (idleTextures.size()-1);
            playerSprite.setTexture(idleTextures[idleFrame]);
            cout << idleFrame << endl;
        }
    }
    else {
        // Animation de marche
        if (walkFrameTimer >= walkFrameTime) {
            walkFrameTimer -= walkFrameTime;
            walkFrame = (walkFrame + 1) % (walkTextures.size()-1);
            playerSprite.setTexture(walkTextures[walkFrame]);
        }
    }

    // Déplacement du personnage
    float moveX = 0.0f;
    float moveY = 0.0f;
    const float speed = 6.0f;

    if (Keyboard::isKeyPressed(Keyboard::Z)) {
        moveY -= speed;
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        moveY += speed;
    }
    if (Keyboard::isKeyPressed(Keyboard::Q)) {
        moveX -= speed;
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        moveX += speed;
    }

    // Normalisation du déplacement pour une vitesse constante
    if (moveX != 0.f && moveY != 0.f) {
        float factor = 1.f / sqrt(2.f);
        moveX *= factor;
        moveY *= factor;
    }

    playerSprite.move(moveX, moveY);

    updateProjectiles(deltaTime);
}

// Fonction pour vérifier si le joueur est en mouvement
bool Player::isMoving() const {
    return (Keyboard::isKeyPressed(Keyboard::Z) || Keyboard::isKeyPressed(Keyboard::S) ||
        Keyboard::isKeyPressed(Keyboard::Q) || Keyboard::isKeyPressed(Keyboard::D));
}


void Player::shootProjectile() {
    
    Sprite projectile;
    projectile.setTexture(projectileTexture);
    projectile.setScale(2.f, 2.f);
    projectile.setRotation(45.0f);
    projectile.setPosition(playerSprite.getPosition().x + playerSprite.getGlobalBounds().width,
        playerSprite.getPosition().y + playerSprite.getGlobalBounds().height / 2.f);
    projectiles.push_back(projectile);
}

void Player::updateProjectiles(float deltaTime) {
    const float projectileSpeed = 300.f;

    for (auto it = projectiles.begin(); it != projectiles.end();) {
        it->move(projectileSpeed * deltaTime, 0.f);

        
        if (it->getPosition().x > window.getSize().x) {
            it = projectiles.erase(it);
        }
        else {
            ++it;
        }
    }
}
void Player::draw(RenderWindow& window) {
    
    window.draw(playerSprite);

  
    for (const auto& projectile : projectiles) {
        window.draw(projectile);
    }
}
