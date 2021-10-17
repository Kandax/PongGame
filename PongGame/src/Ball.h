#pragma once
#include "SFML/Graphics.hpp"
#include "BoundingBox.h"


class Ball
{
public:
	Ball();
	Ball(float posX, float posY);
	void draw(sf::RenderWindow* window);
	
	void move(float x, float y);
	void setDirection(float horizontal,float vertical);
	void update();
	void resetAcceleration();

	void setPosition(float x, float y);
	void setSpeed(float speed);
	void setAcceleration(float acceleration);

	BoundingBox getBoundingBox();
	float getPositionX() const;
	float getPositionY() const;
	float getSpeed() const;
	float getVerticalDir() const;
	float getHorizontalDir() const;
	float getSize() const;
	sf::Vector2f getCenterPosition() const;
	float getAcceleration() const;

private:
	const float cAcceleration;

	float mPositionX;
	float mPositionY;
	float mSpeed;
	float mDirVertical;
	float mDirHorizontal;
	float mBoxSize;
	float mAcceleration;
	sf::Vector2f mCenterPosition;



	BoundingBox mBoundingBox;

	sf::RectangleShape mShape;



};

