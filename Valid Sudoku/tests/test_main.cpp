// Minimal test runner: no external libraries needed.
#include <iostream>

#include <string>
#include <vector>

#include "sudoku.h"

static int failures = 0;
#define CHECK(expr)                                                             \
    do {                                                                        \
        if (!(expr)) {                                                          \
            std::cerr << "FAIL " << __FILE__ << ":" << __LINE__ << "  " #expr "\n"; \
            ++failures;                                                         \
        }                                                                       \
    } while (0)

static Board makeBoard(const std::vector<std::string>& rows) {
    Board b;
    for (const auto& r : rows) b.emplace_back(r.begin(), r.end());
    return b;
}

static const std::vector<std::string> kExample1 = {
    "53..7....", "6..195...", ".98....6.",
    "8...6...3", "4..8.3..1", "7...2...6",
    ".6....28.", "...419..5", "....8..79",
};

int main() {
    // Example 1 -> true
    CHECK(isValidSudoku(makeBoard(kExample1)) == true);

    // Example 2: top-left 5 changed to 8 -> two 8s in top-left box -> false
    {
        auto rows = kExample1;
        rows[0][0] = '8';
        CHECK(isValidSudoku(makeBoard(rows)) == false);
    }
    // Edge: empty board -> true
    CHECK(isValidSudoku(makeBoard(std::vector<std::string>(9, "........."))) == true);

    // Row repeat only
    {
        auto rows = std::vector<std::string>(9, ".........");
        rows[4] = "1.......1";
        CHECK(isValidSudoku(makeBoard(rows)) == false);
    }
    // Column repeat only
    {
        auto rows = std::vector<std::string>(9, ".........");
        rows[0][6] = '7';
        rows[8][6] = '7';
        CHECK(isValidSudoku(makeBoard(rows)) == false);
    }
    // Same digit in different rows, columns, and boxes -> still valid
    {
        auto rows = std::vector<std::string>(9, ".........");
        rows[0][0] = '9';
        rows[4][4] = '9';
        rows[8][8] = '9';
        CHECK(isValidSudoku(makeBoard(rows)) == true);
    }

    if (failures == 0) std::cout << "All tests passed\n";
    return failures == 0 ? 0 : 1;
}
