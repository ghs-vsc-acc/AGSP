#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "mapHandler.hpp"


TileMap::TileMap(int t_size, int m_rows, int m_cols)
		: mapSize(m_rows, m_cols), tileSize(64),
			mapGrid(m_rows, std::vector<Tile>(m_cols)) {}

nlohmann::json TileMap::loadMap(const std::string& f_name) {
	std::ifstream file(f_name);
	if (!file.is_open()) {
		std::cerr << "[ERR]: Failed to open '" <<
			f_name << "'." << std::endl;
	}

	nlohmann::json mapData;
	file >> mapData;
	file.close();

	return mapData;
}


void TileMap::render(sf::RenderWindow& m_window, std::string f_name) {
	nlohmann::json mapData = loadMap(f_name);

	if (mapData.contains("tiles")) {
		int index = 0;
		for (int y = 0; y < mapSize[1]; y++) {
			for (int x = 0; x < mapSize[0]; x++) {
				mapGrid[y][x].textureId = mapData["tiles"][index++]["textureId"];
			}
		}
	}

	std::unordered_map<int, std::string> spriteFilePaths;
	spriteFilePaths[0] = "C:/test.png";

	for (int y = 0; y < mapSize[1]; y++) {
		for (int x = 0; x < mapSize[0]; x++) {
			int textureId = mapGrid[y][x].textureId;

			sf::Texture tileTexture;
			if (!tileTexture.loadFromFile(assetDict[textureId])) {
				std::cerr << "Failed to load texture with id..." << std::endl;
			}

			sf::Sprite tileSprite(tileTexture);
			tileSprite.setPosition((x * tileSize), (y * tileSize));

			m_window.draw(tileSprite);
		}
	}
}
