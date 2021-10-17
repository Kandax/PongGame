#pragma once
#include <array>
#include <string>
#include <iostream>
#include <cstdlib>
#include <assert.h>



#include "SFML/Graphics.hpp"
#include "BoundingBox.h"
#include "Ball.h"
#include "Player.h"



class PowerUp
{
public:
	enum  powerUps {
		none = 0,
		speedUpBall = 1,
		sizeOfPowerUps,
	};


public:
	PowerUp();
	void draw(sf::RenderWindow* window);
	void update();
	void powerUpSpeedUpBall(Ball& ball);
	void randomPosition(uint16_t minX, uint16_t maxX, uint16_t minY = 0, uint16_t maxY = 600);
	
	void setPosition(float x, float y);
	
	BoundingBox getBoundingBox();
	float getPositionX() const;
	float getPositionY() const;
	
	bool setTexture(std::string textureName, powerUps powerUp);
	void setTexturesDirectory(const std::string& directory);
	void setActualPowerUp(powerUps powerUp);
	int getActualPowerUp() const;
	int getBoxSize() const;




private:
	float mPositionX;
	float mPositionY;
	uint16_t mBoxSize;
	powerUps mActualPowerUp;


	BoundingBox mBoundingBox;


	sf::Sprite mShape;
	std::array<sf::Texture, 2> mTextures;
	sf::Texture mTempTexture;
	sf::Texture temp;
	std::string mTexturesDirectory;




};

