#include <fmt/printf.h>
#include <vector>
using namespace std;

class Solution
{
public:
    template<typename T = int>
    vector<T> templateFunc(vector<T> &test)
    {
        return test;
    }

    string templateFunc(string word1, string word2) { return ""; }
};

int main()
{
    Solution sol;

    // test cases
    vector<int> test1 = {1, 2, 3};
    vector<int> test2 = {4, 3, 2, 1};
    vector<int> test3 = {9, 9, 9};

    for (auto test : {test1, test2, test3}) {
        fmt::print("Before: {} After: {}\n",
                   fmt::join(test, ", "),
                   fmt::join(sol.templateFunc(test), ", "));
    }
}
