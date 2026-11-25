# Ball Maze Shortest Distance — Diagrams
See [OUTLINE.md](OUTLINE.md)

## Plan

```mermaid
flowchart TD
  S1["Step 1: roll helper<br>src/maze.cpp"]
  S2["Step 2: best-distance grid<br>src/maze.cpp"]
  S3["Step 3: priority queue loop<br>src/maze.cpp"]
  S4["Step 4: return distance or -1<br>src/maze.cpp"]
  S5["Step 5: run tests<br>tests/test_main.cpp"]
  S6["Step 6: write answers<br>ANSWERS.md"]
  S1 --> S2 --> S3 --> S4 --> S5 --> S6
```
Build order from the roll helper to the write-up.

## Code structure

```mermaid
flowchart LR
  main["src/main.cpp<br>main()"]
  tests["tests/test_main.cpp<br>main()"]
  h["src/maze.h<br>Maze = grid of 0/1"]
  f["src/maze.cpp<br>shortestDistance(maze, start, destination)"]
  main -->|calls| f
  tests -->|calls| f
  f -->|uses| h
```
Files and the one function they share. Add the roll helper inside `src/maze.cpp`.

## Program flow

```mermaid
flowchart TD
  A["dist[start] = 0, push start"] --> B{"Queue empty?"}
  B -->|yes| Z["Return -1"]
  B -->|no| C["Pop closest stop cell"]
  C --> D{"It is the destination?"}
  D -->|yes| Y["Return its distance"]
  D -->|no| E{"Stale entry?"}
  E -->|yes| B
  E -->|no| F["For each of 4 directions: roll to wall"]
  F --> G{"New total shorter than best at stop cell?"}
  G -->|yes| H["Update best, push stop cell"]
  G -->|no| B
  H --> B
```
What `shortestDistance` does at runtime.

## Maze (Example 1)

```mermaid
flowchart TD
  subgraph R0["row 0"]
    a00["."] --- a01["."] --- a02["#"] --- a03["."] --- a04["S"]
  end
  subgraph R1["row 1"]
    a10["."] --- a11["."] --- a12["."] --- a13["."] --- a14["."]
  end
  subgraph R3["row 3"]
    a30["#"] --- a31["#"] --- a32["."] --- a33["#"] --- a34["#"]
  end
  subgraph R4["row 4"]
    a40["."] --- a41["."] --- a42["."] --- a43["."] --- a44["D"]
  end
  R0 --- R1 --- R3 --- R4
```
Rows 0, 1, 3, 4 of the maze (row 2 is `. . . # .`). S = start [0,4], D = destination [4,4], # = wall. Row 3 has one gap at column 2.

## Requirements → code

```mermaid
flowchart LR
  R1["Roll until wall"] --> C["shortestDistance"]
  R2["Count cells traveled"] --> C
  R3["Shortest stop distance"] --> C
  R4["Return -1 if no stop"] --> C
  C --> T1["test: Example 1 = 12"]
  C --> T2["test: Example 2 = -1"]
  C --> T3["test: start = destination"]
  C --> T4["test: corridor cases"]
  R5["Algorithm / why / pseudocode"] --> W["ANSWERS.md"]
```
Each requirement, the function that meets it, and the tests.
