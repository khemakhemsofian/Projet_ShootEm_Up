#include "Ennemi.h"

Ennemi::Ennemi(RenderWindow& window) : window(window)
{
    loadResources();
  
}

void Ennemi::loadResources()
{
    if (!ennemiTexture.loadFromFile("Assets/Image/Ennemi/Gobelin/WalksFrames/Walk1.png"))
    {
        throw runtime_error("Erreur de chargement du sprite de l'ennemi");
    }

    ennemiSprite.setTexture(ennemiTexture);
    ennemiSprite.setScale(6.f, 6.f);
}

void Ennemi::EnnemiMovement(float deltaTime)
{
    speed = 200.f;
    x = 800.f;
  
    x -= speed * deltaTime;

    if (x < -ennemiSprite.getGlobalBounds().width)
    {
        ennemiSprite.setPosition(x, ennemiSprite.getPosition().y);
        window.draw(ennemiSprite);
       
    }
}
void Ennemi::Spawn()
{
    int NbEnnemi = 10;

    for (int i = 0; i < NbEnnemi; i++)
    {
        ennemiSprite.setTexture(ennemiTexture);
        ennemiSprite.setPosition(window.getSize().x + ennemiSprite.getGlobalBounds().width, window.getSize().y / 2.f);
        ennemiSprite.setScale(6.f, 6.f);
    }
}

void Ennemi::Events(Event& _event)
{
    Spawn();
}
void Ennemi::update(float deltaTime)
{
    this->deltaTime = deltaTime;
    EnnemiMovement(deltaTime);
}

void Ennemi::draw(RenderWindow& window)
{
    ennemiSprite.setPosition(x, ennemiSprite.getPosition().y);
    window.draw(ennemiSprite);
}
