# Valid Sudoku — Algorithms
See [DIAGRAM.md](DIAGRAM.md) for diagrams.
**Due:** not stated  ·  **Language:** C++20  ·  **Points:** not stated

## Summary
Decide if a partly filled 9×9 Sudoku board is valid: no digit 1–9 may repeat in any row, column, or 3×3 sub-box. Only filled cells are checked, and the board does not need to be solvable. Answer: what type of algorithm, why, and pseudocode.

## Requirements
- [ ] Q1: name the type of algorithm
- [ ] Q2: explain why
- [ ] Q3: write pseudocode
- [ ] Rule 1: each row has no repeated digit
- [ ] Rule 2: each column has no repeated digit
- [ ] Rule 3: each of the nine 3×3 boxes has no repeated digit
- [ ] Only filled cells are validated; `'.'` is skipped
- [ ] Example 1 → true; Example 2 (top-left 5 → 8) → false
- [ ] Constraints: board is 9×9, cells are `'1'`–`'9'` or `'.'`
- [ ] Submission: answers in `ANSWERS.md` (format/where not stated)

## Plan
1. Set up the "seen" records for rows, columns, and boxes in `src/sudoku.cpp`
2. Loop over all 81 cells, skipping `'.'`
3. Work out the box number for a cell and check/mark all three records
4. Run tests: both examples, empty board, row-only, column-only repeats
5. Write Q1–Q3 in `ANSWERS.md`

## Files
| File | Purpose |
|---|---|
| `ANSWERS.md` | Q1–Q3 write-up |
| `src/sudoku.h` / `src/sudoku.cpp` | `Board` type and `isValidSudoku` stub |
| `src/main.cpp` | Runs Example 1 |
| `tests/test_main.cpp` | Example and edge-case checks |
| `assignment/` | Original assignment pages |

## Key concepts
- **Hashing / sets:** "have I seen this digit here before?" is a membership check, which a set (or a 9-slot bool array) answers in O(1).
- **One pass:** each cell belongs to exactly one row, one column, and one box, so you can check all three rules in a single scan.
- **Box index:** rows 0–2 / 3–5 / 6–8 and columns 0–2 / 3–5 / 6–8 make 9 boxes; integer division by 3 picks the band.
- **Cost:** the board is fixed at 81 cells, so time and space are constant; in general it is O(cells).
- **Valid ≠ solvable:** don't try to solve the puzzle.

## Testing
- Example 1 → true
- Example 2 (two 8s in the top-left box) → false
- Empty board → true
- Repeat only in a row → false; only in a column → false
- Same digit in different rows, columns and boxes → true

## Questions / ambiguities
- Is code required, or only the three answers?
- Due date, points, and submission format are not stated.
