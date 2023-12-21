#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include <nlohmann/json.hpp>
#include <vector>

struct Tile {
    int arr_x;
    int arr_y;

    float x_pos;
    float y_pos;

    int t_col; // tmp: color, once fully implemented will instead be index number being the value of a file path
};

struct TileMap {
    int width;
    int height;
    int t_size;
    std::vector<Tile> tiles; // main tile vector
    nlohmann::json m_data;


    TileMap(int map_arr[20][20], std::string manifest_fp);

    void fromJson(const nlohmann::json& t_json, Tile& t_tile);
    nlohmann::json loadManifest(std::string manifest_fp);
    void render(sf::RenderWindow& window_obj);
};
