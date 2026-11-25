# Construct Binary Tree — Algorithms
See [DIAGRAM.md](DIAGRAM.md) for diagrams.
**Due:** not stated  ·  **Language:** C++20  ·  **Points:** not stated

## Summary
Given the preorder and inorder traversals of a binary tree with unique values, rebuild the tree and return it. Answer three questions: what algorithm to use, why, and pseudocode. The C++ project lets you check the pseudocode against the examples.

## Requirements
- [ ] Q1: name a good algorithm
- [ ] Q2: explain why it works / why it is a good choice
- [ ] Q3: write pseudocode that solves it
- [ ] `buildTree(preorder, inorder)` returns the tree
- [ ] Example 1: preorder [3,9,20,15,7], inorder [9,3,15,20,7] → [3,9,20,null,null,15,7]
- [ ] Example 2: preorder [-1], inorder [-1] → [-1]
- [ ] Handles constraints: 1 ≤ n ≤ 3000, values −3000..3000, all unique
- [ ] Submission: answers in `ANSWERS.md` (format/where to submit not stated)

## Plan
1. Work Example 1 by hand on paper: find the root, split inorder, repeat
2. Build the value → inorder-index map in `buildTree`
3. Write the recursive range helper in `src/tree.cpp`
4. Write `serializeLevelOrder` and `freeTree` so you can see and clean up results
5. Run tests: both examples plus left-only and right-only chains
6. Write Q1–Q3 in `ANSWERS.md`, with pseudocode matching your code

## Files
| File | Purpose |
|---|---|
| `ANSWERS.md` | Q1–Q3 write-up |
| `src/tree.h` / `src/tree.cpp` | `TreeNode`, `buildTree`, `serializeLevelOrder`, `freeTree` |
| `src/main.cpp` | Runs Example 1 and prints the tree |
| `tests/test_main.cpp` | Example and edge-case checks |
| `assignment/` | Original assignment page |

## Key concepts
- **Preorder** = root, left subtree, right subtree. So the first value of any subtree's slice is its root.
- **Inorder** = left subtree, root, right subtree. Once you know the root, everything to its left is the left subtree.
- **Divide and conquer:** the same split works on each subtree, so recursion fits.
- **Unique values** make the root's position in inorder unambiguous; a hash map finds it in O(1), giving O(n) total instead of O(n²).
- **Order matters:** consume preorder left subtree before right.

## Testing
- Example 1 → [3,9,20,null,null,15,7]
- Example 2 (one node) → [-1]
- Left-skewed: pre [1,2,3], in [3,2,1] → [1,2,null,3]
- Right-skewed: pre [1,2,3], in [1,2,3] → [1,null,2,null,3]
- Large n (3000, skewed) — recursion depth 3000 should still be fine; mention it if asked about limits

## Questions / ambiguities
- Is code required, or only the three answers? (The page asks only Q1–Q3.)
- Due date, points, and submission format are not stated.
