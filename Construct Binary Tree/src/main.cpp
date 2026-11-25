#include <iostream>
#include <vector>

#include "tree.h"

// Print a serialized tree like [3,9,20,null,null,15,7].
static void printTree(const TreeNode* root) {
    auto out = serializeLevelOrder(root);
    std::cout << '[';
    for (size_t i = 0; i < out.size(); ++i) {
        if (i) std::cout << ',';
        if (out[i]) std::cout << *out[i];
        else std::cout << "null";
    }
    std::cout << "]\n";
}

int main() {
    // Example 1 from the assignment. TODO: read arrays from input if your class wants that.
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);
    printTree(root);  // expected [3,9,20,null,null,15,7]
    freeTree(root);
    return 0;
}
