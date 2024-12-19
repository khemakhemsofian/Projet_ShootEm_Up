#include "Ennemi.h"


Ennemi::Ennemi(RenderWindow& _window, Vector2f position, vector<Texture> _walkTextures)
{
    ennemiPosition = position;
    ennemiSprite.setPosition(ennemiPosition);
    ennemiSpeed = 600.0f;
    hasGoblin = false;

    walkFrame = 0;
    walkFrameTime = 0.1f;
    walkFrameTimer = 0.0f;
    
    walkTextures = _walkTextures;
}

void Ennemi::Events(Event& _event)
{
    
}

void Ennemi::update(float deltaTime, RenderWindow& window)
{
    walkFrameTimer += deltaTime;

    if (walkFrameTimer >= walkFrameTime)
    {
        walkFrameTimer -= walkFrameTime;
        walkFrame = (walkFrame + 1) % (walkTextures.size() - 1);
        ennemiSprite.setTexture(walkTextures[walkFrame]);
    }

    EnnemiMovement(deltaTime, Vector2f(0.f, 0.f), window);
    updateGoblin(deltaTime, window);

}


void Ennemi::spawnGoblin(const Vector2f& position, RenderWindow& window) {
    hasGoblin = true; 
    ennemiPosition = position;
    ennemiSprite.setPosition(ennemiPosition);
 
}

void Ennemi::updateGoblin(float deltaTime, RenderWindow& window)
{
    if (hasGoblin) { 
        ennemiPosition.x -= ennemiSpeed * deltaTime;
        if (ennemiPosition.x < -ennemiSprite.getGlobalBounds().width) {
            hasGoblin = false; 
        }
        ennemiSprite.setPosition(ennemiPosition);
    }
}
const Vector2f& Ennemi::getPosition() const {
    return ennemiPosition;
}

FloatRect Ennemi::getGlobalBounds() const {
    return ennemiSprite.getGlobalBounds();
}
void Ennemi::EnnemiMovement(float deltaTime, const Vector2f& playerPosition, RenderWindow& window)
{
 
    ennemiPosition.x -= ennemiSpeed * deltaTime;
    if (ennemiPosition.x < -ennemiSprite.getGlobalBounds().width)
    {
        
        ennemiPosition.x = window.getSize().x + ennemiSprite.getGlobalBounds().width;
        ennemiPosition.y = rand() % static_cast<int>(window.getSize().y - ennemiSprite.getGlobalBounds().height);
    }

    ennemiSprite.setPosition(ennemiPosition);
    ennemiSprite.setScale(6.f,6.f);
}

void Ennemi::loadResources()
{
}


void Ennemi::draw(RenderWindow& window)
{
        window.draw(ennemiSprite);
}
