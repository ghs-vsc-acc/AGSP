#ifndef CONSTS_HPP
#define CONSTS_HPP

// NOTE: if WINDOW_SIZE should say be not constant and instead based
//       on the grid and tile size, window size should be GRID_SIZE * TILE_SIZE

constexpr int WINDOW_SIZE = 800;
constexpr int GRID_SIZE = 16; // 16x16 grid
constexpr int TILE_SIZE = 50; // 50x50 pixels (size should be WINDOW_SIZE / GRID_SIZE)

#endif // CONSTS_HPP
