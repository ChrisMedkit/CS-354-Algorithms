#include <iostream>
#include <string>
#include <vector>

#include "sudoku.h"

int main() {
    // Example 1 from the assignment. TODO: read 9 lines from input if needed.
    std::vector<std::string> rows = {
        "53..7....", "6..195...", ".98....6.",
        "8...6...3", "4..8.3..1", "7...2...6",
        ".6....28.", "...419..5", "....8..79",
    };
    Board board;
    for (const auto& r : rows) board.emplace_back(r.begin(), r.end());

    std::cout << std::boolalpha << isValidSudoku(board) << '\n';  // expected true
    return 0;
}
