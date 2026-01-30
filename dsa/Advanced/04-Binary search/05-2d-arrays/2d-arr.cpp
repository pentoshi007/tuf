// Find row with maximum 1's
// Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.

// If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.

// Example 1

// Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]

// Output: 0

// Explanation: The row with the maximum number of ones is 0 (0 - indexed).
// Approach 1: Linear search
class Solution
{
public:
    /* Function to find the row
    with the maximum number of 1's*/
    int rowWithMax1s(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        /* Variable to store the
        maximum count of 1's found*/
        int cnt_max = 0;

        /* Variable to store the index
        of the row with max 1's*/
        int index = -1;

        // Traverse the matrix row by row
        for (int i = 0; i < n; i++)
        {

            /* Counter for 1's
            in the current row*/
            int cnt_ones = 0;

            /* Count the number of
            1's in the current row*/
            for (int j = 0; j < m; j++)
            {
                cnt_ones += mat[i][j];
            }

            /* Update cnt_max and index if current
            row has more 1's than previously found*/
            if (cnt_ones > cnt_max)
            {
                cnt_max = cnt_ones;
                index = i;
            }
        }

        /* Return the index of the row
        with the maximum number of 1's*/
        return index;
    }
};

// Approach 2: Binary search
class Solution
{
private:
    // Helper function to find the lower bound of 1.
    int lowerBound(vector<int> arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            /* If element at mid is greater than or equal
            to x then it counld be a possible answer.*/
            if (arr[mid] >= x)
            {
                ans = mid;

                // Look for smaller index on the left
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Return the answer
        return ans;
    }

public:
    /* Function to find the row
    with the maximum number of 1's*/
    int rowWithMax1s(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        /* Variable to store the
        maximum count of 1's found*/
        int cnt_max = 0;

        /* Variable to store the index
        of the row with max 1's*/
        int index = -1;

        // Traverse each row of the matrix
        for (int i = 0; i < n; i++)
        {
            // Get the number of 1's
            int cnt_ones = m - lowerBound(mat[i], m, 1);

            /*If the current count is greater than
            maximum, store the index of current row
            and update the maximum count.*/
            if (cnt_ones > cnt_max)
            {
                cnt_max = cnt_ones;
                index = i;
            }
        }

        /* Return the index of the row
        with the maximum number of 1's*/
        return index;
    }
};

// search in a 2d matrix
// Given a 2-D array mat where the elements of each row are sorted in non-decreasing order, and the first element of a row is greater than the last element of the previous row (if it exists), and an integer target, determine if the target exists in the given mat or not.

// Example 1

// Input: mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8

// Output: True

// Explanation: The target = 8 exists in the 'mat' at index (1, 3).
// Approach 1: Linear search
class Solution
{
private:
    // Fuction to perform binary search
    bool binarySearch(vector<int> &mat, int target)
    {
        int n = mat.size();
        int low = 0, high = n - 1;

        // Perform binary search
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // Return true if target is found
            if (mat[mid] == target)
                return true;
            else if (target > mat[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        // Return false if target not found
        return false;
    }

public:
    // Function to search for a given target in matrix
    bool searchMatrix(vector<vector<int>> &mat, int target)
    {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++)
        {

            /*Check if there is a possibility that
            the target can be found in current row*/
            if (mat[i][0] <= target && target <= mat[i][m - 1])
            {

                /*Return result fetched
                from helper function*/
                return binarySearch(mat[i], target);
            }
        }
        // Return false if target is not found
        return false;
    }
};
// binary search approach
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target)
    {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = n * m - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;
            if (mat[row][col] == target)
                return true;
            else if (mat[row][col] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};

// Search in 2D matrix - II
// Given a 2D array matrix where each row is sorted in ascending order from left to right and each column is sorted in ascending order from top to bottom, write an efficient algorithm to search for a specific integer target in the matrix.

// Example 1

// Input: matrix = [ [1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30] ], target = 5

// Output: True

// Explanation: The target 5 exists in the matrix in the index (1,1)

// better approach
// m*log(n) solution as we are doing binary search on each row

// optimal approach(O(m+n) solution) as we are starting from top right corner and moving left or down depending on the target
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        bool ans = false;
        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                ans = true;
                return ans;
            }
            else if (matrix[row][col] < target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
        return ans;
    }
};

// Find Peak Element - II
// Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j].A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.

// Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// Note: As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.

// Example 1

// Input: mat=[[10, 20, 15], [21, 30, 14], [7, 16, 32]]

// Output: [1, 1]

// Explanation: The value at index [1, 1] is 30, which is a peak element because all its neighbours are smaller or equal to it. Similarly, {2, 2} can also be picked as a peak.

// solution
// O(m*log(n)) solution as we are doing binary search on each row
class Solution
{
public:
    /* Helper function to find the index of the row
    with the maximum element in a given column*/
    int maxElement(vector<vector<int>> &arr, int col)
    {
        int n = arr.size();
        int max_val = INT_MIN;
        int index = -1;

        /* Iterate through each row to find the
        maximum element in the specified column*/
        for (int i = 0; i < n; i++)
        {
            if (arr[i][col] > max_val)
            {
                max_val = arr[i][col];
                index = i;
            }
        }
        // Return the index
        return index;
    }

    /* Function to find a peak element in
     the 2D matrix using binary search */
    vector<int> findPeakGrid(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();

        /* Initialize the lower bound for
        and upper bound for binary search */
        int low = 0;
        int high = m - 1;

        // Perform binary search on columns
        while (low <= high)
        {
            int mid = (low + high) / 2;

            /* Find the index of the row with the
            maximum element in the middle column*/
            int row = maxElement(arr, mid);

            /* Determine the elements to left and
            right of middle element in the found row */
            int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;

            /* Check if the middle element
             is greater than its neighbors */
            if (arr[row][mid] > left && arr[row][mid] > right)
            {
                return {row, mid};
            }
            else if (left > arr[row][mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // Return {-1, -1} if no peak element is found
        return {-1, -1};
    }
};

// Matrix Median
// Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.

// Example 1

// Input: matrix=[ [1, 4, 9], [2, 5, 6], [3, 7, 8] ]

// Output: 5

// Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5
// brute force approach
class Solution
{
public:
    // Function to find the median of a row-wise sorted matrix
    int findMedian(vector<vector<int>> &matrix)
    {
        // Step 1: Flatten the matrix into a single list
        vector<int> flattened;
        for (auto &row : matrix)
        {
            for (int val : row)
            {
                flattened.push_back(val);
            }
        }

        // Step 2: Sort the flattened list
        sort(flattened.begin(), flattened.end());

        // Step 3: Return the middle element
        int n = flattened.size();
        return flattened[n / 2];
    }
};

// optimal approach
class Solution
{
private:
    // Function to find the upper bound of an element in a sorted row
    int upperBound(vector<int> &arr, int x, int m)
    {
        int low = 0, high = m - 1;
        int ans = m; // Default answer is beyond the array size

        // Apply binary search
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // If arr[mid] > x, it can be a possible upper bound
            if (arr[mid] > x)
            {
                ans = mid;
                // Look for smaller upper bound on the left
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans; // Return the upper bound
    }

    // Function to count how many elements in the matrix are less than or equal to x
    int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += upperBound(matrix[i], x, m); // Count the elements in each row
        }
        return cnt; // Return total count
    }

public:
    // Function to find the median element in a sorted matrix
    int findMedian(vector<vector<int>> &matrix)
    {
        int n = matrix.size();    // Number of rows
        int m = matrix[0].size(); // Number of columns

        int low = INT_MAX, high = INT_MIN;

        // Initialize low and high to the first and last elements of the matrix
        for (int i = 0; i < n; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        // We need the element at the (n*m)/2th position
        int req = (n * m) / 2;

        // Perform binary search to find the median
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Count how many elements are less than or equal to mid
            int smallEqual = countSmallEqual(matrix, n, m, mid);

            // Adjust search bounds based on the count
            if (smallEqual <= req)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low; // The answer is the low value after the binary search
    }
};