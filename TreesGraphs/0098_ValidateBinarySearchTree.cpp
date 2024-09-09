#include "TreeNode.h"
#include <fstream>
#include <functional>

class Solution
{
public:
    bool inorderTraversal(TreeNode *node, TreeNode *&prev)
    {
        if (!node)
            return true;
        if (!inorderTraversal(node->left, prev))
            return false;
        fmt::print("{}, ", node->val);
        if (prev and prev->val >= node->val)
            return false;
        prev = node;
        return inorderTraversal(node->right, prev);
    }

    bool isValidBST(TreeNode *root)
    {
        TreeNode *prev = nullptr;
        return inorderTraversal(root, prev);
    }
};

int main()
{
    std::vector<std::pair<TreeNode *, bool>> testCases;

    TreeNode t1{std::vector<std::optional<int>>{5, 1, 4, std::nullopt, std::nullopt, 3, 6}};
    testCases.emplace_back(&t1, false);

    TreeNode t2{std::vector<std::optional<int>>{2, 1, 3}};
    testCases.emplace_back(&t2, true);

    TreeNode t3{std::vector<std::optional<int>>{2, 2, 2}};
    testCases.emplace_back(&t3, false);

    TreeNode t4{std::vector<std::optional<int>>{5, 4, 6, std::nullopt, std::nullopt, 3, 7}};
    testCases.emplace_back(&t4, false);

    TreeNode t5{std::vector<std::optional<int>>{
        120, 70, 140, 50, 100, 130, 160, 20, 55, 75, 110, 119, 135, 150, 200}};
    testCases.emplace_back(&t5, false);

    TreeNode t6{std::vector<std::optional<int>>{
        32, 26, 47, 19, std::nullopt, std::nullopt, 56, std::nullopt, 27}};
    testCases.emplace_back(&t6, false);

    Solution s;
    int index{0}, correctedCases{0};
    for (const auto &[root, expected] : testCases) {
        root->print();
        auto ret = s.isValidBST(root);
        fmt::print("Test Case {}: ret: {} expected: {}\n", ++index, ret, expected);
        correctedCases += ret == expected;
    }
    fmt::print("Total Cases: {} Corrected Cases: {}", index, correctedCases);
    return 0;
}
