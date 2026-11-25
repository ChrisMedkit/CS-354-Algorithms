# Group Anagrams — Diagrams
See [OUTLINE.md](OUTLINE.md)

## Plan

```mermaid
flowchart TD
  S1["Step 1: choose the shared key<br>src/anagrams.cpp"]
  S2["Step 2: map key to word list<br>src/anagrams.cpp"]
  S3["Step 3: collect lists<br>src/anagrams.cpp"]
  S4["Step 4: run tests<br>tests/test_main.cpp"]
  S5["Step 5: write answers<br>ANSWERS.md"]
  S1 --> S2 --> S3 --> S4 --> S5
```
Build order from key choice to the write-up.

## Code structure

```mermaid
flowchart LR
  main["src/main.cpp<br>main()"]
  tests["tests/test_main.cpp<br>main(), normalize()"]
  f["src/anagrams.cpp<br>groupAnagrams(strs)"]
  main -->|calls| f
  tests -->|calls| f
```
Files and the one function they share.

## Program flow

```mermaid
flowchart TD
  A["Start: empty map key to list"] --> B{"More words?"}
  B -->|yes| C["key = signature of word"]
  C --> D["Append word to map at key"]
  D --> B
  B -->|no| E["Return every list in the map"]
```
What `groupAnagrams` does at runtime.

## Map shape (Example 1)

```mermaid
flowchart LR
  K1["key for eat"] --> L1["eat, tea, ate"]
  K2["key for tan"] --> L2["tan, nat"]
  K3["key for bat"] --> L3["bat"]
```
Each key points to its group; the result is the three lists on the right.

## Requirements → code

```mermaid
flowchart LR
  R1["Group anagrams"] --> C["groupAnagrams"]
  R2["Any order"] --> N["normalize (test helper)"]
  R3["Empty string"] --> C
  C --> T1["test: Example 1"]
  C --> T2["test: Example 2 empty"]
  C --> T3["test: Example 3 single"]
  C --> T4["test: counts and duplicates"]
  N --> T1
  R4["Algorithm / why / pseudocode"] --> W["ANSWERS.md"]
```
Each requirement, the code that meets it, and the tests.
