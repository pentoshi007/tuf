// linear search
class Solution
{
public:
    int linearSearch(vector<int> &nums, int target)
    {
        // your code goes here
        for (int i = 0; i < nums.size(); i++)
        {
            if (target == nums[i])
                return i;
        }
        return -1;
    }
};

// find largest element
class Solution
{
public:
    int largestElement(vector<int> &nums)
    {
        int largest = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            largest = max(largest, nums[i]);
        }
        return largest;
    }
};

// second largest element
class Solution
{
public:
    int secondLargestElement(vector<int> &nums)
    {
        // your code goes here
        int largest = nums[0];
        int secondLargest = INT_MIN;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > largest)
            {
                secondLargest = largest;
                largest = nums[i];
            }
            else if (nums[i] < largest && nums[i] > secondLargest)
            {
                secondLargest = nums[i];
            }
        }
        return secondLargest != INT_MIN ? secondLargest : -1;
    }
};

// maximum consecutive ones
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxi = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
                maxi = max(maxi, count);
            }
            else
            {
                count = 0;
            }
        }
        return maxi;
    };
};

// left rotate array by one
class Solution
{
public:
    void rotateArrayByOne(vector<int> &nums)
    {
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i - 1] = nums[i];
        }
        nums[nums.size() - 1] = temp;
    }
};
// left rotate array by k--brute force

class Solution
{
public:
    // Function to rotate the array to the left by k positions
    void rotateArray(vector<int> &nums, int k)
    {
        int n = nums.size(); // Size of array
        k = k % n;           // To avoid unnecessary rotations

        vector<int> temp;

        // Store first k elements in a temporary array
        for (int i = 0; i < k; i++)
        {
            temp.push_back(nums[i]);
        }

        // Shift n-k elements of given array to the front
        for (int i = k; i < n; i++)
        {
            nums[i - k] = nums[i];
        }

        // Copy back the k elemnents at the end
        for (int i = 0; i < k; i++)
        {
            nums[n - k + i] = temp[i];
        }
    }
};
// left rotate array by k--optimal

class Solution
{
private:
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++, end--;
        }
    }

public:
    // Function to rotate the array to the left by k positions
    void rotateArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
        reverse(nums, 0, n - 1);
    }
};