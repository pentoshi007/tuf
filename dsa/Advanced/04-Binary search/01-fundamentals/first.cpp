// Search X in sorted array
/*
Given a sorted array of integers nums with 0-based indexing, find the index of a specified target integer. If the target is found in the array, return its index. If the target is not found, return -1.


Examples:
Input: nums = [-1,0,3,5,9,12], target = 9

Output: 4

Explanation: The target integer 9 exists in nums and its index is 4
*/
class Solution
{
public:
    int binarySearch(vector<int> &nums, int target, int left, int right)
    {
        if (left > right)
            return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target)
        {
            return binarySearch(nums, target, left, mid - 1);
        }
        else
        {
            return binarySearch(nums, target, mid + 1, right);
        }
    }

    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = (int)nums.size() - 1;
        return binarySearch(nums, target, left, right);
    }
};
// int search(vector<int> &nums, int target) {
//         int left = 0;
//         int right = nums.size() - 1;
//         //     while (left <= right) {
//         //         int mid = left + (right - left) / 2;
//         //         if (nums[mid] == target)
//         //             return mid;
//         //         else if (target < nums[mid]) {
//         //             right = mid - 1;
//         //         } else {
//         //             left = mid + 1;
//         //         }
//         //     }
//         //     return -1;
//         // }

//================================================================================
// Lower Bound
/*
Given a sorted array of nums and an integer x, write a program to find the lower bound of x.



The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.



If no such index is found, return the size of the array.


Examples:
Input : nums= [1,2,2,3], x = 2

Output:1

Explanation:

Index 1 is the smallest index such that arr[1] >= x.

*/
class Solution
{
public:
    int lowerBound(vector<int> &nums, int x)
    {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size();
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= x)
            {
                index = min(index, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return index;
    }
};
//================================================================================
// Upper Bound
/*
Given a sorted array of nums and an integer x, write a program to find the upper bound of x.



The upper bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than a given key i.e. x.



If no such index is found, return the size of the array.
*/
class Solution
{
public:
    int upperBound(vector<int> &nums, int x)
    {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size();
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > x)
            {
                index = min(index, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return index;
    }
};