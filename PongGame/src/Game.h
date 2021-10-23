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

class Game
{
public:
	Game();
	~Game();
	void run();
protected:
	void events();
	void input();
	void updatePhysics();
	void update();
	void render();

private:
	uint16_t mWindowWidth;
	uint16_t mWindowHeight;
	std::string mWindowName;

	sf::RenderWindow mWindow;
	sf::Event mEvent;
	ElapsedTime mETime;
	

	GamemodeTwoPlayers mGM2P;

};

