#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std; 

int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Reflex training");

	sf::Color bgColor(204,255,255);

	sf::Cursor cursor;
	if (!cursor.loadFromSystem(sf::Cursor::Cross))
		return EXIT_FAILURE;

	sf::RectangleShape titleRec(sf::Vector2f(200.0f, 50.0f));
	
	titleRec.setPosition(sf::Vector2f(400.0f, 100.0f));

	titleRec.setFillColor(sf::Color::White);

	window.setMouseCursor(cursor);

	window.clear(bgColor);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(bgColor);

		window.display();
	}

	return 0;
}