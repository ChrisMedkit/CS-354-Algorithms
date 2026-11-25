// Minimal test runner: no external libraries needed.
#include <iostream>

#include "tree.h"

static int failures = 0;
#define CHECK(expr)                                                             \
    do {                                                                        \
        if (!(expr)) {                                                          \
            std::cerr << "FAIL " << __FILE__ << ":" << __LINE__ << "  " #expr "\n"; \
            ++failures;                                                         \
        }                                                                       \
    } while (0)

using Out = std::vector<std::optional<int>>;

int main() {
    // Example 1
    {
        TreeNode* root = buildTree({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7});
        Out expected = {3, 9, 20, std::nullopt, std::nullopt, 15, 7};
        CHECK(serializeLevelOrder(root) == expected);
        freeTree(root);
    }
    // Example 2: single node
    {
        TreeNode* root = buildTree({-1}, {-1});
        CHECK(serializeLevelOrder(root) == Out{-1});
        freeTree(root);
    }
    // Edge: left-only chain (1 -> 2 -> 3 down the left)
    {
        TreeNode* root = buildTree({1, 2, 3}, {3, 2, 1});
        Out expected = {1, 2, std::nullopt, 3};
        CHECK(serializeLevelOrder(root) == expected);
        freeTree(root);
    }
    // Edge: right-only chain
    {
        TreeNode* root = buildTree({1, 2, 3}, {1, 2, 3});
        Out expected = {1, std::nullopt, 2, std::nullopt, 3};
        CHECK(serializeLevelOrder(root) == expected);
        freeTree(root);
    }

    if (failures == 0) std::cout << "All tests passed\n";
    return failures == 0 ? 0 : 1;
}
