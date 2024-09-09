#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }

    static int lengthOfLongestSubstringTwoDistinct(string s)
    {
        // left right pointer
        int left = 0, right = 1;

        // init cond
        int max_length = 1, curr_length = 1;
        std::pair<char, int> charA{s[0], 1};
        std::pair<char, int> charB{'0', 0};

        while (left < right and right < s.size()) {
            if (charA.first == s[right]) {
                // existed char
                ++charA.second;
                ++right;
                max_length = max(max_length, ++curr_length);
            } else if (charB.first == s[right]) {
                // existed char
                ++charB.second;
                ++right;
                max_length = max(max_length, ++curr_length);
            } else if (charA.first != '0' and charB.first == '0') {
                // add new char to B
                charB.first = s[right];
                charB.second = 1;
                ++right;
                max_length = max(max_length, ++curr_length);
            } else if (charA.first == '0' and charB.first != '0') {
                // add new char to A
                charA.first = s[right];
                charA.second = 1;
                ++right;
                max_length = max(max_length, ++curr_length);
            } else {
                // more than two distinct char, advancing left pointer
                if (charA.first == s[left]) {
                    if (--charA.second == 0) {
                        charA.first = '0';
                    }
                } else {
                    if (--charB.second == 0) {
                        charB.first = '0';
                    }
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
    cout << Solution::lengthOfLongestSubstringTwoDistinct("ece") << endl;
    cout << Solution::lengthOfLongestSubstringTwoDistinct("ccaabb") << endl;
}