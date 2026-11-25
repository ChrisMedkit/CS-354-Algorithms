#include "maze.h"

/**
 * shortestDistance — rolling-ball maze, shortest stopping distance.
 * Input:  maze m x n of 0/1 (borders count as walls), start [row, col],
 *         destination [row, col]
 * Output: smallest total cells rolled to stop at destination, or -1
 *
 * Rules: the ball rolls up/down/left/right and does not stop until the next
 * cell is a wall or off the grid. Passing over the destination does not count.
 *
 * TODO (Plan step 1): roll helper — from (r, c) in direction (dr, dc), move
 *   while the next cell is inside and 0; return stop cell + steps.
 * TODO (Plan step 2): best-distance grid, all "infinity" except start = 0.
 * TODO (Plan step 3): repeatedly take the stop cell with the smallest known
 *   distance (min-priority queue); try all 4 rolls; keep any shorter total.
 * TODO (Plan step 4): return distance at destination, or -1 if never reached.
 */
int shortestDistance(const Maze& maze, const std::vector<int>& start,
                     const std::vector<int>& destination) {
    (void)maze;
    (void)start;
    (void)destination;
    return 0;
}
