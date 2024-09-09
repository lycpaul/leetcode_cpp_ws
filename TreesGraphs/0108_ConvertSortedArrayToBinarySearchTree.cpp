#include "TreeNode.h"
class Solution
{
public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;
        // extract the median as root
        int mid = nums.size() / 2;
        auto *root = new TreeNode{nums[mid]};
        std::vector<int> leftVec(nums.begin(), nums.begin() + mid);
        std::vector<int> rightVec(nums.begin() + mid + 1, nums.end());
        root->left = sortedArrayToBST(leftVec);
        root->right = sortedArrayToBST(rightVec);
        return root;
    }
};

int main()
{
    std::vector<int> vec1{-10, -3, 0, 5, 9, 10};
    std::vector<int> vec2{1, 2, 3};
    std::vector<int> vec3{1, 3};
    std::vector<int> vec4{1};
    //
    // for (const auto &vec : {vec1, vec2, vec3, vec4}) {
    //     int mid = vec.size() / 2;
    //     std::vector<int> subVec1{vec.begin(), vec.begin() + mid};
    //     std::vector<int> subVec2{vec.begin() + mid + 1, vec.end()};
    //     fmt::print("vec: {}\n", fmt::join(vec, ", "));
    //     fmt::print("left: {} empty: {}\n", fmt::join(subVec1, ", "), subVec1.empty());
    //     fmt::print("right: {} empty: {}\n\n", fmt::join(subVec2, ", "), subVec2.empty());
    // }
}