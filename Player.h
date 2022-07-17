#pragma once

#include <SFML/Graphics.hpp>

#include "Wall.h"

#include <iostream>

class Player
{
	sf::Sprite legs;
	sf::Sprite head;

	float walkSpeedX;
	float walkSpeedY;

	bool walkLeft;
	bool walkRight;
	bool walkDown;
	bool walkUp;

	float sizeX;
	float sizeY;


	char lastButtonPressed;


public:

	Player(sf::Texture* legsTexture, sf::Texture* headTexture);
	virtual ~Player();

	// FUNCTIONS

	void move(sf::Vector2f offset);
	void setPosition(sf::Vector2f pos);
	void render(sf::RenderTarget& target);

	void updateDir(char button);
	void changeLegs(sf::Texture* text);
	void changeHead(sf::Texture* text);

	// accessors
	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f getPosition() const;
};

