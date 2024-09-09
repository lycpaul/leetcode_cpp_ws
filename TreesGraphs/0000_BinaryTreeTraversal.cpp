#include "TreeNode.h"
#include <queue>
/**
 * @brief Inorder traversal visits the node in the order: Left -> Root -> Right
 * 1. In the case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing
 * order.
 * 2. To get nodes of BST in non-increasing order, a variation of Inorder traversal where Inorder
 * traversal is reversed can be used.
 * 3. Inorder traversal can be used to evaluate arithmetic expressions stored
 * in expression trees.
 * @param node
 */
void inorderTraversal(TreeNode *node)
{
    if (!node)
        return;
    inorderTraversal(node->left);
    fmt::print("{}, ", node->val);
    inorderTraversal(node->right);
}

void reverseInorderTraversal(TreeNode *node)
{
    if (!node)
        return;
    reverseInorderTraversal(node->right);
    fmt::print("{}, ", node->val);
    reverseInorderTraversal(node->left);
}

/**
 * @brief Postorder traversal visits the node in the order: Left -> Right -> Root
 * 1. Postorder traversal is used to delete the tree. See the question for the deletion of a tree
 * for details.
 * 2. Postorder traversal is also useful to get the postfix expression of an expression tree.
 * 3. Postorder traversal can help in garbage collection algorithms, particularly in systems where
 * manual memory management is used.
 * @param node
 */
void postorderTraversal(TreeNode *node)
{
    if (!node)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    fmt::print("{}, ", node->val);
}

/**
 * @brief Preorder traversal visits the node in the order: Root -> Left -> Right
 * 1. Preorder traversal is used to create a copy of the tree.
 * 2. Preorder traversal is also used to get prefix expressions on an expression tree.
 * @param node
 */
void preorderTraversal(TreeNode *node)
{
    if (!node)
        return;
    fmt::print("{}, ", node->val);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

/**
 * @brief Level Order Traversal visits all nodes present in the same level completely before
 * visiting the next level.
 * 1. Level Order Traversal is mainly used as Breadth First Search to search or process nodes
 * level-by-level.
 * 2. Level Order traversal is also used for Tree Serialization and Deserialization .
 * @param node
 */
void levelOrderTraversal(TreeNode *node)
{
    if (!node)
        return;
    std::queue<TreeNode *> q;
    q.push(node);
    while (!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();
        fmt::print("{}, ", curr->val);
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main()
{
    TreeNode t1{std::vector<std::optional<int>>{1, 2, 3, 4, 5, 6}};
    t1.print();
    fmt::print("\n");

    TreeNode t3{std::vector<std::optional<int>>{
        120, 70, 140, 50, 100, 130, 160, 20, 55, 75, 110, 119, 135, 150, 200}};
    t3.print();
    fmt::print("\n");

    TreeNode t2{std::vector<std::optional<int>>{1, 2, 3, 4, 5, std::nullopt, 6}};
    t2.print();
    fmt::print("\n");

    fmt::print("Inorder Traversal: ");
    inorderTraversal(&t2);
    fmt::print("\n");

    fmt::print("Preorder Traversal: ");
    preorderTraversal(&t2);
    fmt::print("\n");

    fmt::print("Postorder Traversal: ");
    postorderTraversal(&t2);
    fmt::print("\n");

    fmt::print("Level-order Traversal: ");
    levelOrderTraversal(&t2);
    fmt::print("\n");

    fmt::print("Reverse Inorder Traversal: ");
    reverseInorderTraversal(&t2);
    fmt::print("\n");

    return 0;
}