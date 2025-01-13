#include <cmath>
#include <fmt/ranges.h>
#include <vector>
using namespace std;

class Solution
{
public:
    void backtracking(vector<int> &factors, vector<vector<int>> &ans, const int n)
    {
        if (factors.size() > 1) {
            ans.push_back(factors);
        }
        auto lastFactor = factors.back();
        factors.pop_back();

        // replace the lastFactor
        for (int i = factors.empty() ? 2 : factors.back(); i <= lastFactor / i; ++i) {
            if (lastFactor % i == 0) {
                factors.push_back(i);
                factors.push_back(lastFactor / i);
                backtracking(factors, ans, n);
                // restore back the factors list
                factors.pop_back();
                factors.pop_back();
            }
        }
        factors.push_back(lastFactor);
    }

    vector<vector<int>> getFactors(const int n)
    {
        // list of factors
        vector<int> factors{n};
        vector<vector<int>> ans{};
        backtracking(factors, ans, n);
        return ans;
    }
};

int main()
{
    Solution sol;
    for (int n = 1; n < 30; ++n) {
        fmt::print("n: {} factors: {}\n", n, sol.getFactors(n));
    }
}
