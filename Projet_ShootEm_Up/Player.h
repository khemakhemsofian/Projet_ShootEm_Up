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

private:
    Texture playerTexture;
    Sprite playerSprite;
    vector<Sprite> projectiles;
    RenderWindow& window;
    Texture projectileTexture;

    vector<Texture> idleTextures;
    size_t idleFrame;
    float idleFrameTime;
    float idleFrameTimer;


    void loadResources();
    void updateProjectiles(float deltaTime);
};

#endif // PLAYER_H
