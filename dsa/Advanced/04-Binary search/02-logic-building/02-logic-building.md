# Binary Search - Logic Building Problems (Part 2)

This document continues the binary search logic-building series, covering advanced problems involving rotated sorted arrays with duplicates, finding minimum/rotation count, and finding a single non-duplicate element. Each problem includes detailed explanations, approach breakdowns, complexity analysis, and visual dry runs.

---

## Table of Contents
1. [Search in Rotated Sorted Array - II (With Duplicates)](#1-search-in-rotated-sorted-array---ii-with-duplicates)
2. [Find Minimum in Rotated Sorted Array](#2-find-minimum-in-rotated-sorted-array)
3. [Find Number of Rotations in Array](#3-find-number-of-rotations-in-array)
4. [Single Element in Sorted Array](#4-single-element-in-sorted-array)

---

## 1. Search in Rotated Sorted Array - II (With Duplicates)

### Problem Statement
Given an integer array `nums`, sorted in ascending order (**may contain duplicate values**) and a target value `k`. The array is rotated at some pivot point unknown to you. Return `True` if `k` is present, otherwise return `False`.

### Examples

| Input Array | Target | Output | Explanation |
|-------------|--------|--------|-------------|
| `[7, 8, 1, 2, 3, 3, 3, 4, 5, 6]` | `3` | `True` | Element 3 is present |
| `[2, 5, 6, 0, 0, 1, 2]` | `0` | `True` | Element 0 is present |
| `[2, 5, 6, 0, 0, 1, 2]` | `3` | `False` | Element 3 not present |

### How is This Different from Part I?

```
Part I (Distinct values):     Part II (Duplicates allowed):
[4, 5, 6, 7, 0, 1, 2]         [3, 1, 2, 3, 3, 3, 3]
    ↑                              ↑
We can always identify         nums[low] == nums[mid] == nums[high]
which half is sorted!          Can't determine sorted half!
```

### Key Insight 💡
The main challenge with duplicates is when `nums[low] == nums[mid] == nums[high]`. In this case, we **cannot determine** which half is sorted. The solution is to **shrink the search space** by moving both `low++` and `high--`.

---

### Approach: Binary Search with Edge Case Handling

#### How to Solve - Step by Step Thinking 🧠

1. **Start with the standard rotated array approach**: Check if target equals mid, identify sorted half, search accordingly.

2. **Handle the tricky duplicate case**: When `nums[low] == nums[mid] == nums[high]`:
   - We can't determine which half is sorted
   - **Solution**: Skip the boundary elements by doing `low++` and `high--`
   - Continue to next iteration

3. **For normal cases** (at least one half is identifiable as sorted):
   - If left half is sorted: check if target lies in `[nums[low], nums[mid])`
   - If right half is sorted: check if target lies in `[nums[mid], nums[high]]`

#### Algorithm
```
1. Initialize low = 0, high = n-1
2. While low <= high:
   a. Calculate mid
   b. If nums[mid] == k → return true
   c. If nums[low] == nums[mid] == nums[high]:
      → low++, high--, continue (SKIP this ambiguous state)
   d. If LEFT half is sorted (nums[low] <= nums[mid]):
      → Check if k is in [nums[low], nums[mid])
      → If yes: high = mid - 1
      → If no: low = mid + 1
   e. Else RIGHT half is sorted:
      → Check if k is in (nums[mid], nums[high]]
      → If yes: low = mid + 1
      → If no: high = mid - 1
3. Return false (not found)
```

#### Code
```cpp
class Solution {
public:
    bool searchInARotatedSortedArrayII(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Target found
            if (nums[mid] == k)
                return true;
            
            // CRITICAL: Handle the duplicate edge case
            // When we can't determine which half is sorted
            if (nums[mid] == nums[low] && nums[low] == nums[high]) {
                low++;
                high--;
                continue;  // Skip to next iteration
            }
            
            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if target is in the sorted left half
                if (nums[low] <= k && k < nums[mid]) {
                    high = mid - 1;  // Search left
                } else {
                    low = mid + 1;   // Search right
                }
            }
            // Right half is sorted
            else {
                // Check if target is in the sorted right half
                if (nums[high] >= k && k >= nums[mid]) {
                    low = mid + 1;   // Search right
                } else {
                    high = mid - 1;  // Search left
                }
            }
        }
        return false;
    }
};
```

#### Complexity Analysis

| Complexity | Average Case | Worst Case | Explanation |
|------------|--------------|------------|-------------|
| **Time** | O(log n) | O(n) | Worst case when all elements are duplicates |
| **Space** | O(1) | O(1) | Only constant extra variables |

> ⚠️ **Why O(n) in worst case?**
> Consider array `[3, 3, 3, 3, 3, 3, 3]` searching for `4`. Each iteration only shrinks the search space by 2 elements (`low++`, `high--`), resulting in approximately n/2 iterations → O(n).

---

### Visual Dry Run

**Example 1: `nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6]`, `k = 3`**

```
Initial: low=0, high=9

Iteration 1:
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
│ 7 │ 8 │ 1 │ 2 │ 3 │ 3 │ 3 │ 4 │ 5 │ 6 │
└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
  L               M                   R
  0   1   2   3   4   5   6   7   8   9

mid = (0+9)/2 = 4
nums[4] = 3 == k? YES! ✓

Answer: True
```

**Example 2: Duplicate Edge Case - `nums = [3, 1, 2, 3, 3, 3, 3]`, `k = 1`**

```
Initial: low=0, high=6

Iteration 1:
┌───┬───┬───┬───┬───┬───┬───┐
│ 3 │ 1 │ 2 │ 3 │ 3 │ 3 │ 3 │
└───┴───┴───┴───┴───┴───┴───┘
  L           M             R
  0   1   2   3   4   5   6

mid = 3, nums[3] = 3
3 == 1? NO

Check: nums[low]=3 == nums[mid]=3 == nums[high]=3? YES!
→ This is the ambiguous case!
→ low++, high--
→ low=1, high=5

Iteration 2:
┌───┬───┬───┬───┬───┬───┬───┐
│ 3 │ 1 │ 2 │ 3 │ 3 │ 3 │ 3 │
└───┴───┴───┴───┴───┴───┴───┘
      L       M       R
      1   2   3   4   5

mid = (1+5)/2 = 3, nums[3] = 3
3 == 1? NO

Check duplicate edge case:
nums[1]=1 == nums[3]=3? NO → Normal case

Check sorted half:
nums[1]=1 <= nums[3]=3? YES → Left half [1,2,3] is sorted

Is k=1 in [1, 3)?
1 <= 1 && 1 < 3? YES!
→ high = mid - 1 = 2

Iteration 3:
┌───┬───┬───┬───┬───┬───┬───┐
│ 3 │ 1 │ 2 │ 3 │ 3 │ 3 │ 3 │
└───┴───┴───┴───┴───┴───┴───┘
      L   M   R
      1   2   2

mid = (1+2)/2 = 1, nums[1] = 1
1 == 1? YES! ✓

Answer: True
```

---

### Memory Aid 🎯

```
┌─────────────────────────────────────────────────────────┐
│  ROTATED ARRAY SEARCH WITH DUPLICATES                   │
├─────────────────────────────────────────────────────────┤
│  1. Check if nums[mid] == target → DONE                 │
│                                                         │
│  2. Duplicate Edge Case Check:                          │
│     nums[low] == nums[mid] == nums[high]?               │
│     → YES: low++, high--, continue                      │
│                                                         │
│  3. Normal Case:                                        │
│     → Identify sorted half                              │
│     → Check if target is in sorted range                │
│     → Eliminate appropriate half                        │
└─────────────────────────────────────────────────────────┘
```

---

## 2. Find Minimum in Rotated Sorted Array

### Problem Statement
Given an integer array `nums` of size N, sorted in ascending order with **distinct values**, and then rotated an unknown number of times (between 1 and N). Find the **minimum element** in the array.

### Examples

| Input Array | Output | Explanation |
|-------------|--------|-------------|
| `[4, 5, 6, 7, 0, 1, 2, 3]` | `0` | Minimum element is 0 |
| `[3, 4, 5, 1, 2]` | `1` | Minimum element is 1 |
| `[1, 2, 3, 4, 5]` | `1` | Array not rotated, min is first element |

### Key Insight 💡

In a rotated sorted array, the minimum element is the **rotation point** - where the array "breaks" from the sorted order.

```
Original: [0, 1, 2, 3, 4, 5, 6, 7]
Rotated:  [4, 5, 6, 7, 0, 1, 2, 3]
                      ↑
                  MINIMUM
              (rotation point)
```

The minimum element is always in the **unsorted half** of the array!

---

### Approach: Binary Search with Sorted Half Identification

#### How to Solve - Step by Step Thinking 🧠

1. **Observation**: The minimum is at the "break point" of the rotation.

2. **Key Property**: In a rotated sorted array:
   - If the entire search space `[low, high]` is sorted (`nums[low] <= nums[high]`), then `nums[low]` is the minimum in that range.
   - Otherwise, one half is sorted, and the minimum lies in the unsorted half.

3. **Strategy**:
   - Always track the candidate minimum from sorted portions
   - Eliminate the sorted half (after recording its minimum)
   - Search in the unsorted half

#### Algorithm
```
1. Initialize low = 0, high = n-1, ans = INT_MAX
2. While low <= high:
   a. Calculate mid
   b. If nums[low] <= nums[high]:
      → Entire range is sorted
      → ans = min(ans, nums[low])
      → BREAK (no need to continue)
   c. If LEFT half is sorted (nums[low] <= nums[mid]):
      → ans = min(ans, nums[low])
      → Minimum is in RIGHT half
      → low = mid + 1
   d. Else RIGHT half is sorted:
      → ans = min(ans, nums[mid])
      → Minimum is in LEFT half
      → high = mid - 1
3. Return ans
```

#### Code
```cpp
class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int num = INT_MAX;  // Track minimum
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Optimization: If search space is already sorted
            // The leftmost element is the minimum
            if (arr[low] <= arr[high]) {
                num = min(num, arr[low]);
                break;  // No need to continue
            }
            
            // Left half is sorted
            if (arr[low] <= arr[mid]) {
                num = min(num, arr[low]);  // Record min from sorted half
                low = mid + 1;             // Search in unsorted half
            }
            // Right half is sorted
            else {
                num = min(num, arr[mid]);  // Record min from sorted half
                high = mid - 1;            // Search in unsorted half
            }
        }
        return num;
    }
};
```

#### Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(log n) | Search space halved each iteration |
| **Space** | O(1) | Only constant extra variables |

---

### Visual Dry Run

**Example: `nums = [4, 5, 6, 7, 0, 1, 2, 3]`**

```
Initial: low=0, high=7, num=INT_MAX

Iteration 1:
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ 4 │ 5 │ 6 │ 7 │ 0 │ 1 │ 2 │ 3 │
└───┴───┴───┴───┴───┴───┴───┴───┘
  L           M               R
  0   1   2   3   4   5   6   7

mid = (0+7)/2 = 3

Is arr[0]=4 <= arr[7]=3? NO → Range not fully sorted

Is arr[0]=4 <= arr[3]=7? YES → LEFT half is sorted
→ num = min(INT_MAX, 4) = 4
→ low = mid + 1 = 4

Iteration 2:
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ 4 │ 5 │ 6 │ 7 │ 0 │ 1 │ 2 │ 3 │
└───┴───┴───┴───┴───┴───┴───┴───┘
                  L   M       R
                  4   5   6   7

mid = (4+7)/2 = 5

Is arr[4]=0 <= arr[7]=3? YES → Range IS fully sorted!
→ num = min(4, 0) = 0
→ BREAK

Answer: 0
```

**Example: Already Sorted Array `[1, 2, 3, 4, 5]`**

```
Initial: low=0, high=4, num=INT_MAX

Iteration 1:
┌───┬───┬───┬───┬───┐
│ 1 │ 2 │ 3 │ 4 │ 5 │
└───┴───┴───┴───┴───┘
  L       M       R

mid = 2

Is arr[0]=1 <= arr[4]=5? YES → Range IS sorted!
→ num = min(INT_MAX, 1) = 1
→ BREAK

Answer: 1
```

---

### Why This Works - Visual Explanation

```
Rotated Array: [4, 5, 6, 7, 0, 1, 2, 3]

Visual as a "broken" sorted sequence:

     7
   6   
  5        3
 4        2
        1
       0  ← MINIMUM (break point)
░░░░░░░░░░░░░░░░░░░░░░░░░░░░

The LEFT sorted portion: [4,5,6,7] - starts HIGH
The RIGHT sorted portion: [0,1,2,3] - starts LOW

Minimum is always at the START of the RIGHT sorted portion!
```

---

## 3. Find Number of Rotations in Array

### Problem Statement
Given an integer array `nums` of size n, sorted in ascending order with **distinct values**. The array has been **right rotated** an unknown number of times (between 0 and n-1). Determine the **number of rotations** performed on the array.

### Examples

| Input Array | Output | Explanation |
|-------------|--------|-------------|
| `[4, 5, 6, 7, 0, 1, 2, 3]` | `4` | Original was [0,1,2,3,4,5,6,7], rotated 4 times |
| `[3, 4, 5, 1, 2]` | `3` | Original was [1,2,3,4,5], rotated 3 times |
| `[1, 2, 3, 4, 5]` | `0` | Array not rotated |

### Key Insight 💡

The **index of the minimum element** = Number of rotations!

```
Original:  [0, 1, 2, 3, 4, 5, 6, 7]
            ↑
           min at index 0

Rotate 4:  [4, 5, 6, 7, 0, 1, 2, 3]
                        ↑
                   min at index 4

Number of rotations = 4 (index of minimum)
```

---

### Approach: Find Index of Minimum Element

#### How to Solve - Step by Step Thinking 🧠

1. **Realize the connection**: Finding rotations = Finding index of minimum.

2. **Use the same approach as Find Minimum**, but track the **index** instead of just the value.

3. **Slight modification**: Instead of storing `min(num, arr[low])`, store the index when we find a smaller element.

#### Algorithm
```
1. Initialize low = 0, high = n-1, ans = INT_MAX, index = -1
2. While low <= high:
   a. Calculate mid
   b. If nums[low] <= nums[high]:
      → Range is sorted, check if nums[low] is new minimum
      → If yes, update ans and index
      → BREAK
   c. If LEFT half is sorted (nums[low] <= nums[mid]):
      → Check if nums[low] < ans, update ans and index
      → low = mid + 1
   d. Else RIGHT half is sorted:
      → Check if nums[mid] < ans, update ans and index
      → high = mid - 1
3. Return index
```

#### Code
```cpp
class Solution {
public:
    int findKRotation(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;  // Track minimum value
        int index = -1;     // Track index of minimum
        
        while (low <= high) {
            int mid = (low + high) / 2;

            // Optimization: Search space is already sorted
            // nums[low] is the minimum in this range
            if (nums[low] <= nums[high]) {
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                break;
            }
            
            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                low = mid + 1;  // Minimum is in right half
            } 
            // Right half is sorted
            else {
                if (nums[mid] < ans) {
                    index = mid;
                    ans = nums[mid];
                }
                high = mid - 1;  // Minimum is in left half
            }
        }
        return index;
    }
};
```

#### Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(log n) | Binary search |
| **Space** | O(1) | Only constant extra variables |

---

### Visual Dry Run

**Example: `nums = [4, 5, 6, 7, 0, 1, 2, 3]`**

```
Initial: low=0, high=7, ans=INT_MAX, index=-1

Iteration 1:
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ 4 │ 5 │ 6 │ 7 │ 0 │ 1 │ 2 │ 3 │
└───┴───┴───┴───┴───┴───┴───┴───┘
  L           M               R
  0   1   2   3   4   5   6   7

mid = 3

Is nums[0]=4 <= nums[7]=3? NO → Not fully sorted

Is nums[0]=4 <= nums[3]=7? YES → LEFT half sorted
→ Is 4 < INT_MAX? YES
→ index = 0, ans = 4
→ low = mid + 1 = 4

Iteration 2:
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ 4 │ 5 │ 6 │ 7 │ 0 │ 1 │ 2 │ 3 │
└───┴───┴───┴───┴───┴───┴───┴───┘
                  L   M       R
                  4   5   6   7

mid = 5

Is nums[4]=0 <= nums[7]=3? YES → Range IS sorted
→ Is 0 < 4? YES
→ index = 4, ans = 0
→ BREAK

Answer: 4 (the array was rotated 4 times)
```

---

### Connection Between Problems

```
┌─────────────────────────────────────────────────────────┐
│  ROTATED ARRAY PROBLEMS - THE CONNECTION                │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  Find Minimum ─────────────────────► Value of min       │
│       │                                                 │
│       │ Same logic, different tracking                  │
│       ▼                                                 │
│  Find Rotations ───────────────────► Index of min       │
│                                                         │
│  Both use: Identify sorted half → Collect candidate     │
│            → Eliminate sorted half → Continue           │
└─────────────────────────────────────────────────────────┘
```

---

## 4. Single Element in Sorted Array

### Problem Statement
Given an array `nums` sorted in non-decreasing order. Every number in the array except one appears **twice**. Find the **single number** that appears only once.

### Examples

| Input Array | Output | Explanation |
|-------------|--------|-------------|
| `[1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6]` | `4` | Only 4 appears once |
| `[1, 1, 2, 3, 3, 4, 4, 8, 8]` | `2` | Only 2 appears once |
| `[3, 3, 7, 7, 10, 11, 11]` | `10` | Only 10 appears once |

### Key Insight 💡

In a sorted array where every element appears twice except one:
- **Before the single element**: Pairs start at EVEN indices (0,1), (2,3), (4,5)...
- **After the single element**: Pairs start at ODD indices (odd,even), (odd,even)...

```
Array:  [1, 1, 2, 2, 4, 5, 5, 6, 6]
Index:   0  1  2  3  4  5  6  7  8
              ↑     ↑
         (0,1) pairs  Single   (5,6) pairs
         EVEN start   Element  ODD start
```

---

### Approach 1: Linear Search (Brute Force)

#### Intuition
Traverse the array in pairs. If the current element doesn't match the next element, it's the single element.

#### Code
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        if (n == 1)
            return nums[0];  // Only one element

        while (i < n - 1) {
            if (nums[i] == nums[i + 1]) {
                i += 2;  // Skip the pair
            } else {
                return nums[i];  // Found single element
            }
        }

        // Single element is at the last index
        return nums[n - 1];
    }
};
```

#### Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n) | May traverse entire array |
| **Space** | O(1) | Constant extra space |

---

### Approach 2: XOR Approach

#### Intuition
XOR has the property: `a ^ a = 0` and `0 ^ a = a`. So XORing all elements cancels out pairs, leaving only the single element.

#### Code
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // XOR all elements
        for (int i = 0; i < n; i++) {
            ans = ans ^ nums[i];
        }

        return ans;
    }
};
```

#### How XOR Works

```
nums = [1, 1, 2, 2, 4]

Step by step:
0 ^ 1 = 1
1 ^ 1 = 0
0 ^ 2 = 2
2 ^ 2 = 0
0 ^ 4 = 4

Answer: 4 ✓
```

#### Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n) | Must visit all elements |
| **Space** | O(1) | Only one variable |

> **Note**: This approach works but doesn't utilize the **sorted** property of the array. We can do better!

---

### Approach 3: Binary Search (Optimal) ⭐

#### How to Solve - Step by Step Thinking 🧠

1. **Observation about pairs and indices**:
   - Before the single element: First of pair is at EVEN index
   - After the single element: First of pair is at ODD index

2. **The pattern**:
   ```
   Before single: (even, odd) - first match is at even index
   After single:  (odd, even) - first match is at odd index
   
   Example: [1, 1, 2, 2, 4, 5, 5]
             0  1  2  3  4  5  6
            └──┘ └──┘ ↑ └──┘
            even odd  S  odd even
   ```

3. **Strategy**:
   - At any `mid`, check if we're on the LEFT side or RIGHT side of the single element
   - If LEFT side: single element is to the right → `low = mid + 1`
   - If RIGHT side: single element is to the left → `high = mid - 1`

4. **How to identify which side we're on**:
   - If `mid` is EVEN and `nums[mid] == nums[mid+1]` → We're on LEFT side
   - If `mid` is ODD and `nums[mid] == nums[mid-1]` → We're on LEFT side
   - Otherwise → We're on RIGHT side

#### Algorithm
```
1. Handle edge cases:
   - If n == 1: return nums[0]
   - If nums[0] != nums[1]: return nums[0]
   - If nums[n-1] != nums[n-2]: return nums[n-1]
2. Search in range [1, n-2] (edges already handled)
3. While low <= high:
   a. Calculate mid
   b. If nums[mid] != neighbors → return nums[mid]
   c. Check if we're on LEFT side:
      - (mid is ODD and nums[mid] == nums[mid-1]) OR
      - (mid is EVEN and nums[mid] == nums[mid+1])
      → low = mid + 1
   d. Else we're on RIGHT side:
      → high = mid - 1
4. Return -1 (shouldn't reach here)
```

#### Code
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Edge cases
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        // Binary search in range [1, n-2]
        int low = 1, high = n - 2;
        
        while (low <= high) {
            int mid = (low + high) / 2;

            // If nums[mid] is the single element
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            // Check if we are on the LEFT side of single element
            // LEFT side: pairs follow (even, odd) pattern
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                // Single element is on the right
                low = mid + 1;
            }
            // We are on the RIGHT side of single element
            else {
                // Single element is on the left
                high = mid - 1;
            }
        }

        return -1;  // Should never reach here
    }
};
```

#### Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(log n) | Binary search |
| **Space** | O(1) | Constant extra space |

---

### Visual Dry Run

**Example: `nums = [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6]`**

```
Array with index parity highlighted:
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
│ 1 │ 1 │ 2 │ 2 │ 3 │ 3 │ 4 │ 5 │ 5 │ 6 │ 6 │
└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
  E   O   E   O   E   O   E   O   E   O   E
  0   1   2   3   4   5   6   7   8   9   10

Edge checks: nums[0]=nums[1]? YES, nums[10]=nums[9]? YES
→ Single element is in the middle

low = 1, high = 9

Iteration 1:
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
│ 1 │ 1 │ 2 │ 2 │ 3 │ 3 │ 4 │ 5 │ 5 │ 6 │ 6 │
└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
      L               M               R
      1   2   3   4   5   6   7   8   9

mid = 5, nums[5] = 3

Is nums[5] != nums[4] AND nums[5] != nums[6]?
3 != 3? NO → Not the single element

Check if on LEFT side:
mid=5 is ODD, check if nums[5]==nums[4]?
3 == 3? YES → We're on LEFT side
→ low = mid + 1 = 6

Iteration 2:
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
│ 1 │ 1 │ 2 │ 2 │ 3 │ 3 │ 4 │ 5 │ 5 │ 6 │ 6 │
└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
                          L   M   R
                          6   7   8   9

mid = 7, nums[7] = 5

Is nums[7] != nums[6] AND nums[7] != nums[8]?
5 != 4? YES, 5 != 5? NO → Not the single element

Check if on LEFT side:
mid=7 is ODD, check if nums[7]==nums[6]?
5 == 4? NO

mid=7 is ODD and doesn't match left, so check other condition:
mid=7 is ODD (not even), so even condition doesn't apply
→ We're on RIGHT side
→ high = mid - 1 = 6

Iteration 3:
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
│ 1 │ 1 │ 2 │ 2 │ 3 │ 3 │ 4 │ 5 │ 5 │ 6 │ 6 │
└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
                         L,M,R
                          6

mid = 6, nums[6] = 4

Is nums[6] != nums[5] AND nums[6] != nums[7]?
4 != 3? YES, 4 != 5? YES → FOUND! ✓

Answer: 4
```

---

### Pattern Summary - When to Use Which Index Check

```
┌─────────────────────────────────────────────────────────┐
│  SINGLE ELEMENT - INDEX PATTERN                         │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  BEFORE single element:                                 │
│  ┌────────────────────────────────────────────┐        │
│  │ (E,O) (E,O) (E,O) ... SINGLE ... (O,E)(O,E)│        │
│  │  0,1   2,3   4,5                  7,8  9,10│        │
│  └────────────────────────────────────────────┘        │
│                                                         │
│  ON LEFT SIDE (before single):                          │
│  → mid is EVEN & nums[mid] == nums[mid+1]              │
│  → mid is ODD  & nums[mid] == nums[mid-1]              │
│                                                         │
│  ON RIGHT SIDE (after single):                          │
│  → mid is EVEN & nums[mid] == nums[mid-1]              │
│  → mid is ODD  & nums[mid] == nums[mid+1]              │
└─────────────────────────────────────────────────────────┘
```

---

## Comparison of All Approaches for Single Element

| Approach | Time | Space | Uses Sorted Property? |
|----------|------|-------|----------------------|
| Linear Search | O(n) | O(1) | ✓ (partially) |
| XOR | O(n) | O(1) | ✗ |
| Binary Search | O(log n) | O(1) | ✓ (fully) |

---

## Summary - Key Takeaways 🎯

### 1. Search in Rotated Sorted Array - II
- **Challenge**: Duplicates break sorted half identification
- **Solution**: When `nums[low] == nums[mid] == nums[high]`, shrink from both ends
- **Worst case**: O(n) when all elements are same

### 2. Find Minimum in Rotated Sorted Array
- **Key Insight**: Minimum is at the rotation point
- **Strategy**: Always pick minimum from sorted half, search in unsorted half
- **Optimization**: If range is sorted, leftmost is minimum

### 3. Find Number of Rotations
- **Connection**: Rotations count = Index of minimum element
- **Same logic as Find Minimum**, just track index instead of value

### 4. Single Element in Sorted Array
- **Key Insight**: Before single → pairs start at EVEN index; After → pairs start at ODD index
- **Binary Search**: Determine which side of single element we're on using index parity

---

## Quick Revision Patterns 📝

```
┌─────────────────────────────────────────────────────────┐
│  BINARY SEARCH IN ROTATED ARRAYS - MASTER PATTERN       │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  1. Identify which half is SORTED                       │
│     → nums[low] <= nums[mid] → LEFT is sorted           │
│     → else → RIGHT is sorted                            │
│                                                         │
│  2. Check if target/answer is in SORTED half            │
│     → If yes, search sorted half                        │
│     → If no, search unsorted half                       │
│                                                         │
│  3. For DUPLICATES: Handle ambiguous case               │
│     → low++, high-- when all three equal                │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

```
┌─────────────────────────────────────────────────────────┐
│  SINGLE ELEMENT - QUICK PATTERN                         │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  Before single: pairs at (EVEN, ODD) indices            │
│  After single: pairs at (ODD, EVEN) indices             │
│                                                         │
│  At mid, check:                                         │
│  → (mid ODD && match left) OR (mid EVEN && match right) │
│    = We're before single → go RIGHT                     │
│  → Otherwise → go LEFT                                  │
│                                                         │
└─────────────────────────────────────────────────────────┘
```
