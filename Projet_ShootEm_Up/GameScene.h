#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Game.h";


using namespace sf;
using namespace std;

class GameScene
{
public:
    
    //void handleEvents(Event& event, RenderWindow& window);
    //void update(float deltaTime);
   // void draw(RenderWindow& window);
    GameScene(Game& _game);
    void run();

private:

    Game& _game;

};

#endif // !GAMESCENE_H