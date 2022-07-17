#pragma once

#include <SFML/Graphics.hpp>

class Dice
{
private:
	sf::Sprite dice;

	float sizeX;
	float sizeY;

	sf::Vector2f pos;

public:
	int diceType;

	Dice(sf::Texture* text, int type, sf::Vector2f pos);
	virtual ~Dice();

	// accessors 
	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f getPosition() const;

	// functions
	void render(sf::RenderTarget& target);

	void setPosition(sf::Vector2f pos);

};

