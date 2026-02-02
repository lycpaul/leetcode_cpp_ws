#include <chrono>
#include <fmt/ranges.h>
#include <random>
#include <span>
#include <vector>
using namespace std;

/*
Frequently seen in LeetCode:
- 912. Sort an Array (implement sorting; merge/quick/heap are common)
- Merge Sort: stable, O(n log n), extra memory for merging [web:11]
- Quick Sort: average O(n log n), worst O(n^2) if pivot choices go bad; pivot partitioning [web:12]
- Heap Sort: O(n log n), in-place-ish, not stable; uses heapify/extract-max idea [web:10]
*/
static void printVec(std::span<const int> a, const string &label)
{
    fmt::print("{}: {}\n", label, a);
}

/* =========================
   1) MERGE SORT (stable)
   =========================
   Key idea: recursively split into halves, sort both halves, merge them back [web:11].
   Time: O(n log n), Space: O(n) auxiliary.
*/
static void mergeRange(std::span<int> a, int l, int mid, int r, std::span<int> tmp)
{
    int i = l, j = mid, k = l;
    while (i < mid && j < r) {
        if (a[i] <= a[j])
            tmp[k++] = a[i++]; // <= keeps stability
        else
            tmp[k++] = a[j++];
    }
    while (i < mid)
        tmp[k++] = a[i++];
    while (j < r)
        tmp[k++] = a[j++];
    for (int t = l; t < r; ++t)
        a[t] = tmp[t];
}

static void mergeSortRec(std::span<int> a, int l, int r, std::span<int> tmp)
{
    if (r - l <= 1)
        return;
    int mid = l + (r - l) / 2;
    mergeSortRec(a, l, mid, tmp);
    mergeSortRec(a, mid, r, tmp);
    mergeRange(a, l, mid, r, tmp);
}

static void mergeSort(std::span<int> a)
{
    vector<int> tmp(a.size());
    mergeSortRec(a, 0, (int) a.size(), tmp);
}

/* =========================
   2) QUICK SORT (in-place)
   =========================
   Key idea: choose pivot, partition array around pivot, recurse on both sides [web:12].
   Average O(n log n), worst O(n^2). Random pivot helps in practice.
*/
static int partitionLomuto(std::span<int> a, int l, int r)
{ // r is inclusive
    int pivot = a[r];
    int i = l; // place for next <= pivot
    for (int j = l; j < r; ++j) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);
            ++i;
        }
    }
    swap(a[i], a[r]);
    return i;
}

static void quickSortRec(std::span<int> a, int l, int r, std::mt19937 &rng)
{
    if (l >= r)
        return;

    // Randomize pivot choice to avoid worst-case patterns.
    std::uniform_int_distribution<int> dist(l, r);
    int pivotIndex = dist(rng);
    swap(a[pivotIndex], a[r]);

    int p = partitionLomuto(a, l, r);
    quickSortRec(a, l, p - 1, rng);
    quickSortRec(a, p + 1, r, rng);
}

static void quickSort(std::span<int> a)
{
    std::mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
    if (!a.empty())
        quickSortRec(a, 0, (int) a.size() - 1, rng);
}

/* =========================
   3) HEAP SORT
   =========================
   Key idea: build max-heap, repeatedly swap max (root) to end, heapify remaining [web:10].
   Time O(n log n), Space O(1) extra (besides recursion stack if any).
*/
static void heapifyDown(std::span<int> a, int n, int i)
{
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest])
            largest = left;
        if (right < n && a[right] > a[largest])
            largest = right;

        if (largest == i)
            break;
        swap(a[i], a[largest]);
        i = largest;
    }
}

static void heapSort(std::span<int> a)
{
    int n = (int) a.size();
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i)
        heapifyDown(a, n, i);

    // Extract elements
    for (int end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);     // move max to end
        heapifyDown(a, end, 0); // restore heap on remaining [0, end)
    }
}

/* =========================
   "LeetCode style" wrapper:
   =========================
   Many problems expect: vector<int> sortArray(vector<int>& nums).
*/
static vector<int> sortArray_merge(vector<int> nums)
{
    mergeSort(nums);
    return nums;
}
static vector<int> sortArray_quick(vector<int> nums)
{
    quickSort(nums);
    return nums;
}
static vector<int> sortArray_heap(vector<int> nums)
{
    heapSort(nums);
    return nums;
}

int main()
{
    std::random_device rng;  //  seed source for the random number engine
    std::mt19937 gen(rng()); // mersenne_twister_engine seeded with rng()
    std::uniform_int_distribution<> dist(1, 100);

    constexpr int N = 20;
    std::vector<int> nums = {};
    nums.reserve(N);
    for (int i = 0; i < N; ++i) {
        nums.push_back(dist(gen));
    }
    printVec(nums, "Original");

    auto a = sortArray_merge(nums);
    printVec(a, "MergeSort");

    auto b = sortArray_quick(nums);
    printVec(b, "QuickSort");

    auto c = sortArray_heap(nums);
    printVec(c, "HeapSort");

    // Sanity check vs STL
    auto d = nums;
    sort(d.begin(), d.end());
    printVec(d, "std::sort");

    auto e = nums;
    ranges::sort(e);
    printVec(e, "ranges::sort");

    return 0;
}
