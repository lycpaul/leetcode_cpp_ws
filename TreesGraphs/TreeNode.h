#pragma once
#include <fmt/ranges.h>
#include <iostream>
#include <vector>

template<typename T = int>
struct TreeNodeT
{
    T val;
    TreeNodeT *left;
    TreeNodeT *right;

    TreeNodeT()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {}

    explicit TreeNodeT(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {}

    TreeNodeT(T x, TreeNodeT *left, TreeNodeT *right)
        : val(x)
        , left(left)
        , right(right)
    {}

    /**
     * Print function that is not provided by leetcode
     * @param prefix
     * @param isLeft
     */
    void print(const std::string &prefix = "", const bool isLeft = true) const
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << val << std::endl;
        if (!left && !right)
            return;
        if (left)
            left->print(prefix + (isLeft ? "│  " : "   "), true);
        else
            fmt::print("{}   ├──nullptr\n", prefix);
        if (right)
            right->print(prefix + (isLeft ? "│  " : "   "), false);
        else
            fmt::print("{}   └──nullptr\n", prefix);
    }

    /**
     * Init Tree Node with std::vector
     * @param v
     */
    explicit TreeNodeT(const std::vector<std::optional<T>> &v)
    {
        if (v.empty())
            return;
        val = v[0].value();
        std::vector<TreeNodeT *> nodes;
        nodes.push_back(this);
        for (size_t i = 1; i < v.size(); i += 2) {
            auto node = nodes.front();
            nodes.erase(nodes.begin());
            if (v[i].has_value()) {
                node->left = new TreeNodeT(v[i].value());
                nodes.push_back(node->left);
            }
            if (i + 1 < v.size() && v[i + 1].has_value()) {
                node->right = new TreeNodeT(v[i + 1].value());
                nodes.push_back(node->right);
            }
        }
    }
};

using TreeNode = TreeNodeT<int>;

template<typename T>
std::string printOptVec(const std::vector<std::optional<T>> &vec)
{
    std::string ret = "[";
    for (auto const &num : vec) {
        if (num.has_value()) {
            ret += std::to_string(num.value()) + ", ";
        } else {
            ret += "null, ";
        }
    }
    ret += "]";
    return ret;
}
template<typename T>
std::string printVecVec(const std::vector<std::vector<T>> &vecs)
{
    std::string ret = "[";
    for (auto const &vec : vecs) {
        ret += "[";
        for (auto const num : vec) {
            ret += std::to_string(num) + ", ";
        }
        ret += "],";
    }
    ret += "]";
    return ret;
}