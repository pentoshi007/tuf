// Pascal's Triangle -1
/*
 Given two integers r and c, return the value at the rth row and cth column (1-indexed) in a Pascal's Triangle.



In Pascal's triangle:


The first row contains a single element 1.


Each row has one more element than the previous row.


Every row starts and ends with 1.


For all interior elements (i.e., not at the ends), the value at position (r, c) is computed as the sum of the two elements directly above it from the previous row:

Pascal[r][c]=Pascal[r−1][c−1]+Pascal[r−1][c]
where indexing is 1-based

Examples:
Input: r = 4, c = 2

Output: 3

Explanation:

The Pascal's Triangle is as follows:

1

1 1

1 2 1

1 3 3 1

....

Thus, value at row 4 and column 2 = 3*/

//---Code---
class Solution
{
private:
    int nCr(int n, int r)
    {
        if (r > n - r)
        {
            r = n - r;
        }
        if (r == 1)
            return n;
        int res = 1;
        for (int i = 0; i < r; i++)
        {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

public:
    int pascalTriangleI(int r, int c) { return nCr(r - 1, c - 1); }
};

// Pascal's Triangle II
/*
Given an integer r, return all the values in the rth row (1-indexed) in Pascal's Triangle in correct order.



In Pascal's triangle:



The first row has one element with a value of 1.


Each row has one more element in it than its previous row.


The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

Examples:
Input: r = 4

Output: [1, 3, 3, 1]

Explanation:

The Pascal's Triangle is as follows:

1

1 1

1 2 1

1 3 3 1

....

Thus the 4th row is [1, 3, 3, 1]*/

//---Code---
class Solution
{
public:
    vector<int> pascalTriangleII(int r)
    {
        vector<int> ans(r, 0);

        int num = 1;
        ans[0] = num;

        for (int i = 1; i < r; i++)
        {
            num = (r - 1 - (i - 1)) * num;
            num = num / i;
            ans[i] = num;
        }
        return ans;
    }
};

// Pascal's Triangle III
/*
Given an integer n, return the first n (1-Indexed) rows of Pascal's triangle.



In Pascal's triangle:

The first row has one element with a value of 1.
Each row has one more element in it than its previous row.
The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

Examples:
Input: n = 4

Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]

Explanation: The Pascal's Triangle is as follows:

1

1 1

1 2 1

1 3 3 1

1st Row has its value set to 1.

All other cells take their value as the sum of the values directly above them*/

//---Code---
class Solution
{
private:
    vector<int> generateRow(int row)
    {
        int ans = 1;
        vector<int> ansRow;
        ansRow.push_back(ans);
        for (int i = 1; i < row; i++)
        {
            ans = (ans * (row - 1 - (i - 1))) / i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

public:
    vector<vector<int>> pascalTriangleIII(int n)
    {
        vector<vector<int>> res;
        for (int row = 1; row <= n; row++)
        {
            res.push_back(generateRow(row));
        }
        return res;
    }
};