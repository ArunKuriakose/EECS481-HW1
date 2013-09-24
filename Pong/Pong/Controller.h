#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "PongPaddle.h"
#include "Model.h"

class Controller {
public:
	static void beginPong();
	const static sf::Input& getInput();
	const static sf::RenderWindow& getWindow();
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;
	const static Model& getModel();

private:
	static void play();
	static sf::RenderWindow window;
	static Model model;
};