#pragma once
#include <string>
#include <iostream>
#include <vector>


#include "SFML/Graphics.hpp"

#include "ElapsedTime.h"



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

private:

	uint16_t mWindowWidth;
	uint16_t mWindowHeight;
	std::string mWindowName;

	sf::RenderWindow mWindow;
	sf::Event mEvent;
	ElapsedTime mETime;







};

