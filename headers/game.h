#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

class Game {
	public:
		Game();
		void run();
	private:
		void eventProcessor();
		void render();
		void textSet();
		void logic();
		void constrain();
		sf::RenderWindow window;
		
};
#endif // _GAME_H