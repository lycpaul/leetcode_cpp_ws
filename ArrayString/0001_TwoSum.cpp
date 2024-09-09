#include <fmt/printf.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    // the basic brute force version
    vector<int> twoSumBF(vector<int> &nums, int target)
    {
        for (auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
            auto it2 = std::find(it1 + 1, nums.end(), target - *it1);
            if (it2 != nums.end())
                return {static_cast<int>(it1 - nums.begin()), static_cast<int>(it2 - nums.begin())};
        }
        return {};
    }

    // One-pass has table
    vector<int> twoSumOnePassHash(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash.contains(complement)) {
                return {i, hash[complement]};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution sol;

    // test cases
    std::pair<vector<int>, int> test1 = {{11, 15, 2, 7}, 9};
    std::pair<vector<int>, int> test2 = {{3, 2, 4}, 6};
    std::pair<vector<int>, int> test3 = {{3, 3}, 6};

    for (auto [nums, target] : {test1, test2, test3}) {
        fmt::print("nums: {} target: {} Output: {}\n",
                   fmt::join(nums, ", "),
                   target,
                   fmt::join(sol.twoSumOnePassHash(nums, target), ", "));
    }
}
