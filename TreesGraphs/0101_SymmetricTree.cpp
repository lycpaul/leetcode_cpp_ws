#include "TreeNode.h"
#include <deque>

class Solution
{
public:
    bool isValid(TreeNode *left, TreeNode *right)
    {
        if (!left and !right)
            return true;
        if (!left or !right)
            return false;
        return isValid(left->left, right->right) and isValid(left->right, right->left)
               and left->val == right->val;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return isValid(root->left, root->right);
    }
};

int main()
{
    std::vector<std::pair<TreeNode *, bool>> testCases;

    const auto t1Vals = std::vector<std::optional<int>>{1, 2, 2, 3, 4, 4, 3};
    TreeNode t1{t1Vals};
    testCases.emplace_back(&t1, true);

    const auto t2Vals = std::vector<std::optional<int>>{1, 2, 2, std::nullopt, 3, std::nullopt, 3};
    TreeNode t2{t2Vals};
    testCases.emplace_back(&t2, false);

    const auto t3Vals = std::vector<std::optional<int>>{1, 2, 2, 2, std::nullopt, 2};
    TreeNode t3{t3Vals};
    testCases.emplace_back(&t3, false);

    const auto t4Vals = std::vector<std::optional<int>>{1, 2, 4};
    TreeNode t4{t4Vals};
    testCases.emplace_back(&t4, false);

    Solution s;
    int index{0}, correctedCases{0};
    for (const auto &[root, expected] : testCases) {
        root->print();
        auto ret = s.isSymmetric(root);
        correctedCases += ret == expected;
        fmt::print("Test Case: {} Expected: {} Return: {}\n", ++index, expected, ret);
    }
    fmt::print("Number of Corrected Cases: {}", correctedCases);
    return 0;
}