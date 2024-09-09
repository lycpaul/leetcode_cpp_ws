#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution
{
public:
    int missingNumberBitWise(vector<int> &nums)
    {
        int xorofn = 0;
        int xorofarr = 0;
        for (int i = 1; i <= nums.size(); i++) {
            xorofn ^= i;
            xorofarr ^= nums[i - 1];
        }
        return xorofn ^ xorofarr;
    }

    static int missingNumber(vector<int> &nums)
    {
        const auto n = static_cast<int>(nums.size());
        return (n + 1) * n / 2 - std::accumulate(nums.begin(), nums.end(), 0, std::plus());
    }
};

int main()
{
    std::vector test1{3, 0, 1};
    cout << Solution::missingNumber(test1) << endl;
}