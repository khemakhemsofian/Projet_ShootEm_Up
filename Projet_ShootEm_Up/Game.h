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
    void playMusic();
    void stopMusic();

private:
    void event(Event& _event);
    Clock clock;
    void update();
    void rendu();
    Texture playerTexture;
    Sprite playerSprite;
    Texture projectileTexture;
    Sprite projectileSprite;
    Texture backgroundTextures[4];
    Sprite backgroundSprites[8];
    float backgroundOffsets[4];

    void loadResources();
    void shootProjectile();
    void updateProjectiles(float deltaTime);


protected:
    vector<Sprite> projectiles;
    RenderWindow& window; 
    Music _gameMusic;
   vector<Texture> idleTextures; // Pour les textures Idle
    size_t idleFrame = 0;              // Frame actuelle de l'animation
    float idleFrameTime = 0.2f;        // Temps entre deux frames (en secondes)
    float idleFrameTimer = 0.0f;       // Timer pour gérer le changement de frame
};

#endif // !GAME_H
