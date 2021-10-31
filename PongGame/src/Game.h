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
#include "GamemodeTwoPlayers.h"
#include "GamemodePlayerBot.h"

class Game
{
private:
	struct Button
	{
		Button(float posX, float posY, uint16_t boxWidth, uint16_t boxHeight, std::string text);

		float posX;
		float posY;
		uint16_t boxWidth;
		uint16_t boxHeight;
		BoundingBox boundingBox;
		sf::RectangleShape shape;
		std::string text;

	};




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

	bool isColliding(const BoundingBox& boundingBox, float pointX,float pointY);

private:
	uint16_t mWindowWidth;
	uint16_t mWindowHeight;
	std::string mWindowName;

	sf::RenderWindow mWindow;
	sf::Event mEvent;
	ElapsedTime mETime;
	
	int mMenuChoice;
	Button mButton1;
	Button mButton2;

	sf::Font mFont;
	sf::Text mText;

	GamemodeTwoPlayers mGM2P;
	GamemodePlayerBot mGMPB;
};

