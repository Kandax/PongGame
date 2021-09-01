#pragma once
#include "SFML/Graphics.hpp"
#include "BoundingBox.h"


class Player
{
public:
	Player();
	Player(float posX, float posY, float width = 32, float height =96);
	void draw(sf::RenderWindow* window);
	void move(float x, float y);
	void update();

	void setPosition(float x, float y);
	void setSpeed(float speed);



	BoundingBox getBoundingBox();
	float getPositionX();
	float getPositionY();
	float getSpeed();
	sf::RectangleShape* getShape();
	float getWitdh();
	float getHeight();
	sf::Vector2f getCenterPosition();

private:
	float mPositionX;
	float mPositionY;
	float mSpeed;
	float mWitdh;
	float mHeight;
	BoundingBox mBoundingBox;
	sf::RectangleShape mShape;
	sf::Vector2f mCenterPosition;
};

