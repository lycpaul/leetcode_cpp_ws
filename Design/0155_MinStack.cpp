#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
    // keep track of the current inserted val and min value in the stack
    std::stack<std::pair<int, int>> s;

public:
    MinStack() = default;

    void push(const int val)
    {
        if (s.empty()) {
            s.emplace(val, val);
        } else {
            if (val < s.top().second) {
                s.emplace(val, val);
            } else {
                s.emplace(val, s.top().second);
            }
        }
    }

    void pop() { s.pop(); }

    int top() const { return s.top().first; }

    int getMin() const { return s.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack minStack{};
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << minStack.top() << endl;    // return 0
    cout << minStack.getMin() << endl; // return -2
}