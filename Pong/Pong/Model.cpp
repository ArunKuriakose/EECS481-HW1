#include "stdafx.h"
#include "Model.h"
#include "Controller.h"

Model::Model(){}
Model::~Model(){
	 std::for_each(pongObjects.begin(),pongObjects.end(),realDestructor());
}

simObject* Model::getObj(std::string name) const{
	std::map<std::string, simObject*>::const_iterator it = pongObjects.find(name);
	return (it == pongObjects.end()) ? nullptr : it->second;
}

void Model::add(std::string name, simObject* simObj) {
	pongObjects[name] = simObj;
}

void Model::remove(std::string name) {
	std::map<std::string, simObject*>::iterator it = pongObjects.find(name);
	if(it != pongObjects.end()) {
		delete it->second;
		pongObjects.erase(it);
	}
}

void Model::drawAll(sf::RenderWindow &window) {
	for(std::map<std::string, simObject*>::iterator it = pongObjects.begin(); it != pongObjects.end(); ++it) {
		it->second->Draw(window);
	}
}

void Model::updateAll() {
	float time = Controller::getWindow().GetFrameTime();
	for(std::map<std::string, simObject*>::iterator it = pongObjects.begin(); it != pongObjects.end(); ++it) {
		it->second->update(time);
	}
}