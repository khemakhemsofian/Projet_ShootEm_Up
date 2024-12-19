#include "Game.h"

Game::Game(RenderWindow& win) : window(win), player(win), ennemi(win){
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
    if (!_gameMusic.openFromFile("Assets/Audio/Music/Game/The knight journey game-music.mp3")) {
        throw runtime_error("Erreur de chargement de la musique du jeu");
    }	
    _gameMusic.setLoop(true);
    _gameMusic.setVolume(100.0f);
    _gameMusic.play();

}
void Game::event(Event& _event)
{
    player.Events(_event);
    ennemi.Events(_event);
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
    player.update(deltaTime);
  
}

void Game::playMusic() {
    _gameMusic.setLoop(true);
    _gameMusic.play();
}
void Game::stopMusic() {
    _gameMusic.stop(); 
}

void Game::rendu()
{
    window.clear();

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
    player.draw(window);
    window.display();
}


