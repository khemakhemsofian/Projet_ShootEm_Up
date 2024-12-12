#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class Game
{
public:
    Game(RenderWindow& window);
    void run();

private:
    void event(Event& _event);
    Clock clock;
    void update();
    void rendu();
    Texture playerTexture;
    Sprite playerSprite;
    Texture backgroundTextures[4];
    Sprite backgroundSprites[8];
    float backgroundOffsets[4];

    void loadResources();
protected:
  
    RenderWindow& window; 
};

#endif // !GAME_H
