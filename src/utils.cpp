#include "utils.hpp"

namespace ns_utils {
	void debug_setPositionToTopLeftOnSpawn(sf::RenderWindow& m_window_obj) {
		m_window_obj.setPosition(sf::Vector2i(10, 10));
	}

	void debug_applicationQuickEscQuickExit(sf::Event t_event, sf::RenderWindow& m_window_obj) {
		if (t_event.type == sf::Event::KeyPressed && t_event.key.code == sf::Keyboard::Escape) {
			m_window_obj.close();
		}
	}
}
