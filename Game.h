#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Wall.h"
#include "Number.h"
#include "Dice.h"
#include "TitleScreen.h"

#include <map>
#include <vector>
#include <iostream>
#include <sstream>

// random num generator
#include <stdlib.h>
#include <time.h>

class Game
{
private:
	sf::RenderWindow* window;

	sf::View* camera;

	TitleScreen* title;

	Player* player;

	sf::RectangleShape* numPlatform;

	float movementSpeed;
	// collision stuff
	sf::Vector2f velocity;
	sf::FloatRect nextPos;
	sf::FloatRect playerBounds;

	// TIMER
	sf::Clock* clock;

	// text
	sf::Font* font;

	sf::Text* timer;

	sf::Text* pointsText;

	// audio
	sf::SoundBuffer* soundCollect;
	sf::Sound* Collect;
	
	sf::SoundBuffer* soundPlatform;
	sf::Sound* Platform;

	// PRIVATE FUNCTIONS
	void initWindow();
	void initTextures();
	void initFont();
	void initAudio();

	void initPlayer();
	void initWalls();

	void initNumPlatform();

	void initCamera();
	
	void initTimer();
	void initPoints();

	void startTitle();

	// DICE AND NUMBER STUFF
	void initNumbers();
	void initDice();
	int heldNumber; // NUMBER PLAYER IS HOLDING
	int neededNumber;
	Dice* neededNum;

	sf::Vector2f possibleCoords[24];


	float diceDistance;

	std::vector <Number*> numbers;
	std::vector <Dice*> dice;

	std::vector <sf::Texture*> diceHeads;

	// resources
	std::map<std::string, sf::Texture*> textures;

	// points
	int points;
	int numbersFound;
	bool neededNumberFound;

	std::vector<Wall*> walls;
	sf::FloatRect wallBounds;

	// animation
	sf::Clock* animationTimer;
	sf::Time maxTime;

	sf::Texture* lastTexture;


public:

	// CONSTRUCTOR & DECONSTRUCTOR
	Game();
	virtual ~Game();

	// FUNCTIONS
	void update();
	void render();

	void randomDice();

	void updatePollEvents();
	void updateInput();
	void updateCollision();
	void updateVariables();
	void updateMovement();
	void updateDice();
	void updateCamera();
	void updateTimer();
	void updatePoints(); // VISUALLY

	void run();

};

