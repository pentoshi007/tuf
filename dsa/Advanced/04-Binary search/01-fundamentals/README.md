# Binary Search - Fundamentals

> **Binary Search** is a search algorithm used to find the position of a target value within a **sorted array**. It works by repeatedly dividing the search interval in half, eliminating half of the remaining elements at each step.

---

## Table of Contents

1. [Binary Search (Search X in Sorted Array)](#1-binary-search---search-x-in-sorted-array)
2. [Lower Bound](#2-lower-bound)
3. [Upper Bound](#3-upper-bound)
4. [Key Differences: Lower Bound vs Upper Bound](#4-key-differences-lower-bound-vs-upper-bound)

---

## 1. Binary Search - Search X in Sorted Array

### Problem Statement

Given a sorted array of integers `nums` with 0-based indexing, find the index of a specified target integer.
- If the target is found, return its index.
- If the target is not found, return `-1`.

### Examples

```
Input:  nums = [-1, 0, 3, 5, 9, 12], target = 9
Output: 4
Explanation: The target integer 9 exists in nums at index 4

Input:  nums = [-1, 0, 3, 5, 9, 12], target = 2
Output: -1
Explanation: 2 does not exist in the array
```

---

### Approach 1: Iterative Binary Search

#### Intuition
- Since the array is sorted, we can leverage this property to eliminate half of the search space at each step.
- Compare the middle element with the target:
  - If equal → found!
  - If middle > target → search in the left half
  - If middle < target → search in the right half

#### Code (Iterative)

```cpp
int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevents overflow
        
        if (nums[mid] == target)
            return mid;
        else if (target < nums[mid])
            right = mid - 1;  // Search left half
        else
            left = mid + 1;   // Search right half
    }
    return -1;  // Target not found
}
```

---

### Approach 2: Recursive Binary Search

#### Intuition
Same logic as iterative, but implemented using recursion. The base case is when `left > right` (search space exhausted).

#### Code (Recursive)

```cpp
class Solution {
public:
    int binarySearch(vector<int> &nums, int target, int left, int right) {
        // Base case: search space exhausted
        if (left > right)
            return -1;
        
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target)
            return mid;
        
        if (nums[mid] > target) {
            // Target is in left half
            return binarySearch(nums, target, left, mid - 1);
        } else {
            // Target is in right half
            return binarySearch(nums, target, mid + 1, right);
        }
    }

    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;
        return binarySearch(nums, target, left, right);
    }
};
```

---

### Dry Run (Visual)

**Example:** `nums = [-1, 0, 3, 5, 9, 12]`, `target = 9`

```
Initial State:
┌─────┬─────┬─────┬─────┬─────┬─────┐
│ -1  │  0  │  3  │  5  │  9  │ 12  │
└─────┴─────┴─────┴─────┴─────┴─────┘
   0     1     2     3     4     5
   ↑                             ↑
  left                         right

═══════════════════════════════════════════════════════════════

Iteration 1:
  left = 0, right = 5
  mid = 0 + (5 - 0) / 2 = 2
  
┌─────┬─────┬─────┬─────┬─────┬─────┐
│ -1  │  0  │  3  │  5  │  9  │ 12  │
└─────┴─────┴─────┴─────┴─────┴─────┘
   0     1     2     3     4     5
   ↑           ↑                 ↑
  left        mid              right

  nums[2] = 3, target = 9
  3 < 9 → Search in RIGHT half
  left = mid + 1 = 3

═══════════════════════════════════════════════════════════════

Iteration 2:
  left = 3, right = 5
  mid = 3 + (5 - 3) / 2 = 4
  
┌─────┬─────┬─────┬─────┬─────┬─────┐
│ -1  │  0  │  3  │  5  │  9  │ 12  │
└─────┴─────┴─────┴─────┴─────┴─────┘
   0     1     2     3     4     5
                     ↑     ↑     ↑
                   left   mid  right

  nums[4] = 9, target = 9
  9 == 9 → FOUND! Return 4

═══════════════════════════════════════════════════════════════

Result: Index 4
```

---

### Complexity Analysis

| Approach  | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Iterative | O(log n)        | O(1)             |
| Recursive | O(log n)        | O(log n) - recursion stack |

**Why O(log n)?**
- At each step, we reduce the search space by half.
- For n elements: n → n/2 → n/4 → ... → 1
- Number of steps = log₂(n)

---

## 2. Lower Bound

### Problem Statement

Given a sorted array `nums` and an integer `x`, find the **lower bound** of `x`.

**Definition:** The lower bound is the **smallest index** where `arr[index] >= x`.

If no such index exists, return the size of the array.

### Examples

```
Input:  nums = [1, 2, 2, 3], x = 2
Output: 1
Explanation: Index 1 is the smallest index where arr[1] >= 2

Input:  nums = [1, 2, 2, 3], x = 2.5
Output: 3
Explanation: Index 3 is the smallest index where arr[3] >= 2.5

Input:  nums = [1, 2, 2, 3], x = 4
Output: 4
Explanation: No element >= 4, so return array size (4)

Input:  nums = [1, 2, 2, 3], x = 0
Output: 0
Explanation: All elements >= 0, smallest index is 0
```

---

### Approach

#### Intuition
- We need to find the **first position** where `nums[mid] >= x`.
- When we find such a position, it's a potential answer, but there might be a smaller index satisfying the condition.
- So we **store the index** and continue searching in the **left half** for a potentially smaller index.
- If `nums[mid] < x`, we need to search in the **right half**.

#### Key Insight
- Initialize `index = n` (array size) as the default answer (when no element >= x).
- When `nums[mid] >= x`: update `index = mid` and search left (`right = mid - 1`).
- When `nums[mid] < x`: search right (`left = mid + 1`).

---

### Code

```cpp
class Solution {
public:
    int lowerBound(vector<int> &nums, int x) {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size();  // Default: no element >= x
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] >= x) {
                index = mid;       // Potential answer
                right = mid - 1;   // Search for smaller index in left half
            } else {
                left = mid + 1;    // Search in right half
            }
        }
        return index;
    }
};
```

> **Note:** Using `index = min(index, mid)` is redundant since we're moving left, so `mid` will always be smaller than or equal to the previous `index`. Simply `index = mid` suffices.

---

### Dry Run (Visual)

**Example:** `nums = [1, 2, 2, 3]`, `x = 2`

```
Initial State:
┌─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  3  │
└─────┴─────┴─────┴─────┘
   0     1     2     3
   ↑                 ↑
  left             right
  
  index = 4 (default = array size)

═══════════════════════════════════════════════════════════════

Iteration 1:
  left = 0, right = 3
  mid = 0 + (3 - 0) / 2 = 1
  
┌─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  3  │
└─────┴─────┴─────┴─────┘
   0     1     2     3
   ↑     ↑           ↑
  left  mid        right

  nums[1] = 2, x = 2
  2 >= 2 → TRUE
  index = 1 (potential answer)
  right = mid - 1 = 0 (search left for smaller index)

═══════════════════════════════════════════════════════════════

Iteration 2:
  left = 0, right = 0
  mid = 0 + (0 - 0) / 2 = 0
  
┌─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  3  │
└─────┴─────┴─────┴─────┘
   0     1     2     3
   ↑
  left
  mid
  right

  nums[0] = 1, x = 2
  1 >= 2 → FALSE
  left = mid + 1 = 1

═══════════════════════════════════════════════════════════════

Termination:
  left = 1, right = 0
  left > right → EXIT loop
  
Result: index = 1

┌─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  3  │
└─────┴─────┴─────┴─────┘
   0     1     2     3
         ↑
    Lower Bound
    (first index where arr[i] >= 2)
```

---

### Edge Cases Dry Run

**Case 1:** `nums = [1, 2, 2, 3]`, `x = 4` (No element >= x)

```
┌─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  3  │
└─────┴─────┴─────┴─────┘
   0     1     2     3

Iteration 1: mid=1, nums[1]=2 < 4 → left=2
Iteration 2: mid=2, nums[2]=2 < 4 → left=3
Iteration 3: mid=3, nums[3]=3 < 4 → left=4

left > right → EXIT
Result: index = 4 (array size, meaning no element >= 4)
```

**Case 2:** `nums = [1, 2, 2, 3]`, `x = 0` (All elements >= x)

```
┌─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  3  │
└─────┴─────┴─────┴─────┘
   0     1     2     3

Iteration 1: mid=1, nums[1]=2 >= 0 → index=1, right=0
Iteration 2: mid=0, nums[0]=1 >= 0 → index=0, right=-1

left > right → EXIT
Result: index = 0 (first element itself)
```

---

### Complexity Analysis

| Metric           | Value    |
|------------------|----------|
| Time Complexity  | O(log n) |
| Space Complexity | O(1)     |

---

## 3. Upper Bound

### Problem Statement

Given a sorted array `nums` and an integer `x`, find the **upper bound** of `x`.

**Definition:** The upper bound is the **smallest index** where `arr[index] > x`.

If no such index exists, return the size of the array.

### Examples

```
Input:  nums = [1, 2, 2, 3], x = 2
Output: 3
Explanation: Index 3 is the smallest index where arr[3] > 2

Input:  nums = [1, 2, 2, 3], x = 1
Output: 1
Explanation: Index 1 is the smallest index where arr[1] > 1

Input:  nums = [1, 2, 2, 3], x = 3
Output: 4
Explanation: No element > 3, so return array size (4)

Input:  nums = [1, 2, 2, 3], x = 0
Output: 0
Explanation: All elements > 0, smallest index is 0
```

---

### Approach

#### Intuition
- Similar to lower bound, but we need `nums[mid] > x` (strictly greater).
- When we find such a position, store it and search left for a potentially smaller index.
- If `nums[mid] <= x`, search right.

#### Key Difference from Lower Bound
- Lower Bound: `nums[mid] >= x` (greater than or equal to)
- Upper Bound: `nums[mid] > x` (strictly greater than)

---

### Code

```cpp
class Solution {
public:
    int upperBound(vector<int> &nums, int x) {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size();  // Default: no element > x
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > x) {
                index = mid;       // Potential answer
                right = mid - 1;   // Search for smaller index in left half
            } else {
                left = mid + 1;    // Search in right half
            }
        }
        return index;
    }
};
```

---

### Dry Run (Visual)

**Example:** `nums = [1, 2, 2, 3]`, `x = 2`

```
Initial State:
┌─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  3  │
└─────┴─────┴─────┴─────┘
   0     1     2     3
   ↑                 ↑
  left             right
  
  index = 4 (default = array size)

═══════════════════════════════════════════════════════════════

Iteration 1:
  left = 0, right = 3
  mid = 0 + (3 - 0) / 2 = 1
  
┌─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  3  │
└─────┴─────┴─────┴─────┘
   0     1     2     3
   ↑     ↑           ↑
  left  mid        right

  nums[1] = 2, x = 2
  2 > 2 → FALSE
  left = mid + 1 = 2

═══════════════════════════════════════════════════════════════

Iteration 2:
  left = 2, right = 3
  mid = 2 + (3 - 2) / 2 = 2
  
┌─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  3  │
└─────┴─────┴─────┴─────┘
   0     1     2     3
               ↑     ↑
              left  right
              mid

  nums[2] = 2, x = 2
  2 > 2 → FALSE
  left = mid + 1 = 3

═══════════════════════════════════════════════════════════════

Iteration 3:
  left = 3, right = 3
  mid = 3 + (3 - 3) / 2 = 3
  
┌─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  3  │
└─────┴─────┴─────┴─────┘
   0     1     2     3
                     ↑
                   left
                   mid
                   right

  nums[3] = 3, x = 2
  3 > 2 → TRUE
  index = 3 (potential answer)
  right = mid - 1 = 2

═══════════════════════════════════════════════════════════════

Termination:
  left = 3, right = 2
  left > right → EXIT loop
  
Result: index = 3

┌─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  3  │
└─────┴─────┴─────┴─────┘
   0     1     2     3
                     ↑
              Upper Bound
         (first index where arr[i] > 2)
```

---

### Complexity Analysis

| Metric           | Value    |
|------------------|----------|
| Time Complexity  | O(log n) |
| Space Complexity | O(1)     |

---

## 4. Key Differences: Lower Bound vs Upper Bound

### Comparison Table

| Property | Lower Bound | Upper Bound |
|----------|-------------|-------------|
| **Definition** | Smallest index where `arr[i] >= x` | Smallest index where `arr[i] > x` |
| **Condition** | `nums[mid] >= x` | `nums[mid] > x` |
| **For x present in array** | Returns index of first occurrence | Returns index after last occurrence |
| **For x not present** | Returns index where x would be inserted | Returns index where x would be inserted |

### Visual Comparison

```
Array: [1, 2, 2, 2, 3, 4, 5]
        0  1  2  3  4  5  6

For x = 2:
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  1  │  2  │  2  │  2  │  3  │  4  │  5  │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   0     1     2     3     4     5     6
         ↑                 ↑
    Lower Bound = 1   Upper Bound = 4
    (first 2)         (first element > 2)

Count of 2s = Upper Bound - Lower Bound = 4 - 1 = 3 ✓
```

### Practical Applications

| Use Case | Formula |
|----------|---------|
| Count occurrences of x | `upperBound(x) - lowerBound(x)` |
| Check if x exists | `lowerBound(x) < n && arr[lowerBound(x)] == x` |
| Insert position for x | `lowerBound(x)` |
| Elements < x | `lowerBound(x)` |
| Elements <= x | `upperBound(x)` |
| Elements > x | `n - upperBound(x)` |
| Elements >= x | `n - lowerBound(x)` |

---

## Summary: Binary Search Template

```cpp
// Generic Binary Search Template
int binarySearch(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int result = /* default value */;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevents integer overflow
        
        if (/* condition based on problem */) {
            result = mid;           // Update result
            right = mid - 1;        // Search left for better answer
            // OR left = mid + 1;   // Search right for better answer
        } else {
            left = mid + 1;         // Adjust search space
            // OR right = mid - 1;
        }
    }
    return result;
}
```

### Key Points to Remember

1. **Always use `mid = left + (right - left) / 2`** to prevent integer overflow.
2. **Loop condition `left <= right`** ensures we check all elements.
3. **Sorted array is prerequisite** for binary search.
4. **Time Complexity is O(log n)** because we halve the search space each iteration.
5. **Space Complexity is O(1)** for iterative, O(log n) for recursive (stack space).

---

## C++ STL Functions

C++ provides built-in functions for lower and upper bound:

```cpp
#include <algorithm>

vector<int> nums = {1, 2, 2, 3, 4};
int x = 2;

// Lower bound - returns iterator to first element >= x
auto lb = lower_bound(nums.begin(), nums.end(), x);
int lbIndex = lb - nums.begin();  // Index = 1

// Upper bound - returns iterator to first element > x
auto ub = upper_bound(nums.begin(), nums.end(), x);
int ubIndex = ub - nums.begin();  // Index = 3

// Count of x
int count = ub - lb;  // 3 - 1 = 2 occurrences of 2
```

---

## Practice Problems

1. **Binary Search** - [LeetCode 704](https://leetcode.com/problems/binary-search/)
2. **Search Insert Position** - [LeetCode 35](https://leetcode.com/problems/search-insert-position/)
3. **Find First and Last Position** - [LeetCode 34](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
4. **Count of Smaller Numbers After Self** - [LeetCode 315](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

---

> **Next Up:** Search in Rotated Sorted Array, Finding Peak Element, and more advanced binary search patterns!

