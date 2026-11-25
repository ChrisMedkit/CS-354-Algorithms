#include "fibonacci.h"

/**
 * IterativeFibonacci(n) — must match the assignment's pseudocode line for line.
 * Input:  n >= 0
 * Output: F(n), where F(0) = 0, F(1) = 1, F(k) = F(k-1) + F(k-2)
 *
 * TODO (Plan step 1):
 *   - if n == 0 return 0; if n == 1 return 1
 *   - prev = 0, curr = 1
 *   - for i = 2 to n: next = prev + curr; prev = curr; curr = next
 *   - return curr
 */
long long iterativeFibonacci(int n) {
    (void)n;
    return 0;
}

/**
 * Trace helper for Part A (table for n = 6).
 * Input:  n >= 1
 * Output: one TraceRow per i = 1..n. Row i = 1 holds the values before the
 *         loop; row i (i >= 2) holds prev/curr after iteration i runs.
 *
 * TODO (Plan step 2):
 *   - push {1, 0, 1} for the starting state
 *   - run the same loop as iterativeFibonacci, pushing {i, prev, curr} each step
 */
std::vector<TraceRow> traceFibonacci(int n) {
    (void)n;
    return {};
}
