#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std; 

void ChangePos(sf::RectangleShape& shp) {
	int rrx = rand() % 970 + 30;
	int rry = rand() % 780 + 20;
	float frrx = static_cast<float>(rrx);
	float frry = static_cast<float>(rry);
	sf::Vector2f newPos = sf::Vector2f(frrx, frry);
	shp.setPosition(newPos);
}

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
	sf::Text hitsShow("", font, 30);
	sf::Text missesShow("", font, 30);

	sf::RectangleShape titleRec(sf::Vector2f(400.0f, 75.0f));
	sf::RectangleShape objective(sf::Vector2f(40.0f, 40.0f));
	
	titleRec.setPosition(sf::Vector2f(300.0f, 25.0f));
	title.setPosition(sf::Vector2f(370.0f, 30.0f));
	objective.setPosition(sf::Vector2f(500.0f, 400.0f));
	hitsShow.setPosition(sf::Vector2f(50.0f, 40.0f));
	missesShow.setPosition(sf::Vector2f(850.0f, 40.0f));

	titleRec.setFillColor(sf::Color::White);
	title.setFillColor(textColor);
	objective.setFillColor(sf::Color(255, 0, 0));
	hitsShow.setFillColor(textColor);
	missesShow.setFillColor(textColor);

	window.setMouseCursor(cursor);

	window.clear(bgColor);

	sf::Clock clock;
	int moveIterator = 0;
	int hits = 0; 
	int misses = 0;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}			
			sf::Vector2i mousePos = mouse.getPosition(window);
			float mx = static_cast<float>(mousePos.x);
			float my = static_cast<float>(mousePos.y);

			sf::Vector2f mousePosFloat = sf::Vector2f(mx, my);

			bool onTarget = objective.getGlobalBounds().contains(mousePosFloat);

			sf::Time elapsed = clock.getElapsedTime();
			float timeRaw = elapsed.asSeconds();
			int timeApproximated = static_cast<int>(timeRaw);

			if (timeApproximated % 3 == 0)
				moveIterator = 0;

			if (timeApproximated % 2 == 0 && moveIterator == 0) {
				ChangePos(objective);
				moveIterator++;
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left && onTarget) {
					ChangePos(objective);
					hits++;
				}
				else if (event.mouseButton.button == sf::Mouse::Left && !onTarget)
					misses++;
			}

			string hitsString = to_string(hits);
			string missesString = to_string(misses);
			string hitsShowString = "Hits : " + hitsString;
			string missesShowString = "Misses : " + missesString;
			hitsShow.setString(hitsShowString);
			missesShow.setString(missesShowString);

			window.clear(bgColor);

			window.draw(titleRec);
			window.draw(title);
			window.draw(objective);
			window.draw(hitsShow);
			window.draw(missesShow);

			window.display();
		}
	}
	return 0;
}