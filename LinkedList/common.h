#pragma once
#include <fmt/printf.h>
#include <vector>

template<typename T = int>
struct ListNodeT
{
    // elements
    T val;
    ListNodeT *next;

    // default constructors
    ListNodeT()
        : val(0)
        , next(nullptr)
    {}

    explicit ListNodeT(const T x)
        : val(x)
        , next(nullptr)
    {}

    ListNodeT(const T x, ListNodeT *next)
        : val(x)
        , next(next)
    {}

    // method not in LeetCode
    explicit ListNodeT(const std::vector<T> &v)
    {
        auto node = this;
        for (int i = 0; i < v.size(); i++) {
            node->val = v[i];
            if (i < v.size() - 1) {
                node->next = new ListNodeT();
                node = node->next;
            }
        }
    }

    // method not in LeetCode
    ListNodeT *push_back(const T x)
    {
        auto node = this;
        while (node->next != nullptr) {
            node = node->next;
        }
        node->next = new ListNodeT(x);
        return this;
    }

    // method not in LeetCode
    void print(const std::optional<size_t> max = std::nullopt) const
    {
        auto node = this;
        if (max.has_value()) {
            for (size_t i = 0; i < max.value() and node != nullptr; ++i) {
                fmt::print("{} -> ", node->val);
                node = node->next;
            }
            fmt::print("nullptr\n");
            return;
        }
        while (node != nullptr) {
            fmt::print("{} -> ", node->val);
            node = node->next;
        }
        fmt::print("nullptr\n");
    }

    ListNodeT *get_tail()
    {
        auto node = this;
        while (node->next != nullptr) {
            node = node->next;
        }
        return node;
    }
};

using ListNode = ListNodeT<int>;