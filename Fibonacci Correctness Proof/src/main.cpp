#include <iostream>

#include "fibonacci.h"

int main() {
    // Part A: print the trace table for n = 6.
    std::cout << "i\tprev\tcurr\n";
    for (const TraceRow& row : traceFibonacci(6)) {
        std::cout << row.i << '\t' << row.prev << '\t' << row.curr << '\n';
    }

    // Sanity output: F(0)..F(10). Not a proof — just a check for you.
    // TODO (Plan step 3): compare against the known values 0 1 1 2 3 5 8 13 21 34 55.
    for (int n = 0; n <= 10; ++n) {
        std::cout << "F(" << n << ") = " << iterativeFibonacci(n) << '\n';
    }
    return 0;
}
