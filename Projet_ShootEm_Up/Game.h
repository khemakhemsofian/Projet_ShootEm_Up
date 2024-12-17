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
    float deltaTime;
    RenderWindow& window;
    void event(Event& _event);
    Clock clock;
    void update();
    void rendu();
    Texture backgroundTextures[4];
    Sprite backgroundSprites[8];
    float backgroundOffsets[4];
    void loadResources();
    Player player;
    Ennemi ennemi;
    Music _gameMusic;


protected:

};

#endif // !GAME_H
