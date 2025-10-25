// rotate matrix by 90 degrees
/*
Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.



The rotation must be done in place, meaning the input 2D matrix must be modified directly.

*/
//---brute force
class Solution
{
public:
    /* Function to rotate the given
    matrix by 90 degrees clockwise*/
    void rotateMatrix(vector<vector<int>> &matrix)
    {

        /* Get the size of the matrix
        (assuming it's a square matrix)*/
        int n = matrix.size();

        // Initialize new matrix to store rotated values
        vector<vector<int>> rotated(n, vector<int>(n, 0));

        // Iterate through elements of original matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                /* Rotate the element to its new
                position in the rotated matrix
                New position is (j, n - i - 1)
                in the rotated matrix*/

                rotated[j][n - i - 1] = matrix[i][j];
            }
        }

        // copy rotated elements to matrix
        for (int i = 0; i < rotated.size(); i++)
        {
            for (int j = 0; j < rotated[0].size(); j++)
            {
                matrix[i][j] = rotated[i][j];
            }
        }
    }
};
//---optimal
class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix[0].size();
        // swap-to find Transpose
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int k = 0; k < n; k++)
        {
            reverse(matrix[k].begin(), matrix[k].end());
        }
    }
};

//---Two Sum---
/*
Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.



Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in increasing order.


Examples:
Input: nums = [1, 6, 2, 10, 3], target = 7

Output: [0, 1]

Explanation:

nums[0] + nums[1] = 1 + 6 = 7
*/

//---brute force
class Solution
{
public:
    /*Function to find two indices in the array `nums`
    such that their elements sum up to `target`.*/

    vector<int> twoSum(vector<int> &nums, int target)
    {

        int n = nums.size();
        // create ans vector to store ans
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                /*if nums[i] + nums[j] is equal to
                target put i and j in ans*/
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }

        // Return {-1, -1} if no such pair is found
        return {-1, -1};
    }
};

//---better
class Solution
{
public:
    /* Function to find two indices in the array `nums`
           such that their elements sum up to `target`.
        */
    vector<int> twoSum(vector<int> &nums, int target)
    {

        // Map to store (element, index) pairs
        unordered_map<int, int> mpp;

        // Size of the nums vector
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // Current number in the vector
            int num = nums[i];
            // Number needed to reach the target
            int moreNeeded = target - num;

            // Check if the complement exists in map
            if (mpp.find(moreNeeded) != mpp.end())
            {
                /* Return the indices of the
                two numbers that sum up to target*/
                return {mpp[moreNeeded], i};
            }

            // Store current number and its index in map
            mpp[num] = i;
        }

        // If no such pair found, return {-1, -1}
        return {-1, -1};
    }
};

//---optimal {in only case where yes or no is asked, here we are returning the indices, so using extra space}
class Solution
{
public:
    /* Function to find two indices in the array `nums`
       such that their elements sum up to `target`.
    */
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Size of the nums vector
        int n = nums.size();

        // Vector to store indices of two numbers
        vector<int> ans;

        vector<vector<int>> eleIndex;
        for (int i = 0; i < nums.size(); i++)
        {
            eleIndex.push_back({nums[i], i});
        }

        // Sort by first element in ascending order
        sort(eleIndex.begin(), eleIndex.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        /* Two pointers: one starting
        from left and one from right*/
        int left = 0, right = n - 1;

        while (left < right)
        {
            /* Calculate sum of elements
            at left and right pointers*/
            int sum = eleIndex[left][0] + eleIndex[right][0];

            if (sum == target)
            {

                /* If sum equals target,
                store indices and return*/
                ans.push_back(eleIndex[left][1]);
                ans.push_back(eleIndex[right][1]);
                return ans;
            }
            else if (sum < target)
            {

                /* If sum is less than target,
                move left pointer to the right*/
                left++;
            }
            else
            {

                /* If sum is greater than target,
                move right pointer to the left*/
                right--;
            }
        }

        // If no such pair found, return {-1, -1}
        return {-1, -1};
    }
};

//---three sum---
/*
Given an integer array nums. Return all triplets such that:



i != j, i != k, and j != k


nums[i] + nums[j] + nums[k] == 0.


Notice that the solution set must not contain duplicate triplets. One element can be a part of multiple triplets. The output and the triplets can be returned in any order.


Examples:
Input: nums = [2, -2, 0, 3, -3, 5]

Output: [[-2, 0, 2], [-3, -2, 5], [-3, 0, 3]]

Explanation:

nums[1] + nums[2] + nums[0] = 0

nums[4] + nums[1] + nums[5] = 0

nums[4] + nums[2] + nums[3] = 0
*/
//---brute force
class Solution
{
public:
    // Function to find triplets having sum equals to target
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // Set to store unique triplets
        set<vector<int>> tripletSet;

        int n = nums.size();

        // Check all possible triplets
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        // Found a triplet that sums up to target
                        vector<int> temp = {nums[i], nums[j], nums[k]};

                        /* Sort the triplet to ensure
                         uniqueness when storing in set*/
                        sort(temp.begin(), temp.end());
                        tripletSet.insert(temp);
                    }
                }
            }
        }

        // Convert set to vector (unique triplets)
        vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());

        // Return the ans
        return ans;
    }
};

//---better
class Solution
{
public:
    // Function to find triplets having sum equals to target
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // Set to store unique triplets
        set<vector<int>> tripletSet;

        int n = nums.size();

        // Check all possible triplets
        for (int i = 0; i < n; i++)
        {
            // Set to store elements seen so far in the loop
            set<int> hashset;

            for (int j = i + 1; j < n; j++)
            {
                // Calculate the 3rd element needed to reach target
                int third = -(nums[i] + nums[j]);

                /* Find if third element exists in
                hashset (complements seen so far)*/
                if (hashset.find(third) != hashset.end())
                {
                    // Found a triplet that sums up to target
                    vector<int> temp = {nums[i], nums[j], third};

                    /* Sort the triplet to ensure
                    uniqueness when storing in set*/
                    sort(temp.begin(), temp.end());
                    tripletSet.insert(temp);
                }

                /* Insert the current element
                into hashset for future checks*/
                hashset.insert(nums[j]);
            }
        }

        // Convert set to vector (unique triplets)
        vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());

        // Return the ans
        return ans;
    }
};

//---optimal
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int target = 0;
        int n = nums.size();
        vector<vector<int>> ans;
        int sum;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                sum = nums[i] + nums[j] + nums[k];
                if (sum < target)
                {
                    j++;
                }
                else if (sum > target)
                {
                    k--;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while (k > j && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};

//---4 sum---
/*
Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:



a, b, c, d are all distinct valid indices of nums.


nums[a] + nums[b] + nums[c] + nums[d] == target.


Notice that the solution set must not contain duplicate quadruplets. One element can be a part of multiple quadruplets. The output and the quadruplets can be returned in any order.


Examples:
Input: nums = [1, -2, 3, 5, 7, 9], target = 7

Output: [[-2, 1, 3, 5]]

Explanation:

nums[1] + nums[0] + nums[2] + nums[3] = 7
*/

//---brute force
class Solution
{
public:
    // function to find quadruplets having sum equal to target
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // Size of the array
        int n = nums.size();

        // Set to store unique quadruplets
        set<vector<int>> st;

        // Checking all possible quadruplets
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        // Calculate the sum of the current quadruplet
                        long long sum = nums[i] + nums[j] + nums[k] + nums[l];

                        // Check if the sum matches the target
                        if (sum == target)
                        {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            // Sort the quadruplet to ensure uniqueness
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        // Convert set to vector (unique quadruplets)
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//---better
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // Size of the array
        int n = nums.size();

        // Set to store unique quadruplets
        set<vector<int>> st;

        // Checking all possible quadruplets
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                // Set to store elements seen so far in the loop
                set<long long> hashset;
                for (int k = j + 1; k < n; k++)
                {

                    // Calculate the fourth element needed to reach target
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;

                    /* Find if fourth element exists in
                    hashset (complements seen so far)*/
                    if (hashset.find(fourth) != hashset.end())
                    {

                        // Found a quadruplet that sums up to target
                        vector<int> temp = {nums[i], nums[j], nums[k], static_cast<int>(fourth)};
                        // Sort the quadruplet to ensure uniqueness
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    // Insert the kth element into hashset for future checks
                    hashset.insert(nums[k]);
                }
            }
        }

        // Convert set to vector (unique quadruplets)
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//---optimal
class Solution
{
public:
    // function to find quadruplets having sum equals to target
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // Vector to store the quadruplets that sum up to target
        vector<vector<int>> ans;

        int n = nums.size();

        // Sort the input array nums
        sort(nums.begin(), nums.end());

        // Iterate through the array to find quadruplets
        for (int i = 0; i < n; i++)
        {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Two pointers approach
                int k = j + 1;
                int l = n - 1;

                while (k < l)
                {
                    long long sum = nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                        // Found a quadruplet that sums up to target
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);

                        // Skip duplicates for k and l
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};