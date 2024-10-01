#include <fmt/ranges.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static void printMat(vector<vector<int>> &mat)
    {
        for (const auto &row : mat) {
            fmt::print("[{}]\n", fmt::join(row, ", "));
        }
    }

    using Matrix = vector<vector<int>>;
    using SparseMatrix = vector<vector<pair<int, int>>>;
    /**
     * Dense computation
     * @param mat1 size: m x k
     * @param mat2 size: k x n
     * @return mat size: m x n
     */
    vector<vector<int>> multiplyDense(Matrix &mat1, Matrix &mat2)
    {
        // init ret matrix: (m x n)
        Matrix product(mat1.size(), vector<int>(mat2[0].size(), 0));
        // dense computation
        for (auto m = 0; m < mat1.size(); ++m) {
            for (auto n = 0; n < mat2[0].size(); ++n) {
                for (auto k = 0; k < mat1[0].size(); ++k) {
                    product[m][n] += mat1[m][k] * mat2[k][n];
                }
            }
        }
        return product;
    }

    // compress the sparse matrix
    static SparseMatrix compressMatrix(const Matrix &mat)
    {
        const auto rows = mat.size();
        const auto cols = mat[0].size();
        SparseMatrix sparse(rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] != 0) {
                    sparse[i].emplace_back(j, mat[i][j]);
                }
            }
        }
        return sparse;
    }

    // sparse computation version
    static Matrix multiply(const Matrix &mat1, const Matrix &mat2)
    {
        auto sm1 = compressMatrix(mat1);
        auto sm2 = compressMatrix(mat2);
        Matrix product(mat1.size(), vector<int>(mat2[0].size(), 0));

        // iterate the non-zero items
        for (int m = 0; m < mat1.size(); ++m) {
            for (const auto &[k, val1] : sm1[m]) {
                for (const auto &[n, val2] : sm2[k]) {
                    product[m][n] += val1 * val2;
                }
            }
        }

        return product;
    }
};

int main()
{
    using MatPair = std::pair<Solution::Matrix, Solution::Matrix>;
    // MatPair p{{{1, 0, 0}, {-1, 0, 3}}, {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}}};
    MatPair p{{{1, -5}}, {{12}, {-1}}};

    Solution::printMat(p.first);
    cout << endl;
    Solution::printMat(p.second);
    cout << endl;

    auto mat = Solution::multiply(p.first, p.second);
    Solution::printMat(mat);
}