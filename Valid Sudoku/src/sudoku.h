#pragma once

#include <vector>

using Board = std::vector<std::vector<char>>;

// True if every filled cell follows the row, column, and 3x3 box rules.
bool isValidSudoku(const Board& board);
