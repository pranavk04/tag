#include "headers/game.h"

using namespace sf;

int r1X = 40, r1Y = 300, r2X = 540, r2Y = 300, multiplier = 1, p1Score = 0, p2Score = 0, tagtime = 100;
bool p1Tagger = true;
CircleShape r1(20, 1000);
CircleShape r2(20, 1000);
Text p1S;
Text p2S;
Font font;
bool vsync = true;
Game::Game() : window(VideoMode(600, 600), "Tag!") {
	window.setVerticalSyncEnabled(true);
}
void Game::textSet() {
	
	if (!font.loadFromFile("resources/micross.ttf")) {
		std::cout << "File not loeaded" << std::endl;
		system("pause");
	}	
	p1S.setFont(font);
	p2S.setFont(font);
	p1S.setCharacterSize(50);
	p2S.setCharacterSize(50);
	std::stringstream ss1;
	ss1 << p1Score;
	p1S.setString(ss1.str());
	std::stringstream ss2;
	ss2 << p2Score;
	p2S.setString(ss2.str());
	p1S.setPosition(Vector2f(0, 0));
	p2S.setPosition(Vector2f(400, 0));
	p1S.setFillColor(Color::Black);
	p2S.setFillColor(Color::Blue);
	Text win1, win2;
	win1.setFillColor(Color::Red);
	win1.setCharacterSize(100);
	win1.setString("PLAYER 1 WINS!!!");
	win1.setPosition(400, 400);
	win2.setFillColor(Color::Red);
	win2.setCharacterSize(100);
	win2.setString("PLAYER 2 WINS!!!");
}
void Game::run() {
	while (window.isOpen()) {
		r1.setPosition(r1X, r1Y);
		r2.setPosition(r2X, r2Y);
		eventProcessor();
		logic();
		render();
	}
}
void Game::logic() {
	r1.setFillColor(Color::Black);
	if (p1Tagger == true) {
		p2Score++;
		r1.setFillColor(Color::Red);
		r2.setFillColor(Color::Blue);
	}
	else {
		p1Score++;
		r1.setFillColor(Color::Black);
		r2.setFillColor(Color::Red);
	}
	// tagtime exists so that the collision detection won't happen over and over again defeating its purpose
	tagtime++;
	if (abs(r1X-r2X) < 40 & abs(r2Y - r1Y) < 40 & tagtime >= 45) {
		// resets the delay
		tagtime = 0;
		if (p1Tagger == true) {
			p1Tagger = false;
		}
		else {
			p1Tagger = true;
		}
	}
}
void Game::eventProcessor() {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			r1Y -= 10;
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			r1X -= 10;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			r1Y += 10;
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			r1X += 10;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			r2Y -= 10;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			r2Y += 10;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			r2X -= 10;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			r2X += 10;
		}
	}
	
}
void Game::constrain() {
	if (r1X > 560) {
		r1X = 560;
	}
	if (r2X > 560) {
		r2X = 560;
	}
	if (r1Y > 560) {
		r1Y = 560;
	}
	if (r2Y > 560) {
		r2Y = 560;
	}
	if (r1X < 0) {
		r1X = 0;
	}
	if (r2X < 0) {
		r2X = 0;
	}
	if (r2Y < 0) {
		r2Y = 0;
	}
	if (r1Y < 0) {
		r1Y = 0;
	}
}
void Game::render() {
	textSet();
	constrain();
	window.clear(Color(230, 230, 230));
	window.draw(r1);
	window.draw(r2);
	window.draw(p1S);	
	window.draw(p2S);
	window.display();
}