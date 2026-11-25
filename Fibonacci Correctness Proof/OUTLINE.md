# Fibonacci Correctness Proof — Algorithms
See [DIAGRAM.md](DIAGRAM.md) for diagrams.
**Due:** not stated  ·  **Language:** C++20 (code) + written proof  ·  **Points:** not stated

## Summary
Analyze the given `IterativeFibonacci(n)` algorithm and prove it returns F(n) for every n ≥ 0. The main deliverable is a written proof: variable meanings and an n = 6 trace table, a loop invariant with initialization/maintenance/termination, an induction proof, design-choice answers, and a short reflection. The C++ code is only a helper to check your trace table; it does not count as proof.

## Requirements
- [ ] Part A.1: explain in words what `prev`, `curr`, `next` represent, tied to F(k)
- [ ] Part A.2: fill in the i / prev / curr table for n = 6 with correct values
- [ ] Part B.1: state a formal, unambiguous loop invariant about `prev` and `curr` at the start of each iteration
- [ ] Part B.2: prove Initialization, Maintenance, Termination (each labeled and justified)
- [ ] Part B: invariant directly implies correctness when the loop ends
- [ ] Part C: induction proof for all n ≥ 0 with base cases, induction hypothesis, inductive step using the loop
- [ ] Part C: hypothesis used explicitly; no steps skipped
- [ ] Part D: answer the three design questions (start at i = 2, start at i = 1, other initial values), referencing the invariant/proof
- [ ] Part E: reflection, ≤ 150 words, about correctness not efficiency, tied to this assignment
- [ ] Submission: complete sentences, consistent notation; code output/screenshots/tests are not proof

## Plan
1. Implement `iterativeFibonacci` in `src/fibonacci.cpp` exactly as the pseudocode reads
2. Implement `traceFibonacci` and print the n = 6 table with `main`; copy the values into `writeup/PROOF.md` Part A
3. Run the tests (`./build/tests`) to confirm F(0..10) and the table
4. Write Part A.1 (variable meanings) in `writeup/PROOF.md`
5. Write the loop invariant and its three proof steps (Part B)
6. Write the induction proof (Part C)
7. Answer Part D using the invariant from Part B
8. Write the Part E reflection and count words (≤ 150)
9. Proofread for complete sentences and consistent F(k) notation; export to the format your class wants

## Files
| File | Purpose |
|---|---|
| `writeup/PROOF.md` | The real deliverable: Parts A–E with TODO headings |
| `src/fibonacci.h` / `src/fibonacci.cpp` | `iterativeFibonacci` and `traceFibonacci` stubs |
| `src/main.cpp` | Prints the n = 6 table and F(0..10) |
| `tests/test_main.cpp` | Checks base cases, F(6) = 8, and the table |
| `assignment/` | Original assignment pages |

## Key concepts
- **Fibonacci definition:** F(0) = 0, F(1) = 1, F(k) = F(k−1) + F(k−2) for k ≥ 2. Every proof step must come back to this.
- **Loop invariant:** a statement about the variables that is true at the start of every iteration. It needs three parts: true before the first iteration (initialization), kept true by one iteration (maintenance), and useful when the loop stops (termination).
- **Loop bounds:** for `i = 2 to n`, the loop stops when i becomes n + 1. Termination uses that value of i.
- **Induction:** base cases plus "if true for k, then true for k + 1". The inductive step should point to what the loop body does.
- **Edge cases:** n = 0 and n = 1 return before the loop, so they are base cases, not loop cases.

## Testing
- n = 0 → 0, n = 1 → 1 (early returns)
- n = 2 → 1 (loop runs once)
- n = 6 → 8, and the table rows match your Part A table
- n = 10 → 55
- Reminder: passing tests is a check for you, not part of the proof

## Questions / ambiguities
- Part A table lists i = 1..6 but the loop starts at i = 2. Should row i = 1 be the state before the loop, and should rows show values before or after iteration i? State your choice in the write-up.
- Due date, points, and submission format (PDF? Word?) are not stated.
