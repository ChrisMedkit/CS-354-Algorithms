# Proving Correctness of an Iterative Fibonacci Algorithm

> Write every answer in complete sentences. Use F(k) notation the same way everywhere.
> Code output and test runs do **not** count as proof.

## Part A — Understanding the Algorithm State

### A.1 What each variable represents
- `prev`: TODO — connect to F(k).
- `curr`: TODO — connect to F(k).
- `next`: TODO — connect to F(k).

### A.2 Table for n = 6

| i | prev | curr |
|---|------|------|
| 1 |  |  |
| 2 |  |  |
| 3 |  |  |
| 4 |  |  |
| 5 |  |  |
| 6 |  |  |

TODO: one sentence saying what row i means (before or after iteration i).

## Part B — Loop Invariant

**Invariant:** TODO — state exactly what `prev` and `curr` equal at the start of each iteration i.

**Initialization:** TODO

**Maintenance:** TODO

**Termination:** TODO — show the invariant gives `curr = F(n)` when the loop ends.

## Part C — Inductive Proof of Correctness

**Claim:** For all integers n ≥ 0, IterativeFibonacci(n) returns F(n).

**Base cases:** TODO (n = 0 and n = 1)

**Induction hypothesis:** TODO

**Inductive step:** TODO — reference the loop body and use the hypothesis explicitly.

**Conclusion:** TODO

## Part D — Reasoning About Design Choices

1. **Why does the loop begin at i = 2?** TODO — reference your invariant.
2. **What fails if the loop started at i = 1?** TODO — name the proof step that breaks.
3. **Would different initial `prev`/`curr` still be correct?** TODO — justify.

## Part E — Reflection (≤ 150 words)

TODO: Why are loop invariants more powerful than tracing sample executions?

Word count: TODO
