// Longest Consecutive Sequence in an Array
/*
Given an array nums of n integers.



Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.


Examples:
Input: nums = [100, 4, 200, 1, 3, 2]

Output: 4

Explanation:

The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.
 */

// brute force
class Solution
{
private:
    // Helper function to perform linear search
    bool linearSearch(vector<int> &a, int num)
    {
        int n = a.size();
        // Traverse through the array
        for (int i = 0; i < n; i++)
        {
            if (a[i] == num)
                return true;
        }
        return false;
    }

public:
    // Function to find the longest consecutive sequence
    int longestConsecutive(vector<int> &nums)
    {
        // If the array is empty
        if (nums.size() == 0)
        {
            return 0;
        }
        int n = nums.size();
        // Initialize the longest sequence length
        int longest = 1;

        // Iterate through each element in the array
        for (int i = 0; i < n; i++)
        {
            // Current element
            int x = nums[i];
            // Count of the current sequence
            int cnt = 1;

            // Search for consecutive numbers
            while (linearSearch(nums, x + 1) == true)
            {
                // Move to the next number in the sequence
                x += 1;
                // Increment the count of the sequence
                cnt += 1;
            }

            // Update the longest sequence length found so far
            longest = max(longest, cnt);
        }
        return longest;
    }
};
// better approach
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int longest = 1;
        int count = 1;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                continue;
            else if (nums[i + 1] == (nums[i] + 1))
            {
                count++;
                longest = max(longest, count);
            }
            else
            {
                longest = max(longest, count);

                count = 1;
            }
        }
        return longest;
    }
};

// best approach
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int longest = 1;
        unordered_set<int> st(nums.begin(), nums.end());
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int count = 1;

                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    x++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};

//====
// Longest subarray with sum K
/*Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.


Examples:
Input: nums = [10, 5, 2, 7, 1, 9],  k=15

Output: 4

Explanation:

The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.
*/
// brute force
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLength = 0;

        // starting index
        for (int startIndex = 0; startIndex < n; startIndex++)
        {
            // ending index
            for (int endIndex = startIndex; endIndex < n; endIndex++)
            {
                /* add all the elements of
                   subarray = nums[startIndex...endIndex]  */
                int currentSum = 0;
                for (int i = startIndex; i <= endIndex; i++)
                {
                    currentSum += nums[i];
                }

                if (currentSum == k)
                    maxLength = max(maxLength, endIndex - startIndex + 1);
            }
        }
        return maxLength;
    }
};
// optimal(positives+negatives numbers)
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();

        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            // calculate the prefix sum till index i
            sum += nums[i];

            // if the sum equals k, update maxLen
            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            // calculate the sum of remaining part i.e., sum - k
            int rem = sum - k;

            // calculate the length and update maxLen
            if (preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // update the map if sum is not already present
            if (preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};
// optimal(only positives numbers)
class Solution
{
public:
    // Function to find the length of longest subarray having sum k
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();

        // To store the maximum length of the subarray
        int maxLen = 0;

        // Pointers to mark the start and end of window
        int left = 0, right = 0;

        // To store the sum of elements in the window
        int sum = nums[0];

        // Traverse all the elements
        while (right < n)
        {

            // If the sum exceeds K, shrink the window
            while (left <= right && sum > k)
            {
                sum -= nums[left];
                left++;
            }

            // store the maximum length
            if (sum == k)
            {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
            if (right < n)
                sum += nums[right];
        }

        return maxLen;
    }
};
//====
// Count subarrays with given sum
// brute force
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        // Number of subarrays
        int count = 0;

        // starting index
        for (int startIndex = 0; startIndex < n; startIndex++)
        {
            int currentSum = 0;
            // ending index
            for (int endIndex = startIndex; endIndex < n; endIndex++)
            {
                // calculate the sum of subarray [startIndex...endIndex]
                // sum of [startIndex..endIndex-1] + nums[endIndex]
                currentSum += nums[endIndex];

                // Increase the count if currentSum == k:
                if (currentSum == k)
                    count++;
            }
        }
        return count;
    }
};
// optimal
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        int n = nums.size();
        int presum = 0;
        map<int, int> mpp;
        mpp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            presum = presum + nums[i];
            int remove = presum - k;
            count += mpp[remove]; // mpp[sum] will be zero, so no effect on
                                  // count if presum doesn't exist
            mpp[presum]++;
        }

        return count;
    }
};

//====
// Count subarrays with given xor K
/*
Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.


Examples:
Input : nums = [4, 2, 2, 6, 4], k = 6



Output : 4



Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]
 */
// brute force
class Solution
{
public:
    // Function to count the number of subarrays with XOR k
    int subarraysWithXorK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;

        // Step 1: Generate subarrays
        for (int i = 0; i < n; i++)
        {
            int xorr = 0;
            for (int j = i; j < n; j++)
            {
                /* Step 2: Calculate XOR of
                   all elements in the subarray */
                xorr = xorr ^ nums[j];

                // Step 3: Check XOR and count
                if (xorr == k)
                    cnt++;
            }
        }
        return cnt;
    }
};

// optimal
class Solution
{
public:
    int subarraysWithXorK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int xr = 0;
        map<int, int> mpp;
        // setting the value of 0.
        mpp[xr]++;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            // prefix XOR till index i:
            xr = xr ^ nums[i];

            // By formula: x = xr^k:
            int x = xr ^ k;

            // add the occurrence of xr^k to the count:
            cnt += mpp[x];

            // Insert the prefix xor till index i into the map:
            mpp[xr]++;
        }
        return cnt;
    }
};