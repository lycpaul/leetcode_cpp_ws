#include "common.h"
#include <list>
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = nullptr;
        ListNode *curr = nullptr;

        // traverse both list
        ListNode *itr1 = list1;
        ListNode *itr2 = list2;
        ListNode *next = nullptr;

        while (itr1 != nullptr or itr2 != nullptr) {
            if (itr1 and itr2) {
                if (itr1->val <= itr2->val) {
                    next = itr1;
                    itr1 = itr1->next;
                } else {
                    next = itr2;
                    itr2 = itr2->next;
                }
            } else if (itr1 == nullptr and itr2 != nullptr) {
                next = itr2;
                itr2 = next->next;
            } else {
                next = itr1;
                itr1 = next->next;
            }

            if (curr == nullptr) {
                head = next;
            } else {
                curr->next = next;
            }
            curr = next;
        }

        if (curr != nullptr) {
            curr->next = nullptr;
        }

        return head;
    }
};

int main()
{
    Solution sol;

    ListNode list1{std::vector{1, 2, 4}};
    ListNode list2{std::vector{1, 3, 4}};
    ListNode list3{0};

    std::pair pair1{&list1, &list2};
    std::pair<ListNode *, ListNode *> pair2{nullptr, nullptr};
    std::pair<ListNode *, ListNode *> pair3{nullptr, &list3};

    for (auto const [l1, l2] : {pair1, pair2, pair3}) {
        fmt::print("Before: \n");
        l1->print();
        l2->print();
        const auto ret = sol.mergeTwoLists(l1, l2);
        fmt::print("After: \n");
        if (ret != nullptr)
            ret->print();
        else
            fmt::print("return nullptr\n");
    }
}
