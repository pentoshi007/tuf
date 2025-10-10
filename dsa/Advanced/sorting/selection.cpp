// it is basically get the minimum and swap it
// time complexity is O(n^2)
// space complexity is O(1)
// it is not a stable sort
// it is not a in place sort
// it is not a adaptive sort
// it is not a online sort
// it is not a batch sort
// it is not a parallel sort

// outer loop for n-1 times, because last element will be sorted
// inner loop starts from i+1 to n, because we are comparing with the current element and before i+1 is already sorted
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> selectionSort(vector<int> &nums)
    {
        int min;
        int n = nums.size();
        int tmp;
        for (int i = 0; i < n - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[min])
                {
                    min = j;
                }
            }
            tmp = nums[min];
            nums[min] = nums[i];
            nums[i] = tmp;
        }
        return nums;
    }
};
