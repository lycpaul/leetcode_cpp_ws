#include "common.h"

// cheat code
// #include <fstream>
// #include <iostream>
// https://dev.to/aphelionz/exposed-the-leetcode-c-cheat-code-4mfa
// int init = [] {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::ofstream out("user.out");
//     std::cout.rdbuf(out.rdbuf());
//     for (std::string s; getline(std::cin, s);)
//         out << (equal(s.begin() + 1, s.begin() + s.size() / 2, s.rbegin() + 1) ? "true\n"
//                                                                                : "false\n");
//     out.flush();
//     exit(0);
//     return 0;
// }();

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

    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
            return true;
        // check if head and tail are equal, recursively
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        const auto second = reverseList(slow);
        ListNode *itr1 = second;
        ListNode *itr2 = head;
        // odd number size(second) == size(head)
        // even number size(second) == size(head) + 1
        while (itr1 != nullptr) {
            if (itr1->val == itr2->val) {
                itr1 = itr1->next;
                itr2 = itr2->next;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    ListNode test1{std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1}};
    ListNode test2{std::vector{1, 2, 3, 4, 5, 6, 7, 8, 8, 7, 6, 5, 4, 3, 2, 1}};
    ListNode test3{std::vector{1, 2, 3, 4, 5, 6, 8, 8, 7, 6, 5, 4, 3, 2, 1}};
    ListNode test4{std::vector{1, 1, 2, 1}};
    ListNode test5{1};
    Solution sol;

    for (ListNode *test : {&test1, &test2, &test3, &test4, &test5}) {
        fmt::print("Test: ");
        test->print();
        auto ret = sol.isPalindrome(test);
        fmt::print("ret: {}\n", ret);
    }
}
