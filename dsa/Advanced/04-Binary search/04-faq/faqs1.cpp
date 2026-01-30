// aggressive cows
/*
Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.


Example 1

Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]

Output: 3

Explanation:

The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively.

In no manner can we increase the minimum distance beyond 3.
*/

// approach 1: linear search
class Solution
{
private:
    /* Function to check if we can place 'cows' cows
    with at least 'dist' distance apart in 'stalls' */
    bool canWePlace(vector<int> &nums, int dist, int cows)
    {

        // Size of array
        int n = nums.size();

        // Number of cows placed
        int cntCows = 1;

        // Position of last placed cow
        int last = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - last >= dist)
            {

                // Place next cow
                cntCows++;

                // Update the last location
                last = nums[i];
            }
            if (cntCows >= cows)
                return true;
        }
        return false;
    }

public:
    /* Function to find the maximum possible minimum
    distance 'k' cows can have between them in 'stalls' */
    int aggressiveCows(vector<int> &nums, int k)
    {

        // Size of array
        int n = nums.size();
        // Sort the nums
        sort(nums.begin(), nums.end());

        int limit = nums[n - 1] - nums[0];
        for (int i = 1; i <= limit; i++)
        {
            if (canWePlace(nums, i, k) == false)
            {
                return (i - 1);
            }
        }
        // Retrun the answer
        return limit;
    }
};

// approach 2: binary search
class Solution
{
private:
    bool isItPossible(vector<int> &stalls, int dist, int k)
    {
        int lastCow = stalls[0];
        int n = stalls.size();
        bool isPossible = false;
        k--;

        for (int i = 1; i < n; i++)
        {
            if ((stalls[i] - lastCow) >= dist)
            {
                lastCow = stalls[i];
                k--;
            }
            if (k == 0)
            {
                isPossible = true;
            };
            // cout<<"k: "<<k<<" dist: "<<dist<<endl;
        }
        return isPossible;
    }

public:
    int aggressiveCows(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int left = 1;
        int right = nums[n - 1] - nums[0];

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isItPossible(nums, mid, k) == true)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return right;
    }
};
// find peak element
/*
Given an array arr of integers. A peak element is defined as an element greater than both of its neighbors.

Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i].



Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.



Note:

As there can be many peak values, "true" is given as output if the returned index is a peak number, otherwise "false".

Example 1

Input : arr = [1, 2, 3, 4, 5, 6, 7, 8, 5, 1]

Output: 7

Explanation: In this example, there is only 1 peak that is at index 7.

*/
// approach 1: linear search
class Solution
{
public:
    // Function to find the peak element in the array
    int findPeakElement(vector<int> &arr)
    {
        // Size of array
        int n = arr.size();

        /* Iterate through the array
        to find the peak element */
        for (int i = 0; i < n; i++)
        {

            // Check if arr[i] is a peak
            if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))
            {

                // Return the index of peak element
                return i;
            }
        }
        /* Return -1 if no peak element
        found (dummy return) */
        return -1;
    }
};

// approach 2: binary search
class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int low = 1;
        int high = arr.size() - 2;
        int n = arr.size();

        if (arr.size() == 1)
            return 0;
        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
};

// book allocation problem
// Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students, allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.

// Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1.

// Example 1

// Input: nums = [12, 34, 67, 90], m=2

// Output: 113

// Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

// approach 1: linear search
class Solution
{
private:
    /* Function to count the number of
    students required given the maximum
    pages each student can read */
    int countStudents(vector<int> &nums, int pages)
    {
        // Size of array
        int n = nums.size();

        int students = 1;
        int pagesStudent = 0;

        for (int i = 0; i < n; i++)
        {
            if (pagesStudent + nums[i] <= pages)
            {
                // Add pages to current student
                pagesStudent += nums[i];
            }
            else
            {
                // Add pages to next student
                students++;
                pagesStudent = nums[i];
            }
        }
        return students;
    }

public:
    /*Function to allocate the book to ‘m’
    students such that the maximum number
    of pages assigned to a student is minimum */
    int findPages(vector<int> &nums, int m)
    {
        int n = nums.size();

        // Book allocation impossible
        if (m > n)
            return -1;

        // Calculate the range for binary search
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        // Linear search for minimum maximum pages
        for (int pages = low; pages <= high; pages++)
        {
            if (countStudents(nums, pages) <= m)
            {
                return pages;
            }
        }
        return low;
    }
};

// approach 2: binary search
class Solution
{
private:
    int countStudents(vector<int> &nums, int maxPages)
    {
        int n = nums.size();
        int numsStudent = 1;
        int studentPages = 0;
        for (int i = 0; i < n; i++)
        {
            if (studentPages + nums[i] <= maxPages)
            {
                studentPages += nums[i];
            }
            else
            {
                // then i will have to introduce one more student
                numsStudent++;
                studentPages = nums[i]; // now the new student will have these
                                        // new current pages
            };
        };
        return numsStudent;
    };

public:
    int findPages(vector<int> &nums, int m)
    {
        int n = nums.size();
        int high = accumulate(nums.begin(), nums.end(), 0);
        int low = *max_element(nums.begin(), nums.end());
        int ans = -1;
        if (n < m)
            return ans;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (m >= countStudents(nums, mid))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// median of two sorted arrays
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1

Input: nums1 = [1,3], nums2 = [2]

Output: 2.00000
*/
// brute force
class Solution
{
public:
    // Function to find the median of two sorted arrays.
    double median(vector<int> &arr1, vector<int> &arr2)
    {
        // Size of two given arrays
        int n1 = arr1.size(), n2 = arr2.size();

        vector<int> merged;
        // Apply the merge step
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
                merged.push_back(arr1[i++]);
            else
                merged.push_back(arr2[j++]);
        }

        // Copy the remaining elements
        while (i < n1)
            merged.push_back(arr1[i++]);
        while (j < n2)
            merged.push_back(arr2[j++]);

        // Find the median
        int n = n1 + n2;
        if (n % 2 == 1)
        {
            return (double)merged[n / 2];
        }

        double median = ((double)merged[n / 2] + (double)merged[(n / 2) - 1]) / 2.0;
        return median;
    }
};

// better approach
class Solution
{
public:
    // Function to find the median of two sorted arrays.
    double median(vector<int> &arr1, vector<int> &arr2)
    {
        // Size of two given arrays
        int n1 = arr1.size(), n2 = arr2.size();
        int n = n1 + n2; // Total size

        // Required indices for median calculation
        int ind2 = n / 2;
        int ind1 = ind2 - 1;
        int cnt = 0;
        int ind1el = -1, ind2el = -1;

        // Apply the merge step
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                if (cnt == ind1)
                    ind1el = arr1[i];
                if (cnt == ind2)
                    ind2el = arr1[i];
                cnt++;
                i++;
            }
            else
            {
                if (cnt == ind1)
                    ind1el = arr2[j];
                if (cnt == ind2)
                    ind2el = arr2[j];
                cnt++;
                j++;
            }
        }

        // Copy the remaining elements
        while (i < n1)
        {
            if (cnt == ind1)
                ind1el = arr1[i];
            if (cnt == ind2)
                ind2el = arr1[i];
            cnt++;
            i++;
        }
        while (j < n2)
        {
            if (cnt == ind1)
                ind1el = arr2[j];
            if (cnt == ind2)
                ind2el = arr2[j];
            cnt++;
            j++;
        }

        // Find the median
        if (n % 2 == 1)
        {
            return (double)ind2el;
        }

        return (double)((double)(ind1el + ind2el)) / 2.0;
    }
};

// optimal approach
class Solution
{
public:
    // Function to find the median of two sorted arrays.
    double median(vector<int> &arr1, vector<int> &arr2)
    {
        // Size of two given arrays
        int n1 = arr1.size(), n2 = arr2.size();

        /* Ensure arr1 is not larger than
        arr2 to simplify implementation*/
        if (n1 > n2)
            return median(arr2, arr1);

        int n = n1 + n2;

        // Length of left half
        int left = (n1 + n2 + 1) / 2;

        // Apply binary search
        int low = 0, high = n1;
        while (low <= high)
        {
            // Calculate mid index for arr1
            int mid1 = (low + high) >> 1;

            // Calculate mid index for arr2
            int mid2 = left - mid1;

            // Calculate l1, l2, r1, and r2
            int l1 = (mid1 > 0) ? arr1[mid1 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? arr1[mid1] : INT_MAX;
            int l2 = (mid2 > 0) ? arr2[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n2) ? arr2[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1)
            {
                // If condition for finding median
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
            {
                // Eliminate the right half of arr1
                high = mid1 - 1;
            }
            else
            {
                // Eliminate the left half of arr1
                low = mid1 + 1;
            }
        }
        // Dummy statement
        return 0;
    }
};
