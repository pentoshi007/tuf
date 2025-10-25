# Array Problems: Questions 7-10

## 📋 Table of Contents
1. [Problem 7: Rotate Matrix by 90 Degrees](#problem-7-rotate-matrix-by-90-degrees)
2. [Problem 8: Two Sum](#problem-8-two-sum)
3. [Problem 9: Three Sum](#problem-9-three-sum)
4. [Problem 10: Four Sum](#problem-10-four-sum)

---

## Problem 7: Rotate Matrix by 90 Degrees

### Problem Statement
Given an N × N 2D integer matrix, rotate the matrix by 90 degrees **clockwise**.

**Constraints:**
- The rotation must be done **in place** (modify input directly)
- N × N square matrix

**Example:**
```
Input:
1 2 3
4 5 6
7 8 9

Output:
7 4 1
8 5 2
9 6 3
```

---

### Approach 1: Brute Force (Extra Space)

#### Explanation
Create a new matrix to store the rotated values. For every element at position `(i, j)` in the original matrix, place it at position `(j, n - i - 1)` in the rotated matrix.

**Key Formula:** `rotated[j][n - i - 1] = matrix[i][j]`

#### Logic
- Element at row `i`, column `j` in original → Element at row `j`, column `n-1-i` in rotated
- This is because rotating 90° clockwise means:
  - First row becomes last column
  - Second row becomes second-last column
  - And so on...

#### Code
```cpp
class Solution {
public:
    void rotateMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        
        // Step 1: Create new matrix to store rotated values
        vector<vector<int>> rotated(n, vector<int>(n, 0));
        
        // Step 2: Iterate through original matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Place element at new position
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }
        
        // Step 3: Copy rotated matrix back to original
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rotated[i][j];
            }
        }
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N²) - Need to traverse all N² elements
- **Space Complexity:** O(N²) - Extra space for new matrix

#### Dry Run with Visual

**Input Matrix (3×3):**
```
1 2 3
4 5 6
7 8 9
```

**Mapping Process:**
```
Original Position → Rotated Position
(0,0)→1  becomes  (0,2)→1
(0,1)→2  becomes  (1,2)→2
(0,2)→3  becomes  (2,2)→3
(1,0)→4  becomes  (0,1)→4
(1,1)→5  becomes  (1,1)→5
(1,2)→6  becomes  (2,1)→6
(2,0)→7  becomes  (0,0)→7
(2,1)→8  becomes  (1,0)→8
(2,2)→9  becomes  (2,0)→9
```

**Rotated Matrix:**
```
7 4 1
8 5 2
9 6 3
```

---

### Approach 2: Optimal (In-Place - Transpose + Reverse)

#### Explanation
**Key Insight:** Rotate 90° clockwise = Transpose + Reverse Each Row

This two-step process:
1. **Transpose:** Swap `matrix[i][j]` with `matrix[j][i]`
2. **Reverse Each Row:** Reverse elements in each row

#### Why This Works
- **Transpose** flips the matrix along the diagonal
- **Row Reversal** completes the 90° clockwise rotation

**Example:**
```
Original:           After Transpose:    After Row Reverse:
1 2 3               1 4 7               7 4 1
4 5 6      →        2 5 8       →       8 5 2
7 8 9               3 6 9               9 6 3
```

#### Code
```cpp
class Solution {
public:
    void rotateMatrix(vector<vector<int>> &matrix) {
        int n = matrix[0].size();
        
        // Step 1: Transpose the matrix
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for (int k = 0; k < n; k++) {
            reverse(matrix[k].begin(), matrix[k].end());
        }
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N²) - Transpose: O(N²) + Row reversal: O(N²) = O(N²)
- **Space Complexity:** O(1) - Only using `swap` operation, no extra space

#### Dry Run with Visual

**Original Matrix:**
```
1 2 3
4 5 6
7 8 9
```

**After Transpose (swap [i][j] ↔ [j][i]):**
```
Row 0, Col 1: swap(2, 4) → [1 4 3]
                              [2 5 6]
                              [7 8 9]

Row 0, Col 2: swap(3, 7) → [1 4 7]
                              [2 5 6]
                              [3 8 9]

Row 1, Col 2: swap(6, 8) → [1 4 7]
                              [2 5 8]
                              [3 6 9]
```

**Matrix After Transpose:**
```
1 4 7
2 5 8
3 6 9
```

**After Reversing Each Row:**
```
Row 0: reverse [1, 4, 7] → [7, 4, 1]
Row 1: reverse [2, 5, 8] → [8, 5, 2]
Row 2: reverse [3, 6, 9] → [9, 6, 3]
```

**Final Rotated Matrix:**
```
7 4 1
8 5 2
9 6 3
```

#### Key Points
✅ **Optimal solution** - O(1) space complexity  
✅ **In-place rotation** - Modifies original matrix  
✅ **Elegant approach** - Mathematical transformation  

---

## Problem 8: Two Sum

### Problem Statement
Given an array of integers `nums` and an integer `target`, return the **indices** of the two elements that add up to the target.

**Constraints:**
- Exactly one solution exists
- Same element cannot be used twice
- Return indices in increasing order

**Example:**
```
Input: nums = [1, 6, 2, 10, 3], target = 7
Output: [0, 1]
Explanation: nums[0] + nums[1] = 1 + 6 = 7
```

---

### Approach 1: Brute Force (Nested Loop)

#### Explanation
Check all possible pairs and find the pair whose sum equals the target.

**Algorithm:**
1. Use two nested loops to generate all pairs
2. For each pair, check if sum equals target
3. If found, return their indices immediately

#### Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size();
        vector<int> ans;
        
        // Check all possible pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // If pair found, return immediately
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        
        // No pair found
        return {-1, -1};
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N²) - Two nested loops checking all pairs
- **Space Complexity:** O(1) - Only using constant extra space (answer vector excluded)

#### Dry Run with Visual

**Input:** `nums = [1, 6, 2, 10, 3]`, `target = 7`

```
Pair Checks:
(i=0, j=1): 1 + 6 = 7 ✓ FOUND! Return [0, 1]

(Other pairs not checked)
```

---

### Approach 2: Better (Hash Map)

#### Explanation
Use a hash map to store elements we've seen along with their indices. For each element, check if its complement (`target - current`) exists in the map.

**Key Insight:** Instead of checking all pairs, maintain a map of seen elements. When we see a number, we immediately check if its complement exists.

**Algorithm:**
1. Iterate through the array
2. Calculate `complement = target - current_element`
3. Check if complement exists in map
   - If YES: Return indices of complement and current element
   - If NO: Store current element and its index in map
4. If no pair found, return {-1, -1}

#### Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // Map to store (element, index) pairs
        unordered_map<int, int> mpp;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int complement = target - num;
            
            // Check if complement exists in map
            if (mpp.find(complement) != mpp.end()) {
                return {mpp[complement], i};
            }
            
            // Store current number and its index
            mpp[num] = i;
        }
        
        // No pair found
        return {-1, -1};
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N) - Single pass through array, each hash operation is O(1) on average
- **Space Complexity:** O(N) - Hash map stores up to N elements

#### Dry Run with Visual

**Input:** `nums = [1, 6, 2, 10, 3]`, `target = 7`

```
Iteration 1 (i=0, num=1):
  complement = 7 - 1 = 6
  mpp = {} → 6 not found
  mpp = {1: 0}

Iteration 2 (i=1, num=6):
  complement = 7 - 6 = 1
  mpp = {1: 0} → 1 FOUND! 
  Return [mpp[1], 1] = [0, 1] ✓

Result: [0, 1]
```

**Why This Is Better:**
- ✅ Single pass through array
- ✅ Average O(N) time complexity
- ✅ Early termination when pair found

---

### Approach 3: Optimal (Two Pointers - When Sorted)

#### Explanation
If the array needs to be sorted (not a constraint here, but shown for completeness), use two-pointer approach:
1. Create pairs of `(element, original_index)`
2. Sort by element value
3. Use two pointers from start and end
4. If sum = target, return original indices
5. If sum < target, move left pointer right (need larger sum)
6. If sum > target, move right pointer left (need smaller sum)

**Why Sorting Helps:** With sorted data, two pointers can efficiently navigate the search space.

#### Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size();
        vector<int> ans;
        
        // Create pairs of (value, original_index)
        vector<vector<int>> eleIndex;
        for (int i = 0; i < nums.size(); i++) {
            eleIndex.push_back({nums[i], i});
        }
        
        // Sort by value
        sort(eleIndex.begin(), eleIndex.end(), 
             [](const vector<int> &a, const vector<int> &b) {
                 return a[0] < b[0];
             });
        
        // Two pointers approach
        int left = 0, right = n - 1;
        
        while (left < right) {
            int sum = eleIndex[left][0] + eleIndex[right][0];
            
            if (sum == target) {
                ans.push_back(eleIndex[left][1]);
                ans.push_back(eleIndex[right][1]);
                return ans;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return {-1, -1};
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N log N) - Dominated by sorting
- **Space Complexity:** O(N) - For storing (value, index) pairs

#### Dry Run with Visual

**Input:** `nums = [1, 6, 2, 10, 3]`, `target = 7`

```
Step 1: Create pairs with original indices
[(1,0), (6,1), (2,2), (10,3), (3,4)]

Step 2: Sort by value
[(1,0), (2,2), (3,4), (6,1), (10,3)]

Step 3: Two pointers
left=0 (1,0), right=4 (10,3): sum = 1+10 = 11 > 7 → right--
left=0 (1,0), right=3 (6,1): sum = 1+6 = 7 = 7 ✓

Return [0, 1] (original indices)
```

#### Comparison Table

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(N²) | O(1) | Simple but slow |
| Hash Map | **O(N)** | O(N) | **Best for this problem** |
| Two Pointers | O(N log N) | O(N) | Good when array is sorted |

---

## Problem 9: Three Sum

### Problem Statement
Given an integer array `nums`, return all **unique triplets** that sum to **zero**.

**Constraints:**
- Return unique triplets only (no duplicates)
- Element indices must be distinct
- Solution set can be in any order
- One element can be part of multiple triplets

**Example:**
```
Input: nums = [2, -2, 0, 3, -3, 5]
Output: [[-3, -2, 5], [-3, 0, 3], [-2, 0, 2]]
```

---

### Approach 1: Brute Force (3 Nested Loops)

#### Explanation
Check all possible triplets using three nested loops. Use a set to handle duplicates automatically.

**Algorithm:**
1. Generate all possible triplets using three nested loops
2. For each triplet, check if sum equals 0
3. If yes, sort and insert into set (set handles duplicates)
4. Convert set to vector and return

#### Code
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        set<vector<int>> tripletSet;
        int n = nums.size();
        
        // Check all possible triplets
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        // Found a triplet
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        tripletSet.insert(temp);
                    }
                }
            }
        }
        
        // Convert set to vector
        vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());
        return ans;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N³ log K) - Three nested loops: O(N³), sorting each triplet: O(1) (fixed size), inserting into set: O(log K)
  - Where K is the number of unique triplets (at most O(N³))
  - Overall: **O(N³ log N)**
- **Space Complexity:** O(K) - Set stores unique triplets

#### Dry Run with Visual

**Input:** `nums = [2, -2, 0, 3, -3, 5]`

```
Triplet Checks (Only showing relevant ones):
(0,1,2): 2 + (-2) + 0 = 0 ✓ → sorted [0, 2, -2] → add to set
(0,1,3): 2 + (-2) + 3 = 3 ✗
(1,2,3): -2 + 0 + 3 = 1 ✗
(1,2,4): -2 + 0 + (-3) = -5 ✗
(1,3,4): -2 + 3 + (-3) = -2 ✗
(2,3,4): 0 + 3 + (-3) = 0 ✓ → sorted [0, 3, -3] → add to set
(0,4,5): 2 + (-3) + 5 = 4 ✗
(1,4,5): -2 + (-3) + 5 = 0 ✓ → sorted [-2, -3, 5] → add to set
... (continue)

Result Set: {[-3, -2, 5], [-3, 0, 3], [-2, 0, 2]}
```

---

### Approach 2: Better (Outer Loop + Hash Set)

#### Explanation
Optimize by:
1. Using outer loop to fix first element
2. Using hash set for remaining two elements (inner two-pointer logic with set)

**Algorithm:**
1. Iterate through each element as the fixed element
2. For remaining elements, use a hash set approach
3. For each element, check if complement exists in set
4. Use set to track duplicates

#### Code
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        set<vector<int>> tripletSet;
        int n = nums.size();
        
        // Fix first element
        for (int i = 0; i < n; i++) {
            set<int> hashset;
            
            // Find two elements that sum to -nums[i]
            for (int j = i + 1; j < n; j++) {
                // We need: nums[i] + nums[j] + third = 0
                // So: third = -(nums[i] + nums[j])
                int third = -(nums[i] + nums[j]);
                
                if (hashset.find(third) != hashset.end()) {
                    // Found a triplet
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    tripletSet.insert(temp);
                }
                
                hashset.insert(nums[j]);
            }
        }
        
        vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());
        return ans;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N²) - Outer loop: O(N), inner hash set operations: O(N) average
- **Space Complexity:** O(N) - Hash set stores up to N elements

#### Dry Run with Visual

**Input:** `nums = [2, -2, 0, 3, -3, 5]`

```
i=0 (fixed=2):
  j=1: third = -(2 + -2) = 0, hashset = {}, not found, hashset = {-2}
  j=2: third = -(2 + 0) = -2, hashset = {-2}, FOUND! 
       triplet = [2, 0, -2] → sorted = [-2, 0, 2] ✓
  j=3: third = -(2 + 3) = -5, hashset = {-2, 0}, not found
  ...

i=1 (fixed=-2):
  j=2: third = -(-2 + 0) = 2, hashset = {}, not found, hashset = {0}
  j=3: third = -(-2 + 3) = -1, hashset = {0}, not found, hashset = {0, 3}
  j=4: third = -(-2 + -3) = 5, hashset = {0, 3}, not found
  j=5: third = -(-2 + 5) = -3, hashset = {0, 3, -3}, FOUND!
       triplet = [-2, 5, -3] → sorted = [-3, -2, 5] ✓
  ...

i=2 (fixed=0):
  j=3: third = -(0 + 3) = -3, hashset = {}, not found, hashset = {3}
  j=4: third = -(0 + -3) = 3, hashset = {3}, FOUND!
       triplet = [0, -3, 3] → sorted = [-3, 0, 3] ✓
  ...

Result: {[-3, -2, 5], [-3, 0, 3], [-2, 0, 2]}
```

---

### Approach 3: Optimal (Sort + Two Pointers)

#### Explanation
**Most Efficient Approach:**
1. Sort the array first
2. Fix one element using outer loop
3. Use two-pointer technique on remaining elements
4. Skip duplicates explicitly (no set needed)

**Key Advantages:**
- Sorting enables two-pointer optimization
- Explicit duplicate skipping is O(1)
- Set insertion is eliminated (saves log N factor)

#### Code
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int target = 0;
        int n = nums.size();
        vector<vector<int>> ans;
        
        // Fix first element
        for (int i = 0; i < n; i++) {
            // Skip duplicate values for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            // Two pointers for remaining elements
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < target) {
                    j++;
                }
                else if (sum > target) {
                    k--;
                }
                else {
                    // Found a triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    
                    // Skip duplicates for j
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    
                    // Skip duplicates for k
                    while (k > j && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        
        return ans;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N²) - Sorting: O(N log N), outer loop with two pointers: O(N²)
  - Overall: **O(N log N) + O(N²) = O(N²)**
- **Space Complexity:** O(1) - No extra space (excluding answer)

#### Dry Run with Visual

**Input:** `nums = [2, -2, 0, 3, -3, 5]`

```
Step 1: Sort
[-3, -2, 0, 2, 3, 5]

Step 2: Fix elements and use two pointers

i=0 (fixed=-3):
  j=1(-2), k=5(5): sum = -3 + -2 + 5 = 0 ✓ → Add [-3, -2, 5]
  j++, k--
  j=2(0), k=4(3): sum = -3 + 0 + 3 = 0 ✓ → Add [-3, 0, 3]
  j++, k--
  j=3, k=3: Exit (j < k fails)

i=1 (fixed=-2):
  j=2(0), k=5(5): sum = -2 + 0 + 5 = 3 > 0 → k--
  j=2(0), k=4(3): sum = -2 + 0 + 3 = 1 > 0 → k--
  j=2(0), k=3(2): sum = -2 + 0 + 2 = 0 ✓ → Add [-2, 0, 2]
  j++, k--
  j=3, k=2: Exit (j < k fails)

i=2 (fixed=0):
  j=3(2), k=5(5): sum = 0 + 2 + 5 = 7 > 0 → k--
  j=3(2), k=4(3): sum = 0 + 2 + 3 = 5 > 0 → k--
  j=3, k=3: Exit (j < k fails)

Result: [[-3, -2, 5], [-3, 0, 3], [-2, 0, 2]]
```

#### Comparison Table

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(N³ log N) | O(K) | Very slow |
| Hash Set | **O(N²)** | O(N) | Better |
| Two Pointers | **O(N²)** | O(1) | **Best - Optimal** |

---

## Problem 10: Four Sum

### Problem Statement
Given an integer array `nums` and an integer `target`, return all **unique quadruplets** that sum to the target.

**Constraints:**
- All indices must be distinct
- No duplicate quadruplets in result
- One element can be part of multiple quadruplets

**Example:**
```
Input: nums = [1, -2, 3, 5, 7, 9], target = 7
Output: [[-2, 1, 3, 5]]
```

---

### Approach 1: Brute Force (4 Nested Loops)

#### Explanation
Generate all possible quadruplets using four nested loops and check if sum equals target.

**Algorithm:**
1. Use four nested loops to generate all combinations
2. For each quadruplet, check if sum equals target
3. Use set to handle duplicates automatically
4. Convert set to vector and return

#### Code
```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        
        // Check all possible quadruplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        // Calculate sum as long long to avoid overflow
                        long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                        
                        if (sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N⁴ log M) - Four nested loops: O(N⁴), sorting: O(1), set insertion: O(log M)
  - Where M is the number of unique quadruplets
  - Overall: **O(N⁴ log N)**
- **Space Complexity:** O(M) - Set stores unique quadruplets

#### Dry Run with Visual

**Input:** `nums = [1, -2, 3, 5, 7, 9]`, `target = 7`

```
Quadruplet Checks (showing relevant ones):
i=0, j=1, k=2, l=3: 1 + (-2) + 3 + 5 = 7 ✓
  sorted = [1, -2, 3, 5] = [-2, 1, 3, 5] → add to set

i=0, j=1, k=2, l=4: 1 + (-2) + 3 + 7 = 9 ✗
i=0, j=1, k=2, l=5: 1 + (-2) + 3 + 9 = 11 ✗
...

Result: {[-2, 1, 3, 5]}
```

---

### Approach 2: Better (2 Fixed + Hash Set)

#### Explanation
Fix two elements (outer two loops) and use hash set for the inner two elements.

**Algorithm:**
1. Iterate through first element (i)
2. Iterate through second element (j)
3. For remaining elements, maintain hash set
4. For each element, calculate required fourth element
5. Check if fourth element exists in hash set

#### Code
```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        
        // Fix first two elements
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<long long> hashset;
                
                // Find two more elements using hash set
                for (int k = j + 1; k < n; k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    
                    // Check if fourth element exists
                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], 
                                           static_cast<int>(fourth)};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    
                    hashset.insert(nums[k]);
                }
            }
        }
        
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N³) - Two outer loops: O(N²), inner hash set: O(N)
  - Set operations: O(log M), overall dominated by O(N³)
- **Space Complexity:** O(N) - Hash set size

#### Dry Run with Visual

**Input:** `nums = [1, -2, 3, 5, 7, 9]`, `target = 7`

```
i=0 (1), j=1 (-2):
  k=2 (3): sum = 1 + (-2) + 3 = 2, fourth = 7 - 2 = 5
           hashset = {}, not found, hashset = {3}
  k=3 (5): sum = 1 + (-2) + 5 = 4, fourth = 7 - 4 = 3
           hashset = {3}, FOUND! ✓
           quadruplet = [1, -2, 5, 3] → sorted = [-2, 1, 3, 5]
           hashset = {3, 5}
  k=4 (7): sum = 1 + (-2) + 7 = 6, fourth = 7 - 6 = 1
           hashset = {3, 5}, not found, hashset = {3, 5, 7}
  k=5 (9): sum = 1 + (-2) + 9 = 8, fourth = 7 - 8 = -1
           hashset = {3, 5, 7}, not found, hashset = {3, 5, 7, 9}

i=0 (1), j=2 (3):
  ... (no results)

Result: {[-2, 1, 3, 5]}
```

---

### Approach 3: Optimal (Sort + 2 Fixed + Two Pointers)

#### Explanation
**Most Efficient Approach:**
1. Sort the array first
2. Fix two elements using nested loops
3. Use two-pointer technique on remaining elements
4. Skip duplicates explicitly

**Key Insight:** After sorting, we can use two pointers for the last two elements, reducing one dimension of the loop.

#### Code
```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Fix first two elements
        for (int i = 0; i < n; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                // Two pointers for remaining two elements
                int k = j + 1;
                int l = n - 1;
                
                while (k < l) {
                    long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                    
                    if (sum == target) {
                        // Found a quadruplet
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        
                        k++;
                        l--;
                        
                        // Skip duplicates for k
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        
                        // Skip duplicates for l
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }
        
        return ans;
    }
};
```

#### Complexity Analysis
- **Time Complexity:** O(N³) - Sorting: O(N log N), two fixed loops: O(N²), two pointers: O(N)
  - Overall: **O(N log N) + O(N³) = O(N³)**
- **Space Complexity:** O(1) - No extra space (excluding answer)

#### Dry Run with Visual

**Input:** `nums = [1, -2, 3, 5, 7, 9]`, `target = 7`

```
Step 1: Sort
[-2, 1, 3, 5, 7, 9]

Step 2: Fix first two elements and use two pointers

i=0 (fixed=-2):
  j=1 (fixed=1):
    k=2 (3), l=5 (9): sum = -2 + 1 + 3 + 9 = 11 > 7 → l--
    k=2 (3), l=4 (7): sum = -2 + 1 + 3 + 7 = 9 > 7 → l--
    k=2 (3), l=3 (5): sum = -2 + 1 + 3 + 5 = 7 ✓ → Add [-2, 1, 3, 5]
    k++, l--
    k=3, l=2: Exit (k < l fails)

  j=2 (fixed=3):
    k=3 (5), l=5 (9): sum = -2 + 3 + 5 + 9 = 15 > 7 → l--
    ...

Result: [[-2, 1, 3, 5]]
```

**Visual Representation of Two-Pointer Movement:**
```
Array: [-2, 1, 3, 5, 7, 9]
       i=0, j=1

Initial:  k        l
          ↓        ↓
        [-2, 1, 3, 5, 7, 9]  sum = 11 > 7 → l--

        k        l
        ↓        ↓
        [-2, 1, 3, 5, 7, 9]  sum = 9 > 7 → l--

        k        l
        ↓        ↓
        [-2, 1, 3, 5, 7, 9]  sum = 7 = 7 ✓ Found!
```

#### Comparison Table

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(N⁴ log N) | O(M) | Very slow |
| Hash Set | O(N³) | O(N) | Better |
| Two Pointers | **O(N³)** | O(1) | **Best - Optimal** |

---

## 🔑 Key Insights & Patterns

### Pattern Recognition

1. **Rotate Matrix:**
   - Transpose + Row Reverse = 90° Clockwise Rotation
   - In-place with O(1) space

2. **Two Sum:**
   - Hash Map: O(N) optimal for unsorted array
   - Two Pointers: O(N log N) better when sorted

3. **Three Sum:**
   - Extends Two Sum by fixing first element
   - Sort + Two Pointers: O(N²) optimal
   - Duplicate handling is crucial

4. **Four Sum:**
   - Extends Three Sum by fixing first two elements
   - Reduces to Two Sum problem
   - Maintain O(N³) with two pointers

### General Strategies

| Problem Type | Strategy | Complexity |
|-------------|----------|-----------|
| Find N elements with condition | Brute Force | O(N^k) |
| Find N elements (unsorted) | Hash Map | O(N) |
| Find N elements (sorted) | Two Pointers | O(N^(k-1)) |
| Matrix Transformation | Mathematical Pattern | O(N²) |

---

## ⏱️ Complexity Summary

| Problem | Brute Force | Better | Optimal | Space |
|---------|-------------|--------|---------|-------|
| Matrix Rotate | O(N²) | - | **O(N²)** | O(1) |
| Two Sum | O(N²) | **O(N)** | O(N log N) | O(N) |
| Three Sum | O(N³) | O(N²) | **O(N²)** | O(1) |
| Four Sum | O(N⁴) | O(N³) | **O(N³)** | O(1) |

---

## 📝 Practice Tips

1. **Always consider:**
   - Input constraints (array size, value range)
   - Edge cases (empty array, duplicates, negative numbers)
   - Space vs Time trade-offs

2. **Common techniques:**
   - Hash maps for fast lookups
   - Two pointers for sorted arrays
   - Duplicate handling with nested loops or sets

3. **Verification:**
   - Always dry run with examples
   - Check duplicate handling
   - Verify time/space complexity calculations

---

## 📚 References & Further Learning

- Hash Map operations: Average O(1) lookup/insertion
- Sorting algorithms: O(N log N) comparison-based
- Two-pointer technique: Effective for sorted data
- In-place operations: No additional O(N) space needed

---

**Last Updated:** October 2025  
**Total Problems:** 4  
**Total Solutions:** 10 (Brute Force, Better, Optimal approaches)
