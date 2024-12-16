#include "Ennemi.h"
#include "Game.h"

Ennemi::Ennemi(RenderWindow& win) : window(win){
	loadResources();
}

void Ennemi::loadResources()
{
	if (!ennemiTexture.loadFromFile("Assets/Image/Ennemi/Gobelin/WalksFrames/Walk1.png"))
	{
		throw runtime_error("Erreur de chargement du sprite de l'ennemi");
	}


	
	
}
void Ennemi::Spawn()
{
	int NbEnnemi = 10;
	
	for (int i = 0; i < NbEnnemi; i++)
	{
		ennemiSprite[i].setTexture(ennemiTexture);
		ennemiSprite[i].setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
		ennemiSprite[i].setScale(6.f, 6.f);
		window.draw(ennemiSprite[i]);
	}
	
}
void Ennemi::Events(const Event& event)
{
	Spawn();
}

void Ennemi::update(float deltatime)
{

}

void Ennemi::draw(RenderWindow& window)
{
	Spawn();
}