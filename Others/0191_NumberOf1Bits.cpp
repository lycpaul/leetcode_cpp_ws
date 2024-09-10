#include <fmt/ranges.h>
#include <iostream>

using namespace std;
class Solution
{
public:
    static int hammingWeight(const int n)
    {
        int counts{};
        auto bit = [](const int i, const int shift) -> bool { return i & 1 << shift; };
        for (int i = 0; i < 32; ++i) {
            counts += bit(n, i);
        }
        return counts;
    }
};

int main()
{
    auto bit = [](const int i, const int shift) -> bool { return i & 1 << shift; };
    auto bit8 = [](const int i) -> bool { return i & 0b000010000000; };
    auto bit7 = [](const int i) -> bool { return i & 0b000001000000; };
    fmt::print("{} {} {}\n", bit(128, 8), bit8(128), bit7(128));
    fmt::print("{}", Solution::hammingWeight(128));
}