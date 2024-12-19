#include "Menu.h"

Menu::Menu(float _width, float _height)
{
	if (!_MenuFront.loadFromFile("Assets/Font/MedievalMystery.ttf"))
	{
		cerr << "Erreur de chargement de la police" << endl;
	}
	if (!_MenuMusic.openFromFile("Assets/Audio/Music/Menu/The knight journey main menu.mp3")) {
		cerr << "Erreur de chargement de la musique" << endl;
	}
	_MenuMusic.setLoop(true);
	_MenuMusic.setVolume(100.0f);
	_MenuMusic.play();

	if (!clickSoundBuffer.loadFromFile("Assets/Audio/Music/Menu/clicksound.wav")) {
		throw std::runtime_error("Erreur de chargement du son de tir");
	}
	clickSound.setBuffer(clickSoundBuffer);
	clickSound.setVolume(100.0f);
	
	vector<string> _MenuContainer = {"Faire festin de jeu" , "Les besognes de choix","Forger son recit", "Abandonner la joute"};
	_selectedIndex = 0;

	for (size_t i = 0; i < _MenuContainer.size(); i++)
	{
		Text _TextMenu;
		_backgroundMenu0.setSize(Vector2f(200.f, 100.f));
		_backgroundMenu1.setSize(Vector2f(200.f, 100.f));
		_backgroundMenu2.setSize(Vector2f(200.f, 100.f));
		_backgroundMenu0.setFillColor(Color(139, 69, 19,230));
		_backgroundMenu1.setFillColor(Color(139, 69, 19,230));
		_backgroundMenu2.setFillColor(Color(139, 69, 19,230));
		_backgroundMenu0.setPosition(Vector2f(0.0f,0.0f));
		_backgroundMenu1.setPosition(Vector2f(100.0f,100.0f));
		_backgroundMenu2.setPosition(Vector2f(200.0f,200.0f));
		
		
		_TextMenu.setFont(_MenuFront);
		_TextMenu.setString(_MenuContainer[i]);
		_TextMenu.setCharacterSize(24);
		_TextMenu.setPosition(_width/2 - _TextMenu.getGlobalBounds().width/ 2 , _height / (_MenuContainer.size() + 1)* (i + 1 ));
		_selectTextMenu.push_back(_TextMenu);
	}
}

void Menu::draw(RenderWindow& _window)
{
	
	for (const auto& _drawMenu : _selectTextMenu)
	{
		_window.draw(_drawMenu);
		_window.draw(_backgroundMenu0);
		_window.draw(_backgroundMenu1);
		_window.draw(_backgroundMenu2);

	}
}

void Menu::ClickSound()
{
	clickSound.play();
}

void Menu::moveUp()
{
	if (_selectedIndex - 1 >= 0 )
	{
		_selectedIndex--;
	}
}void Menu::moveDown()
{
	if (_selectedIndex + 1 < _selectTextMenu.size())
	{
		_selectedIndex++;
	}
}

int Menu::getSelectedIndex()
{
	return _selectedIndex;
}

void Menu::selectOption(Vector2f mousePosition)
{
	for (size_t i = 0; i < _selectTextMenu.size(); i++)
	{
		if(_selectTextMenu[i].getGlobalBounds().contains(mousePosition))
		{
			_selectedIndex = i;
			
			break;
		}
	}
}

void Menu::playMusic() {
	_MenuMusic.play(); 
}
void Menu::stopMusic() {
	_MenuMusic.stop(); 
}

void Menu::UpdateEffetSurvol(Vector2f mousePosition)
{
	for (size_t i = 0; i < _selectTextMenu.size(); i++)
	{
		if(_selectTextMenu[i].getGlobalBounds().contains(mousePosition))
		{
			_selectTextMenu[i].setFillColor(Color(255, 51, 10, 230));
			_selectTextMenu[i].setScale(1.2f,1.2f);
		}
		else
		{
			_selectTextMenu[i].setFillColor(Color(0, 0, 0, 230));
			_selectTextMenu[i].setScale(1.0f, 1.0f);
		}
	}
}