class Solution
{
public:
    int climbStairs(int n)
    {
        int cs[n + 5];

        // init base case
        cs[0] = 1;
        cs[1] = 1;
        cs[2] = 2; // 1+1 and 2
        cs[3] = 3; // 1+1+1, 1+2, 2+1
        cs[4] = 5; // 1+1+1+1, 1+2+1, 2+1+1; 1+1+2, 2+2

        for (int i = 4; i <= n; i++) {
            cs[i] = cs[i - 1] + cs[i - 2];
        }
        return cs[n];
    }
};

int main() {}