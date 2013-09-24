#include "StdAfx.h"
#include "Pongball.h"
#include "Controller.h"

Pongball::Pongball() : speed(230.0f), timeGone(0.0f)
{
  loadObjectImage("images/Ball.png");
  getSprite().SetCenter(15,15);
  sf::Randomizer::SetSeed(std::clock());
  angle = (float)sf::Randomizer::Random(0,360);
}

Pongball::~Pongball(){}

void Pongball::update(float time){
	timeGone += time;
	if(timeGone < 3.0f)
		return;
	float distanceMoved = speed*timeGone;
	float distanceX = LinearVelocityX(angle)*distanceMoved;
	float distanceY = LinearVelocityY(angle)*distanceMoved;
	if(getPos().x + distanceX <= 0 + getWidth()/2 || getPos().x + getHeight()/2 + distanceX >= Controller::SCREEN_WIDTH) {
		angle = 360.0f-angle;
		if(angle > 260.0f && angle < 280.0f) 
			angle += 20.0f;
		if(angle > 80.0f && angle < 100.0f) 
			angle += 20.0f;
		distanceX = -distanceX;
	}
  
	PongPaddle* player1 = dynamic_cast<PongPaddle*>(Controller::getModel().getObj("player1"));
	if(player1 != NULL) { 
		sf::Rect<float> p1hitBox = player1->getHitBox();
  
		if(p1hitBox.Intersects(getHitBox())) { 
			angle = 360.0f-(angle - 180.0f);
			if(angle > 360.0f) 
				 angle -= 360.0f;
			distanceY = -distanceY;

			if(getHitBox().Bottom > player1->getHitBox().Top) {
				setPos(getPos().x,player1->getHitBox().Top - getWidth()/2 -1);
			} 
			float playerSpeed = player1->getSpeed();
			if(playerSpeed < 0) {
				angle -= 20.0f;	
				if(angle < 0) 
					angle = 360.0f - angle;
			}
			else if(playerSpeed > 0) {
				angle += 20.0f;
				if(angle > 360.0f) 
					angle = angle - 360.0f;
			}
			speed += 5.0f;
		}
		if(getPos().y - getHeight()/2 <= 0) {
			angle =  180.0 - angle;
			distanceY = -distanceY;
		}
		if(getPos().y + getHeight()/2 + distanceY >= Controller::SCREEN_HEIGHT) {
			getSprite().SetPosition(Controller::SCREEN_WIDTH/2, Controller::SCREEN_HEIGHT/2);
			angle = (float)sf::Randomizer::Random(0,360); 
			speed = 220.0f;
			timeGone = 0.0f;
		}
		std::cout << distanceX << " " << distanceY << std::endl;
		getSprite().Move(distanceX,distanceY);
	}
}

float Pongball::LinearVelocityX(float angle) {
	angle -= 90;
    if (angle < 0) 
		angle = 360 + angle;
    return (float)std::cos( angle * ( 3.1415926 / 180.0f ));
}

float Pongball::LinearVelocityY(float angle) {
	angle -= 90;
    if (angle < 0) 
		angle = 360 + angle;
    return (float)std::sin( angle * ( 3.1415926 / 180.0f ));
}
