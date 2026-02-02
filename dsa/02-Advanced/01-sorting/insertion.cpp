// time complexity is O(n^2)
// space complexity is O(1)
// it is not a stable sort
// it is not a in place sort
// it is not a adaptive sort
// it is not a online sort
// it is not a batch sort
// it is not a parallel sort

// determine a pivot, and place it at the second position, and sort all elements left to it and keep moving the pivot to the right and keep sorting the elements left to it

class Solution
{
public:
    vector<int> insertionSort(vector<int> &nums)
    {
        int n = nums.size();
        int j;
        for (int i = 1; i < n; i++)
        {
            j = i;
            while (j > 0 && nums[j] < nums[j - 1])
            {
                swap(nums[j], nums[j - 1]);
                j--;
            }
        }
        return nums;
    }
};
