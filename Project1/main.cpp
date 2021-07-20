#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std; 

int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Reflex training");

	sf::Color bgColor(204,255,255);
	sf::Color textColor(51,255,153);

	sf::Cursor cursor;
	if (!cursor.loadFromSystem(sf::Cursor::Cross))
		return EXIT_FAILURE;

	sf::Mouse mouse;

	sf::Font font;
	if (!font.loadFromFile("BebasNeue-Regular.ttf"))
		return EXIT_FAILURE;
	sf::Text title("Reflex training", font, 50);

	sf::RectangleShape titleRec(sf::Vector2f(400.0f, 75.0f));
	sf::RectangleShape objective(sf::Vector2f(40.0f, 40.0f));
	sf::RectangleShape miniPointer(sf::Vector2f(2.0f, 2.0f));
	
	titleRec.setPosition(sf::Vector2f(300.0f, 25.0f));
	title.setPosition(sf::Vector2f(370.0f, 30.0f));
	objective.setPosition(sf::Vector2f(500.0f, 400.0f));

	titleRec.setFillColor(sf::Color::White);
	title.setFillColor(textColor);
	objective.setFillColor(sf::Color(255, 0, 0));

	window.setMouseCursor(cursor);

	window.clear(bgColor);

	sf::Clock clock;
	int moveIterator = 0;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		sf::Vector2i mousePos = mouse.getPosition(window);
		sf::Vector2f mousePosFloat = sf::Vector2f(mousePos.x, mousePos.y);
		miniPointer.setPosition(mousePosFloat);

		sf::Time elapsed = clock.getElapsedTime();
		int timeApproximated = elapsed.asSeconds();

		if (timeApproximated % 3 == 0)
			moveIterator = 0;

		if (timeApproximated % 2 == 0 && moveIterator == 0) {
			float rrx = rand() % 970 + 30;
			float rry = rand() % 780 + 20;
			sf::Vector2f newPos = sf::Vector2f(rrx, rry);
			objective.setPosition(newPos);
			moveIterator++;
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Right) {

			}
		}

		window.clear(bgColor);

		window.draw(titleRec);
		window.draw(title);
		window.draw(objective);

		window.display();
	}

	return 0;
}