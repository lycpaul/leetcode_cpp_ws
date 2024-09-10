#include <fmt/ranges.h>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // [A] using ranges
        const auto [first, last] = ranges::remove(nums, 0);
        ranges::fill(first, nums.end(), 0);

        // [B] using two pointers
        // auto nz = nums.begin();
        // for (auto it = nums.begin(); it != nums.end(); ++it) {
        //     if (*it != 0) {
        //         std::swap(*it, *nz);
        //         ++nz;
        //     }
        // }
        // ranges::fill(nz, nums.end(), 0);
    }
};

int main()
{
    Solution sol;

    // TEST CASE
    std::vector<int> nums1{0, 1, 0, 3, 12};
    std::vector<int> nums2{0};

    for (auto num : {nums1, nums2}) {
        fmt::print("Before: {}\n", fmt::join(nums1, ", "));
        sol.moveZeroes(nums1);
        fmt::print("After: {}\n\n", fmt::join(nums1, ", "));
    }
}