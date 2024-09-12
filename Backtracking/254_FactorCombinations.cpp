#include <cmath>
#include <fmt/ranges.h>
#include <vector>
using namespace std;

class Solution
{
public:
    static bool isPrime(const int n)
    {
        // O(sqrt(n))
        for (int d = 2; d < std::sqrt(n) + 1; ++d) {
            if (n % d == 0)
                return false;
        }
        return true;
    }

    vector<vector<int>> getFactors(const int n)
    {
        if (isPrime(n))
            return {};

        vector<vector<int>> allFactors;
        for (int divisor = 2; divisor < n; ++divisor) {
            if (n % divisor == 0) {
                // divisible by d
                int quotient = n / divisor;
                allFactors.push_back({divisor > quotient ? quotient : divisor,
                                      divisor > quotient ? divisor : quotient});
                for (auto &f : getFactors(quotient)) {
                    if (!f.empty()) {
                        f.push_back(divisor);
                        ranges::sort(f);
                        allFactors.push_back(f);
                    }
                }
            }
        }
        ranges::sort(allFactors);
        allFactors.erase(ranges::unique(allFactors).begin(), allFactors.end());
        return allFactors;
    }
};

int main()
{
    Solution sol;
    for (int n = 1; n < 30; ++n) {
        fmt::print("n: {} factors: {}\n", n, sol.getFactors(n));
    }
}
