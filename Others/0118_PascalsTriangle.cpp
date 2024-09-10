#include <fmt/ranges.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static vector<vector<int>> generate(const int numRows)
    {
        //     std::ios_base::sync_with_stdio(false);
        //     std::cin.tie(nullptr);

        vector<vector<int>> pascal{{1}}; // 0
        if (numRows == 1)
            return pascal;
        pascal.push_back({1, 1}); // 1
        if (numRows == 2)
            return pascal;
        for (int i = 3; i <= numRows; ++i) {
            const int rowIdx = i - 1;
            // sliding window of prev row
            pascal.push_back({1});
            int j = 0;
            for (; j < rowIdx / 2; ++j) {
                pascal[rowIdx].push_back(pascal[rowIdx - 1][j] + pascal[rowIdx - 1][j + 1]);
            }
            for (; j < rowIdx; ++j) {
                pascal[rowIdx].push_back(pascal[rowIdx][i - 2 - j]);
            }
        }
        return pascal;
    }
};

int main()
{
    const auto rows = Solution::generate(7);
    for (const auto &row : rows) {
        fmt::print("{}\n", fmt::join(row, ", "));
    }
}