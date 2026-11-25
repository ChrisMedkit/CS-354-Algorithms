// Minimal test runner: no external libraries needed.
#include <iostream>

#include "maze.h"

static int failures = 0;
#define CHECK(expr)                                                             \
    do {                                                                        \
        if (!(expr)) {                                                          \
            std::cerr << "FAIL " << __FILE__ << ":" << __LINE__ << "  " #expr "\n"; \
            ++failures;                                                         \
        }                                                                       \
    } while (0)

static const Maze kMaze = {
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0},
};

int main() {
    // Example 1 -> 12
    CHECK(shortestDistance(kMaze, {0, 4}, {4, 4}) == 12);

    // Example 2: ball can pass [3,2] but never stop there -> -1
    CHECK(shortestDistance(kMaze, {0, 4}, {3, 2}) == -1);

    // Edge: start == destination -> 0
    CHECK(shortestDistance(kMaze, {0, 4}, {0, 4}) == 0);

    // Edge: one straight roll in a corridor -> 3
    CHECK(shortestDistance(Maze{{0, 0, 0, 0}}, {0, 0}, {0, 3}) == 3);

    // Edge: middle of corridor is never a stop -> -1
    CHECK(shortestDistance(Maze{{0, 0, 0, 0}}, {0, 0}, {0, 2}) == -1);

    if (failures == 0) std::cout << "All tests passed\n";
    return failures == 0 ? 0 : 1;
}
