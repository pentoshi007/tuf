// find leaders in an array--right to it, all elements should be smaller
class Solution
{
public:
    // Function to find leaders in an array.
    vector<int> leaders(vector<int> &nums)
    {
        vector<int> ans;

        // Iterate through each element in nums
        for (int i = 0; i < nums.size(); i++)
        {
            bool leader = true;

            /* Check whether nums[i] is greater
            than all elements to its right*/
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] >= nums[i])
                {
                    /* If any element to the right is greater
                    or equal, nums[i] is not a leader*/
                    leader = false;
                    break;
                }
            }

            // If nums[i] is a leader, add it to the ans vector
            if (leader)
            {
                ans.push_back(nums[i]);
            }
        }

        // Return the leaders
        return ans;
    }
};

// optimal solution
class Solution
{
public:
    vector<int> leaders(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > maxi)
            {
                // to be leader, every element should be greater than its prev maximum.
                ans.push_back(nums[i]);
                maxi = nums[i]; // then if element is greater than prev max, element itself becomes new max
            }
        }
        reverse(ans.begin(), ans.end());

        // Return the leaders
        return ans;
    }
};
//----------------------------------------------------
// Rearrange array elements by sign
/*
Given an integer array nums of even length consisting of an equal number of positive and negative integers.Return the answer array in such a way that the given conditions are met:



Every consecutive pair of integers have opposite signs.


For all integers with the same sign, the order in which they were present in nums is preserved.


The rearranged array begins with a positive integer.

Input : nums = [2, 4, 5, -1, -3, -4]

Output : [2, -1, 4, -3, 5, -4]

Explanation:

The positive number 2, 4, 5 maintain their relative positions and -1, -3, -4 maintain their relative positions

Input : nums = [1, -1, -3, -4, 2, 3]

Output : [1, -1, 2, -3, 3, -4]

Explanation:

The positive number 1, 2, 3 maintain their relative positions and -1, -3, -4 maintain their relative positions

*/

//--brute force
class Solution
{
public:
    // Function to rearrange the given array by signs
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();

        // Define 2 vectors, one for storing positive
        // and the other for negative elements of the array
        vector<int> pos, neg;

        // Segregate the array into positives and negatives
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }

        // Positives on even indices, negatives on odd
        for (int i = 0; i < n / 2; ++i)
        {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }

        // Return the result
        return nums;
    }
};

//--optimal----postive on even indices, negative on odd indices-- create extra arrays for positive and negative elements--then place them in the array
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0;
        int negIndex = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                ans[posIndex] = nums[i];
                posIndex = posIndex + 2;
            }
            else
            {
                ans[negIndex] = nums[i];
                negIndex = negIndex + 2;
            }
        }
        return ans;
    }
};

//----------------------------------------------------
// Print the matrix in a spiral order
/*
 Given an M * N matrix, print the elements in a clockwise spiral manner.



Return an array with the elements in the order of their appearance when printed in a spiral manner.


Examples:
Input: matrix = [[1, 2, 3], [4 ,5 ,6], [7, 8, 9]]

Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]

Explanation:

The elements in the spiral order are 1, 2, 3 -> 6, 9 -> 8, 7 -> 4, 5

Input: matrix = [[1, 2, 3, 4], [5, 6, 7, 8]]

Output: [1, 2, 3, 4, 8, 7, 6, 5]

Explanation:

The elements in the spiral order are 1, 2, 3, 4 -> 8, 7, 6, 5*/

//--solution
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;
        vector<int> ans;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top > bottom)
                break;
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            };
            bottom--;
            if (left > right)
                break;
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};