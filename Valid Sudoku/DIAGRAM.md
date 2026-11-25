# Valid Sudoku — Diagrams
See [OUTLINE.md](OUTLINE.md)

## Plan

```mermaid
flowchart TD
  S1["Step 1: seen records for rows, cols, boxes<br>src/sudoku.cpp"]
  S2["Step 2: loop all 81 cells, skip dots<br>src/sudoku.cpp"]
  S3["Step 3: box number + check and mark<br>src/sudoku.cpp"]
  S4["Step 4: run tests<br>tests/test_main.cpp"]
  S5["Step 5: write Q1 to Q3<br>ANSWERS.md"]
  S1 --> S2 --> S3 --> S4 --> S5
```
Build order from data setup to written answers.

## Code structure

```mermaid
flowchart LR
  main["src/main.cpp<br>main()"]
  tests["tests/test_main.cpp<br>main(), makeBoard()"]
  h["src/sudoku.h<br>Board = 9x9 chars"]
  f["src/sudoku.cpp<br>isValidSudoku(board)"]
  main -->|calls| f
  tests -->|calls| f
  f -->|uses| h
```
Files and the one function they share.

## Program flow

```mermaid
flowchart TD
  A["Start"] --> B["Next cell (r, c)"]
  B --> C{"Cell is a dot?"}
  C -->|yes| G{"More cells?"}
  C -->|no| D["b = box number of (r, c)"]
  D --> E{"Digit seen in row r, col c, or box b?"}
  E -->|yes| F["Return false"]
  E -->|no| H["Mark digit seen in row r, col c, box b"]
  H --> G
  G -->|yes| B
  G -->|no| I["Return true"]
```
What `isValidSudoku` does at runtime.

## Box layout

```mermaid
flowchart TD
  subgraph Top["rows 0-2"]
    B0["box 0"] --- B1["box 1"] --- B2["box 2"]
  end
  subgraph Mid["rows 3-5"]
    B3["box 3"] --- B4["box 4"] --- B5["box 5"]
  end
  subgraph Bot["rows 6-8"]
    B6["box 6"] --- B7["box 7"] --- B8["box 8"]
  end
  Top --- Mid --- Bot
```
How the nine boxes are numbered; columns 0-2, 3-5, 6-8 go left to right.

## Requirements → code

```mermaid
flowchart LR
  R1["Rule 1 rows"] --> C["isValidSudoku"]
  R2["Rule 2 columns"] --> C
  R3["Rule 3 boxes"] --> C
  R4["Skip empty cells"] --> C
  C --> T1["test: Example 1 true"]
  C --> T2["test: Example 2 false"]
  C --> T3["test: row / column repeats"]
  C --> T4["test: empty board"]
  R5["Q1 to Q3"] --> W["ANSWERS.md"]
```
Each rule, the function that checks it, and the tests.
