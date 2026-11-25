// Minimal test runner: no external libraries needed.
#include <iostream>

#include <algorithm>
#include <string>
#include <vector>

#include "anagrams.h"

static int failures = 0;
#define CHECK(expr)                                                             \
    do {                                                                        \
        if (!(expr)) {                                                          \
            std::cerr << "FAIL " << __FILE__ << ":" << __LINE__ << "  " #expr "\n"; \
            ++failures;                                                         \
        }                                                                       \
    } while (0)

using Groups = std::vector<std::vector<std::string>>;

// Output may be in any order: sort words in each group, then sort groups.
static Groups normalize(Groups g) {
    for (auto& group : g) std::sort(group.begin(), group.end());
    std::sort(g.begin(), g.end());
    return g;
}

int main() {
    // Example 1
    CHECK(normalize(groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"})) ==
          normalize({{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}));

    // Example 2: single empty string
    CHECK(normalize(groupAnagrams({""})) == normalize({{""}}));

    // Example 3: single letter
    CHECK(normalize(groupAnagrams({"a"})) == normalize({{"a"}}));

    // Edge: same letters, different counts are NOT anagrams
    CHECK(normalize(groupAnagrams({"aab", "abb"})) == normalize({{"aab"}, {"abb"}}));

    // Edge: duplicates stay together
    CHECK(normalize(groupAnagrams({"ab", "ba", "ab"})) == normalize({{"ab", "ab", "ba"}}));

    if (failures == 0) std::cout << "All tests passed\n";
    return failures == 0 ? 0 : 1;
}
