#include "Dice.h"

Dice::Dice(sf::Texture* text, int type, sf::Vector2f pos)
{
	this->sizeX = 25.f;
	this->sizeY = 25.f;

	this->diceType = type;

	text->setSmooth(false);
	this->dice.setTexture(*text);

	this->dice.setScale(sf::Vector2f(sizeX / text->getSize().x, sizeY / text->getSize().y));

	this->dice.setOrigin(12.5f, 12.5f);

	this->pos = pos;
	this->dice.setPosition(pos);
}

Dice::~Dice()
{
}

const sf::FloatRect Dice::getGlobalBounds() const
{
	return this->dice.getGlobalBounds();
}

const sf::Vector2f Dice::getPosition() const
{
	return this->dice.getPosition();
}

void Dice::render(sf::RenderTarget& target)
{
	target.draw(this->dice);
}

void Dice::setPosition(sf::Vector2f pos)
{
	this->dice.setPosition(pos);
}
