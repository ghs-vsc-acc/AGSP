#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

#include "consts.hpp" // adjust values within

namespace ns_tile_map {
	class TileMap {
		private:
			struct Tile {
				// position within array
				int arr_x;
				int arr_y;

				// in-game position
				int x_pos;
				int y_pos;

				// color value (later to be texture path index)
				int t_col;
			};

			std::vector<std::vector<Tile>> tileVector;

		public:
			TileMap(std::string manifest_fp);
			void draw(sf::RenderWindow& m_window_instance);
	};
}
