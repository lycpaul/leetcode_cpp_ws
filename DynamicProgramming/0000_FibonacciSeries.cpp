#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fibonacci(const int n)
    {
        // Declare an array to store
        // Fibonacci numbers.
        // 1 extra to handle
        // case, n = 0
        int f[n + 2];

        // 0th and 1st number of the
        // series are 0 and 1
        f[0] = 0;
        f[1] = 1;

        for (int i = 2; i <= n; i++) {
            // Add the previous 2 numbers
            // in the series and store it
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};

// Driver code
int main()
{
    Solution sol;
    int n = 19;

    cout << sol.fibonacci(n);
    return 0;
}