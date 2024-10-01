#include <cmath>
#include <fmt/format.h>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string stringShift(const string &s, vector<vector<int>> &shifts)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        string ret = s;
        // aggregate all shift operators
        int totalShifts = 0; // left +ve, right -ve
        for (const auto &shift : shifts) {
            totalShifts += (shift[0] == 0 ? 1 : -1) * shift[1];
        }
        totalShifts = copysign(abs(totalShifts) % s.size(), totalShifts);
        // cout << totalShifts << endl;

        // shift the string
        if (totalShifts > 0) {
            ret = s.substr(totalShifts) + s.substr(0, totalShifts);
        } else if (totalShifts < 0) {
            ret = s.substr(s.size() + totalShifts) + s.substr(0, s.size() + totalShifts);
        }

        return ret;
    }
};

int main()
{
    std::pair<string, std::vector<vector<int>>>
        testCases{"joiazl", {{1, 1}, {1, 6}, {0, 1}, {1, 3}, {1, 0}, {0, 3}}};
    Solution sol;
    fmt::print("{}", sol.stringShift(testCases.first, testCases.second));
}