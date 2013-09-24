#pragma once
#include "StdAfx.h"
#include "PongPaddle.h"
#include "Controller.h"
#include "simObject.h"

class PongPaddle : public simObject {
public :
	PongPaddle();
	~PongPaddle();
	void update(float time);
	void Draw(sf::RenderWindow &window);
	float getSpeed() const;

private:
	float speed;
	float maxSpeed;
};