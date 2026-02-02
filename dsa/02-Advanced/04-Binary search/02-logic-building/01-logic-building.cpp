// Search insert position
/*
 Given a sorted array of nums consisting of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.


Examples:
Input: nums = [1, 3, 5, 6], target = 5

Output: 2

Explanation: The target value 5 is found at index 2 in the sorted array. Hence, the function returns 2.

*/
// Approach 1: Linear search
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= target)
            {
                return i;
            }
        }
        return n;
    }
};
// Approach 2: Binary search--basically lower bound problem
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size();
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
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
// Floor and Ceil in Sorted Array
/*
 Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.


Examples:
Input : nums =[3, 4, 4, 7, 8, 10], x= 5

Output: 4 7

Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> getFloorAndCeil(vector<int> &nums, int x)
    {
        int left = 0;
        int right = (int)nums.size() - 1;
        int ceilVal = -1;
        int floorVal = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == x)
            {
                return {nums[mid], nums[mid]};
            }

            if (nums[mid] < x)
            {
                floorVal = nums[mid];
                left = mid + 1;
            }
            else
            {
                ceilVal = nums[mid];
                right = mid - 1;
            }
        }

        return {floorVal, ceilVal};
    }
};
// other approach is to use lower bound and upper bound
class Solution
{
private:
    // Helper function to find the floor of x
    int findFloor(vector<int> &nums, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = -1;

        // Perform binary search to find floor value
        while (low <= high)
        {
            int mid = (low + high) / 2;

            /*Check if mid element lesser than
                              or equal to x, if it is update ans
                        and eliminate the left half */
            if (nums[mid] <= x)
            {
                ans = nums[mid];
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

    // Helper function to find the ceil of x
    int findCeil(vector<int> &nums, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = -1;

        // Perform binary search to find ceil value
        while (low <= high)
        {
            int mid = (low + high) / 2;

            /*Check if mid element greater than
                             or equal to x, if it is update ans
                       and eliminate the left half */
            if (nums[mid] >= x)
            {
                ans = nums[mid];
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }

public:
    // Function to find both floor and ceil of x in nums
    vector<int> getFloorAndCeil(vector<int> nums, int x)
    {
        int n = nums.size();
        int floor = findFloor(nums, n, x);
        int ceil = findCeil(nums, n, x);
        return {floor, ceil};
    }
};

//================================================================================
// first and last occurrence of an element in a sorted array
/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If the target is not found in the array, return [-1, -1].


Examples:
Input: nums = [5, 7, 7, 8, 8, 10], target = 8

Output: [3, 4]

Explanation:The target is 8, and it appears in the array at indices 3 and 4, so the output is [3,4]
*/
// approach 1: linear search
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int first = -1;
        int last = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                if (first == -1)
                {
                    first = i;
                }
                last = i;
            }
        }
        return {first, last};
    }
};
// using bounds
class Solution
{
private:
    // Function to find the lower bound of the target
    int lowerBound(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();

        // Applying binary search algorithm
        while (low <= high)
        {
            int mid = (low + high) / 2;

            /*  If the middle element is greater than
                or equal to the target element update
                the answer as mid and eliminate the right half  */
            if (nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }

            /*  If the middle element is smaller than
                the target element then we eliminate
                the left half  */
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    // Function to find the upper bound of the target
    int upperBound(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();

        // Applying binary search algorithm
        while (low <= high)
        {
            int mid = (low + high) / 2;

            /*  If the middle element is greater than
                the target element update the answer
                as mid and eliminate the right half  */
            if (nums[mid] > target)
            {
                ans = mid;
                high = mid - 1;
            }
            /*  If the middle element is greater than
                or equal to the target element
                eliminate the right half  */
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    // Function to find the first and last occurrences of the target
    vector<int> searchRange(vector<int> &nums, int target)
    {

        // Function call to find the first occurrence (lower bound)
        int firstOcc = lowerBound(nums, target);

        // Check if the target is present in the array or not
        if (firstOcc == nums.size() || nums[firstOcc] != target)
            return {-1, -1};

        // Function call to find the last occurrence (upper bound)
        int lastOcc = upperBound(nums, target) - 1;

        return {firstOcc, lastOcc};
    }
};
// binary search approach
class Solution
{
public:
    int first(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int fo = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                fo = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return fo;
    };
    int last(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int lo = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                lo = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return lo;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int fo = first(nums, target);
        if (fo == -1)
        {
            return {-1, -1};
        }
        else
        {
            int lo = last(nums, target);
            return {fo, lo};
        }
    }
};
//================================================================================
// Search in rotated sorted array-I
/*
 Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.


Examples:
Input : nums = [4, 5, 6, 7, 0, 1, 2], k = 0

Output: 4

Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.
*/
// binary search approach
//--whenever search and sorted word appers think of binary search
class Solution
{
public:
    int search(vector<int> &nums, int k)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == k)
                return mid;
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= k && k < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (k > nums[mid] && k <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
