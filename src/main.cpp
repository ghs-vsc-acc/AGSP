#include <SFML/Window/Event.hpp>
#include <vector>

#include "tileMap.hpp"

int main(int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(20 * 32, 20 * 32), "Tilemap Test");
    int map_arr[20][20];

    // load map with test data
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            map_arr[i][j] = (i + j) % 2 == 0 ? 1 : 0;
        }
    }

    TileMap tileMap(map_arr, "./exampleFileManifestPath.json");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // clear frame
        window.clear();

        // do/draw stuff
        tileMap.render(window);

        // render new frame
        window.display();
    }

    return 0;
}
