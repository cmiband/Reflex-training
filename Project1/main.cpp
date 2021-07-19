#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std; 

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Mikoshi");

	sf::Event event;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}

	return 0;
}