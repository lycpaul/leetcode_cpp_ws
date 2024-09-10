#include <vector>
#include <fmt/ranges.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> anagramMappings(vector<int> &nums1, vector<int> &nums2)
    {
        std::unordered_map<int, vector<int>> numsMap;
        std::vector<int> mappings;

        for (int i = 0; i < nums2.size(); ++i) {
            numsMap[nums2[i]].push_back(i);
        }

        for (int i : nums1) {
            auto &numsRef = numsMap[i];
            mappings.push_back(numsRef.back());
            numsRef.pop_back();
        }
        return mappings;
    }
};


int main()
{
    Solution sol;

    vector<int> nums1{12, 28, 46, 32, 50};
    vector<int> nums2{50, 12, 32, 46, 28};
    auto ret = sol.anagramMappings(nums1, nums2);
    fmt::print("{}", fmt::join(ret, ", "));
}