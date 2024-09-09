/**
 * Maximum Subarray Sum – Kadane’s Algorithm
 * https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 * @param max_ending_here that stores the maximum sum contiguous subarray ending at current index
 * @param max_so_far stores the maximum sum of contiguous subarray found so far
 * @brief positive-sum value in max_ending_here compare it with max_so_far and update max_so_far if
 * it is greater than max_so_far
 *
 *
Kadane's Algorithm is a dynamic programming technique used to find the maximum subarray sum in an
array of numbers. The algorithm maintains two variables: max_current represents the maximum sum
ending at the current position, and max_global represents the maximum subarray sum encountered so
far. At each iteration, it updates max_current to include the current element or start a new
subarray if the current element is larger than the accumulated sum. The max_global is updated if
max_current surpasses its value.
 */

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &nums)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (const int i : nums) {
        max_ending_here += i;
        max_so_far = max(max_so_far, max_ending_here);
        max_ending_here = max(max_ending_here, 0);
    }
    return max_so_far;
}

/**
 * @brief DP[i] stores the maximum possible Largest Sum Contiguous Subarray ending at index i,
 * DP[i] = max(DP[i-1] + arr[i] , arr[i] )
 */
int maxSubArraySumDynProg(vector<int> &nums)
{
    std::vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int ret = dp[0];
    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        ret = max(ret, dp[i]);
    }
    return ret;
}

// Driver Code
int main()
{
    vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "Maximum contiguous sum is " << maxSubArraySum(nums);
    return 0;
}