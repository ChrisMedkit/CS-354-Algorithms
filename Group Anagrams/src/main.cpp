#include <iostream>
#include <string>
#include <vector>

#include "anagrams.h"

int main() {
    // Example 1 from the assignment. TODO: read words from input if needed.
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    std::cout << '[';
    bool firstGroup = true;
    for (const auto& group : groupAnagrams(strs)) {
        if (!firstGroup) std::cout << ',';
        firstGroup = false;
        std::cout << '[';
        for (size_t i = 0; i < group.size(); ++i) {
            if (i) std::cout << ',';
            std::cout << '"' << group[i] << '"';
        }
        std::cout << ']';
    }
    std::cout << "]\n";  // expected (any order) [["bat"],["nat","tan"],["ate","eat","tea"]]
    return 0;
}
