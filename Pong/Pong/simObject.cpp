#include "StdAfx.h"
#include "simObject.h"

simObject::simObject(){}
simObject::~simObject(){}

void simObject::loadObjectImage(std::string filename) {
	icon.LoadFromFile(filename);
	sprite.SetImage(icon);
}

void simObject::Draw(sf::RenderWindow &window) {
	window.Draw(sprite);
}

void simObject::setPos(float x, float y) {
	sprite.SetPosition(x,y);
}

sf::Vector2f simObject::getPos() const {
	return sprite.GetPosition();
}

sf::Sprite& simObject::getSprite() {
	return sprite;
}

void simObject::update(float time){}

sf::Rect<float> simObject::getHitBox() const {
	sf::Vector2f size = sprite.GetSize();
	sf::Vector2f pos = sprite.GetPosition();
	return sf::Rect<float>( pos.x - size.x/2, pos.y - size.y/2, pos.x + size.x/2, pos.y + size.y/2);
}

float simObject::getHeight() const {
	return sprite.GetSize().y;
}

float simObject::getWidth() const {
	return sprite.GetSize().x;
}
 