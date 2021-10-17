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

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	void events();
	void input();
	void updatePhysics();
	void update();
	void render();

	bool isColliding(const BoundingBox& firstBoundingBox, const BoundingBox& secondBoundingBox);
	void restart();

private:

	uint16_t mWindowWidth;
	uint16_t mWindowHeight;
	std::string mWindowName;

	sf::RenderWindow mWindow;
	sf::Event mEvent;
	ElapsedTime mETime;

	Ball mBall;
	Player mPlayerLeft,mPlayerRight;

	bool mStartHorizontalDirectionBall;
	float mStartVerticalDirectionBall;


	BoundingBox mBBLeft, mBBRight, mBBTop, mBBBottom;

	PowerUp mPowerUp;

	const float kPlayerSpeed;



};

