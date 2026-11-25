# Fibonacci Correctness Proof — Diagrams
See [OUTLINE.md](OUTLINE.md)

## Plan

```mermaid
flowchart TD
  subgraph Code["Check with code"]
    S1["Step 1: iterativeFibonacci<br>src/fibonacci.cpp"]
    S2["Step 2: traceFibonacci + table<br>src/fibonacci.cpp, src/main.cpp"]
    S3["Step 3: run tests<br>tests/test_main.cpp"]
  end
  subgraph Proof["Write the proof"]
    S4["Step 4: Part A.1 meanings<br>writeup/PROOF.md"]
    S5["Step 5: Part B invariant<br>writeup/PROOF.md"]
    S6["Step 6: Part C induction<br>writeup/PROOF.md"]
    S7["Step 7: Part D design answers<br>writeup/PROOF.md"]
    S8["Step 8: Part E reflection<br>writeup/PROOF.md"]
    S9["Step 9: proofread + export"]
  end
  S1 --> S2 --> S3 --> S4 --> S5 --> S6 --> S7 --> S8 --> S9
```
The build order: get the code checking your table first, then write each proof part.

## Code structure

```mermaid
flowchart LR
  main["src/main.cpp<br>main()"]
  tests["tests/test_main.cpp<br>main()"]
  fib["src/fibonacci.cpp<br>iterativeFibonacci(n)"]
  trace["src/fibonacci.cpp<br>traceFibonacci(n)"]
  row["src/fibonacci.h<br>struct TraceRow: i, prev, curr"]
  main -->|calls| fib
  main -->|calls| trace
  tests -->|calls| fib
  tests -->|calls| trace
  trace -->|returns list of| row
```
Which file holds which function, and who calls what.

## Program flow

```mermaid
flowchart TD
  A["Start main"] --> B["traceFibonacci(6)"]
  B --> C["Print i, prev, curr rows"]
  C --> D["n = 0"]
  D --> E{"n up to 10?"}
  E -->|yes| F["Print F(n) = iterativeFibonacci(n)"]
  F --> G["n = n + 1"]
  G --> E
  E -->|no| H["Return 0"]
```
What the helper program does when run: print the table, then F(0) to F(10).

## Algorithm state (the loop)

```mermaid
flowchart TD
  A["Input n"] --> B{"n == 0?"}
  B -->|yes| R0["Return 0"]
  B -->|no| C{"n == 1?"}
  C -->|yes| R1["Return 1"]
  C -->|no| D["prev = 0, curr = 1, i = 2"]
  D --> E{"i up to n?"}
  E -->|yes| F["next = prev + curr"]
  F --> G["prev = curr; curr = next"]
  G --> H["i = i + 1"]
  H --> E
  E -->|no| R2["Return curr"]
```
The algorithm under study. Your invariant is a claim about prev and curr each time the flow reaches the "i up to n?" check.

## Requirements → code

```mermaid
flowchart LR
  R1["A.2 table for n = 6"] --> C1["traceFibonacci"] --> T1["test: trace rows"]
  R2["C base cases"] --> C2["iterativeFibonacci"] --> T2["test: F(0), F(1)"]
  R3["B initialization at i = 2"] --> C2 --> T3["test: F(2)"]
  R4["Correct F(n)"] --> C2 --> T4["test: F(6), F(10)"]
  R5["A.1, B, C, D, E written parts"] --> W["writeup/PROOF.md"]
```
Each requirement, the code or file that covers it, and the test that checks it. The written parts have no test; only you can check them.
