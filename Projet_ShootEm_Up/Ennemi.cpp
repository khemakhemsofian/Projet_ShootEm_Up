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
  

  
}


void Ennemi::Events(Event& _event)
{
    
}
void Ennemi::update(float deltaTime)
{
  
}

void Ennemi::draw(RenderWindow& window)
{
    
   
}
