#include <bits/stdc++.h>
#include <iostream>
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (const int curProfit = prices[i] - buy; curProfit > profit) {
                profit = curProfit;
            }
        }
        return profit;
    }
};

int main(const int argc, const char *const *const argv)
{
    std::vector<std::string_view> args(argv, std::next(argv, static_cast<std::ptrdiff_t>(argc)));

    Solution sol;

    std::vector<int> p1{7, 1, 5, 3, 6, 4};
    std::cout << sol.maxProfit(p1) << std::endl;
}