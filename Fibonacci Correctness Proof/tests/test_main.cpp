// Minimal test runner: no external libraries needed.
#include <iostream>

#include "fibonacci.h"

static int failures = 0;
#define CHECK(expr)                                                             \
    do {                                                                        \
        if (!(expr)) {                                                          \
            std::cerr << "FAIL " << __FILE__ << ":" << __LINE__ << "  " #expr "\n"; \
            ++failures;                                                         \
        }                                                                       \
    } while (0)

int main() {
    // Base cases (Part C base cases)
    CHECK(iterativeFibonacci(0) == 0);
    CHECK(iterativeFibonacci(1) == 1);

    // First loop step (invariant initialization at i = 2)
    CHECK(iterativeFibonacci(2) == 1);

    // Part A input
    CHECK(iterativeFibonacci(6) == 8);
    CHECK(iterativeFibonacci(10) == 55);

    // Part A table for n = 6
    auto t = traceFibonacci(6);
    CHECK(t.size() == 6);
    if (t.size() == 6) {
        CHECK(t[0].prev == 0 && t[0].curr == 1);  // i = 1 (before loop)
        CHECK(t[5].prev == 5 && t[5].curr == 8);  // i = 6
    }

    if (failures == 0) std::cout << "All tests passed\n";
    return failures == 0 ? 0 : 1;
}
