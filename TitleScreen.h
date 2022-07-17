#pragma once

#include <SFML/Graphics.hpp>

class TitleScreen
{
private:
	sf::Sprite* bkg;
	
	sf::Font* font;

	sf::Text* text;

	sf::Text* title;

	sf::RenderWindow* window;

	sf::Clock* tempTime;

public:
	TitleScreen(sf::Texture* text, sf::RenderWindow& window, sf::View* cam);
	virtual ~TitleScreen();


	void run();

};

