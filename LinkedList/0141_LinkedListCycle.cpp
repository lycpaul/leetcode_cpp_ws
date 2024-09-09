#include "common.h"
#include <fstream>
#include <iostream>

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        if (head == nullptr)
            return false;
        // check if head and tail are equal, recursively
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr and fast->next != nullptr) {
            if (fast->next == slow or fast->next->next == slow) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

int main()
{
    ListNode test1{std::vector{3, 2, 0, -4}};
    const auto tail1 = test1.get_tail();
    tail1->next = test1.next->next;
    ListNode test2{std::vector{1, 2}};
    const auto tail2 = test2.get_tail();
    tail2->next = &test2;
    ListNode test3{1};

    Solution sol;
    for (ListNode *test : {&test1, &test2, &test3}) {
        fmt::print("Test: ");
        test->print(10);
        auto ret = sol.hasCycle(test);
        fmt::print("ret: {}\n", ret);
    }
}