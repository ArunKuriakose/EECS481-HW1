#include "stdafx.h"
#include "Controller.h"
#include "Pongball.h"

sf::RenderWindow Controller::window;
Model Controller::model;

void Controller::beginPong() {
	window.Create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32),"Wall Pong");
	PongPaddle* p1 = new PongPaddle();
	p1->setPos((SCREEN_WIDTH/2),700);
	model.add("player1", p1);
	Pongball *ball = new Pongball();
	ball->setPos((SCREEN_WIDTH/2),(SCREEN_HEIGHT/2)-15);
	model.add("Ball",ball);
	while(true) {
		play();
	}
	window.Close();
}

void Controller::play() {
	sf::Event currentEvent;
	window.GetEvent(currentEvent);
	window.Clear(sf::Color(sf::Color(0,0,0)));
	model.updateAll();
	model.drawAll(window);
	window.Display();
}

const sf::RenderWindow& Controller::getWindow(){
	return window;
}

const sf::Input& Controller::getInput() {
	return window.GetInput();
}

const Model& Controller::getModel() {
	return Controller::model;
}
