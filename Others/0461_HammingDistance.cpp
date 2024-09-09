#include <fmt/core.h>
#include <iostream>

using namespace std;
class Solution
{
public:
    static int hammingDistance(const int x, const int y)
    {
        int distance{};
        auto bit = [](const int i, const int j, const int shift) -> bool {
            const auto mask = 1 << shift;
            return (i & mask) != (j & mask);
        };
        for (int i = 0; i < 32; ++i) {
            if (bit(x, y, i))
                ++distance;
        }
        return distance;
    }
};

int main()
{
    auto bit = [](const int i, const int shift) -> bool { return i & 1 << shift; };
    auto bit8 = [](const int i) -> bool { return i & 0b000010000000; };
    auto bit7 = [](const int i) -> bool { return i & 0b000001000000; };
    fmt::print("{} {} {}\n", bit(128, 8), bit8(128), bit7(128));
    fmt::print("{}", Solution::hammingDistance(1, 4));
}