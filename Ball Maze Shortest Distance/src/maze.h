#pragma once

#include <vector>

using Maze = std::vector<std::vector<int>>;  // 0 = empty, 1 = wall

// Shortest number of empty cells the ball travels (start excluded, destination
// included) to STOP at destination. Returns -1 if it cannot stop there.
int shortestDistance(const Maze& maze, const std::vector<int>& start,
                     const std::vector<int>& destination);
