#include <fmt/ranges.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(const vector<int> &nums)
    {
        if (nums.size() == 1) {
            return 1;
        }
        int flipped{-1};
        int maxCounts{1};
        int offset{0};

        int start{0}, end{0};
        while (end < nums.size()) {
            if (nums[end]) {
                ++end;
            } else if (flipped < 0) {
                flipped = end;
                ++end;
            } else {
                maxCounts = std::max(maxCounts, end - start + offset);
                offset = end - (flipped + 1);
                start = end;
                flipped = -1;
            }
        }
        maxCounts = std::max(maxCounts, end - start + offset);
        return maxCounts;
    }
};

int main()
{
    Solution sol;

    const vector<std::pair<vector<int>, int>> testCases{{{0, 0, 0, 0, 0, 1, 0, 1, 1, 0}, 4},
                                                        {{0, 0}, 1},
                                                        {{0, 0, 1}, 2},
                                                        {{1, 0, 1, 1, 0}, 4},
                                                        {{1, 0, 1, 1, 0, 1}, 4},
                                                        {{1, 1, 0, 1}, 4}};

    for (const auto &[testCase, expected] : testCases) {
        fmt::print("{} ret: {} expected\n",
                   testCase,
                   sol.findMaxConsecutiveOnes(testCase),
                   expected);
    }
}