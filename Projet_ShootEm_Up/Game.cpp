#include "Game.h"

Game::Game(RenderWindow& win) : window(win) {
    window.setVerticalSyncEnabled(true);

}

void Game::run()
{
    loadResources();
    while (window.isOpen())
    {
        Event _event;

        while (window.pollEvent(_event))
        {
            event(_event);
        }
        rendu();
        update();
    }
}

void Game::event(Event& _event)
{
    
    if (_event.type == Event::KeyPressed) {
        float moveX = 0.f;
        float moveY = 0.f;

        // Vérification des touches ZQSD pour les directions
        if (_event.key.code == Keyboard::Z) {
            moveY = -15.f; // Déplacer vers le haut
        }
        else if (_event.key.code == Keyboard::S) {
            moveY = 15.f;  // Déplacer vers le bas
        }
        else if (_event.key.code == Keyboard::Q) {
            moveX = -15.f; // Déplacer vers la gauche
        }
        else if (_event.key.code == Keyboard::D) {
            moveX = 15.f;  // Déplacer vers la droite
        }
        else if (_event.key.code == (Keyboard::Q | Keyboard::Z)) {
            moveX = -15.f; // Déplacer en haut à gauche
            moveY = -15.f;
        }
        else if (_event.key.code == (Keyboard::D | Keyboard::Z)) {
            moveX = 15.f;  // Déplacer en haut à droite
            moveY = -15.f;
        }
        else if (_event.key.code == (Keyboard::Q | Keyboard::S)) {
            moveX = -15.f; // Déplacer en bas à gauche
            moveY = 15.f;
        }
        else if (_event.key.code == (Keyboard::D | Keyboard::S)) {
            moveX = 15.f;  // Déplacer en bas à droite
            moveY = 15.f;
        }

        // Appliquer le déplacement
        playerSprite.move(moveX, moveY);
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

    // Charger la texture du personnage
    if (!playerTexture.loadFromFile("Assets/Image/Player/Idle.png")) {
        throw runtime_error("Erreur de chargement du sprite du personnage");
    }
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(7.0f,7.0f);
    playerSprite.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f); // Position initiale personnage
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

    // Dessiner le personnage
    window.draw(playerSprite);

    window.display(); 
}
