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


    Texture texture;
    for (int i = 1; i <= 6; ++i) {
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

    for (int i = 1; i <= 4; ++i) {
        if (!texture.loadFromFile("Assets/Image/Player/DeathFrames/Death" + std::to_string(i) + ".png")) {
            throw std::runtime_error("Erreur de chargement du sprite Death" + std::to_string(i));
        }
        deathTextures.push_back(texture);
    }

    if (!shootSoundBuffer.loadFromFile("Assets/Audio/Music/Game/Player_projectile_attack_sword_0.wav")) {
        throw std::runtime_error("Erreur de chargement du son de tir");
    }
    shootSound.setBuffer(shootSoundBuffer);
    shootSound.setVolume(70.f);

    // Initialiser le cooldown
    shootCooldownTime = 0.5f;  // 0.5 seconde entre deux tirs
    shootCooldownTimer = 0.0f;


    walkFrame = 0;
    walkFrameTime = 0.1f;
    walkFrameTimer = 0.0f;

    idleFrame = 0;
    idleFrameTime = 0.2f;
    idleFrameTimer = 0.0f;

    deathFrame = 0;
    deathFrameTime = 0.2f;  
    deathFrameTimer = 0.0f;
    isDead = false;

    maxHealth = 100.0f;  // La vie maximale du personnage
    health = maxHealth;  

    // Barre de vie de fond (arrière-plan)
    healthBarBackground.setSize(sf::Vector2f(200.f, 20.f));  // Taille de la barre
    healthBarBackground.setPosition(10.f, 10.f);  
    healthBarBackground.setFillColor(sf::Color::Red);  

    // Barre de vie (partie dynamique)
    healthBar.setSize(sf::Vector2f(200.f, 20.f));  
    healthBar.setPosition(10.f, 10.f);  
    healthBar.setFillColor(sf::Color(0, 255, 0));

    // Chargement de la police pour "Game Over"
    if (!gameOverFont.loadFromFile("Assets/Font/MedievalMystery.ttf")) {
        throw std::runtime_error("Erreur de chargement de la police Game Over");
    }

    gameOverText.setFont(gameOverFont);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(200);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(400.f, 400.f);  // Position au centre

}

void Player::Events(const Event& event) {

    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        shootProjectile();
    }

    if (event.type == Event::KeyPressed && event.key.code == Keyboard::H) {
        takeDamage(10.0f);  // Appliquer 10 points de dégâts
    }
    
}

void Player::update(float deltaTime) {

    if (shootCooldownTimer > 0.0f) {
        shootCooldownTimer -= deltaTime;
    }

    if (isDead) {
        // Animation de mort
        deathFrameTimer += deltaTime;
        if (deathFrameTimer >= deathFrameTime) {
            deathFrameTimer -= deathFrameTime;

            
            if (deathFrame < deathTextures.size() - 1) {
                deathFrame++;
                playerSprite.setTexture(deathTextures[deathFrame]);
            }
        }
        return;  // On fait plus rien car personnage mort
    }

    // Gére les animations et le mouvement si personnage vivant
    idleFrameTimer += deltaTime;
    walkFrameTimer += deltaTime;

    if (!isMoving()) {
        // Animation Idle
        if (idleFrameTimer >= idleFrameTime) {
            idleFrameTimer -= idleFrameTime;
            idleFrame = (idleFrame + 1) % idleTextures.size();
            playerSprite.setTexture(idleTextures[idleFrame]);
        }
    }
    else {
        // Animation Walk
        if (walkFrameTimer >= walkFrameTime) {
            walkFrameTimer -= walkFrameTime;
            walkFrame = (walkFrame + 1) % walkTextures.size();
            playerSprite.setTexture(walkTextures[walkFrame]);
        }
    }

    // Déplacement
    float moveX = 0.0f, moveY = 0.0f;
    const float speed = 6.0f;

    if (Keyboard::isKeyPressed(Keyboard::Z)) moveY -= speed;
    if (Keyboard::isKeyPressed(Keyboard::S)) moveY += speed;
    if (Keyboard::isKeyPressed(Keyboard::Q)) moveX -= speed;
    if (Keyboard::isKeyPressed(Keyboard::D)) moveX += speed;

    if (moveX != 0.f && moveY != 0.f) {
        float factor = 1.f / sqrt(2.f);
        moveX *= factor;
        moveY *= factor;
    }

    playerSprite.move(moveX, moveY);

    Vector2f newPosition = playerSprite.getPosition() + sf::Vector2f(moveX, moveY);

    float leftBound = 0.0f;
    float rightBound = window.getSize().x - playerSprite.getGlobalBounds().width;
    float topBound = 0.0f;
    float bottomBound = window.getSize().y - playerSprite.getGlobalBounds().height;

    if (newPosition.x < leftBound) newPosition.x = leftBound;
    if (newPosition.x > rightBound) newPosition.x = rightBound;
    if (newPosition.y < topBound) newPosition.y = topBound;
    if (newPosition.y > bottomBound) newPosition.y = bottomBound;

    playerSprite.setPosition(newPosition);

    updateProjectiles(deltaTime);
}


// Fonction pour vérifier si le joueur est en mouvement
bool Player::isMoving() const {
    return (Keyboard::isKeyPressed(Keyboard::Z) || Keyboard::isKeyPressed(Keyboard::S) ||
        Keyboard::isKeyPressed(Keyboard::Q) || Keyboard::isKeyPressed(Keyboard::D));
}


void Player::takeDamage(float damage) {
    if (isDead) return;  // Ne rien faire si le personnage est déjà mort

    health -= damage;
    if (health <= 0) {
        health = 0;
        isDead = true;  // Le personnage est mort
        deathFrame = 0;  // Réinitialiser l'animation de mort
        playerSprite.setTexture(deathTextures[0]);  
        std::cout << "Le personnage est mort!" << std::endl;
    }

    // Mettre à jour la barre de vie
    healthBar.setSize(sf::Vector2f((health / maxHealth) * 200.f, 20.f));
}
 


void Player::shootProjectile() {

    if (shootCooldownTimer > 0.0f) {
        return;
    }

    shootCooldownTimer = shootCooldownTime;

    Sprite projectile;
    projectile.setTexture(projectileTexture);
    projectile.setScale(2.f, 2.f);
    projectile.setRotation(45.0f);
    projectile.setPosition(playerSprite.getPosition().x + playerSprite.getGlobalBounds().width,
        playerSprite.getPosition().y + playerSprite.getGlobalBounds().height / 2.f);
    shootSound.play();
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

    if (!isDead) {
        window.draw(healthBarBackground);
        window.draw(healthBar);
    }
    else {
        window.draw(gameOverText);
    }

    for (const auto& projectile : projectiles) {
        window.draw(projectile);
    }
}

