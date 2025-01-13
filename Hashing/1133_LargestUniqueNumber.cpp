#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int largestUniqueNumber(vector<int> &nums)
    {
        // sort the nums first
        ranges::sort(nums, std::greater<int>());
        // drop all the duplicates
        std::unordered_map<int, int> hash;
        for (const auto &num : nums) {
            hash[num]++;
        }
        for (const auto &num : nums) {
            if (hash[num] == 1)
                return num;
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1{5, 7, 3, 9, 4, 9, 8, 3, 1};
    vector<int> nums2{9, 9, 8, 8};

    for (auto nums : {nums1, nums2}) {
        auto ret = sol.largestUniqueNumber(nums);
        fmt::print("{}\n", ret);
    }
}