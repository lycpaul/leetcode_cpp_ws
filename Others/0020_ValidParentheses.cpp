#include <fmt/ranges.h>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    static bool isValid(string s)
    {
        static std::unordered_map<char, char> closeMap{{')', '('}, {']', '['}, {'}', '{'}};
        static std::set<char> open{'(', '[', '{'};
        std::stack<char> brackets;
        for (const auto &c : s) {
            if (open.contains(c)) {
                brackets.push(c);
            } else {
                // check the last open bracket
                if (!brackets.empty() and brackets.top() == closeMap[c]) {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }
        return brackets.empty();
    }
};

int main()
{
    std::vector<string> testCases{"()", "()[]{}", "(]", "([])", "]"};
    for (const auto &test : testCases) {
        fmt::print("{:s}: {}\n", test, Solution::isValid(test));
    }
}