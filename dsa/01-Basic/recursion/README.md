# Recursion - Complete Guide 📚

A comprehensive collection of fundamental recursion problems with detailed explanations, complexity analysis, and visual dry runs for effective revision.

## Table of Contents

1. [Introduction to Recursion](#introduction-to-recursion)
2. [Sum of N Natural Numbers](#1-sum-of-n-natural-numbers)
3. [Factorial of a Number](#2-factorial-of-a-number)
4. [Sum of Array Elements](#3-sum-of-array-elements)
5. [Reverse a String](#4-reverse-a-string)
6. [Check if String is Palindrome](#5-check-if-string-is-palindrome)
7. [Check if Number is Prime](#6-check-if-number-is-prime)
8. [Reverse an Array](#7-reverse-an-array)
9. [Check if Array is Sorted](#8-check-if-array-is-sorted)
10. [Sum of Digits](#9-sum-of-digits)
11. [Fibonacci Number](#10-fibonacci-number)

---

## Introduction to Recursion

**Recursion** is a programming technique where a function calls itself to solve a problem by breaking it down into smaller, similar subproblems.

### Key Components:

1. **Base Case**: The condition that stops the recursion
2. **Recursive Case**: The part where the function calls itself
3. **Progress towards Base Case**: Each recursive call should move closer to the base case

### Why Use Recursion?

- Simplifies complex problems
- Natural for problems with recursive structure (trees, graphs)
- Makes code more readable and elegant

---

## 1. Sum of N Natural Numbers

### Problem Statement

Find the sum of first N natural numbers using recursion.

### Code

```cpp
int sum(int n)
{
    if (n == 0)  // Base case
        return 0;
    return n + sum(n - 1);  // Recursive case
}
```

### Approach

1. **Base Case**: If n = 0, return 0
2. **Recursive Case**: Add n to the sum of (n-1) numbers
3. Formula: sum(n) = n + sum(n-1)

### Complexity Analysis

- **Time Complexity**: O(n) - Function is called n times
- **Space Complexity**: O(n) - Recursion call stack depth is n

### Dry Run (n = 5)

```
sum(5) = 5 + sum(4)
       = 5 + 4 + sum(3)
       = 5 + 4 + 3 + sum(2)
       = 5 + 4 + 3 + 2 + sum(1)
       = 5 + 4 + 3 + 2 + 1 + sum(0)
       = 5 + 4 + 3 + 2 + 1 + 0
       = 15

Call Stack Visualization:
sum(5) → sum(4) → sum(3) → sum(2) → sum(1) → sum(0)
  ↓        ↓        ↓        ↓        ↓        ↓
  5    +   4    +   3    +   2    +   1    +   0 = 15
```

### Key Takeaway

Each call adds the current number and waits for the result of the smaller subproblem.

---

## 2. Factorial of a Number

### Problem Statement

Calculate the factorial of a number n (n!) using recursion.

### Code

```cpp
int factorial(int n)
{
    if (n == 0)  // Base case: 0! = 1
        return 1;
    return n * factorial(n - 1);  // Recursive case
}
```

### Approach

1. **Base Case**: If n = 0 or n = 1, return 1
2. **Recursive Case**: Multiply n with factorial of (n-1)
3. Formula: factorial(n) = n × factorial(n-1)

### Complexity Analysis

- **Time Complexity**: O(n) - Function is called n times
- **Space Complexity**: O(n) - Recursion stack depth

### Dry Run (n = 4)

```
factorial(4) = 4 × factorial(3)
             = 4 × 3 × factorial(2)
             = 4 × 3 × 2 × factorial(1)
             = 4 × 3 × 2 × 1 × factorial(0)
             = 4 × 3 × 2 × 1 × 1
             = 24

Call Stack:
factorial(4) → factorial(3) → factorial(2) → factorial(1) → factorial(0)
    ↓              ↓              ↓              ↓              ↓
    4      ×       3      ×       2      ×       1      ×       1  = 24
```

### Visual Representation

```
         factorial(4)
              |
         4 * factorial(3)
              |
         3 * factorial(2)
              |
         2 * factorial(1)
              |
         1 * factorial(0)
              |
              1 (base case)
```

---

## 3. Sum of Array Elements

### Problem Statement

Find the sum of all elements in a vector/array using recursion.

### Code

```cpp
int arraySum(vector<int> &nums)
{
    if (nums.size() == 1)  // Base case
        return nums[0];
    vector<int> subvec(nums.begin() + 1, nums.end());
    return nums[0] + arraySum(subvec);  // Recursive case
}
```

### Approach

1. **Base Case**: If array has only 1 element, return that element
2. **Recursive Case**: Add first element to sum of remaining elements
3. Create subvector from index 1 to end and recursively sum it

### Complexity Analysis

- **Time Complexity**: O(n²) - Creating subvector takes O(n) and we do it n times
- **Space Complexity**: O(n²) - Due to creating new vectors at each level

### Dry Run (nums = [1, 2, 3, 4])

```
arraySum([1, 2, 3, 4])
= 1 + arraySum([2, 3, 4])
= 1 + 2 + arraySum([3, 4])
= 1 + 2 + 3 + arraySum([4])
= 1 + 2 + 3 + 4 (base case)
= 10

Visual:
[1, 2, 3, 4] → 1 + arraySum([2, 3, 4])
               ↓
           [2, 3, 4] → 2 + arraySum([3, 4])
                       ↓
                   [3, 4] → 3 + arraySum([4])
                            ↓
                         [4] → 4 (base case)
```

### Optimization Note

This approach can be optimized by using indices instead of creating new vectors:

```cpp
int arraySum(vector<int> &nums, int index) {
    if (index == nums.size() - 1) return nums[index];
    return nums[index] + arraySum(nums, index + 1);
}
```

---

## 4. Reverse a String

### Problem Statement

Reverse a string (character vector) in-place using recursion.

### Code

```cpp
class Solution
{
private:
    void reverse(vector<char> &s, int left, int right)
    {
        if (left > right)  // Base case
            return;
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        reverse(s, left + 1, right - 1);  // Recursive case
    }

public:
    vector<char> reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size() - 1;
        reverse(s, left, right);
        return s;
    }
};
```

### Approach

1. Use two pointers: left (start) and right (end)
2. **Base Case**: If left > right, return (all elements swapped)
3. **Recursive Case**:
   - Swap elements at left and right
   - Recursively call with left+1 and right-1

### Complexity Analysis

- **Time Complexity**: O(n) - We process each element once (n/2 swaps)
- **Space Complexity**: O(n) - Recursion stack depth is n/2

### Dry Run (s = ['h', 'e', 'l', 'l', 'o'])

```
Initial: ['h', 'e', 'l', 'l', 'o']
         left=0, right=4

Step 1: Swap s[0] and s[4]
        ['o', 'e', 'l', 'l', 'h']
        left=1, right=3

Step 2: Swap s[1] and s[3]
        ['o', 'l', 'l', 'e', 'h']
        left=2, right=2

Step 3: left > right, base case reached
        Final: ['o', 'l', 'l', 'e', 'h']

Visual:
['h', 'e', 'l', 'l', 'o']
  ↓                   ↓
  └─────── SWAP ──────┘
['o', 'e', 'l', 'l', 'h']
      ↓           ↓
      └─── SWAP ──┘
['o', 'l', 'l', 'e', 'h']
          ↓
       (center)
```

---

## 5. Check if String is Palindrome

### Problem Statement

Check if a given string is a palindrome using recursion.

### Code

```cpp
class Solution
{
private:
    bool ispal(int left, int right, string &s)
    {
        if (left >= right)  // Base case: all checked
            return true;
        if (s[left] != s[right])  // Characters don't match
            return false;
        return ispal(left + 1, right - 1, s);  // Check next pair
    }

public:
    bool palindromeCheck(string &s)
    {
        int left = 0;
        int right = s.length() - 1;
        return ispal(left, right, s);
    }
};
```

### Approach

1. Compare characters from both ends moving inward
2. **Base Case**: If left >= right, all characters matched → palindrome
3. **Recursive Case**:
   - If current characters don't match → not palindrome
   - Otherwise, check next pair (left+1, right-1)

### Complexity Analysis

- **Time Complexity**: O(n) - Check n/2 pairs of characters
- **Space Complexity**: O(n) - Recursion stack depth

### Dry Run (s = "racecar")

```
s = "racecar"
     0123456

Step 1: left=0, right=6
        s[0]='r', s[6]='r' ✓ Match

Step 2: left=1, right=5
        s[1]='a', s[5]='a' ✓ Match

Step 3: left=2, right=4
        s[2]='c', s[4]='c' ✓ Match

Step 4: left=3, right=3
        left >= right → Base case
        Return TRUE

Visual:
r  a  c  e  c  a  r
↓                 ↓
└───────✓─────────┘
   ↓           ↓
   └─────✓─────┘
      ↓     ↓
      └──✓──┘
         ↓
      (center)
```

### Example of Non-Palindrome (s = "hello")

```
Step 1: left=0, right=4
        s[0]='h', s[4]='o' ✗ Don't Match
        Return FALSE immediately
```

---

## 6. Check if Number is Prime

### Problem Statement

Check if a given number is prime using recursion.

### Code

```cpp
class Solution
{
private:
    bool check(int i, int num)
    {
        if (num == 1)  // 1 is not prime
            return false;
        if (i * i > num)  // Base case: checked all divisors
            return true;
        if (num % i == 0)  // Found a divisor
            return false;
        return check(i + 1, num);  // Check next number
    }

public:
    bool checkPrime(int num)
    {
        int i = 2;
        return check(i, num);
    }
};
```

### Approach

1. Check divisibility starting from 2
2. **Base Cases**:
   - If num = 1, return false
   - If i² > num, no divisors found → prime
3. **Recursive Case**:
   - If num % i = 0 → not prime
   - Otherwise, check next number (i+1)
4. Optimization: Only check up to √num

### Complexity Analysis

- **Time Complexity**: O(√n) - Check divisors up to square root
- **Space Complexity**: O(√n) - Recursion stack depth

### Dry Run (num = 17)

```
checkPrime(17)
  → check(2, 17)

Step 1: i=2, num=17
        2*2 = 4 ≤ 17
        17 % 2 = 1 (not divisible)
        → check(3, 17)

Step 2: i=3, num=17
        3*3 = 9 ≤ 17
        17 % 3 = 2 (not divisible)
        → check(4, 17)

Step 3: i=4, num=17
        4*4 = 16 ≤ 17
        17 % 4 = 1 (not divisible)
        → check(5, 17)

Step 4: i=5, num=17
        5*5 = 25 > 17
        Base case: Return TRUE (Prime!)

Visual:
17: Check divisors 2, 3, 4...
    ↓
    2? No (17 % 2 = 1)
    3? No (17 % 3 = 2)
    4? No (17 % 4 = 1)
    5? Stop (5² > 17)
    ↓
    PRIME ✓
```

### Example of Composite Number (num = 15)

```
Step 1: i=2, 15 % 2 = 1 → continue
Step 2: i=3, 15 % 3 = 0 → NOT PRIME ✗
```

---

## 7. Reverse an Array

### Problem Statement

Reverse an array in-place using recursion.

### Code

```cpp
class Solution
{
private:
    void rev(int left, int right, vector<int> &nums)
    {
        if (left >= right)  // Base case
            return;
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        return rev(left + 1, right - 1, nums);  // Recursive case
    }

public:
    vector<int> reverseArray(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        rev(left, right, nums);
        return nums;
    }
};
```

### Approach

1. Use two pointers: left and right
2. **Base Case**: If left >= right, all elements swapped
3. **Recursive Case**:
   - Swap elements at left and right
   - Recursively call with left+1 and right-1

### Complexity Analysis

- **Time Complexity**: O(n) - Process each element once (n/2 swaps)
- **Space Complexity**: O(n) - Recursion stack depth is n/2

### Dry Run (nums = [1, 2, 3, 4, 5])

```
Initial: [1, 2, 3, 4, 5]
         L=0        R=4

Step 1: Swap nums[0] and nums[4]
        [5, 2, 3, 4, 1]
         L=1     R=3

Step 2: Swap nums[1] and nums[3]
        [5, 4, 3, 2, 1]
            L=2

Step 3: left >= right → Base case
        Final: [5, 4, 3, 2, 1]

Visual Representation:
[1,  2,  3,  4,  5]
 ↓              ↓
 └─────SWAP─────┘
[5,  2,  3,  4,  1]
     ↓       ↓
     └─SWAP──┘
[5,  4,  3,  2,  1]
         ↓
     (center)
```

---

## 8. Check if Array is Sorted

### Problem Statement

Check if an array is sorted in non-decreasing order using recursion.

### Code

```cpp
class Solution
{
public:
    bool isSorted(vector<int> &nums)
    {
        if (nums.size() == 1)  // Base case: single element is sorted
            return true;
        if (nums[0] > nums[1])  // First two elements out of order
            return false;
        vector<int> sub(nums.begin() + 1, nums.end());
        return isSorted(sub);  // Check remaining array
    }
};
```

### Approach

1. **Base Case**: Array with 1 element is always sorted
2. **Recursive Case**:
   - If first element > second element → not sorted
   - Otherwise, check if remaining array is sorted
3. Create subarray from index 1 onwards

### Complexity Analysis

- **Time Complexity**: O(n²) - Creating subvector takes O(n), done n times
- **Space Complexity**: O(n²) - New vectors created at each level

### Dry Run (nums = [1, 2, 3, 4, 5])

```
Step 1: [1, 2, 3, 4, 5]
        1 ≤ 2 ✓ → Check [2, 3, 4, 5]

Step 2: [2, 3, 4, 5]
        2 ≤ 3 ✓ → Check [3, 4, 5]

Step 3: [3, 4, 5]
        3 ≤ 4 ✓ → Check [4, 5]

Step 4: [4, 5]
        4 ≤ 5 ✓ → Check [5]

Step 5: [5]
        Single element → Return TRUE

Visual:
[1, 2, 3, 4, 5]
 ✓
   [2, 3, 4, 5]
    ✓
      [3, 4, 5]
       ✓
         [4, 5]
          ✓
            [5] → SORTED ✓
```

### Example of Unsorted Array (nums = [1, 3, 2, 4])

```
Step 1: [1, 3, 2, 4]
        1 ≤ 3 ✓ → Check [3, 2, 4]

Step 2: [3, 2, 4]
        3 > 2 ✗ → Return FALSE
```

### Optimization Note

```cpp
// Better approach using index:
bool isSorted(vector<int> &nums, int index = 0) {
    if (index == nums.size() - 1) return true;
    if (nums[index] > nums[index + 1]) return false;
    return isSorted(nums, index + 1);
}
```

---

## 9. Sum of Digits

### Problem Statement

Find the sum of digits of a number, repeatedly until a single digit remains.

### Code

```cpp
class Solution
{
public:
    int addDigits(int num)
    {
        if (num < 10)  // Base case: single digit
            return num;

        // Sum the digits and continue recursively
        int sum = sumDigits(num);
        return addDigits(sum);
    }

private:
    int sumDigits(int num)
    {
        if (num == 0)  // Base case
            return 0;
        // Add last digit + sum of remaining digits
        return sumDigits(num / 10) + (num % 10);
    }
};
```

### Approach

1. **Helper Function (sumDigits)**: Calculate sum of all digits
   - Extract last digit using num % 10
   - Recursively sum remaining digits (num / 10)
2. **Main Function (addDigits)**: Keep summing until single digit
   - **Base Case**: If num < 10, return it
   - **Recursive Case**: Sum digits and recursively process result

### Complexity Analysis

- **Time Complexity**: O(log n) - Number of digits in n
- **Space Complexity**: O(log n) - Recursion stack depth

### Dry Run (num = 38)

```
addDigits(38)
  → sumDigits(38)

sumDigits(38):
  = sumDigits(3) + 8
  = sumDigits(0) + 3 + 8
  = 0 + 3 + 8
  = 11

addDigits(11):
  → sumDigits(11)

sumDigits(11):
  = sumDigits(1) + 1
  = sumDigits(0) + 1 + 1
  = 0 + 1 + 1
  = 2

addDigits(2):
  → 2 < 10
  → Return 2

Visual:
    38
    ↓
  3 + 8 = 11
    ↓
  1 + 1 = 2
    ↓
    2 (single digit)
```

### Detailed sumDigits Recursion (num = 38)

```
sumDigits(38)
  = sumDigits(38/10) + 38%10
  = sumDigits(3) + 8
  = (sumDigits(3/10) + 3%10) + 8
  = (sumDigits(0) + 3) + 8
  = (0 + 3) + 8
  = 11

Call Stack:
sumDigits(38) → sumDigits(3) → sumDigits(0)
     ↓              ↓              ↓
     8      +       3      +       0
```

---

## 10. Fibonacci Number

### Problem Statement

Find the nth Fibonacci number using recursion.

### Code

```cpp
class Solution
{
public:
    int fibonacci(int n)
    {
        if (n == 0)  // Base case 1
            return 0;
        if (n == 1)  // Base case 2
            return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
    }
};
```

### Approach

1. **Base Cases**:
   - fibonacci(0) = 0
   - fibonacci(1) = 1
2. **Recursive Case**: fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
3. Each call branches into two recursive calls

### Complexity Analysis

- **Time Complexity**: O(2ⁿ) - Each call makes 2 recursive calls (exponential)
- **Space Complexity**: O(n) - Maximum recursion depth is n

### Dry Run (n = 5)

```
fibonacci(5)
= fibonacci(4) + fibonacci(3)

fibonacci(4) = fibonacci(3) + fibonacci(2)
fibonacci(3) = fibonacci(2) + fibonacci(1)
fibonacci(2) = fibonacci(1) + fibonacci(0) = 1 + 0 = 1

Working backwards:
fibonacci(2) = 1
fibonacci(3) = 1 + 1 = 2
fibonacci(4) = 2 + 1 = 3
fibonacci(5) = 3 + 2 = 5
```

### Visual Tree Representation

```
                    fib(5)
                   /      \
              fib(4)        fib(3)
             /     \        /     \
         fib(3)   fib(2)  fib(2)  fib(1)
        /    \    /   \   /   \     |
    fib(2) fib(1) f(1) f(0) f(1) f(0)  1
    /   \    |     |    |    |    |
  f(1) f(0)  1     1    0    1    0
   |    |
   1    0

Computing values:
fib(0) = 0
fib(1) = 1
fib(2) = fib(1) + fib(0) = 1 + 0 = 1
fib(3) = fib(2) + fib(1) = 1 + 1 = 2
fib(4) = fib(3) + fib(2) = 2 + 1 = 3
fib(5) = fib(4) + fib(3) = 3 + 2 = 5
```

### Fibonacci Sequence

```
n:     0  1  2  3  4  5  6  7   8   9   10
fib(n): 0  1  1  2  3  5  8  13  21  34  55
```

### Performance Issue and Optimization

This naive recursive approach recalculates the same values multiple times:

```
fib(5) calls fib(3) twice
fib(4) calls fib(2) three times
```

**Optimization using Memoization:**

```cpp
// Using dynamic programming / memoization
int fibonacci(int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
}
// This reduces time complexity to O(n)
```

---

## Recursion Patterns Summary

### 1. Linear Recursion

- Single recursive call per function call
- Examples: Sum of N numbers, Factorial, Array sum
- Complexity: Usually O(n) time and O(n) space

### 2. Divide and Conquer

- Problem divided into smaller subproblems
- Examples: Binary search, Merge sort
- Complexity: Often O(log n) or O(n log n)

### 3. Multiple Recursion

- Multiple recursive calls per function call
- Examples: Fibonacci, Tree traversals
- Complexity: Can be exponential O(2ⁿ) without optimization

### 4. Two-Pointer Recursion

- Using two indices that move towards each other
- Examples: Reverse array, Palindrome check
- Complexity: O(n) time, O(n/2) space

---

## Common Recursion Pitfalls

1. **Missing Base Case**: Leads to infinite recursion and stack overflow
2. **Wrong Base Case**: May produce incorrect results
3. **Not Making Progress**: Each recursive call must move toward base case
4. **Exponential Time**: Some problems need memoization/DP
5. **Stack Overflow**: Deep recursion can exceed stack limit

---

## When to Use Recursion

✅ **Use Recursion When:**

- Problem has recursive structure (trees, graphs)
- Problem can be broken into similar subproblems
- Code becomes simpler and more readable
- Working with recursive data structures

❌ **Avoid Recursion When:**

- Simple iteration is more efficient
- Stack space is limited
- Performance is critical and recursion adds overhead
- Tail recursion isn't optimized by compiler

---

## Practice Tips

1. **Always identify the base case first**
2. **Draw recursion tree for better understanding**
3. **Trace through small examples**
4. **Consider space complexity (stack space)**
5. **Think about optimization (memoization, tail recursion)**
6. **Practice converting between recursion and iteration**

---

## Additional Resources

- **Time/Space Complexity**: Understanding recursion stack
- **Tail Recursion**: Optimization technique
- **Memoization**: Caching results to avoid recomputation
- **Dynamic Programming**: Bottom-up approach to recursive problems

---

## Conclusion

Recursion is a powerful technique that makes complex problems simpler. Master these fundamental patterns, and you'll be well-prepared for more advanced recursive problems in trees, graphs, backtracking, and dynamic programming.

**Key Takeaways:**

- Always have a clear base case
- Make progress toward the base case in each recursive call
- Consider both time and space complexity
- Use memoization when you notice overlapping subproblems
- Practice visualizing recursion trees and call stacks

Happy Coding! 🚀

---

**File Location**: `/dsa/Basic/recursion/rec.cpp`

**Last Updated**: October 3, 2025
