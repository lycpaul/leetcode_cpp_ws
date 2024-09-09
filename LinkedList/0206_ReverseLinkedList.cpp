#include "common.h"
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr != nullptr) {
            const auto next = curr->next; // traverse to next
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main()
{
    ListNode test1{std::vector{1, 2, 3, 4, 5}};
    ListNode test2{std::vector{1, 2}};
    ListNode test3{};
    Solution sol;

    for (ListNode *test : {&test1, &test2, &test3}) {
        fmt::print("Before: ");
        test->print();
        auto ret = sol.reverseList(test);
        fmt::print("After: ");
        ret->print();
    }
}
