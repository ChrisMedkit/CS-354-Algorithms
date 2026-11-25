# Ball Maze Shortest Distance — Algorithms
See [DIAGRAM.md](DIAGRAM.md) for diagrams.
**Due:** not stated  ·  **Language:** C++20  ·  **Points:** not stated

## Summary
A ball sits in an m×n maze of empty cells (0) and walls (1). It rolls up, down, left, or right and only stops when it hits a wall. Return the shortest distance (empty cells rolled, start excluded, destination included) for the ball to **stop** at the destination, or −1 if it can't. The borders count as walls.

## Requirements
- [ ] `shortestDistance(maze, start, destination)` returns the shortest stopping distance
- [ ] Ball rolls until the next cell is a wall or the border
- [ ] Distance counts cells traveled: start excluded, destination included
- [ ] Return −1 if the ball cannot stop at the destination (passing through does not count)
- [ ] Example 1: start [0,4], destination [4,4] → 12
- [ ] Example 2: start [0,4], destination [3,2] → −1
- [ ] Answer what algorithm / why / pseudocode (if asked like the other problems) in `ANSWERS.md`
- [ ] Submission: format and where to submit not stated

## Plan
1. Write the roll helper: from a cell and direction, find the stop cell and the step count
2. Set up the best-distance grid (start = 0, rest = infinity)
3. Main loop with a min-priority queue over stop cells, trying 4 rolls each
4. Return the destination's distance or −1
5. Run tests: both examples plus start = destination and corridor cases
6. Fill `ANSWERS.md`

## Files
| File | Purpose |
|---|---|
| `ANSWERS.md` | Algorithm / why / pseudocode write-up |
| `src/maze.h` / `src/maze.cpp` | `Maze` type and `shortestDistance` stub |
| `src/main.cpp` | Runs both examples |
| `tests/test_main.cpp` | Example and edge-case checks |
| `assignment/` | Original assignment pages |

## Key concepts
- **Graph model:** nodes are the cells where the ball can stop; edges are single rolls.
- **Weighted edges:** a roll's weight is how many cells it covers, and rolls differ in length. "Fewest moves" (plain BFS) is not the same as "fewest cells".
- **Shortest path with non-negative weights:** a priority queue that always expands the closest known stop cell gives the right answer.
- **Stop vs. pass:** only the roll's end cell is a node. The destination counts only if a roll ends there.
- **Stale queue entries:** a cell can be pushed more than once; skip entries worse than the best known.

## Testing
- Example 1 → 12
- Example 2 → −1 (passes [3,2] but can't stop)
- start == destination → 0
- Single corridor `[[0,0,0,0]]`, [0,0] → [0,3] = 3; → [0,2] = −1
- Maze with no open neighbor from start → −1 unless start is the destination

## Questions / ambiguities
- The page shows only the problem, not the questions. Does this one also want "algorithm / why / pseudocode", or working code?
- Constraints (maze size limits) are not shown on the page; check if a page is missing.
- Due date, points, and submission format are not stated.
