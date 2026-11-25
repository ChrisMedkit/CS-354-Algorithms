# Group Anagrams — Algorithms
See [DIAGRAM.md](DIAGRAM.md) for diagrams.
**Due:** not stated  ·  **Language:** C++20  ·  **Points:** not stated

## Summary
Given an array of lowercase words, group the words that are anagrams of each other (same letters, same counts, any order). Groups and their contents may be returned in any order.

## Requirements
- [ ] `groupAnagrams(strs)` returns the groups of anagrams
- [ ] Example 1: ["eat","tea","tan","ate","nat","bat"] → [["bat"],["nat","tan"],["ate","eat","tea"]]
- [ ] Example 2: [""] → [[""]]
- [ ] Example 3: ["a"] → [["a"]]
- [ ] Any output order accepted
- [ ] Constraints: 1 ≤ strs.length ≤ 10⁴, 0 ≤ word length ≤ 100, lowercase letters only
- [ ] Write-up in `ANSWERS.md` if your class asks for algorithm / why / pseudocode
- [ ] Submission: format and where to submit not stated

## Plan
1. Choose the key that all anagrams share
2. Fill a map from key → list of words
3. Collect the lists into the result
4. Run tests: the three examples, different letter counts, duplicates
5. Fill `ANSWERS.md`

## Files
| File | Purpose |
|---|---|
| `ANSWERS.md` | Algorithm / why / pseudocode write-up |
| `src/anagrams.h` / `src/anagrams.cpp` | `groupAnagrams` stub |
| `src/main.cpp` | Runs Example 1 and prints groups |
| `tests/test_main.cpp` | Example and edge checks (order-independent) |
| `assignment/` | Original assignment page |

## Key concepts
- **Canonical key:** two words are anagrams exactly when some "signature" of them matches. Common signatures: the letters sorted, or the count of each of the 26 letters.
- **Hash map grouping:** a map from signature to list puts each word in its group in one pass.
- **Cost:** sorting each word costs O(k log k) for length k; letter counts cost O(k). Total is about n times that.
- **Edge cases:** the empty string has an empty signature and is its own group; duplicate words go in the same group.

## Testing
- Example 1, 2, 3 (compare after sorting, since order is free)
- "aab" vs "abb": same letters, different counts → separate groups
- Duplicates: ["ab","ba","ab"] → one group of three
- 10⁴ words of length 100 should run quickly

## Questions / ambiguities
- The page gives the problem only. Does it also want "algorithm / why / pseudocode" like the others, or working code?
- Due date, points, and submission format are not stated.
