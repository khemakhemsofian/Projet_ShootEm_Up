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
 

private:
    RenderWindow& window;
    float deltaTime;
    Sprite ennemiSprite;
    Texture ennemiTexture;


};

#endif // ENNEMI_H
