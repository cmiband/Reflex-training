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

	sf::Font font;
	if (!font.loadFromFile("BebasNeue-Regular.ttf"))
		return EXIT_FAILURE;
	sf::Text title("Reflex training", font, 50);
	title.setColor

	sf::RectangleShape titleRec(sf::Vector2f(400.0f, 80.0f));
	
	titleRec.setPosition(sf::Vector2f(300.0f, 25.0f));
	title.setPosition(sf::Vector2f(400.0f, 30.0f));

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

		window.draw(titleRec);
		window.draw(title);

		window.display();
	}

	return 0;
}