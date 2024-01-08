#include "tileMap.hpp"
#include "utils.hpp"

#include <SFML/Window/Event.hpp>
#include <iostream>
#include <time.h>

int main(void) {
	std::cout << "[LOG]: Application begin..." << std::endl;

	sf::RenderWindow m_window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "AGSP++", sf::Style::Close);
	//ns_tile_map::TileMap m_tileMap("assets/exampleMapData.json"); <-- map actual (uncomment when done using test map data script to generate maps)
	ns_tile_map::TileMap m_tileMap("scripts/generated_data.json");

	// DEBUG
	ns_utils::debug_setPositionToTopLeftOnSpawn(m_window);

	sf::VideoMode screenSize = sf::VideoMode::getDesktopMode();
	std::cout << "[SCREEN-SIZE-W]: " << screenSize.width << std::endl;
	std::cout << "[SCREEN-SIZE-H]: " << screenSize.height  << std::endl;
	// =====

	std::cout << "[LOG]: Entering into main window loop." << std::endl;
	while (m_window.isOpen()) {
		sf::Event event;

		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_window.close();
			}

			// DEBUG
			ns_utils::debug_applicationQuickEscQuickExit(event, m_window);
			// =====
		}

		// clear frame
		m_window.clear();

		// draw/update/do stuff
		m_tileMap.draw(m_window);

		// render new frame
		m_window.display();
	}

	std::cout << "[LOG]: Application exiting..." << std::endl;
	return 0;
}
