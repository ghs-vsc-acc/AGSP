#include <SFML/Graphics.hpp>

constexpr int MAP_WIDTH = 20;
constexpr int MAP_HEIGHT = 20;
constexpr int TILE_SIZE = 32; // x32 pixels

int tilemap[MAP_WIDTH][MAP_HEIGHT];

void drawTilemap(sf::RenderWindow& window) {
    sf::VertexArray vertices(sf::Quads, MAP_WIDTH * MAP_HEIGHT * 4);

    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            int tileType = tilemap[x][y];

            float xPos = (x * (float)TILE_SIZE);
            float yPos = (y * (float)TILE_SIZE);

            vertices[(x + y * MAP_WIDTH) * 4].position = sf::Vector2f(xPos, yPos);
            vertices[(x + y * MAP_WIDTH) * 4 + 1].position = sf::Vector2f((xPos + TILE_SIZE), yPos);
            vertices[(x + y * MAP_WIDTH) * 4 + 2].position = sf::Vector2f((xPos + TILE_SIZE), yPos + TILE_SIZE);
            vertices[(x + y * MAP_WIDTH) * 4 + 3].position = sf::Vector2f(xPos, (yPos + TILE_SIZE));

            sf::Color tileColor = (tileType == 1) ? sf::Color::Black : sf::Color::White;

            vertices[((x + y * MAP_WIDTH) * 4)].color = tileColor;
            vertices[((x + y * MAP_WIDTH) * 4 + 1)].color = tileColor;
            vertices[((x + y * MAP_WIDTH) * 4 + 2)].color = tileColor;
            vertices[((x + y * MAP_WIDTH) * 4 + 3)].color = tileColor;
        }
    }

    window.draw(vertices);
}

// basic tilemap test
int main() {
    sf::RenderWindow window(sf::VideoMode((MAP_WIDTH * TILE_SIZE), (MAP_HEIGHT * TILE_SIZE)), "AGSP++");

    // color
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            tilemap[x][y] = (x + y) % 2 == 0 ? 1 : 0;
        }
    }

    // main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // clear current frame
        window.clear();

        // do/draw stuff...
        drawTilemap(window);

        // render new frame
        window.display();
    }

    return 0;
}


