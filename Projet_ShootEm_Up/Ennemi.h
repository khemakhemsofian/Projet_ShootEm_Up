#ifndef ENNEMI_H
#define ENNEMI_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Ennemi
{
public:
	Ennemi(RenderWindow& window);
	void Events(const Event& event);
	void update(float deltatime);
	void draw(RenderWindow& window);
	void Spawn();
private:
	RenderWindow& window;
	void loadResources();
	Texture ennemiTexture;
	Sprite ennemiSprite[10];
};


#endif // !ENNEMI_H

