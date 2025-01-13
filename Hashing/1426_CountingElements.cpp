#include <fmt/ranges.h>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int countElements(vector<int> &arr)
    {
        std::unordered_map<int, int> hash;
        for (auto a : arr) {
            hash[a]++;
        }

        // counting valid pair
        int pairs = 0;
        for (auto const &k : std::views::keys(hash)) {
            if (hash.contains(k + 1)) {
                // pairs += std::min(hash[k], hash[k + 1]);
                pairs += hash[k];
            }
        }
        return pairs;
    }
};

int main()
{
    Solution sol;
    std::vector<int> test1{1, 2, 3}, test2{1, 1, 3, 3, 5, 5, 7, 7}, test3{1, 1, 2, 2};
    for (auto test : {test1, test2, test3}) {
        auto ret = sol.countElements(test);
        fmt::print("{}\n", ret);
    }
}