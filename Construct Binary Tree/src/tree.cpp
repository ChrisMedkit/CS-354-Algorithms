#include "tree.h"

/**
 * buildTree — construct and return the binary tree.
 * Input:  preorder, inorder (same length, 1..3000, unique values)
 * Output: pointer to the root (caller frees with freeTree)
 *
 * TODO (Plan step 2): map each value -> its index in inorder.
 * TODO (Plan step 3): recursive helper over an inorder range [lo, hi]:
 *   - empty range -> nullptr
 *   - next preorder value is this subtree's root
 *   - split the range at the root's inorder index
 *   - build left subtree first, then right (preorder order)
 */
TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
    (void)preorder;
    (void)inorder;
    return nullptr;
}

/**
 * serializeLevelOrder — turn a tree into the example output format.
 * Input:  root (may be nullptr)
 * Output: values in level order, nullopt for missing children, no trailing nulls
 *
 * TODO (Plan step 4): breadth-first walk with a queue; push children even when
 *   null; at the end pop trailing nullopt entries.
 */
std::vector<std::optional<int>> serializeLevelOrder(const TreeNode* root) {
    (void)root;
    return {};
}

/**
 * freeTree — delete all nodes.
 * TODO (Plan step 4): post-order delete (children before parent).
 */
void freeTree(TreeNode* root) {
    (void)root;
}
