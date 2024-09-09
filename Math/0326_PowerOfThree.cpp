#include <cmath>
#include <iostream>

class Solution
{
    static constexpr double LOG3 = std::log(3);

public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        double power = log(n) / LOG3;
        return std::fabs(power - std::round(power)) < 1e-6;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.isPowerOfThree(27) << std::endl;
    std::cout << sol.isPowerOfThree(28) << std::endl;
    std::cout << sol.isPowerOfThree(243) << std::endl;
}