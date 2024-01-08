#include "tileMap.hpp"
#include "consts.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

#include <fstream>
#include <iostream>

namespace ns_tile_map {
	TileMap::TileMap(std::string manifest_fp)
			: tileVector(GRID_SIZE, std::vector<Tile>(GRID_SIZE)) {
		nlohmann::json t_jsonData = readMapData(manifest_fp);

		// ensure map data and texture dictionary exists
		if (t_jsonData.find("map") != t_jsonData.end() && t_jsonData.find("textureDict") != t_jsonData.end()) {
			auto& mapData = t_jsonData["map"];
			auto& textureDict = t_jsonData["textureDict"];

			// ensure tiles exist
			if (mapData.find("tiles") != mapData.end()) {
				auto& tilesData = mapData["tiles"];

				// for each tile assign respective data,
				// once complete push to main vector.
				for (auto& tile : tilesData.items()) {
					Tile t_tile;

					// set position within array
					t_tile.arr_x = tile.value()["arr_x"];
					t_tile.arr_y = tile.value()["arr_y"];

					// set ingame position
					t_tile.x_pos = tile.value()["x_pos"];
					t_tile.y_pos = tile.value()["y_pos"];

					// set tile color (soon to be texture index)
					t_tile.t_col = tile.value()["t_col"];

					// push to main vector
					tileVector[t_tile.arr_x][t_tile.arr_y] = t_tile;
				}
			} else {
				std::cerr << "[ERR]: 'tiles' not found in manifest" << std::endl;
				// return -1 // not possible due to current program setup
				// but ideal process would be escape program when map cant load
			}
		} else {
			std::cerr << "[ERR]: 'map' not found in manifest" << std::endl;
			// return -1 // not possible due to current program setup
			// but ideal process would be escape program when map cant load
		}
	}

	// needs to account for:
	// if cant read file, return should be like some specific json data
	// check to see if that data is there, if it is, we fucked up, if not
	// all good, continue with program execution
	nlohmann::json TileMap::readMapData(std::string manifest_fp) {
		//std::ifstream t_file("assets/exampleMapData.json");
		std::ifstream t_file(manifest_fp);
		if (!t_file.is_open()) {
			std::cerr << "" << std::endl;
			// return -1 // not possible due to current program setup
			// but ideal process would be escape program when map cant load
		}

		nlohmann::json jsonData;
		t_file >> jsonData;

		// temporary fix for the issue with program scope in 'draw' function
		// where the texture dictionary needs to be referenced
		test_json_data_var = jsonData;

		return jsonData;
	}

	// NOTE: (note to self) the spacing issue is due to the way we go about
	//       generating test data. our defined values (consts.hpp) are fine,
	//		 its the values generated on map data generation that are wrong.
	void TileMap::draw(sf::RenderWindow& m_window_obj) {
		nlohmann::json t_jsonData = test_json_data_var["map"]["tiles"];

		int t_index = 0;
		for (int k = 0; k < GRID_SIZE; k++) {
			for (int j = 0; j < GRID_SIZE; j++) {
				sf::RectangleShape t_tile(sf::Vector2f((float)TILE_SIZE, (float)TILE_SIZE));

				// set position
				//t_tile.setPosition(static_cast<float>(j * TILE_SIZE), // original implementation
				//		static_cast<float>(k * TILE_SIZE));
				t_tile.setPosition((float)tileVector[k][j].x_pos, (float)tileVector[k][j].y_pos); // new implementation

				// set color (soon to be texture)
				nlohmann::json t_textureDict = test_json_data_var["textureDict"];
				int t_col = tileVector[k][j].t_col;
				std::string tileColStr = t_textureDict[std::to_string(t_col)];

				if (tileColStr == "red") t_tile.setFillColor(sf::Color::Red);
				else if (tileColStr == "green") t_tile.setFillColor(sf::Color::Green);
				else if (tileColStr == "blue") t_tile.setFillColor(sf::Color::Blue);

				// draw to screen
				m_window_obj.draw(t_tile);
			}
		}
	}
}
