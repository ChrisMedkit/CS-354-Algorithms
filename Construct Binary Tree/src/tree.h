#pragma once

#include <optional>
#include <vector>

// Binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Build the tree from its preorder and inorder traversals (unique values).
TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder);

// Level-order output like the examples: [3,9,20,null,null,15,7].
// Trailing nulls are dropped. nullopt means "null".
std::vector<std::optional<int>> serializeLevelOrder(const TreeNode* root);

// Delete every node in the tree.
void freeTree(TreeNode* root);
