#include <fmt/printf.h>
#include <string>
#include <sys/stat.h>

class Solution
{
    static constexpr auto makeRomanParser()
    {
        enum State { Start, Numbers, Invalid };
        return [value = 0, state = Start, sign = 1](const char input) mutable -> int32_t {
            switch (state) {
            case Start:
                if (input == ' ') {
                    return 0;
                }
                if (input == '-') {
                    sign = -1;
                    state = Numbers;
                    return value;
                }
                if (input == '+') {
                    sign = 1;
                    state = Numbers;
                    return value;
                }
                [[fallthrough]];
            case Numbers:
                if (input >= '0' && input <= '9') {
                    state = Numbers;
                    value = static_cast<int32_t>(
                        std::clamp(static_cast<int64_t>(value) * 10 + sign * (input - '0'),
                                   static_cast<int64_t>(INT_MIN),
                                   static_cast<int64_t>(INT_MAX)));
                    return value;
                }
                [[fallthrough]];
            case Invalid:
                state = Invalid;
                return value;
            default:
                return 0;
            }
        };
    }

public:
    int myAtoi(std::string s)
    {
        auto parser = makeRomanParser();
        int result = 0;
        for (const auto &c : s) {
            result = parser(c);
        }
        return result;
    }
};

int main()
{
    Solution sol;

    // test cases
    std::string s1 = "42";
    std::string s2 = "   -042";
    std::string s3 = "-1337c0d3";
    std::string s4 = "0-1";
    std::string s5 = "words and 987";
    std::string s6 = "-91283472332";
    std::string s7 = "+1";

    for (auto s : {s1, s2, s3, s4, s5, s6, s7}) {
        fmt::print("Before: [{}] After: [{}]\n", s, sol.myAtoi(s));
    }
}
