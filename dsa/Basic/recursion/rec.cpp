#include <bits/stdc++.h>
using namespace std;

// sum of n natural numbers
int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}
// factorial of a number
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// sum of array elements
int arraySum(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    vector<int> subvec(nums.begin() + 1, nums.end());
    return nums[0] + arraySum(subvec);
};

// reverse a string
class Solution
{
private:
    void reverse(vector<char> &s, int left, int right)
    {
        if (left > right)
            return;
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        reverse(s, left + 1, right - 1);
    }

public:
    vector<char> reverseString(vector<char> &s)
    {
        // your code goes here
        int left = 0;
        int right = s.size() - 1;
        reverse(s, left, right);
        return s;
    }
};
// check if a string is palindrome
class Solution
{
private:
    bool ispal(int left, int right, string &s)
    {
        if (left >= right)
            return true;
        if (s[left] != s[right])
            return false;
        return ispal(left + 1, right - 1, s);
    }

public:
    bool palindromeCheck(string &s)
    {
        // your code goes here
        int left = 0;
        int right = s.length() - 1;
        return ispal(left, right, s);
    }
};
// check if a number is prime
class Solution
{
private:
    bool check(int i, int num)
    {
        if (num == 1)
            return false;
        if (i * i > num)
            return true;
        if (num % i == 0)
            return false;
        return check(i + 1, num);
    }

public:
    bool checkPrime(int num)
    {
        // your code goes here
        int i = 2;
        return check(i, num);
    }
};
// reverse an array
class Solution
{
private:
    void rev(int left, int right, vector<int> &nums)
    {
        if (left >= right)
            return;
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        return rev(left + 1, right - 1, nums);
    }

public:
    vector<int> reverseArray(vector<int> &nums)
    {
        // your code goes here
        int left = 0;
        int right = nums.size() - 1;
        rev(left, right, nums);
        return nums;
    }
};

// check if an array is sorted
class Solution
{
public:
    bool isSorted(vector<int> &nums)
    {
        // your code goes here
        if (nums.size() == 1)
            return true;
        if (nums[0] > nums[1])
            return false;
        vector<int> sub(nums.begin() + 1, nums.end());
        return isSorted(sub);
    }
};
// sum of digits of a number
class Solution
{
public:
    int addDigits(int num)
    {
        // your code goes here
        if (num < 10)
        {
            return num;
        }

        // Recursive case: sum the digits and continue
        int sum = sumDigits(num);

        return addDigits(sum);
    }

private:
    // Helper function to add the sum of digits recursively
    int sumDigits(int num)
    {
        // Base case: If the number is 0, return 0
        if (num == 0)
            return 0;

        // Recursive case
        return sumDigits(num / 10) + (num % 10);
    };
};

// fibonacci number
class Solution
{
public:
    int fibonacci(int n)
    {
        // your code goes here
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};

int main()
{

    return 0;
}