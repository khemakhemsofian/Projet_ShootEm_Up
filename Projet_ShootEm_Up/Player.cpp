// Player.cpp
#include "Player.h"
#include "Game.h"

Player::Player(RenderWindow& win) : window(win) {
    loadResources();
}

void Player::loadResources() {
    
    if (!playerTexture.loadFromFile("Assets/Image/Player/Idle1.png")) {
        throw runtime_error("Erreur de chargement du sprite du personnage");
    }
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f); 
    playerSprite.setScale(6.f, 6.f); 

 
    for (int i = 1; i <= 6; ++i) {
        sf::Texture texture;
        if (!texture.loadFromFile("Assets/Image/Player/Idle" + to_string(i) + ".png")) {
            throw runtime_error("Erreur de chargement du sprite Idle" + to_string(i));
        }
        idleTextures.push_back(texture);
    }
    if (!projectileTexture.loadFromFile("Assets/Image/Player/Weapon/Projectile.png")) {
        throw runtime_error("Erreur de chargement du sprite des projectiles");
    }

  
    idleFrame = 0;
    idleFrameTime = 0.2f;
    idleFrameTimer = 0.0f;


 
}

void Player::Events(const Event& event) {
 
    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        shootProjectile();
    }
  
}

void Player::update(float deltaTime) {

    idleFrameTimer += deltaTime;
    if (idleFrameTimer >= idleFrameTime) {
        idleFrameTimer -= idleFrameTime;
        idleFrame = (idleFrame + 1) % idleTextures.size();
        playerSprite.setTexture(idleTextures[idleFrame]);
    }
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

  
    if (moveX != 0.f && moveY != 0.f) {
        float factor = 1.f / sqrt(2.f); 
        moveX *= factor;
        moveY *= factor;
    }

    playerSprite.move(moveX, moveY);

    updateProjectiles(deltaTime);
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
