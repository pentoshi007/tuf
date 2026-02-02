//=============================================
// Sort an array of 0's 1's and 2's
//=============================================

/*
Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.



The sorting must be done in-place, without making a copy of the original array.


Examples:
Input: nums = [1, 0, 2, 1, 0]

Output: [0, 0, 1, 1, 2]

Explanation:

The nums array in sorted order has 2 zeroes, 2 ones and 1 two
*/

// brute force approach
class Solution
{
public:
    // Function to sort the array
    void sortZeroOneTwo(vector<int> &nums)
    {
        // Sort the vector using std::sort
        sort(nums.begin(), nums.end());
    }
};

// better approach
class Solution
{
public:
    // Function to sort the array containing only 0s, 1s, and 2s
    void sortZeroOneTwo(vector<int> &nums)
    {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        // Counting the number of 0s, 1s, and 2s in the array
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                cnt0++;
            else if (nums[i] == 1)
                cnt1++;
            else
                cnt2++;
        }

        /* Placing the elements in the
        original array based on counts*/
        // placing 0's
        for (int i = 0; i < cnt0; i++)
            nums[i] = 0;

        // placing 1's
        for (int i = cnt0; i < cnt0 + cnt1; i++)
            nums[i] = 1;

        // placing 2's
        for (int i = cnt0 + cnt1; i < nums.size(); i++)
            nums[i] = 2;
    }
};

// optimal approach---mine
class Solution
{
public:
    void sortZeroOneTwo(vector<int> &nums)
    {
        int n = nums.size();
        int zero = 0;
        int two = n - 1;
        for (int i = 0; i <= two; i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[zero], nums[i]);
                zero++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[two], nums[i]);
                two--;
                i--;
            }
        }
    }
};

// optimal approach -- given
class Solution
{
public:
    // Function to sort the array containing only 0s, 1s, and 2s
    void sortZeroOneTwo(vector<int> &nums)
    {

        // 3 pointers: low, mid, high
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {

                /* Swap nums[low] and nums[mid], then
                 move both low and mid pointers forward*/
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                // Move mid pointer forward
                mid++;
            }
            else
            {
                /* Swap nums[mid] and nums[high],
                then move high pointer backward*/
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

//=============================================
// Kadane's Algorithm
/*
 Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.



A subarray is a contiguous non-empty sequence of elements within an array.


Examples:
Input: nums = [2, 3, 5, -2, 7, -4]

Output: 15

Explanation:

The subarray from index 0 to index 4 has the largest sum = 15
*/
// -------brute force approach-------
class Solution
{
public:
    // Function to find maximum sum of subarrays
    int maxSubArray(vector<int> &nums)
    {

        /* Initialize maximum sum with
        the smallest possible integer*/
        int maxi = INT_MIN;

        // Iterate over each starting index of subarrays
        for (int i = 0; i < nums.size(); i++)
        {

            /* Iterate over each ending index
            of subarrays starting from i*/
            for (int j = i; j < nums.size(); j++)
            {

                // Variable to store the sum of the current subarray
                int sum = 0;

                // Calculate the sum of subarray nums[i...j]
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }

                /* Update maxi with the maximum of its current
                value and the sum of the current subarray*/
                maxi = max(maxi, sum);
            }
        }

        // Return the maximum subarray sum found
        return maxi;
    }
};
//-------better approach-------
class Solution
{
public:
    // Function to find maximum sum of subarrays
    int maxSubArray(vector<int> &nums)
    {

        /* Initialize maximum sum with
        the smallest possible integer*/
        int maxi = INT_MIN;

        // Iterate over each starting index of subarrays
        for (int i = 0; i < nums.size(); i++)
        {

            /* Variable to store the sum
            of the current subarray*/
            int sum = 0;

            /* Iterate over each ending index
            of subarrays starting from i*/
            for (int j = i; j < nums.size(); j++)
            {

                /* Add the current element nums[j] to
                the sum i.e. sum of nums[i...j-1]*/
                sum += nums[j];

                /* Update maxi with the maximum of its current
                value and the sum of the current subarray*/
                maxi = max(maxi, sum);
            }
        }

        // Return the maximum subarray sum found
        return maxi;
    }
};
//-------optimal approach-------kadane's algorithm
class Solution
{
public:
    // Function to find maximum sum of subarrays and print the subarray having maximum sum
    int maxSubArray(vector<int> &nums)
    {

        // maximum sum
        long long maxi = LLONG_MIN;

        // current sum of subarray
        long long sum = 0;

        // starting index of current subarray
        int start = 0;

        // indices of the maximum sum subarray
        int ansStart = -1, ansEnd = -1;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {

            // update starting index if sum is reset
            if (sum == 0)
            {
                start = i;
            }

            // add current element to the sum
            sum += nums[i];

            /* Update maxi and subarray indice
            s if current sum is greater*/
            if (sum > maxi)
            {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }

            // Reset sum to 0 if it becomes negative
            if (sum < 0)
            {
                sum = 0;
            }
        }

        // Printing the subarray
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++)
        {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;

        // Return the maximum subarray sum found
        return maxi;
    }
};

//=============================================
// Next Permutation

/*
 A permutation of an array of integers is an arrangement of its members into a sequence or linear order.



For example, for arr = [1,2,3], the following are all the permutations of arr:

[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].



The next permutation of an array of integers is the next lexicographically greater permutation of its integers.

More formally, if all the permutations of the array are sorted in lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted order.



If such arrangement is not possible (i.e., the array is the last permutation), then rearrange it to the lowest possible order (i.e., sorted in ascending order).



You must rearrange the numbers in-place and use only constant extra memory.


Examples:
Input: nums = [1,2,3]

Output: [1,3,2]

Explanation:

The next permutation of [1,2,3] is [1,3,2].
*/
//-------brute force approach-------

class Solution
{
public:
    // Function to get the next permutation of given array
    void nextPermutation(vector<int> &nums)
    {
        // Get all the Permutations
        vector<vector<int>> ans = getAllPermutations(nums);

        int index = -1; // Current permutation index

        /* Perform a linear search to get the
        permutation of current permutation */
        for (int i = 0; i < ans.size(); i++)
        {
            if (nums == ans[i])
            {
                index = i;
                break;
            }
        }

        // Store the next permutation in-place
        if (index == ans.size() - 1)
            nums = ans[0];
        else
            nums = ans[index + 1];

        return;
    }

private:
    /* Function to generate all permutations of
    the given array in sorted order */
    vector<vector<int>> getAllPermutations(vector<int> &nums)
    {
        vector<vector<int>> ans; // To store the permutation

        // Recursive Helper function call
        helperFunc(0, nums, ans);

        sort(ans.begin(), ans.end()); // Sort the permutations
        return ans;                   // Return the result
    }

    // Helper function to get all the permutations of the given array
    void helperFunc(int ind, vector<int> &nums,
                    vector<vector<int>> &ans)
    {

        // Base case
        if (ind == nums.size())
        {
            // Add the permutation to the answer
            ans.push_back(nums);
            return;
        }

        // Traverse the array
        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[ind], nums[i]); // Swap-In

            // Recursively call the helper function
            helperFunc(ind + 1, nums, ans);

            swap(nums[ind], nums[i]); // Swap-Out
        }

        return;
    }
};
// optimal approach
class Solution
{
public:
    // Function to get the next permutation of given array
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(); // Size of the given array

        // To store the index of the first smaller element from right
        int ind = -1;

        // Find the first index from the end where nums[i] < nums[i+1]
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                ind = i;
                break;
            }
        }

        /* If no such index exists, array is in descending order
         So, reverse it to get the smallest permutation */
        if (ind == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the element just greater than nums[ind] from the end
        for (int i = n - 1; i > ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]); // Swap with nums[ind]
                break;
            }
        }

        // Reverse the right half to get the next smallest permutation
        reverse(nums.begin() + ind + 1, nums.end());
        return;
    }
};
