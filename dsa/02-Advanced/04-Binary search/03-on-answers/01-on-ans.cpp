// Find square root of a number
/*
 Given a positive integer n. Find and return its square root. If n is not a perfect square, then return the floor value of sqrt(n).


Examples:
Input: n = 36

Output: 6

Explanation: 6 is the square root of 36.*/
//--if we find any case where till certain portion answer is possible and after that answer is not possible then we can use binary search to find the answer
//--in the any que,if the ans will be in 1 and n, and max or min is asked then we can use binary search to find the answer
class Solution
{
public:
    /* Function to compute the floor of square root
       of a given integer */
    int floorSqrt(int n)
    {
        int ans = 0;

        // Linear search in the answer space
        for (int i = 1; i <= n; i++)
        {
            long long val = 1LL * i * i;
            // Check if val is less than or equal to n
            if (val <= (long long)n)
            {
                ans = i; // Update ans to current value of i
            }
            else
            {
                break; // Exit loop if val exceeds n
            }
        }

        // Return the computed floor of square root
        return ans;
    }
};
// binary search
class Solution
{
public:
    int floorSqrt(int n)
    {
        if (n == 0)
            return 0;

        int low = 1, high = n;
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long sq = 1LL * mid * mid; // promote to long long

            if (sq <= n)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};

//---
// Find Nth root of a number
/*
Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.


Examples:
Input: N = 3, M = 27

Output: 3

Explanation: The cube root of 27 is equal to 3.

*/
// linear search
class Solution
{
private:
    /* Function to calculate power using
    exponentiation by squaring method*/
    long long Pow(int b, int exp)
    {
        long long ans = 1;
        long long base = b;

        // Exponentiation by squaring method
        while (exp > 0)
        {
            if (exp % 2)
            {
                exp--;
                ans = ans * base;
            }
            else
            {
                exp /= 2;
                base = base * base;
            }
        }
        return ans;
    }

public:
    /* Function to find the nth root
    of m using linear search*/
    int NthRoot(int N, int M)
    {
        // Linear search on the answer space
        for (int i = 1; i <= M; i++)
        {
            long long val = Pow(i, N);

            /* Check if the computed
            value is equal to M */
            if (val == M * 1ll)
            {
                // Return the root value
                return i;
            }
            else if (val > M * 1ll)
            {
                break;
            }
        }
        // Return -1 if no root found
        return -1;
    }
};
// binary search
class Solution
{
public:
    int NthRoot(int N, int M)
    {
        int low = 1, high = M, ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long power = 1;
            for (int i = 0; i < N; i++)
            {
                power = power * mid;
                if (power > M)
                    break;
            }
            if (power == M)
                return mid;
            else if (power > M)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
};
//---
// Find the smallest divisor
/*
Given an array of integers nums and an integer limit as the threshold value, find the smallest positive integer divisor such that upon dividing all the elements of the array by this divisor, the sum of the division results is less than or equal to the threshold value.

After dividing each element by the chosen divisor, take the ceiling of the result (i.e., round up to the next whole number).


Examples:
Input: nums = [1, 2, 3, 4, 5], limit = 8

Output: 3

Explanation: We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor.

The sum is 9(1 + 1 + 2 + 2 + 3) if we choose 2 as a divisor. Upon dividing all the elements of the array by 3, we get 1,1,1,2,2 respectively. Now, their sum is equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.

Input: nums = [8,4,2,3], limit = 10

Output: 2

Explanation: If we choose 1, we get 17 as the sum. If we choose 2, we get 9 (4+2+1+2) <= 10 as the answer. So, 2 is the answer.*/
// linear search
class Solution
{
public:
    // Function to find the smallest divisor
    int smallestDivisor(vector<int> &nums, int limit)
    {
        // Size of array.
        int n = nums.size();

        // Find the maximum element in arr
        int maxi = *max_element(nums.begin(), nums.end());

        // Find the smallest divisor
        for (int d = 1; d <= maxi; d++)
        {
            int sum = 0;

            /* Calculate the sum of ceil
            (nums[i] / d) for all elements*/
            for (int i = 0; i < n; i++)
            {
                sum += ceil((double)nums[i] / (double)d);
            }

            // Check if the sum is <= limit
            if (sum <= limit)
                return d;
        }

        // Return -1 if no valid divisor found
        return -1;
    }
};
// binary search
class Solution
{
private:
    /* Helper function to find the
    summation of division values*/
    int sumByD(vector<int> &nums, int limit)
    {
        // Size of array
        int n = nums.size();

        // Find the summation of division values
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)(nums[i]) / (double)(limit));
        }
        return sum;
    }

public:
    // Function to find the smallest divisor
    int smallestDivisor(vector<int> &nums, int limit)
    {
        int n = nums.size();
        if (n > limit)
            return -1;

        // Initialize binary search bounds
        int low = 1, high = *max_element(nums.begin(), nums.end());

        // Apply binary search
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid) <= limit)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
