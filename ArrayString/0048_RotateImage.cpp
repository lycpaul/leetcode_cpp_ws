#include <fmt/printf.h>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // [A] erase & insert
        const int n = static_cast<int>(matrix.size());
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                const int element = matrix[i][0];
                matrix[j].push_back(element);
                matrix[i].erase(matrix[i].begin());
            }
        }

        // [B] swap and reverse
        // for (int i = 0; i < matrix.size() - 1; i++) {
        //     for (int j = i + 1; j < matrix.size(); j++) {
        //         if (i != j) {
        //             swap(matrix[i][j], matrix[j][i]);
        //         }
        //     }
        // }
        // for (auto &row : matrix) {
        //     ranges::reverse(row);
        // }
    }
    static void printMatrix(vector<vector<int>> &matrix)
    {
        for (auto &row : matrix) {
            fmt::print("{}\n", fmt::join(row, ", "));
        }
    }
};

int main()
{
    Solution sol;
    const vector<vector<int>> test1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    const vector<vector<int>> test2 = {{5, 1, 9, 11},
                                       {2, 4, 8, 10},
                                       {13, 3, 6, 7},
                                       {15, 14, 12, 16}};
    for (auto test : {test1, test2}) {
        fmt::print("Before:\n");
        Solution::printMatrix(test);
        sol.rotate(test);
        fmt::print("After:\n");
        Solution::printMatrix(test);
    }
}
