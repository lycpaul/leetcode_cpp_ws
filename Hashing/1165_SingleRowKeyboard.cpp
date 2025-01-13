#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int calculateTime(string keyboard, string word)
    {
        // create a hashmap to encode the distance of each word in the keyword away from orogin
        unordered_map<char, int> hash;
        int iloc = 0;
        for (auto c : keyboard) {
            hash[c] = iloc++;
        }
        iloc = 0; // current location
        int distance = 0;
        for (auto c : word) {
            distance += std::abs(hash[c] - iloc);
            iloc = hash[c];
        }
        return distance;
    }
};

int main()
{
    Solution sol;
    std::pair<string, string> test1{"abcdefghijklmnopqrstuvwxyz", "cba"};
    std::pair<string, string> test2{"pqrstuvwxyzabcdefghijklmno", "leetcode"};
    for (auto &[keyboard, word] : {test1, test2}) {
        auto ret = sol.calculateTime(keyboard, word);
        fmt::print("{}\n", ret);
    }
}