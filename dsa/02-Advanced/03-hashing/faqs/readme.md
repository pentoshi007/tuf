# Hashing Problems - Comprehensive Guide

This document covers 4 important hashing problems with multiple approaches, complexity analysis, and detailed dry runs for optimal revision.

---

## Table of Contents
1. [Longest Consecutive Sequence in an Array](#1-longest-consecutive-sequence-in-an-array)
2. [Longest Subarray with Sum K](#2-longest-subarray-with-sum-k)
3. [Count Subarrays with Given Sum](#3-count-subarrays-with-given-sum)
4. [Count Subarrays with Given XOR K](#4-count-subarrays-with-given-xor-k)

---

## 1. Longest Consecutive Sequence in an Array

### Problem Statement
Given an array `nums` of `n` integers, return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

**Example:**
```
Input: nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive sequence is [1, 2, 3, 4], length = 4
```

---

### Approach 1: Brute Force (Linear Search)

#### Intuition
For each element, check if the next consecutive element exists in the array using linear search. Keep counting consecutive elements and track the maximum length.

#### Algorithm
1. For each element `x` in the array
2. Set `count = 1`
3. While `x+1` exists in array (using linear search):
   - Increment `x`
   - Increment `count`
4. Update `longest = max(longest, count)`

#### Code
```cpp
class Solution {
private:
    bool linearSearch(vector<int> &a, int num) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] == num)
                return true;
        }
        return false;
    }

public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int n = nums.size();
        int longest = 1;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int cnt = 1;

            while (linearSearch(nums, x + 1) == true) {
                x += 1;
                cnt += 1;
            }

            longest = max(longest, cnt);
        }
        return longest;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N²) - For each element, we perform linear search which takes O(N)
- **Space Complexity:** O(1) - No extra space used

#### Dry Run
```
Input: nums = [100, 4, 200, 1, 3, 2]

i=0, x=100: Search for 101 → Not found → cnt=1
i=1, x=4: Search for 5 → Not found → cnt=1
i=2, x=200: Search for 201 → Not found → cnt=1
i=3, x=1: Search for 2 → Found → x=2, cnt=2
          Search for 3 → Found → x=3, cnt=3
          Search for 4 → Found → x=4, cnt=4
          Search for 5 → Not found → cnt=4
          longest = 4
i=4, x=3: Search for 4 → Found → x=4, cnt=2
          Search for 5 → Not found → cnt=2
i=5, x=2: Search for 3 → Found → x=3, cnt=2
          Search for 4 → Found → x=4, cnt=3
          Search for 5 → Not found → cnt=3

Result: 4
```

---

### Approach 2: Better Approach (Sorting)

#### Intuition
Sort the array first. Then traverse the array and count consecutive elements. Handle duplicates by skipping them.

#### Algorithm
1. Sort the array
2. Initialize `count = 1` and `longest = 1`
3. Traverse the sorted array:
   - If `nums[i] == nums[i+1]`: Skip (duplicate)
   - If `nums[i+1] == nums[i] + 1`: Increment count
   - Else: Reset count to 1
4. Update longest in each iteration

#### Code
```cpp
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int longest = 1;
        int count = 1;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1])
                continue;
            else if (nums[i + 1] == (nums[i] + 1)) {
                count++;
                longest = max(longest, count);
            }
            else {
                longest = max(longest, count);
                count = 1;
            }
        }
        return longest;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N log N) - Sorting takes O(N log N)
- **Space Complexity:** O(1) - Sorting in-place (or O(N) if we consider sorting space)

#### Dry Run
```
Input: nums = [100, 4, 200, 1, 3, 2]

After sorting: [1, 2, 3, 4, 100, 200]

i=0: nums[0]=1, nums[1]=2 → 2 == 1+1 → count=2, longest=2
i=1: nums[1]=2, nums[2]=3 → 3 == 2+1 → count=3, longest=3
i=2: nums[2]=3, nums[3]=4 → 4 == 3+1 → count=4, longest=4
i=3: nums[3]=4, nums[4]=100 → 100 != 4+1 → count=1
i=4: nums[4]=100, nums[5]=200 → 200 != 100+1 → count=1

Result: 4
```

**Visual Representation:**
```
Sorted Array:  [1] → [2] → [3] → [4]   [100]   [200]
                └─────┴─────┴─────┘
              Consecutive Sequence (length 4)
```

---

### Approach 3: Optimal Approach (Hashing with Set)

#### Intuition
Use an unordered set for O(1) lookup. For each number, check if it's the start of a sequence (i.e., `num-1` doesn't exist). If yes, count consecutive numbers from there.

#### Algorithm
1. Insert all elements into an unordered set
2. For each element in set:
   - Check if `element - 1` exists in set
   - If NOT exists, this is the start of a sequence
   - Count consecutive elements from here
3. Track maximum length

#### Code
```cpp
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int longest = 1;
        unordered_set<int> st(nums.begin(), nums.end());

        for (auto it : st) {
            // Check if it's the start of a sequence
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {
                    x++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N) - Each element is visited at most twice (once in outer loop, once in while loop)
- **Space Complexity:** O(N) - Unordered set storage

#### Dry Run
```
Input: nums = [100, 4, 200, 1, 3, 2]

Set: {100, 4, 200, 1, 3, 2}

Iteration 1: element = 100
  - Check 99 in set? NO → Start of sequence
  - Check 101 in set? NO → count = 1

Iteration 2: element = 4
  - Check 3 in set? YES → Not start, skip

Iteration 3: element = 200
  - Check 199 in set? NO → Start of sequence
  - Check 201 in set? NO → count = 1

Iteration 4: element = 1
  - Check 0 in set? NO → Start of sequence
  - Check 2 in set? YES → x=2, count=2
  - Check 3 in set? YES → x=3, count=3
  - Check 4 in set? YES → x=4, count=4
  - Check 5 in set? NO → count = 4
  - longest = 4

Iteration 5: element = 3
  - Check 2 in set? YES → Not start, skip

Iteration 6: element = 2
  - Check 1 in set? YES → Not start, skip

Result: 4
```

**Visual Representation:**
```
Set: {1, 2, 3, 4, 100, 200}

Checking 1: (0 not in set) ✓ Start of sequence
   1 → 2 ✓ → 3 ✓ → 4 ✓ → 5 ✗
   Count = 4

Checking 2: (1 in set) ✗ Not a start, skip
Checking 3: (2 in set) ✗ Not a start, skip
Checking 4: (3 in set) ✗ Not a start, skip
Checking 100: (99 not in set) ✓ Start, but 101 not in set → Count = 1
Checking 200: (199 not in set) ✓ Start, but 201 not in set → Count = 1

Maximum: 4
```

---

## 2. Longest Subarray with Sum K

### Problem Statement
Given an array `nums` of size `n` and an integer `k`, find the length of the longest sub-array that sums to `k`. If no such sub-array exists, return 0.

**Example:**
```
Input: nums = [10, 5, 2, 7, 1, 9], k = 15
Output: 4
Explanation: The longest sub-array is [5, 2, 7, 1] with sum = 15, length = 4
```

---

### Approach 1: Brute Force (Three Nested Loops)

#### Intuition
Generate all possible subarrays and calculate their sums. Track the maximum length where sum equals k.

#### Algorithm
1. Use two loops to generate all subarrays [i...j]
2. Use third loop to calculate sum of subarray
3. If sum equals k, update maxLength

#### Code
```cpp
class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        int n = nums.size();
        int maxLength = 0;

        for (int startIndex = 0; startIndex < n; startIndex++) {
            for (int endIndex = startIndex; endIndex < n; endIndex++) {
                int currentSum = 0;
                for (int i = startIndex; i <= endIndex; i++) {
                    currentSum += nums[i];
                }

                if (currentSum == k)
                    maxLength = max(maxLength, endIndex - startIndex + 1);
            }
        }
        return maxLength;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N³) - Three nested loops
- **Space Complexity:** O(1) - No extra space

#### Dry Run
```
Input: nums = [10, 5, 2, 7, 1, 9], k = 15

startIndex=0:
  endIndex=0: sum=10 ≠ 15
  endIndex=1: sum=10+5=15 ✓ → maxLength = 2
  endIndex=2: sum=10+5+2=17 ≠ 15
  endIndex=3: sum=10+5+2+7=24 ≠ 15
  ...

startIndex=1:
  endIndex=1: sum=5 ≠ 15
  endIndex=2: sum=5+2=7 ≠ 15
  endIndex=3: sum=5+2+7=14 ≠ 15
  endIndex=4: sum=5+2+7+1=15 ✓ → maxLength = 4
  ...

Result: 4
```

---

### Approach 2: Optimal for Positives + Negatives (Prefix Sum with Hashing)

#### Intuition
Use prefix sum and hashing. If `sum - k` exists in the map, we found a subarray with sum k. Store the first occurrence of each prefix sum to get the longest subarray.

**Key Insight:** If `prefixSum[j] - prefixSum[i-1] = k`, then subarray [i...j] has sum k.
Rearranging: `prefixSum[i-1] = prefixSum[j] - k`

#### Algorithm
1. Maintain a map of prefix sums and their indices
2. For each index:
   - Calculate prefix sum
   - If sum equals k, update maxLen
   - If (sum - k) exists in map, calculate length
   - Store sum in map (only if not present)

#### Code
```cpp
class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        int n = nums.size();
        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            int rem = sum - k;

            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N log N) - Map operations take O(log N)
- **Space Complexity:** O(N) - Map storage

#### Dry Run
```
Input: nums = [10, 5, 2, 7, 1, 9], k = 15

Index | Element | Sum | rem=sum-k | Map Before | Found? | maxLen | Map After
------|---------|-----|-----------|------------|--------|--------|------------
  0   |   10    | 10  |   -5      |    {}      |   NO   |   0    | {10:0}
  1   |    5    | 15  |    0      |  {10:0}    |   NO   |   2    | {10:0, 15:1}
  2   |    2    | 17  |    2      |{10:0,15:1} |   NO   |   2    | {10:0,15:1,17:2}
  3   |    7    | 24  |    9      |{10:0,...}  |   NO   |   2    | {10:0,15:1,17:2,24:3}
  4   |    1    | 25  |   10      |{10:0,...}  |  YES   |   4    | (10 at index 0, len=4-0=4)
  5   |    9    | 34  |   19      |   ...      |   NO   |   4    | ...

Result: 4

Explanation for index 4:
- sum = 25, rem = 25 - 15 = 10
- 10 exists in map at index 0
- Subarray from index 1 to 4: [5, 2, 7, 1] → sum = 15 ✓
- Length = 4 - 0 = 4
```

**Visual Representation:**
```
Array:  [10,  5,  2,  7,  1,  9]
Index:   0   1   2   3   4   5

Prefix Sum:
Index 0: 10
Index 1: 10 + 5 = 15 ✓ (sum == k, length = 2)
Index 2: 15 + 2 = 17
Index 3: 17 + 7 = 24
Index 4: 24 + 1 = 25
         rem = 25 - 15 = 10
         10 found at index 0
         Subarray [1 to 4]: [5, 2, 7, 1] ✓
         Length = 4

     [10] [5, 2, 7, 1] [9]
      ↑    └────────┘
   sum=10  sum=15 (k=15)
```

---

### Approach 3: Optimal for Only Positive Numbers (Two Pointer/Sliding Window)

#### Intuition
Since all numbers are positive, we can use the two-pointer technique. Expand the window when sum < k, shrink when sum > k.

#### Algorithm
1. Use two pointers: left = 0, right = 0
2. Maintain sum of current window
3. While right < n:
   - If sum > k: shrink window from left
   - If sum == k: update maxLen
   - Expand window from right

#### Code
```cpp
class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int left = 0, right = 0;
        int sum = nums[0];

        while (right < n) {
            while (left <= right && sum > k) {
                sum -= nums[left];
                left++;
            }

            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
            if (right < n)
                sum += nums[right];
        }

        return maxLen;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N) - Each element is visited at most twice
- **Space Complexity:** O(1) - Only pointers used

#### Dry Run
```
Input: nums = [10, 5, 2, 7, 1, 9], k = 15

Step | left | right | sum | Action              | maxLen
-----|------|-------|-----|---------------------|-------
  1  |  0   |   0   | 10  | sum < k, expand     |   0
  2  |  0   |   1   | 15  | sum == k ✓          |   2
  3  |  0   |   2   | 17  | sum > k, shrink     |   2
  4  |  1   |   2   |  7  | sum < k, expand     |   2
  5  |  1   |   3   | 14  | sum < k, expand     |   2
  6  |  1   |   4   | 15  | sum == k ✓          |   4
  7  |  1   |   5   | 24  | sum > k, done       |   4

Result: 4
```

**Visual Representation:**
```
Array: [10, 5, 2, 7, 1, 9], k = 15

Step 1: [10] 5  2  7  1  9     sum=10 < 15
         L,R

Step 2: [10, 5] 2  7  1  9     sum=15 == 15 ✓ (len=2)
         L   R

Step 3:  10 [5, 2] 7  1  9     sum=17 > 15, shrink → sum=7
             L  R

Step 4:  10 [5, 2, 7] 1  9     sum=14 < 15
             L     R

Step 5:  10 [5, 2, 7, 1] 9     sum=15 == 15 ✓ (len=4)
             L        R

Maximum length = 4
```

---

## 3. Count Subarrays with Given Sum

### Problem Statement
Given an array `nums` and an integer `k`, return the total number of subarrays whose sum equals `k`.

**Example:**
```
Input: nums = [1, 2, 3], k = 3
Output: 2
Explanation: Subarrays [1, 2] and [3] have sum = 3
```

---

### Approach 1: Brute Force

#### Intuition
Generate all subarrays and count those with sum equal to k.

#### Algorithm
1. Use two nested loops to generate subarrays
2. Calculate sum on the fly (optimization over 3 loops)
3. If sum equals k, increment count

#### Code
```cpp
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int startIndex = 0; startIndex < n; startIndex++) {
            int currentSum = 0;
            for (int endIndex = startIndex; endIndex < n; endIndex++) {
                currentSum += nums[endIndex];

                if (currentSum == k)
                    count++;
            }
        }
        return count;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N²) - Two nested loops
- **Space Complexity:** O(1) - No extra space

#### Dry Run
```
Input: nums = [1, 2, 3], k = 3

startIndex=0 (element=1):
  endIndex=0: sum=1 ≠ 3
  endIndex=1: sum=1+2=3 ✓ → count=1
  endIndex=2: sum=3+3=6 ≠ 3

startIndex=1 (element=2):
  endIndex=1: sum=2 ≠ 3
  endIndex=2: sum=2+3=5 ≠ 3

startIndex=2 (element=3):
  endIndex=2: sum=3 ✓ → count=2

Result: 2
```

**Visual Representation:**
```
Array: [1, 2, 3], k = 3

All subarrays:
[1]       → sum = 1
[1, 2]    → sum = 3 ✓
[1, 2, 3] → sum = 6
[2]       → sum = 2
[2, 3]    → sum = 5
[3]       → sum = 3 ✓

Count = 2
```

---

### Approach 2: Optimal (Prefix Sum with Hashing)

#### Intuition
Use prefix sum and hashing. If `prefixSum - k` exists in the map, we found subarray(s) with sum k. Count all occurrences.

**Key Insight:** If we have prefix sum `sum` at index `i`, and we've seen prefix sum `sum - k` before, then there exists a subarray ending at `i` with sum `k`.

#### Algorithm
1. Initialize map with {0: 1} (for subarrays starting from index 0)
2. For each element:
   - Calculate prefix sum
   - Add count of (sum - k) from map
   - Increment frequency of current sum in map

#### Code
```cpp
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int count = 0;
        int n = nums.size();
        int presum = 0;
        map<int, int> mpp;
        mpp[0] = 1;  // Important: for subarrays starting from index 0

        for (int i = 0; i < n; i++) {
            presum = presum + nums[i];
            int remove = presum - k;
            count += mpp[remove];
            mpp[presum]++;
        }

        return count;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N log N) - Map operations (or O(N) with unordered_map)
- **Space Complexity:** O(N) - Map storage

#### Dry Run
```
Input: nums = [1, 2, 3], k = 3

Initial: mpp = {0: 1}, count = 0

Index | Element | presum | remove=presum-k | mpp[remove] | count | Map After
------|---------|--------|-----------------|-------------|-------|-------------
  0   |    1    |   1    |    1-3 = -2     |      0      |   0   | {0:1, 1:1}
  1   |    2    |   3    |    3-3 = 0      |      1      |   1   | {0:1, 1:1, 3:1}
  2   |    3    |   6    |    6-3 = 3      |      1      |   2   | {0:1, 1:1, 3:1, 6:1}

Result: 2

Explanation:
- At index 1: presum=3, remove=0. Map has {0:1}, so we found 1 subarray [0 to 1]
- At index 2: presum=6, remove=3. Map has {3:1}, so we found 1 subarray [2 to 2]
```

**Visual Representation:**
```
Array: [1, 2, 3], k = 3

Prefix Sums:
Index -1: 0 (initial)
Index  0: 0 + 1 = 1
Index  1: 1 + 2 = 3
Index  2: 3 + 3 = 6

Finding subarrays:
At index 1:
  presum = 3
  remove = 3 - 3 = 0
  0 exists in map (count = 1)
  → Subarray from after index of presum=0 to current index
  → [1, 2] has sum = 3 ✓

At index 2:
  presum = 6
  remove = 6 - 3 = 3
  3 exists in map (count = 1)
  → Subarray from after index of presum=3 to current index
  → [3] has sum = 3 ✓

Total count = 2

Map Evolution:
{0:1} → {0:1, 1:1} → {0:1, 1:1, 3:1} → {0:1, 1:1, 3:1, 6:1}
```

---

## 4. Count Subarrays with Given XOR K

### Problem Statement
Given an array of integers `nums` and an integer `k`, return the total number of subarrays whose XOR equals `k`.

**Example:**
```
Input: nums = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: Subarrays [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6] have XOR = 6
```

---

### Approach 1: Brute Force

#### Intuition
Generate all subarrays and calculate their XOR. Count those with XOR equal to k.

#### Algorithm
1. Use two nested loops to generate subarrays
2. Calculate XOR on the fly
3. If XOR equals k, increment count

#### Code
```cpp
class Solution {
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int xorr = 0;
            for (int j = i; j < n; j++) {
                xorr = xorr ^ nums[j];

                if (xorr == k)
                    cnt++;
            }
        }
        return cnt;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N²) - Two nested loops
- **Space Complexity:** O(1) - No extra space

#### Dry Run
```
Input: nums = [4, 2, 2, 6, 4], k = 6

i=0 (start with 4):
  j=0: xorr = 4 ≠ 6
  j=1: xorr = 4^2 = 6 ✓ → cnt=1
  j=2: xorr = 6^2 = 4 ≠ 6
  j=3: xorr = 4^6 = 2 ≠ 6
  j=4: xorr = 2^4 = 6 ✓ → cnt=2

i=1 (start with 2):
  j=1: xorr = 2 ≠ 6
  j=2: xorr = 2^2 = 0 ≠ 6
  j=3: xorr = 0^6 = 6 ✓ → cnt=3
  j=4: xorr = 6^4 = 2 ≠ 6

i=2 (start with 2):
  j=2: xorr = 2 ≠ 6
  j=3: xorr = 2^6 = 4 ≠ 6
  j=4: xorr = 4^4 = 0 ≠ 6

i=3 (start with 6):
  j=3: xorr = 6 ✓ → cnt=4
  j=4: xorr = 6^4 = 2 ≠ 6

i=4 (start with 4):
  j=4: xorr = 4 ≠ 6

Result: 4
```

**XOR Table:**
```
Array: [4, 2, 2, 6, 4], k = 6

Subarrays with XOR = 6:
[4, 2]             → 4 ^ 2 = 6 ✓
[4, 2, 2, 6, 4]    → 4 ^ 2 ^ 2 ^ 6 ^ 4 = 6 ✓
[2, 2, 6]          → 2 ^ 2 ^ 6 = 6 ✓
[6]                → 6 ✓

Count = 4
```

---

### Approach 2: Optimal (Prefix XOR with Hashing)

#### Intuition
Similar to prefix sum approach, but using XOR. If `prefixXOR ^ k` exists in the map, we found subarray(s) with XOR k.

**Key Property:** For XOR, if `a ^ b = c`, then `a = b ^ c` and `b = a ^ c`

**Algorithm:**
- If `xr` is prefix XOR up to index `i`
- And we want subarray XOR = `k`
- Then we need to find if `xr ^ k` exists before index `i`
- Because: `(xr ^ k) ^ k = xr`

#### Algorithm
1. Initialize map with {0: 1}
2. For each element:
   - Calculate prefix XOR
   - Calculate `x = xr ^ k`
   - Add count of `x` from map
   - Increment frequency of current XOR in map

#### Code
```cpp
class Solution {
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int xr = 0;
        map<int, int> mpp;
        mpp[xr]++;  // mpp[0] = 1
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            xr = xr ^ nums[i];
            int x = xr ^ k;
            cnt += mpp[x];
            mpp[xr]++;
        }
        return cnt;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N log N) - Map operations (or O(N) with unordered_map)
- **Space Complexity:** O(N) - Map storage

#### Dry Run
```
Input: nums = [4, 2, 2, 6, 4], k = 6

Initial: mpp = {0: 1}, cnt = 0

Index | Element | xr  | x = xr^k | mpp[x] | cnt | Map After
------|---------|-----|----------|--------|-----|-------------
  0   |    4    |  4  |  4^6=2   |   0    |  0  | {0:1, 4:1}
  1   |    2    |  6  |  6^6=0   |   1    |  1  | {0:1, 4:1, 6:1}
  2   |    2    |  4  |  4^6=2   |   0    |  1  | {0:1, 4:2, 6:1}
  3   |    6    |  2  |  2^6=4   |   2    |  3  | {0:1, 4:2, 6:1, 2:1}
  4   |    4    |  6  |  6^6=0   |   1    |  4  | {0:1, 4:2, 6:2, 2:1}

Result: 4
```

**Detailed Explanation:**

```
Binary Representation:
4 = 100
2 = 010
6 = 110
k = 6 = 110

XOR Properties:
4 ^ 2 = 110 = 6 ✓
4 ^ 2 ^ 2 = 100 = 4
4 ^ 2 ^ 2 ^ 6 = 010 = 2
4 ^ 2 ^ 2 ^ 6 ^ 4 = 110 = 6 ✓

Prefix XOR Array: [4, 6, 4, 2, 6]

At index 1:
  xr = 6, x = 6 ^ 6 = 0
  0 exists in map → Found subarray [0 to 1]: [4, 2] → XOR = 6 ✓

At index 3:
  xr = 2, x = 2 ^ 6 = 4
  4 exists in map 2 times (at index 0 and 2)
  → Subarray [1 to 3]: [2, 2, 6] → XOR = 6 ✓
  → But we only count 2 occurrences

At index 4:
  xr = 6, x = 6 ^ 6 = 0
  0 exists in map → Found subarray [0 to 4]: [4,2,2,6,4] → XOR = 6 ✓
  AND
  xr = 6 exists at index 1
  → Subarray [index 1+1 to 4]: Would be counted if we had multiple

Actually at index 3:
  xr = 2, x = 2 ^ 6 = 4
  4 appears at indices: 0, 2
  From index 0: subarray [1 to 3] = [2, 2, 6] → 2^2^6 = 6 ✓
  From index 2: subarray [3 to 3] = [6] → 6 ✓

Total: 4 subarrays
```

**Visual Representation:**
```
Array:     [4,  2,  2,  6,  4]
Index:      0   1   2   3   4
XOR:        4   6   4   2   6

Map Evolution & Findings:

Index 0: xr=4, need x=4^6=2
  {0:1, 4:1} - No match

Index 1: xr=6, need x=6^6=0
  {0:1, 4:1, 6:1} - Found 0!
  → Subarray [0→1]: [4,2] XOR=6 ✓

Index 2: xr=4, need x=4^6=2
  {0:1, 4:2, 6:1} - No match

Index 3: xr=2, need x=2^6=4
  {0:1, 4:2, 6:1, 2:1} - Found 4 twice!
  → Subarray [1→3]: [2,2,6] XOR=6 ✓
  → Subarray [3→3]: [6] XOR=6 ✓

Index 4: xr=6, need x=6^6=0
  {0:1, 4:2, 6:2, 2:1} - Found 0!
  → Subarray [0→4]: [4,2,2,6,4] XOR=6 ✓

Total Count = 4
```

---

## Summary Table

| Problem | Brute Force | Better/Intermediate | Optimal | Key Technique |
|---------|-------------|-------------------|---------|---------------|
| **Longest Consecutive** | O(N²), O(1) | O(N log N), O(1) | O(N), O(N) | Hash Set |
| **Longest Subarray Sum K** | O(N³), O(1) | O(N log N), O(N) | O(N), O(N) or O(1) | Prefix Sum + Hashing / Two Pointer |
| **Count Subarray Sum K** | O(N²), O(1) | - | O(N), O(N) | Prefix Sum + Hashing |
| **Count Subarray XOR K** | O(N²), O(1) | - | O(N), O(N) | Prefix XOR + Hashing |

---

## Key Concepts to Remember

### 1. Prefix Sum/XOR Technique
- **Prefix Sum:** `prefixSum[i] = prefixSum[i-1] + arr[i]`
- **Subarray Sum [i...j]:** `prefixSum[j] - prefixSum[i-1]`
- **To find sum = k:** Look for `prefixSum - k` in map

### 2. XOR Properties
- `a ^ a = 0`
- `a ^ 0 = a`
- `a ^ b = c` implies `a = b ^ c`
- XOR is associative and commutative

### 3. Hashing Patterns
- **Count problems:** Store frequency in map
- **Length problems:** Store first occurrence index
- **Initialize with {0: 1}** for subarrays starting from index 0

### 4. Two Pointer Technique
- **Only for positive numbers** (monotonic property)
- Expand window when sum < target
- Shrink window when sum > target

---

## Practice Tips

1. **Start with Brute Force:** Always think of the brute force solution first
2. **Identify Pattern:** Look for prefix sum/XOR patterns
3. **Use Hashing:** When you need to look up previous values quickly
4. **Consider Constraints:** Positive-only arrays → Two pointer possible
5. **Edge Cases:** Empty array, single element, all same elements
6. **Dry Run:** Always dry run with a small example

---

## Common Mistakes to Avoid

1. **Map Initialization:** Forgetting `mpp[0] = 1` for prefix techniques
2. **XOR vs Sum:** Confusing XOR properties with arithmetic operations
3. **Index Calculation:** Off-by-one errors in length calculations
4. **Duplicate Handling:** Not handling duplicates in consecutive sequence
5. **Two Pointer Scope:** Using two pointer for arrays with negatives

---

Happy Learning! 🚀
