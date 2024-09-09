#include <bits/stdc++.h>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

class Solution
{
public:
    static int maxDistance(const vector<vector<int>>& arrays) {
        cin.tie(nullptr)->sync_with_stdio(false);
        int smallest = arrays.front().front();
        int biggest = arrays.front().back();
        int maxDistance = 0;
        for (const auto& array : arrays | std::views::drop(1)) {
            maxDistance = max(maxDistance, abs(biggest - array.front()));
            maxDistance = max(maxDistance, abs(array.back() - smallest));
            smallest = min(array.front(), smallest);
            biggest = max(array.back(), biggest);
        }
        return maxDistance;
    }
};

int main()
{
    vector<vector<int>> arrays1{{1, 2, 3}, {4, 5}, {1, 2, 3}};
    auto ret = Solution::maxDistance(arrays1);
    cout << ret << endl;
}