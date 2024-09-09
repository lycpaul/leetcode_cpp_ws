#include "TreeNode.h"
#include <fstream>
#include <iostream>

class Solution
{
public:
    int _depth(TreeNode *root, int height)
    {
        if (root == nullptr) {
            return height - 1;
        }
        return std::max(_depth(root->left, height + 1), _depth(root->right, height + 1));
    }
    int maxDepth(TreeNode *root) { return _depth(root, 1); }
};

int main()
{
    auto *test1 = new TreeNode(3);
    test1->left = new TreeNode(9);
    test1->right = new TreeNode(20);
    test1->right->left = new TreeNode(15);
    test1->right->right = new TreeNode(7);

    auto *test2 = new TreeNode(1);
    test2->right = new TreeNode(2);

    Solution s;
    std::cout << s.maxDepth(test1) << std::endl;
    std::cout << s.maxDepth(test2) << std::endl;

    return 0;
}