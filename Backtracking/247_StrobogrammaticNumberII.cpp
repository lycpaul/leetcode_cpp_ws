#include <fmt/ranges.h>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    vector<string_view> oddMiddleSets{"0", "1", "8"};
    vector<string_view> evenMiddleSets{"00", "11", "88", "69", "96"};
    const std::unordered_map<char, char> invertedMap{{'0', '0'},
                                                     {'1', '1'},
                                                     {'6', '9'},
                                                     {'8', '8'},
                                                     {'9', '6'}};

public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    vector<string> findStrobogrammatic(int n)
    {
        if (n == 1) {
            return {"0", "1", "8"};
        }
        if (n == 2) {
            return {"11", "88", "69", "96"};
        }
        // n >= 3
        vector<string> sets{};

        // process the subStr
        for (const auto &s1 : findStrobogrammatic(n % 2 ? n - 1 : n - 2)) {
            for (const auto &s2 : (n % 2 ? oddMiddleSets : evenMiddleSets)) {
                std::string num{s1};
                num.insert(num.begin() + s1.size() / 2, s2.begin(), s2.end());
                sets.push_back(num);
            }
        }
        // TODO: can further optimize it with N/2 size
        return sets;
    }

    bool isStrobogrammatic(const int n)
    {
        const std::string numStr = to_string(n);
        static const std::set invalidSet{'2', '3', '4', '5', '7'};
        bool isValid = true;
        for (int i = 0; i < numStr.size(); ++i) {
            const auto c = numStr[i];
            if (invalidSet.contains(c))
                return false;
            if (numStr[numStr.size() - 1 - i] != invertedMap.at(c))
                isValid = false;
        }
        return isValid;
    }
};

int main()
{
    Solution sol;
    const vector testCases{4, 5, 6};

    for (const auto testCase : testCases) {
        vector<bool> validation{};
        const auto sets = sol.findStrobogrammatic(testCase);
        for (const auto &num : sets) {
            validation.push_back(sol.isStrobogrammatic(stoi(num)));
        }
        fmt::print("{}\n", sets);
        fmt::print("{}\n\n", validation);
    }
}