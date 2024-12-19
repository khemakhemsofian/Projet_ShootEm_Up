#ifndef ENNEMI_H
#define ENNEMI_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Ennemi
{
public:
   
    Ennemi(RenderWindow& window, Vector2f position, vector<Texture> _walkTextures);
    void update(float deltaTime, RenderWindow& window);
    void draw(RenderWindow& window);
    void Events(Event& _event);
    void EnnemiMovement(float deltaTime, const Vector2f& playerPosition, RenderWindow& window);
    void loadResources();
    //void updateAnimation(float deltaTime);
    void spawnGoblin(const Vector2f& position, RenderWindow& window);
    void updateGoblin(float deltaTime,RenderWindow& window);
    const Vector2f& getPosition() const;
    FloatRect getGlobalBounds() const;
    bool hasGoblins() const { return hasGoblin; }

private:
    //RenderWindow& window;
    bool hasGoblin;
    float ennemiSpeed;
    Sprite ennemiSprite;
    Texture EnnemiTexture;
    vector<Texture> walkTextures;
    Vector2f ennemiPosition;
    int walkFrame;
    float walkFrameTime;
    float walkFrameTimer;
  
};

#endif // ENNEMI_H
