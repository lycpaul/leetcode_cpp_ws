#include <fmt/ranges.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // boundary case
        if (strs.size() == 1) {
            return strs[0];
        }
        int n = 200;
        for (std::string_view str : strs) {
            n = std::min(n, static_cast<int>(str.size()));
        }
        int i = 0;
        for (; i < n; ++i) {
            bool matched = true;
            for (int j = 0; j < strs.size() - 1; ++j) {
                matched &= strs[j][i] == strs[j + 1][i];
                if (not matched)
                    return strs[0].substr(0, i);
            }
        }
        // boundary case n=0
        if (n == 0 or i == 0) {
            return "";
        }
        return strs[0].substr(0, i);
    }
};

int main()
{
    Solution sol;
    std::vector<string> strs1 = {"flower", "flow", "flight"};
    std::vector<string> strs2 = {"dog", "racecar", "car"};
    std::vector<string> strs3 = {"a"};
    std::vector<string> strs4 = {"a", "ab"};

    for (vector<string> str : {strs1, strs2, strs3, strs4}) {
        fmt::print("set: [{}] longestCommonPrefix: {}\n",
                   fmt::join(str, ","),
                   sol.longestCommonPrefix(str));
    }
}
