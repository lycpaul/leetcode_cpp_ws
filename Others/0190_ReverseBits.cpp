#include <fmt/ranges.h>
class Solution
{
public:
    static uint32_t reverseBits(const uint32_t n)
    {
        auto maskedMSBShift = [](const uint32_t num, const int idx) {
            const int shift = 31 - 2 * idx;
            const int bitMask = 0b1 << 31 - idx;
            return num >> shift & bitMask >> shift;
        };
        auto maskedLSBShift = [](const uint32_t num, const int idx) {
            const int shift = 31 - 2 * idx;
            const int bitMask = 0b1 << idx;
            return num << shift & bitMask << shift;
        };

        uint32_t ret{};
        // MSB to LSB
        for (int i = 0; i < 16; ++i) {
            ret += maskedMSBShift(n, i);
        }
        // LSB to MSB
        for (int i = 0; i < 16; ++i) {
            ret += maskedLSBShift(n, i);
        }
        return ret;
    }
};

int main()
{
    fmt::print("0b{:b}\n", 0b00000010100101000001111010011100);
    fmt::print("0b{:b}\n", Solution::reverseBits(0b00000010100101000001111010011100));
}