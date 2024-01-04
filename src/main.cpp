#include "tileMap.hpp"
#include "utils.hpp"

#include <SFML/Window/Event.hpp>

int main(void) {
	sf::RenderWindow m_window(sf::VideoMode((GRID_SIZE * TILE_SIZE), (GRID_SIZE * TILE_SIZE)), "AGSP++", sf::Style::Close);
	ns_tile_map::TileMap m_tileMap("assets/exampleMapData.json");

	// DEBUG
	ns_utils::debug_setPositionToTopLeftOnSpawn(m_window);
	// =====

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

	return 0;
}
