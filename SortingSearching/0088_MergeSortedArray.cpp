#include <fmt/core.h>
#include <vector>

class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        auto i = m - 1;
        auto j = n - 1;
        auto k = m + n - 1;
        // O(m+n)
        while (i >= 0 and j >= 0) {
            // fill up the last n value (biggest n) in the nums1 list
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        // O(n)
        while (j >= 0)
            // fill up the remaining terms of nums2 to nums1 (if any)
            nums1[k--] = nums2[j--];
    }
};

int main()
{
    std::vector<std::pair<std::vector<int>, std::vector<int>>> testCases;
    testCases.emplace_back(std::vector<int>{1, 2, 3, 4, 5, 0, 0, 0}, std::vector<int>{2, 5, 6});
    testCases.emplace_back(std::vector<int>{1, 2, 3, 0, 0, 0}, std::vector<int>{2, 5, 6});
    testCases.emplace_back(std::vector<int>{1}, std::vector<int>{});
    testCases.emplace_back(std::vector<int>{0}, std::vector<int>{1});

    Solution sol;
    // test 1
    for (auto &[nums1, nums2] : testCases) {
        sol.merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
        fmt::print("nums1: {}\n", fmt::join(nums1, ", "));
        fmt::print("nums2: {}\n\n", fmt::join(nums2, ", "));
    }
}
