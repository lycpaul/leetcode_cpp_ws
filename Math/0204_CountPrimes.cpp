#include <fmt/core.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // basic Sieve of Eratosthenes
    static int countPrimes(const int n)
    {
        if (n <= 2)
            return 0;
        bool nonPrimes[n];
        memset(nonPrimes, false, sizeof(nonPrimes));
        int primeCounts{};
        for (int i = 2; i < n; ++i) {
            if (!nonPrimes[i]) {
                // cout << i << " is a prime!" << endl;
                ++primeCounts;
                int j = 2;
                int notAPrime = i * j;
                while (notAPrime < n) {
                    // cout << notAPrime << " is NOT a prime!" << endl;
                    nonPrimes[notAPrime] = true;
                    notAPrime = i * ++j;
                }
            }
        }
        return primeCounts;
    }

    // modified
    int countPrimesMod(int n)
    {
        if (--n < 2)
            return 0;
        const int m = (n + 1) / 2;
        int count = m, u = (sqrt(n) - 1) / 2;
        bool nonPrimes[n];
        memset(nonPrimes, false, sizeof(nonPrimes));
        for (int i = 1; i <= u; i++)
            if (!nonPrimes[i])
                for (int k = (i + 1) * 2 * i; k < m; k += i * 2 + 1)
                    if (!nonPrimes[k]) {
                        nonPrimes[k] = true;
                        count--;
                    }
        return count;
    }

    // Fastest!
    int countPrimesAdj(int n)
    {
        if (n < 3)
            return 0;

        int sqrtn = sqrt(n - 1);
        int smallPrimes[sqrtn];
        int smallPrimeSquares[sqrtn];
        int smallPrimeCount = 0;

        // Finding Small Primes
        for (int i = 2; i <= sqrtn; i++) {
            bool isPrime = true;
            for (int j = 0; j < smallPrimeCount - 1 && smallPrimeSquares[j] <= i; j++) {
                if (i % smallPrimes[j] == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                smallPrimes[smallPrimeCount] = i;
                smallPrimeSquares[smallPrimeCount] = i * i;
                smallPrimeCount++;
            }
        }
        int primeCount = (n - 2) + smallPrimeCount - adjust(smallPrimes, smallPrimeCount, n, 1, 0);
        return primeCount;
    }

private:
    int adjust(int *primes, int numPrimes, int n, int base, int start)
    {
        int adj = 0;
        for (int i = start; i < numPrimes; i++) {
            int num = base * primes[i];
            if (num >= n)
                break;
            adj += ((n - 1) / num);
            if (i + 1 < numPrimes && num <= n / primes[i + 1]) {
                adj -= adjust(primes, numPrimes, n, num, i + 1);
            }
        }
        return adj;
    }
};

int main()
{
    Solution sol;
    auto ret = sol.countPrimes(10);
    std::cout << "Count Primes: " << ret << std::endl;
}