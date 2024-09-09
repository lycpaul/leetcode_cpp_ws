#include <fmt/printf.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        if (digits.empty()) {
            return {1};
        }
        // Add 1 to the last digit
        digits[digits.size() - 1] += 1;
        if (digits[digits.size() - 1] < 10) {
            return digits;
        }

        vector<int> sub = {digits.begin(), digits.end() - 1};
        auto result = plusOne(sub);
        result.push_back(0);
        return result;
    }
};

int main()
{
    Solution sol;

    // test case 1
    vector<int> digits = {1, 2, 3};
    fmt::print("Before: {}\n", fmt::join(sol.plusOne(digits), ", "));

    // test case 2
    digits = {4, 3, 2, 1};
    fmt::print("Before: {}\n", fmt::join(sol.plusOne(digits), ", "));

    // test case 3
    digits = {9, 9, 9};
    fmt::print("Before: {}\n", fmt::join(sol.plusOne(digits), ", "));
    return 0;
}
