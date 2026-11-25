# Construct Binary Tree — Diagrams
See [OUTLINE.md](OUTLINE.md)

## Plan

```mermaid
flowchart TD
  S1["Step 1: solve Example 1 by hand"]
  S2["Step 2: value to index map<br>src/tree.cpp"]
  S3["Step 3: recursive range helper<br>src/tree.cpp"]
  S4["Step 4: serializeLevelOrder, freeTree<br>src/tree.cpp"]
  S5["Step 5: run tests<br>tests/test_main.cpp"]
  S6["Step 6: write Q1 to Q3<br>ANSWERS.md"]
  S1 --> S2 --> S3 --> S4 --> S5 --> S6
```
Build order from hand-worked example to written answers.

## Code structure

```mermaid
classDiagram
  class TreeNode {
    +int val
    +TreeNode left
    +TreeNode right
    +TreeNode(int v)
  }
  class tree_cpp {
    <<functions>>
    +buildTree(vector~int~ preorder, vector~int~ inorder) TreeNode
    +serializeLevelOrder(TreeNode root) vector~optional~
    +freeTree(TreeNode root) void
  }
  TreeNode --> TreeNode : left, right (pointers)
  tree_cpp ..> TreeNode : creates / reads / deletes
```
The node struct and the free functions in `src/tree.cpp`. Fields and returns marked TreeNode are pointers (`TreeNode*`) in the code.

## Program flow

```mermaid
flowchart TD
  A["Start main"] --> B["preorder, inorder = Example 1"]
  B --> C["root = buildTree(preorder, inorder)"]
  C --> D["printTree(root) via serializeLevelOrder"]
  D --> E["freeTree(root)"]
  E --> F["Return 0"]
```
What `main` does when run.

## Tree shape (Example 1)

```mermaid
flowchart TD
  N3(("3")) --> N9(("9"))
  N3 --> N20(("20"))
  N20 --> N15(("15"))
  N20 --> N7(("7"))
```
Preorder [3,9,20,15,7] starts with root 3. In inorder [9,3,15,20,7], 9 is left of 3 and 15,20,7 are right.

## Requirements → code

```mermaid
flowchart LR
  R1["Build tree"] --> C1["buildTree"]
  R2["Example 1 output"] --> C1
  R2 --> C2["serializeLevelOrder"]
  C1 --> T1["test: Example 1"]
  R3["Example 2 single node"] --> C1 --> T2["test: Example 2"]
  R4["Skewed trees"] --> C1 --> T3["test: left/right chains"]
  R5["Q1 to Q3"] --> W["ANSWERS.md"]
```
Each requirement, the code that meets it, and its test.
