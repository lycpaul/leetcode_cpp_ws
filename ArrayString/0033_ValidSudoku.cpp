#include <fmt/printf.h>
#include <ranges>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        std::unordered_set<char> rowHash, colHash[9], gridHash[9];
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (const char entry = board[i][j]; entry != '.') {
                    const int quadrant = i / 3 * 3 + j / 3;
                    if (rowHash.contains(entry) or colHash[j].contains(entry)
                        or gridHash[quadrant].contains(entry))
                        return false;
                    rowHash.insert(entry);
                    colHash[j].insert(entry);
                    gridHash[quadrant].insert(entry);
                }
            }
            rowHash.clear();
        }
        return true;
    }

    void printBoard(vector<vector<char>> &board)
    {
        for (auto row : board) {
            for (auto cell : row) {
                fmt::print("{} ", cell);
            }
            fmt::print("\n");
        }
    }
};

int main()
{
    Solution sol;

    // test cases
    vector<vector<char>> test1{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> test2{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    for (auto test : {test1, test2}) {
        sol.printBoard(test);
        fmt::print("result: {}\n", sol.isValidSudoku(test));
    }
}
