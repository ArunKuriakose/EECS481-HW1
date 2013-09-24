#pragma once
#include "simObject.h"

class Model {
public:
	Model();
	~Model();
	simObject* getObj(std::string name) const;
	void add(std::string name, simObject* simObject);
	void remove(std::string name);
	void drawAll(sf::RenderWindow &window);
	void updateAll();

private:
	std::map<std::string, simObject*> pongObjects;

	struct realDestructor {
		void operator()(const std::pair<std::string,simObject*> & pair) const
		{
		  delete pair.second;
		}
	};
};