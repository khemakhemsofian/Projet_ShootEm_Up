#include "Game.h"



Game::Game(RenderWindow& win) : window(win), player(win){
    window.setVerticalSyncEnabled(true);
    goblinSpawnTimer = 0.0f;
    goblinSpawnDelay = 2.0f; 
    maxGoblins = 5; 
  
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

    for (int i = 1; i <= 8; ++i) {
        if (!EnnemiTexture.loadFromFile("Assets/Image/Ennemi/Gobelin/WalksFrames/Walk" + to_string(i) + ".png")) {
            throw runtime_error("Erreur de chargement du sprite Walk" + to_string(i));
        }
        walkTextures.push_back(EnnemiTexture);

    }
    
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
    for(auto& ennemi: ennemis)
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
    player.update(deltaTime, ennemis);

    spawnEnnemi(window, deltaTime);
    for (auto& ennemi : ennemis)
    {
        ennemi.update(deltaTime, window);
    }

 
}

void Game::spawnEnnemi(RenderWindow& window,float deltaTime) {
    
    goblinSpawnTimer += deltaTime;
    if (goblinSpawnTimer >= goblinSpawnDelay && ennemis.size() < maxGoblins) {

        goblinSpawnTimer = 0.0f;
        float x = window.getSize().x - 50.0f; 
        float y = static_cast<float>(rand() % static_cast<int>(window.getSize().y - 50.0f)); 
        ennemis.emplace_back(window,Vector2f(x, y), walkTextures);

        cout << ennemis.size() << "   spawn\n";
        
    }

  
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

    for (auto& ennemi : ennemis) {
        cout << "on draw ennemi" << ennemi.getPosition().x << endl;
        ennemi.draw(window);
    }
    player.draw(window);
    window.display();
}


