#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

#include "consts.hpp" // adjust values within

namespace ns_tile_map {
	class TileMap {
		private:
			struct Tile;
			std::vector<std::vector<Tile>> tileVector;

		public:
			TileMap(std::string manifest_fp);
			void draw(sf::RenderWindow& m_window_instance);
	};
}
