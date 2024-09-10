#include <fmt/ranges.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        for (int i = 0; i + needle.size() <= haystack.size(); ++i) {
            if (haystack.substr(i, needle.size()) == needle)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    // test cases
    std::pair<string, string> p1{"adbutsad", "sad"};
    std::pair<string, string> p2{"leetcode", "leeto"};

    for (const auto &[haystack, needle] : {p1, p2}) {
        fmt::print("set: [{}, {}] strSrt: {}\n", haystack, needle, sol.strStr(haystack, needle));
    }
}
