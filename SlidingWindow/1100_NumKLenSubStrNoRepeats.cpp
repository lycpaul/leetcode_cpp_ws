#include <cstring>
#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    std::array<int, 26> charMap;

    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::fill_n(charMap.begin(), charMap.size(), -1);
    }

    int numKLenSubstrNoRepeats(string s, int k)
    {
        if (s.size() < k or k > 26) {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }
        if (k == 1) {
            return s.size();
        }

        int left{0}, right{1};
        charMap[s[left] - 'a'] = left;
        int counts{};
        while (right < s.size()) {
            if (charMap[s[right] - 'a'] >= 0) {
                // reset the left pointer to last repeated char
                left = max(charMap[s[right] - 'a'] + 1, right - k + 2);
                right = left + 1;
                std::fill_n(charMap.begin(), charMap.size(), -1);
                charMap[s[left] - 'a'] = left;
            } else {
                if (right - left + 1 == k) {
                    // sliding windows size reached k
                    ++counts;
                    // contract the window
                    charMap[s[left] - 'a'] = -1;
                    ++left;
                }
                charMap[s[right] - 'a'] = right;
                ++right;
            }
        }
        return counts;
    }

    // using unordered map instead of custom array
    int numKLenSubstrNoRepeatsMap(string s, int k)
    {
        if (s.size() < k or k > 26) {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }
        if (k == 1) {
            return s.size();
        }

        int left{0}, right{1};
        std::unordered_map<char, int> charMap{{s[left], left}};
        int counts{};
        while (right < s.size()) {
            if (charMap.contains(s[right])) {
                // reset the left pointer to last repeated char
                left = max(charMap[s[right]] + 1, right - k + 2);
                right = left + 1;
                charMap.clear();
                charMap[s[left]] = left;
            } else {
                if (right - left + 1 == k) {
                    // sliding windows size reached k
                    ++counts;
                    // contract the window
                    charMap.erase(s[left]);
                    ++left;
                    // printString(s, left, right);
                }
                charMap[s[right]] = right;
                ++right;
            }
        }
        return counts;
    }
};


int main()
{
    Solution sol;
    cout << sol.numKLenSubstrNoRepeats("havefunonleetcode", 5) << endl;
    cout << sol.numKLenSubstrNoRepeats("home", 5) << endl;
}