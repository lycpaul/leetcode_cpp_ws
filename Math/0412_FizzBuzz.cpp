#include <fmt/core.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(size_t n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        vector<string> ret{n, ""};
        for (int i = 1; i <= n; ++i) {
            // divisible by 3
            if (i % 3 == 0 and i % 5 == 0) {
                ret[i - 1] = "FizzBuzz";
            } else if (i % 3 == 0) {
                ret[i - 1] = "Fizz";
            } else if (i % 5 == 0) {
                ret[i - 1] = "Buzz";
            } else {
                ret[i - 1] = std::to_string(i);
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    for (auto ret = sol.fizzBuzz(15); const auto &s : ret) {
        fmt::print("{:s}, ", s);
    }
}