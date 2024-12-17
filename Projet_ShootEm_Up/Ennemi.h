#ifndef ENNEMI_H
#define ENNEMI_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Ennemi
{
public:
   
    Ennemi(RenderWindow& window);
    void update(float deltaTime, RenderWindow& window);
    void draw(RenderWindow& window);
    void Events(Event& _event);
    void EnnemiMovement(float deltaTime, const Vector2f& playerPosition, RenderWindow& window);
    void loadResources();
    //void updateAnimation(float deltaTime);
    void spawnGoblin(const Vector2f& position, RenderWindow& window);
    void updateGoblins(float deltaTime, RenderWindow& window);
    void drawGoblins(RenderWindow& window);
    const Vector2f& getPosition() const;
    FloatRect getGlobalBounds() const;

private:
    //RenderWindow& window;
    float ennemiSpeed;
    Sprite ennemiSprite;
    Texture EnnemiTexture;
    vector<Texture> walkTextures;
    Vector2f ennemiPosition;
    int walkFrame;
    float walkFrameTime;
    float walkFrameTimer;
    vector<Ennemi> goblins;
    float goblinSpawnTimer;
    float goblinSpawnDelay;
    int maxGoblins;
};

#endif // ENNEMI_H
