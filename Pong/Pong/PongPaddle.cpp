 #include "stdafx.h"
 #include "PongPaddle.h"
  
PongPaddle::PongPaddle() : speed(0), maxSpeed(600.0f){
	loadObjectImage("images/paddle1.png");
	getSprite().SetCenter(getSprite().GetSize().x /2, getSprite().GetSize().y / 2);
}

PongPaddle::~PongPaddle(){}

void PongPaddle::update(float time) {
	sf::Vector2f position = this->getPos();
	if(Controller::getInput().IsKeyDown(sf::Key::Left))
        speed -= 3.0f;
    if(Controller::getInput().IsKeyDown(sf::Key::Right))
        speed += 3.0f;
    if(Controller::getInput().IsKeyDown(sf::Key::Down)) 
        speed = 0.0f;
	if(speed > maxSpeed) 
		speed = maxSpeed;
	if(speed < -maxSpeed) 
		speed = -maxSpeed;


	if(position.x <= getWidth()/2 || 
		position.x >= (Controller::SCREEN_WIDTH - getWidth()/2)) {
			speed = -speed; 
	}
	getSprite().Move(speed * time, 0);

}

void PongPaddle::Draw(sf::RenderWindow &window) {
	simObject::Draw(window);
}

float PongPaddle::getSpeed() const {
	return speed;
}