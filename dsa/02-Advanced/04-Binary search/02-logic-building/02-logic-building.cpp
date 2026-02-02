// Search in rotated sorted array-II
/*
 Given an integer array nums, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.


Examples:
Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3

Output: True

Explanation: The element 3 is present in the array. So, the answer is True.

*/
class Solution
{
public:
    bool searchInARotatedSortedArrayII(vector<int> &nums, int k)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == k)
                return true;
            if (nums[mid] == nums[low] && nums[low] == nums[high])
            {
                low++;
                high--;
                continue;
            }
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
                if (nums[high] >= k && k >= nums[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

// Find minimum in Rotated Sorted Array
/*
Given an integer array nums of size N, sorted in ascending order with distinct values, and then rotated an unknown number of times (between 1 and N), find the minimum element in the array.


Examples:
Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

Output: 0

Explanation: Here, the element 0 is the minimum element in the array.*/
class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int low = 0;
        int high = arr.size() - 1;
        int num = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[low] <= arr[high])
            {
                num = min(num, arr[low]);
                break;
            }
            if (arr[low] <= arr[mid])
            {
                num = min(num, arr[low]);
                low = mid + 1;
            }
            else
            {
                num = min(num, arr[mid]);
                high = mid - 1;
            }
        }
        return num;
    }
};
// Find out how many times the array is rotated:--index of the smallest element is the number of rotations
/*
Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.


Examples:
Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

Output: 4

Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.
*/

class Solution {
   public:
    /* Function to find the number of
       rotations in a rotated sorted array */
    int findKRotation(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        int index = -1;
        while (low <= high) {
            int mid = (low + high) / 2;

            /* Search space is already sorted
            then nums[low] will always be
            the minimum in that search space */
            if (nums[low] <= nums[high]) {
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                break;
            }
            // If left part is sorted update the ans
            if (nums[low] <= nums[mid]) {
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                // Eliminate left half
                low = mid + 1;
            } else {
                /*update the ans if it
                is less than nums[mid] */
                if (nums[mid] < ans) {
                    index = mid;
                    ans = nums[mid];
                }
                // Eliminate right half
                high = mid - 1;
            }
        }
        // Return the index as answer
        return index;
    }
};

//Single element in sorted array


/*
Given an array nums sorted in non-decreasing order. Every number in the array except one appears twice. Find the single number in the array.


Examples:
Input :nums = [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6]

Output:4

Explanation: Only the number 4 appears once in the array.*/

// brute force approach
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;

        if (n == 1)
            return nums[0]; // optional but clear

        while (i < n - 1)
        {
            if (nums[i] == nums[i + 1])
            {
                i += 2;
            }
            else
            {
                return nums[i];
            }
        }

        // unique element is at the last index
        return nums[n - 1];
    }
};

// xor approach
class Solution
{
public:
    /* Function to find the single non
    duplicate element in a sorted array */
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size(); // Size of the array.
        int ans = 0;

        /* XOR all the elements to find
        the single non-duplicate element.*/
        for (int i = 0; i < n; i++)
        {
            ans = ans ^ nums[i];
        }

        /* Return the single non
        duplicate element found.*/
        return ans;
    }
};

// binary search approach
class Solution {
public:
    /* Function to find the single non 
    duplicate element in a sorted array*/
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); // Size of the array.

        // Edge cases:
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            // If nums[mid] is the single element:
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            // We are in the left part:
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                // Eliminate the left half:
                low = mid + 1;
            }
            // We are in the right part:
            else {
                // Eliminate the right half:
                high = mid - 1;
            }
        }

        // Dummy return statement:
        return -1;
    }
};