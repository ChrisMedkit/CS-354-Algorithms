#include <iostream>

#include "maze.h"

int main() {
    // Examples from the assignment. TODO: read maze/start/destination from input if needed.
    Maze maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
    };
    std::cout << shortestDistance(maze, {0, 4}, {4, 4}) << '\n';  // expected 12
    std::cout << shortestDistance(maze, {0, 4}, {3, 2}) << '\n';  // expected -1
    return 0;
}
