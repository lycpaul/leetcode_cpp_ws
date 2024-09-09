#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    std::unordered_map<char, int> charSet{};

    Solution()
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        charSet.reserve(50);
    }

    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        // charSet.clear();
        if (k == 0)
            return 0;
        // left right pointer
        int left = 0, right = 1;

        // init cond
        int max_length = 1, curr_length = 1;
        charSet[s[0]] = 1;

        while (left <= right and right < s.size()) {
            // update condition
            if (charSet.contains(s[right])) {
                // existed char
                ++charSet[s[right]];
                ++right;
                max_length = max(max_length, ++curr_length);
            } else if (charSet.size() < k) {
                // add new char
                charSet[s[right]] = 1;
                ++right;
                max_length = max(max_length, ++curr_length);
            } else if (charSet.size() == k) {
                // more than two distinct char, advancing left pointer
                if (--charSet[s[left]] == 0) {
                    charSet.erase(s[left]);
                }
                --curr_length;
                ++left;
            }
        }
        return max_length;
    }
};

int main()
{
    Solution sol;
    cout << sol.lengthOfLongestSubstringKDistinct("ece", 2) << endl;
    cout << sol.lengthOfLongestSubstringKDistinct("ccaaabb", 1) << endl;
}