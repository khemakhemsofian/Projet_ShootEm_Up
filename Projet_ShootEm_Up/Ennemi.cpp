#include "Ennemi.h"

Ennemi::Ennemi(RenderWindow& _window)
{
    loadResources();
    ennemiSpeed = 100.0f;
    ennemiPosition = Vector2f(_window.getSize().x + ennemiSprite.getGlobalBounds().width, _window.getSize().y / 2.f);
   
    
}
void Ennemi::loadResources()
{
    for (int i = 1; i <= 8; ++i) {
        if (!EnnemiTexture.loadFromFile("Assets/Image/Ennemi/Gobelin/WalksFrames/Walk" + to_string(i) + ".png")) {
            throw runtime_error("Erreur de chargement du sprite Walk" + to_string(i));
        }
        walkTextures.push_back(EnnemiTexture);

    }

    walkFrame = 0;
    walkFrameTime = 0.1f;
    walkFrameTimer = 0.0f;
    
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
    updateGoblins(deltaTime, window);
   
}
void Ennemi::spawnGoblin(const Vector2f& position, RenderWindow& window) {
    goblinSpawnTimer = 0.0f;
    goblinSpawnDelay = 2.0f;
    maxGoblins = 10;
    goblins.emplace_back(window);
}
const Vector2f& Ennemi::getPosition() const {
    return ennemiPosition;
}

FloatRect Ennemi::getGlobalBounds() const {
    return ennemiSprite.getGlobalBounds();
}
void Ennemi::updateGoblins(float deltaTime, RenderWindow& window) {
    goblinSpawnTimer += deltaTime;
    if (goblinSpawnTimer >= goblinSpawnDelay && goblins.size() < maxGoblins) {
        goblinSpawnTimer = 0.0f;
        float x = window.getSize().x + ennemiSprite.getGlobalBounds().width;
        float y = static_cast<float>(rand() % static_cast<int>(window.getSize().y - ennemiSprite.getGlobalBounds().height));
        spawnGoblin(Vector2f(x, y), window);
    }

    for (auto it = goblins.begin(); it != goblins.end();) {
        it->update(deltaTime, window);
        if (it->getPosition().x < -it->getGlobalBounds().width) {
            it = goblins.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Ennemi::drawGoblins(RenderWindow& window) {
    for (auto& goblin : goblins) {
        goblin.draw(window);
    }
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
    ennemiSprite.setScale(6.0f,6.0f);
}



void Ennemi::draw(RenderWindow& window)
{
    window.draw(ennemiSprite);
    //drawGoblins(window);

   
}
