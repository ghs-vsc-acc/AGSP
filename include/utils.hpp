#ifndef UTILS_HPP
#define UTILS_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace ns_utils {
	void debug_setPositionToTopLeftOnSpawn(sf::RenderWindow& m_window_obj);
	void debug_applicationQuickEscQuickExit(sf::Event t_event, sf::RenderWindow& m_window_obj);
}

#endif // UTILS_HPP
