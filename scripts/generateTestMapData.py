import json

jsonData = json.loads("{ 'map': { 'tiles': {} }, 'textureDict': { 0: 'red', 1: 'green', 2: 'blue' } }")
tilesData = jsonData["map"]["tiles"]

for k in range(0, 8):
    for j in range(0, 8):
        print("aaaaaa foooo barrrr")

with open("data_file.json", "w") as write_file:
    json.dump(jsonData, write_file)
