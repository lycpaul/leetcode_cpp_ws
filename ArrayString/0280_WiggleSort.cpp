#include <vector>
using namespace std;
class Solution
{
public:
    // nums[0] <= nums[1] >= nums[2] <= nums[3] ...
    void wiggleSort(vector<int> &nums)
    {
        // size = 0
        if (nums.size() == 1)
            return;

        // size = 1
        if (nums[0] > nums[1]) {
            std::swap(nums[0], nums[1]);
        }

        // rest
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (i % 2) {
                // odd case
                if (nums[i] < nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);
                }
                if (nums[i] < nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }
            } else {
                // even case
                if (nums[i] > nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);
                }
                if (nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }
            }
        }
    }
};

int main()
{
    vector nums1{3, 5, 2, 1, 6, 4};
    vector nums2{6, 6, 5, 6, 3, 8};
}