#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <stdlib.h>
#include <math.h>


#include "SFML/Graphics.hpp"

#include "ElapsedTime.h"

#include "BoundingBox.h"
#include "Ball.h"
#include "Player.h"
#include "PowerUp.h"


class GamemodePlayerBot
{
public:
	GamemodePlayerBot();
	GamemodePlayerBot(sf::RenderWindow* window, unsigned int windowWidth, unsigned int windowHeight);
	void Init();
	void input();
	void updatePhysics(float dt);
	void update(float dt);
	void render();
private:

	bool isColliding(const BoundingBox& firstBoundingBox, const BoundingBox& secondBoundingBox);
	void restart();

private:
	uint16_t mWindowWidth;
	uint16_t mWindowHeight;

	sf::RenderWindow* mWindow;

	Ball mBall;
	Player mPlayerLeft, mPlayerRight;

	bool mStartHorizontalDirectionBall;
	float mStartVerticalDirectionBall;


	BoundingBox mBBLeft, mBBRight, mBBTop, mBBBottom;


	sf::Font mFont;
	sf::Text mScoreTextBlue;
	sf::Text mScoreTextRed;

	int16_t mPointsBlue;
	int16_t mPointsRed;

	int8_t mBotDir;
	int8_t mBotDir2;




};

