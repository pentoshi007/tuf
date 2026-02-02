// pow(x,n)
// brute force

class Solution
{
public:
    double myPow(double x, int n)
    {
        // Base case: any number to the power of 0 is 1
        if (n == 0 || x == 1.0)
            return 1;

        long long temp = n; // to avoid integer overflow

        // Handle negative exponents
        if (n < 0)
        {
            x = 1 / x;
            temp = -1 * 1LL * n;
        }

        double ans = 1;

        for (long long i = 0; i < temp; i++)
        {
            // Multiply ans by x for n times
            ans *= x;
        }
        return ans;
    }
};
// optimized
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n; // promote to 64-bit

        if (N == 0)
            return 1.0;

        if (N < 0)
        {
            x = 1.0 / x;
            N = -N; // safe now in 64-bit
        }

        if (N == 1)
            return x;

        if (N % 2 == 0)
        {
            return myPow(x * x, (int)(N / 2)); // cast back to int for signature
        }
        else
        {
            return x * myPow(x, (int)(N - 1));
        }
    }
};

// Generate Parentheses

// Given an integer n.Generate all possible combinations of well-formed parentheses of length 2 x N.

// Example 1

// Input : n = 3

// Output : [ "((()))" , "(()())" , "(())()" , "()(())" , "()()()" ]

// Example 2

// Input : 2

// Output : [ "(())" , "()()" ]
class Solution
{
    void para(int open, int close, vector<string> &list, string s, int n)
    {
        if ((open + close == 2 * n) && (open == close))
        {
            list.push_back(s);
            return;
        }
        if (open <= n)
        {
            para(open + 1, close, list, s + '(', n);
        }

        if (close < open)
        {
            para(open, close + 1, list, s + ')', n);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> list;
        string s = "";
        para(0, 0, list, s, n);
        return list;
    }
};

// powerset
// Given an array of integers nums of unique elements. Return all possible subsets (power set) of the array.

// Do not include the duplicates in the answer.

// Example 1

// Input : nums = [1, 2, 3]

// Output : [ [ ] , [1] , [2] , [1, 2] , [3] , [1, 3] , [2, 3] , [1, 2 ,3] ]

// Example 2

// Input : nums = [1, 2]

// Output : [ [ ] , [1] , [2] , [1,2] ]

class Solution
{
private:
    void func(int ind, int n, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans)
    {
        // Base case: if the index reaches the length of the array,
        // add the current subset to the answer list
        if (ind == n)
        {
            ans.push_back(arr);
            return;
        }

        // Recursive case: Exclude the current element and move to the next element
        func(ind + 1, n, nums, arr, ans);

        // Include the current element in the subset and move to the next element
        arr.push_back(nums[ind]);
        func(ind + 1, n, nums, arr, ans);

        // Backtrack: remove the last added element to explore other subsets
        arr.pop_back();
    }

public:
    vector<vector<int>> powerSet(vector<int> &nums)
    {
        vector<vector<int>> ans;              // List to store all subsets
        vector<int> arr;                      // Temporary list to store the current subset
        func(0, nums.size(), nums, arr, ans); // Start the recursive process
        return ans;                           // Return the list of all subsets
    }
};
