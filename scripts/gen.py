import json
import random

grid_size = 16
tile_size = 50

map_data = {
    "map": {
        "tiles": {}
    }, "textureDict": {
        "0": "red",
        "1": "green",
        "2": "blue"
    }
}

print("out: Generating map data...")

index = 0
for x in range(grid_size):
    for y in range(grid_size):
        tile_data = {
            "arr_x": x,
            "arr_y": y,
            "x_pos": x * tile_size,
            "y_pos": y * tile_size,
            "t_col": random.randint(0, 2)
        }

        map_data["map"]["tiles"][f"{index}"] = tile_data
        index += 1

print("out: Finished generating map data.")
print("out: File should be in 'out_data/generated_data.json'.")

with open("out_data/generated_data.json", 'w') as outfile:
    json.dump(map_data, outfile, indent=4)
