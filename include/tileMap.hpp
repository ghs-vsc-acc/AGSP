#pragma once

/*
NOTE: consider that "levels" need to be implemented, in map have levels then in levels have tiles (for later)
example theoretical manifest file:

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

struct Tile {};

class TileMap {}; // see if should struct
