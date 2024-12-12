#include "Game.h"

Game::Game(RenderWindow& win) : window(win) {
    window.setVerticalSyncEnabled(true);

    // Charger la texture du personnage
    if (!playerTexture.loadFromFile("Assets/Image/Player/Idle1.png")) {
        throw runtime_error("Erreur de chargement du sprite du personnage");
    }
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f); // Position initiale du personnage

    // Taille personnage
    playerSprite.setScale(6.f, 6.f);
}

void Game::run()
{
    while (window.isOpen())
    {
        Event _event;

        while (window.pollEvent(_event))
        {
            event(_event);
        }
        rendu();
        loadResources();
        update();
    }
}

void Game::event(Event& _event)
{
    if (_event.type == Event::MouseButtonPressed && _event.mouseButton.button == Mouse::Left) {
        shootProjectile();
    }
}

void Game::update()
{
    const float speeds[4] = { 100.0f, 150.0f, 200.0f, 250.0f };
    float deltaTime = clock.restart().asSeconds();

    for (int i = 0; i < 4; ++i) {
        backgroundOffsets[i] += speeds[i] * deltaTime;

        float scaleX = static_cast<float>(window.getSize().x) / static_cast<float>(backgroundTextures[i].getSize().x);
        float scaleY = static_cast<float>(window.getSize().y) / static_cast<float>(backgroundTextures[i].getSize().y);
        float scale = min(scaleX, scaleY);

        backgroundSprites[i].setScale(scale, scale);

        backgroundSprites[i].setPosition(
            (window.getSize().x - backgroundTextures[i].getSize().x * scale) / 2.f - backgroundOffsets[i],
            (window.getSize().y - backgroundTextures[i].getSize().y * scale) / 2.f
        );

        backgroundSprites[i + 4].setScale(scale, scale);
        backgroundSprites[i + 4].setPosition(
            (window.getSize().x - backgroundTextures[i].getSize().x * scale) / 2.f - backgroundOffsets[i] + backgroundTextures[i].getSize().x * scale,
            (window.getSize().y - backgroundTextures[i].getSize().y * scale) / 2.f
        );

        if (backgroundOffsets[i] >= backgroundTextures[i].getSize().x * scale) {
            backgroundOffsets[i] = 0.0f;
        }
    }

    // Déplacement du personnage
    float moveX = 0.f;
    float moveY = 0.f;

    // Vitesse de déplacement
    const float speed = 6.f;

    // Accumuler les directions en fonction des touches pressées
    if (Keyboard::isKeyPressed(Keyboard::Z)) {
        moveY -= speed; // Haut
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        moveY += speed; // Bas
    }
    if (Keyboard::isKeyPressed(Keyboard::Q)) {
        moveX -= speed; // Gauche
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        moveX += speed; // Droite
    }

    // Normalisation de la vitesse pour les diagonales
    if (moveX != 0.f && moveY != 0.f) {
        float factor = 1.f / sqrt(2.f); // Diviser par racine de 2 pour un mouvement diagonal fluide
        moveX *= factor;
        moveY *= factor;
    }

    // Appliquer le déplacement
    playerSprite.move(moveX, moveY);

    // Mise à jour des projectiles
    updateProjectiles(deltaTime);
}

void Game::loadResources()
{
    const string filenames[4] = {
        "Assets/Image/Jungle/1.Backround.png",
        "Assets/Image/Jungle/2.Trees_back.png",
        "Assets/Image/Jungle/3.Trees_front.png",
        "Assets/Image/Jungle/4.Ground.png"
    };

    for (int i = 0; i < 4; ++i) {
        if (!backgroundTextures[i].loadFromFile(filenames[i])) {
            throw runtime_error("Erreur de chargement de " + filenames[i]);
        }
        backgroundSprites[i].setTexture(backgroundTextures[i]);
        backgroundTextures[i].setRepeated(true);
    }


    // Charger la texture des projectiles
    if (!projectileTexture.loadFromFile("Assets/Image/Player/Weapon/Projectile.png")) {
        throw runtime_error("Erreur de chargement du sprite des projectiles");
    }

}
void Game::shootProjectile() {
    Sprite projectile;
    projectile.setTexture(projectileTexture);
    projectile.setScale(2.f, 2.f);
    projectile.setRotation(45.0f);
    projectile.setPosition(playerSprite.getPosition().x + playerSprite.getGlobalBounds().width,
        playerSprite.getPosition().y + playerSprite.getGlobalBounds().height / 2.f);
    projectiles.push_back(projectile);
}

void Game::updateProjectiles(float deltaTime) {
    const float projectileSpeed = 300.f;

    for (auto it = projectiles.begin(); it != projectiles.end(); ) {
        it->move(projectileSpeed * deltaTime, 0.f);

        // Supprimer les projectiles qui sortent de l'écran
        if (it->getPosition().x > window.getSize().x) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }
}


void Game::rendu()
{
    window.clear();

    // Dessiner les arrières plans
    for (int i = 0; i < 4; ++i) {
        float scaleX = static_cast<float>(window.getSize().x) / static_cast<float>(backgroundTextures[i].getSize().x);
        float scaleY = static_cast<float>(window.getSize().y) / static_cast<float>(backgroundTextures[i].getSize().y);
        float scale = min(scaleX, scaleY);

        backgroundSprites[i].setScale(scale, scale);
        backgroundSprites[i].setPosition(
            (window.getSize().x - backgroundTextures[i].getSize().x * scale) / 2.f - backgroundOffsets[i],
            (window.getSize().y - backgroundTextures[i].getSize().y * scale) / 2.f
        );
        window.draw(backgroundSprites[i]);

        backgroundSprites[i].setPosition(
            (window.getSize().x - backgroundTextures[i].getSize().x * scale) / 2.f - backgroundOffsets[i] + backgroundTextures[i].getSize().x * scale,
            (window.getSize().y - backgroundTextures[i].getSize().y * scale) / 2.f
        );
        window.draw(backgroundSprites[i]);
    }
 

    // Dessiner les projectiles
    for (const auto& projectile : projectiles) {
        window.draw(projectile); // Utilisez 'projectile' au lieu de 'projectiles'
    }
    // Dessiner le personnage
    window.draw(playerSprite);

    window.display();
}


