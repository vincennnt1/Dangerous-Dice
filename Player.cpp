#include "Player.h"

Player::Player(sf::Texture* legsTexture, sf::Texture* headTexture)
{

	this->sizeX = 50.f;
	this->sizeY = 60.f;

	legsTexture->setSmooth(false);
	headTexture->setSmooth(false);
	this->legs.setTexture(*legsTexture);
	this->head.setTexture(*headTexture);

	// legs
	this->legs.setScale(sf::Vector2f(sizeX / legsTexture->getSize().x, sizeY / legsTexture->getSize().y));

	this->legs.setOrigin(sf::Vector2f(25, 30));

	this->legs.setPosition(sf::Vector2f(750, 800));

	// head

	this->head.setScale(sf::Vector2f(50.f / headTexture->getSize().x, 50.f / headTexture->getSize().y));

	this->head.setOrigin(sf::Vector2f(25, 25));

	this->head.setPosition(sf::Vector2f(this->legs.getPosition().x + 25.f, this->legs.getPosition().y + 23.f));

	this->walkSpeedX = 5.f;
	this->walkSpeedY = 5.f;

	this->walkDown = true;
	this->walkUp = true;
	this->walkLeft = true;
	this->walkRight = true;

	this->lastButtonPressed = 'X';
}

Player::~Player()
{

}



void Player::move(sf::Vector2f offset)
{
	this->legs.move(offset);
	this->head.move(offset.x, offset.y);
}

void Player::setPosition(sf::Vector2f pos)
{
	this->legs.setPosition(pos);
	this->head.setPosition(pos.x + 25.f, pos.y + 23.f);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->legs);
	target.draw(this->head);

}

void Player::updateDir(char button)
{

	if (this->lastButtonPressed == 'X')
	{
		if (button == 'A') {
			this->legs.scale(sf::Vector2f(-1, 1));
		}
	}
	
	if (this->lastButtonPressed != button && this->lastButtonPressed != 'X')
	{
		this->legs.scale(sf::Vector2f(-1, 1));
	}
	this->lastButtonPressed = button;
}

void Player::changeLegs(sf::Texture* text)
{
	this->legs.setTexture(*text);
}

void Player::changeHead(sf::Texture* text)
{
	this->head.setTexture(*text);
}


// accessors

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->legs.getGlobalBounds();
}

const sf::Vector2f Player::getPosition() const
{
	return this->legs.getPosition();
}
