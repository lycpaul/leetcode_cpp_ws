#include <fmt/ranges.h>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    static bool confusingNumber(const int n)
    {
        const std::string numStr = to_string(n);
        static const std::set invalidSet{'2', '3', '4', '5', '7'};
        static const std::unordered_map<char, char> invertedMap{{'0', '0'},
                                                                {'1', '1'},
                                                                {'6', '9'},
                                                                {'8', '8'},
                                                                {'9', '6'}};
        bool confusing = false;
        for (int i = 0; i < numStr.size(); ++i) {
            const auto c = numStr[i];
            if (invalidSet.contains(c))
                return false;
            if (numStr[numStr.size() - 1 - i] != invertedMap.at(c))
                confusing = true;
        }
        return confusing;
    }
};

int main()
{
    cout << Solution::confusingNumber(6889) << endl;
    cout << Solution::confusingNumber(6869) << endl;
    cout << Solution::confusingNumber(150) << endl;
}