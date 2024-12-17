#ifndef ENNEMI_H
#define ENNEMI_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Ennemi
{
public:
    Ennemi(RenderWindow& window);
    void update(float deltaTime);
    void draw(RenderWindow& window);
    void Events(Event& _event);
    void EnnemiMovement(float deltaTime);
    void loadResources();
    void Spawn();

private:
    RenderWindow& window;
    float deltaTime;
    Sprite ennemiSprite;
    Texture ennemiTexture;
    float speed;
    float x;
};

#endif // ENNEMI_H
