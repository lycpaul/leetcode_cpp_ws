#include <iostream>
#include <vector>

class Solution
{
public:
    static int rob(const std::vector<int> &nums)
    {
        const auto n = nums.size();
        if (n == 0)
            return nums[0];
        if (n == 1)
            return std::max(nums[0], nums[1]);

        std::vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = std::max(dp[0], nums[1]);
        auto ret = dp[1];

        for (int i = 2; i < n; ++i) {
            dp[i] = std::max(dp[i - 1], nums[i] + dp[i - 2]);
            ret = std::max(ret, dp[i]);
        }
        return ret;
    }
};

int main()
{
    const std::vector num1{1, 2, 3, 1};
    std::cout << Solution::rob(num1) << std::endl;

    const std::vector num2{2, 7, 9, 3, 1};
    std::cout << Solution::rob(num2) << std::endl;

    const std::vector num3{2, 1, 1, 2};
    std::cout << Solution::rob(num3) << std::endl;
}