#include "sudoku.h"

/**
 * isValidSudoku — check a partly filled 9x9 board.
 * Input:  board[9][9], each cell '1'..'9' or '.'
 * Output: true if no digit repeats in any row, column, or 3x3 box
 *         (only filled cells count; solvable or not does not matter)
 *
 * TODO (Plan step 1): make 9 "seen" sets each for rows, columns, boxes.
 * TODO (Plan step 2): visit every cell; skip '.'.
 * TODO (Plan step 3): box index from (row, col); if the digit was seen in its
 *   row, column, or box -> return false; else mark it seen in all three.
 * TODO: return true after the scan.
 */
bool isValidSudoku(const Board& board) {
    (void)board;
    return false;
}
