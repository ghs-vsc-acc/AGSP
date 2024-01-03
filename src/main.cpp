// very basic program is implemented
// turn the tilemap into a class (will make this significantly cleaner now, and easier in the future to work with)

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include <iostream>
#include <fstream>

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

int main() {
    const int GRID_SIZE = 3;
    const int TILE_SIZE = 100;

    // load map manifest
    std::ifstream file("assets/exampleMapData.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return -1;
    }

    nlohmann::json data;
    file >> data;

    // main tile vector
    std::vector<std::vector<Tile>> tileMap(GRID_SIZE, std::vector<Tile>(GRID_SIZE));

    // check that map and textureDict exist
    if (data.find("map") != data.end() && data.find("textureDict") != data.end()) {
        auto& mapData = data["map"];
        auto& textureDict = data["textureDict"];

        // check that tiles exist
        if (mapData.find("tiles") != mapData.end()) {
            auto& tilesData = mapData["tiles"];

            // interate over each tile
            // assign its respective data
            // once complete push to
            // main tile vector
            for (auto& tile : tilesData.items()) {
                Tile currentTile;

                currentTile.arr_x = tile.value()["arr_x"];
                currentTile.arr_y = tile.value()["arr_y"];
                currentTile.x_pos = tile.value()["x_pos"];
                currentTile.y_pos = tile.value()["y_pos"];
                currentTile.t_col = tile.value()["t_col"];

                tileMap[currentTile.arr_x][currentTile.arr_y] = currentTile;
            }
        }

        sf::RenderWindow window(sf::VideoMode(GRID_SIZE * TILE_SIZE, GRID_SIZE * TILE_SIZE), "Tile Map");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();

            // draw tiles to screen as grid
            for (int i = 0; i < GRID_SIZE; ++i) {
                for (int j = 0; j < GRID_SIZE; ++j) {
                    sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));

                    // set tile position (based on tile size & the current loop index)
                    tile.setPosition(static_cast<float>(j * TILE_SIZE), static_cast<float>(i * TILE_SIZE));

                    // set tile colors (temporary. will be here until texture loading is implemented)
                    int t_col = tileMap[i][j].t_col;
                    std::string textureColor = textureDict[std::to_string(t_col)];

                    if (textureColor == "red") tile.setFillColor(sf::Color::Red);
                    else if (textureColor == "green") tile.setFillColor(sf::Color::Green);
                    else if (textureColor == "blue") tile.setFillColor(sf::Color::Blue);

                    window.draw(tile);
                }
            }

            window.display();
        }
    } else {
        std::cerr << "Failed to find necessary data in the JSON file!" << std::endl;
        return -1;
    }

    return 0;
}
