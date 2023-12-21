#include "tileMap.hpp"

#include <string>
#include <fstream>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

TileMap::TileMap(int map_arr[20][20], std::string manifest_fp) {
    width = 20;
    height = 20;
    t_size = 32; // 32x32 pixels
    m_data = loadManifest(manifest_fp);

    // initialize tilemap
    //for (int x = 0; x < width; x++) {
    //    for (int y = 0; y < height; y++) {
    //        Tile t_tile;
    //
    //        t_tile.arr_x = x;
    //        t_tile.arr_y = y;
    //        t_tile.x_pos = (x * t_size);
    //        t_tile.y_pos = (y * t_size);
    //        t_tile.t_col = map_arr[x][y]; // tmp: color, once basic functional implementation is finished, implement textures
    //
    //        tiles.push_back(t_tile);
    //    }
    //}
/*
    TileMap(const std::string & manifestFile) {
        // Read the JSON file
        std::ifstream file(manifestFile);
        nlohmann::json data;
        file >> data;

        // Parse textures
        std::map<int, std::string> textures;
        if (data.find("textures") != data.end()) {
            auto& textureData = data["textures"];
            for (auto it = textureData.begin(); it != textureData.end(); ++it) {
                textures[it.key()] = it.value();
            }
        }

        // Parse tiles
        if (data.find("map") != data.end()) {
            auto& tilesData = data["map"]["tiles"];
            for (auto it = tilesData.begin(); it != tilesData.end(); ++it) {
                Tile tile;
                tile = it.value(); // Uses the from_json function for parsing
                if (textures.find(tile.t_aid) != textures.end()) {
                    // Handle texture ID not found in textures map
                    // You can load the texture and assign it to the sprite here
                    // For this example, let's just set the texture path
                    textures[tile.t_aid]; // Use the texture path
                }
                tiles.push_back(tile);
            }
        }

        // Set other properties like width, height, t_size if needed
        // ...
    }
*/

    std::map<int, std::string> texture_dict;
    if (m_data.find("textures") != m_data.end()) {
        auto& textureData = data["textures"];
        for (auto& k = te) {}
    }
}

void TileMap::fromJson(const nlohmann::json& t_json, Tile& t_tile) {
    // array(s) index(s)
    t_json.at("arr_x").get_to(t_tile.arr_x);
    t_json.at("arr_y").get_to(t_tile.arr_y);

    // ingame position
    t_json.at("x_pos").get_to(t_tile.x_pos);
    t_json.at("y_pos").get_to(t_tile.y_pos);

    // texture reference
    t_json.at("t_aid").get_to("");
}

nlohmann::json TileMap::loadManifest(std::string manifest_fp) {
    std::ifstream t_file(manifest_fp);
    if (!t_file.is_open()) {
        // failed to open
        return;
    }

    nlohmann::json t_data;
    t_file >> t_data;

    return t_data;
}

void TileMap::render(sf::RenderWindow& window_obj) {
    for (const auto& tile : tiles) {
        // sf::RectangleShape rect(sf::Vector2f((float)t_size, (float)t_size));
        // rect.setPosition(tile.x_pos, tile.y_pos);
        sf::Sprite t_sprite;

        // Set color based on t_col (for testing, use different colors)
        //sf::Color tileColor = (tile.t_col == 1) ? sf::Color::Blue : sf::Color::Green;
        //rect.setFillColor(tileColor);

        // window_obj.draw(rect);
    }
}
