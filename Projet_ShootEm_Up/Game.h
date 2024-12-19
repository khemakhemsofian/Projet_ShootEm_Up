#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Ennemi.h"

using namespace sf;
using namespace std;

class Game
{
public:
    Game(RenderWindow& window);
    void run();
    void playMusic();
    void stopMusic();

private:
    Texture EnnemiTexture;
    vector<Texture> walkTextures;

    float deltaTime;
    RenderWindow& window;
    void event(Event& _event);
    Clock clock;
    void update();
    void spawnEnnemi(RenderWindow& window,float deltaTime);
    void spawnGoblin(const Vector2f& position, RenderWindow& window);
    
   
    void rendu();
    Texture backgroundTextures[4];
    Sprite backgroundSprites[8];
    float backgroundOffsets[4];
   
    void loadResources();
    Player player;
    vector<Ennemi> ennemis;
    float goblinSpawnTimer;
    float goblinSpawnDelay;
    int maxGoblins;
    Music _gameMusic;


protected:

};

#endif // !GAME_H
