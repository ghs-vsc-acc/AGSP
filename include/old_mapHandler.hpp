#pragma once


/*
* Implementing a map handler to read and update a tilemap using a descriptor or manifest file involves several steps:

1. Define the Manifest Format:
Create a format for your map descriptor file. This file should contain data about the map,
including details about each tile, such as its texture image, position, properties, etc.
You can use JSON, XML, or any other format you prefer.

2. Read and Parse the Manifest:
Write code to read and parse the manifest file to extract information about the map.
Use libraries or built-in functions to parse the chosen file format (e.g., JSON parsing libraries like nlohmann/json for C++).

3. Create a Data Structure:
Define a data structure or class to hold the map information.
This structure should store data for each tile or cell in the map,
such as texture/image IDs, positions, properties, etc.

4. Load Textures and Resources:
Load the textures and resources specified in the map descriptor file.
Associate each texture/image ID with its corresponding image file.

5. Render the Map:
Using the map data structure, render the tilemap on the screen based on the loaded textures and properties.
Use the map data to position and display each tile according to its properties.

6. Implement Map Updates:
Provide functions or methods in your map handler to update the map dynamically.
These functions should modify the map's data structure based on changes in the game (e.g., player interactions, events).
*/

/*
example theoretical manifest file (JSON):

{
	"map": {
		"tiles": [
			{
				"textureId": 1,
				"x": 0,
				"y": 0,
				"properties": {
					"passable": false, // like can you walk through this object, is it solid
				}
			}
		],
		"textures": [
			{
				"id": 1,
				"file": "skyTextureBar.png"
			},
			{
				"id": 2,
				"file": "groundTextureFoo.png"
			}
		]
	}
}
*/

/*
example data structures:
struct Tile {
	int textureId,
	int x, y,
	bool isPassable,

	// constructor
	Tile(int id, int xPos, int yPos, bool isSolid)
		: textureId(id), x(xPos), y(yPos), isSolid(isSolid)
};

struct Map {
	std::vector<Tile> tiles;
	
	// methods
	void addTile(int textureId, int xPos, int yPos, bool isSolid)
		tiles.emplace_back(textureId, xPos, yPos, isSolid)
};
*/

// consider this, in pixel games there are also "levels"
// not as in like you complete level 1 and move to level 2 but as in
// like plateaus where each level is a different height level in game.
// basically levels provide height to the game. consider having the map
// manifest contain levels, so instead of stright just containing
// tiles then textures, have it be levels then textures, where each level
// contains the tiles object instead, like so:
//
//	{
//		"levels": {
//			"1": {
//				"tiles": {
//					// etc...
//				},
//				"properties: {  // level independent, in case there is a particular attribute for some part of the map for some reason
//					// etc...
//				}
//			},
//			// etc...
//		}, "textures": {
//			// etc...
//		}
//	}

#include <nlohmann/json.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

#include <iostream>
#include <fstream>
#include <vector>


struct Tile {
	int textureId;
	int x, y;
};

class TileMap {
	private:
		std::vector<std::vector<Tile>> mapGrid;
		std::vector<float> mapSize;
		const int tileSize;

	public:
		TileMap(int t_size, int m_rows, int m_cols);

		nlohmann::json loadMap(const std::string& f_name);
		void render(sf::RenderWindow& m_window, std::string f_name);
};
