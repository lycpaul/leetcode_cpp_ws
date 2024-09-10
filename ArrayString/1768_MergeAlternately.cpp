#include <fmt/ranges.h>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        auto it1 = word1.begin();
        auto it2 = word2.begin();

        while (it2 != word2.end()) {
            if (it1 != word1.end())
                ++it1;
            it1 = word1.insert(it1, *it2);
            if (it1 != word1.end())
                ++it1;
            ++it2;
        }
        return word1;
    }
};

int main()
{
    Solution sol;

    // test cases
    std::pair<string, string> test1 = {"abc", "pqr"};
    std::pair<string, string> test2 = {"ab", "pqrs"};
    std::pair<string, string> test3 = {"abcd", "pq"};
    std::pair<string, string> test4 = {"dajmknzgidixqgt", "nahamebx"};

    for (auto test : {test4, test1, test2, test3}) {
        auto result = sol.mergeAlternately(test.first, test.second);
        fmt::print("Before: {} {} After: {}\n", test.first, test.second, result);
    }
}
