class Solution
{
public:
    int badVersion{0};

    int findBadVersion(int r1, int r2)
    {
        if (r1 == r2)
            return r1;

        if (r2 - r1 == 1)
            return isBadVersion(r1) ? r1 : r2;

        long mid = ((long) r1 + (long) r2) / 2;
        return isBadVersion(mid) ? findBadVersion(r1, mid) : findBadVersion(mid, r2);
    }

    int firstBadVersion(int n) { return findBadVersion(1, n); }

    bool isBadVersion(int n) { return n == badVersion; }
};

int main() {}