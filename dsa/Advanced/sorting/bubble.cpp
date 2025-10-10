// time complexity is O(n^2)

// space complexity is O(1)
// it is not a stable sort
// it is not a in place sort
// it is not a adaptive sort
// it is not a online sort
// it is not a batch sort
// it is not a parallel sort
// outer loop for n-1 times, because last element will be sorted
// inner loop runs from 0 to n-1-i, because after each pass, the last i elements are sorted
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bubbleSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {                    // Corrected bound
            int didSwap = 0; // Reset on each pass
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                    didSwap++;
                }
            }
            if (didSwap == 0)
                break; // Early exit if already sorted
        }
        return nums;
    }
};
