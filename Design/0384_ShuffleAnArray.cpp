#include <cmath>
#include <fmt/core.h>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <vector>

using namespace std;

int randInt(const int low, const int high)
{
    static default_random_engine re{};
    using Dist = uniform_int_distribution<int>;
    static Dist uid{};
    return uid(re, Dist::param_type{low, high});
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
class Solution
{
    // Seed with a real random value, if available
    default_random_engine re{std::random_device{}()};

public:
    const vector<int> original;
    vector<int> arr; // for return
    Solution(vector<int> &nums)
        : original{nums}
        , arr{nums}
    {
        //     std::ios_base::sync_with_stdio(false);
        //     std::cin.tie(nullptr);
    }

    vector<int> reset()
    {
        arr = original;
        return arr;
    }

    vector<int> shuffle()
    {
        for (int i = arr.size() - 1; i > 0; --i) {
            const auto idx = std::uniform_int_distribution<int>(0, i)(re);
            std::swap(arr[i], arr[idx]);
        }
        return arr;
    }

    void randomNumHistogram(const int range)
    {
        // Reference
        // https://en.cppreference.com/w/cpp/numeric/random
        // https://www.stroustrup.com/C++11FAQ.html#std-random

        std::map<int, int> hist;
        for (int n = 0; n != 10000; ++n)
            ++hist[std::uniform_int_distribution<int>(0, range)(re)];

        std::cout << "Uniform distribution "
                  << ":\n"
                  << std::fixed << std::setprecision(1);

        for (auto [x, y] : hist)
            std::cout << std::setw(2) << x << ' ' << std::string(y / 200, '*') << '\n';
    }
};

int main()
{
    vector nums{1, 2, 3, 4, 5};
    Solution obj(nums);
    vector<int> param_1 = obj.shuffle();
    vector<int> param_2 = obj.reset();

    fmt::print("nums: {}\n", fmt::join(nums, ", "));
    fmt::print("shuffle: {}\n", fmt::join(param_1, ", "));
    fmt::print("reset: {}\n", fmt::join(param_2, ", "));

    // obj.randomNumHistogram(nums.size());
}