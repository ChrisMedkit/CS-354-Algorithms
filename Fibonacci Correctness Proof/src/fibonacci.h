#pragma once

#include <vector>

// One row of the Part A trace table: values of prev and curr at step i.
struct TraceRow {
    int i;
    long long prev;
    long long curr;
};

// IterativeFibonacci(n) exactly as given in the assignment. Returns F(n), n >= 0.
long long iterativeFibonacci(int n);

// Records prev/curr for i = 1..n so the Part A table can be printed/checked.
std::vector<TraceRow> traceFibonacci(int n);
