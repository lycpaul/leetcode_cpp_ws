#include <fmt/printf.h>
#include <set>
#include <string>
#include <unordered_map>

class Solution
{
    static constexpr auto makeRomanParser()
    {
        static std::unordered_map<char, int> roman2Val{{'I', 1},
                                                       {'V', 5},
                                                       {'X', 10},
                                                       {'L', 50},
                                                       {'C', 100},
                                                       {'D', 500},
                                                       {'M', 1000}};
        static std::unordered_map<char, char> subtractionSet{{'V', 'I'},
                                                             {'X', 'I'},
                                                             {'L', 'X'},
                                                             {'C', 'X'},
                                                             {'D', 'C'},
                                                             {'M', 'C'}};
        return [value = 0, prev = ' '](const char c) mutable -> int {
            if (subtractionSet.contains(c) and subtractionSet[c] == prev)
                value += roman2Val[c] - 2 * roman2Val[prev];
            else
                value += roman2Val[c];
            prev = c;
            return value;
        };
    }

public:
    static int romanToInt(const std::string &s)
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
    fmt::print("{}\n", Solution::romanToInt("LVIII"));
    fmt::print("{}\n", Solution::romanToInt("MCMXCIV"));
}