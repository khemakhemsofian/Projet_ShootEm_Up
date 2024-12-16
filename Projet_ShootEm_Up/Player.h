// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
using namespace sf;
using namespace std;
class Player {
public:
    Player(RenderWindow& window);
    void Events(const Event& event);
    void update(float deltaTime);
    void draw(RenderWindow& window);
    void shootProjectile();
    bool isMoving() const;

private:
    Texture playerTexture;
    Sprite playerSprite;
    vector<Sprite> projectiles;
    RenderWindow& window;
    Texture projectileTexture;

    std::vector<sf::Texture> walkTextures;  
    int walkFrame;                          
    float walkFrameTime;                    
    float walkFrameTimer;

    vector<Texture> idleTextures;
    size_t idleFrame;
    float idleFrameTime;
    float idleFrameTimer;


    void loadResources();
    void updateProjectiles(float deltaTime);
};

#endif // PLAYER_H
