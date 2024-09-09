#include "TreeNode.h"
#include <fstream>
#include <functional>
#include <queue>

#define DEBUG_PRINT 1

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> ret = {};
        if (!root)
            return ret;
        std::queue<std::pair<TreeNode *, unsigned int>> q = {}; // nodes, height
        q.emplace(root, 1);
        while (!q.empty()) {
            const auto [curr, height] = q.front();
            if (curr->left)
                q.emplace(curr->left, height + 1);
            if (curr->right)
                q.emplace(curr->right, height + 1);
            if (ret.size() < height) {
                ret.push_back({curr->val});
            } else {
                ret[height - 1].push_back(curr->val);
            }
#ifdef DEBUG_PRINT
            fmt::print("{}/{}, ", curr->val, height);
#endif
            q.pop();
        }
#ifdef DEBUG_PRINT
        fmt::print("\n");
#endif
        return ret;
    }
};

int main()
{
    std::vector<std::pair<TreeNode *, std::vector<std::optional<int>>>> testCases;

    const auto t1Vals = std::vector<std::optional<int>>{5, 1, 4, std::nullopt, std::nullopt, 3, 6};
    TreeNode t1{t1Vals};
    testCases.emplace_back(&t1, t1Vals);

    const auto t2Vals = std::vector<std::optional<int>>{2, 1, 3};
    TreeNode t2{t2Vals};
    testCases.emplace_back(&t2, t2Vals);

    const auto t3Vals = std::vector<std::optional<int>>{2, 2, 2};
    TreeNode t3{t3Vals};
    testCases.emplace_back(&t3, t3Vals);

    const auto t4Vals = std::vector<std::optional<int>>{5, 4, 6, std::nullopt, std::nullopt, 3, 7};
    TreeNode t4{t4Vals};
    testCases.emplace_back(&t4, t4Vals);

    const auto t5Vals = std::vector<std::optional<int>>{
        120, 70, 140, 50, 100, 130, 160, 20, 55, 75, 110, 119, 135, 150, 200};
    TreeNode t5{t5Vals};
    testCases.emplace_back(&t5, t5Vals);

    const auto t6Vals = std::vector<std::optional<int>>{32,
                                                        26,
                                                        47,
                                                        19,
                                                        std::nullopt,
                                                        std::nullopt,
                                                        56,
                                                        std::nullopt,
                                                        27};
    TreeNode t6{t6Vals};
    testCases.emplace_back(&t6, t6Vals);

    Solution s;
    int index{0};
    for (const auto &[root, expected] : testCases) {
        root->print();
        auto ret = s.levelOrder(root);
        fmt::print("Test Case: {}\n", ++index);
        std::cout << printVecVec(ret) << std::endl;
        std::cout << printOptVec(expected) << std::endl;
    }
    return 0;
}
