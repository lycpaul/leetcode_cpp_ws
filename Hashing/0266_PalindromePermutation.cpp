#include <vector>
#include <fmt/ranges.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        std::unordered_map<char, int> charFreq{};
        for (const auto &c : s) {
            ++charFreq[c];
        }
        int oddCase = 0;
        for (const auto &[c, freq] : charFreq) {
            if (freq % 2 == 1) {
                ++oddCase;
            }
        }
        return oddCase <= 1;
    }
};


int main()
{
    Solution sol;
    auto ret = sol.canPermutePalindrome("carerac");
    fmt::print("{}", ret);
}