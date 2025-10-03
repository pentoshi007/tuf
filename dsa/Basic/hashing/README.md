# Hashing - Complete Guide 🔑This section is a concise yet comprehensive guide to hashing for DSA: concepts, visuals, trade-offs, and multiple solved problems with code and explanations. It is optimized for quick revision and interview prep.



A comprehensive guide to hashing techniques with detailed explanations, complexity analysis, and practical applications for effective problem-solving.### Why Hashing?



## Table of ContentsHashing lets us map a value/key to an index in constant expected time. It enables O(1) average-time inserts, lookups, and deletions, which is critical for frequency counting, deduplication, set membership, and many more problems.

1. [Introduction to Hashing](#introduction-to-hashing)

2. [Basic Frequency Counting](#1-basic-frequency-counting)```

3. [Character Frequency (Lowercase Letters)](#2-character-frequency-lowercase-letters)key ──hash(key)──► index ──► store/get value

4. [Map vs Unordered Map](#3-map-vs-unordered-map)```

5. [Most Occurring Element - Brute Force](#4-most-occurring-element---brute-force)

6. [Most Occurring Element - Using Hash](#5-most-occurring-element---using-hash)### Core Ideas

7. [Second Most Occurring Element](#6-second-most-occurring-element)

8. [Sum of Highest and Lowest Frequency](#7-sum-of-highest-and-lowest-frequency)- **Hash function**: Maps a key to an integer index. Good hash functions distribute keys uniformly to minimize collisions.

- **Collision**: Two different keys map to the same index. Handled via chaining or open addressing.

---- **Load factor (α)**: α = number_of_elements / number_of_buckets. High α increases collisions; resizing helps keep O(1) average time.



## Introduction to Hashing### Collision Handling (Visual)



**Hashing** is a technique to efficiently store and retrieve data using key-value pairs. It's one of the most important concepts in competitive programming and interviews.```

Chaining (linked lists at each bucket):

### What is Hashing?

- **Hash Table**: Data structure that maps keys to values bucket[0]:  →  10 → 20 → 30

- **Hash Function**: Converts keys to array indices bucket[1]:  →  11

- **Direct Addressing**: Use array index as key (when keys are small integers) bucket[2]:  →  2  → 12



### Why Use Hashing?Open Addressing (probing for next free slot):

- ✅ **Fast Lookups**: O(1) average time

- ✅ **Frequency Counting**: Count occurrences efficiently h(k) = index; if occupied, try index+1 (linear), or index+1^2, index+2^2 (quadratic), or double hashing.

- ✅ **Duplicate Detection**: Quick check for duplicates```

- ✅ **Caching**: Store computed results

### In C++: `unordered_map` vs `map`

### When to Use Hashing?

- Counting frequencies- **unordered_map**: average O(1), not sorted. Backed by a hash table.

- Finding duplicates- **map**: O(log n), keys sorted. Backed by a balanced BST (red–black tree).

- Checking if element exists

- Storing key-value relationshipsPrefer `unordered_map` when order doesn’t matter and you need speed; use `map` when sorted order or ordered traversal is needed.

- Optimization (memoization)

---

### Array Size Constraints (Important!)

```cpp## Frequency Hashing Patterns

// OUTSIDE main():

bool hash[10^8];     // ✓ Can declareCommon use-cases: counting occurrences of integers, characters, strings, or general objects.

int hash[10^7];      // ✓ Can declare

#### Fixed-range integer frequency (array hashing)

// INSIDE main():

bool hash[10^7];     // ✓ Can declareIf you know values are in a bounded non-negative range [0..M], you can use a fixed array of size M+1 for very fast constant-time access.

int hash[10^6];      // ✓ Can declare

Example: lowercase letters only

// Larger sizes → Use dynamic allocation or map

``````cpp

int freq[26] = {0};

### Time Complexity Notefor (char c : s) freq[c - 'a']++;

In one second, a computer can perform approximately **10⁸ operations**. Keep this in mind when designing algorithms.```



---Constraints matter: If elements may be as large as 1e9 or negative, prefer `unordered_map<int,int>`.



## 1. Basic Frequency Counting#### General frequency map



### Problem Statement```cpp

Count the frequency of each element in an array using a hash array.#include <bits/stdc++.h>

using namespace std;

### Code

```cppunordered_map<int, int> freq;

#include <bits/stdc++.h>for (int x : arr) freq[x]++;

using namespace std;```



int main()---

{

    int arr[] = {1, 2, 3, 4, 5, 5, 6, 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};## Problems Implemented in this Folder

    int n = 17;

    int hash[11] = {0};  // Array to store frequencies (0-10)We work with the sample array:

    

    // Count frequencies```cpp

    for (int i = 0; i < n; i++)int arr[] = {1,2,3,4,5,5,6,2,1,3,4,5,6,7,8,9,10};

    {int n = 17;

        hash[arr[i]]++;```

    }

    ### 1) Most Occurring Element — Brute Force

    // Print frequencies

    for (int i = 0; i < 11; i++)Approach: For each unique element, count occurrences by scanning the whole array. Track the max.

    {

        cout << i << ":" << hash[i] << ", ";- Time: O(n^2)

    }- Space: O(U) to track visited (with U as the range bound you choose), or O(1) if you re-count without visited and handle duplicates carefully.

    return 0;

}```cpp

```int mocc_brute(int arr[], int n) {

    int vis[1000000] = {0}; // assumes arr[i] in [0..1e6)

### Approach    int max_count = 0, ele = -1;

1. **Create Hash Array**: Size = max possible value + 1    for (int i = 0; i < n; i++) {

2. **Initialize to 0**: All frequencies start at zero        if (vis[arr[i]] == 0) {

3. **Count**: For each element, increment `hash[element]`            vis[arr[i]] = 1;

4. **Query**: Access `hash[i]` to get frequency of i in O(1)            int count = 0;

            for (int j = 0; j < n; j++) if (arr[i] == arr[j]) count++;

### Complexity Analysis            if (count > max_count) { max_count = count; ele = arr[i]; }

- **Time Complexity**: O(n) - Single pass through array        }

- **Space Complexity**: O(max_value) - Hash array size    }

    return ele;

### Dry Run}

``````

arr[] = {1, 2, 3, 4, 5, 5, 6, 2, 1, 3, 4, 5, 6, 7, 8, 9, 10}

hash[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}Notes:

            0  1  2  3  4  5  6  7  8  9  10

- The `vis` array bounds must cover possible values of `arr[i]`. If not guaranteed, replace with `unordered_set<int>` or compress coordinates.

Processing:

arr[0] = 1  → hash[1]++ → {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}### 2) Most Occurring Element — Hashing

arr[1] = 2  → hash[2]++ → {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}

arr[2] = 3  → hash[3]++ → {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}Approach: Build a frequency table in one pass, then scan for the maximum.

arr[3] = 4  → hash[4]++ → {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}

arr[4] = 5  → hash[5]++ → {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}- Time: O(n + M) where M is hash size (or keys iterated), typically O(n)

arr[5] = 5  → hash[5]++ → {0, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0}- Space: O(M) or O(K) unique values

arr[6] = 6  → hash[6]++ → {0, 1, 1, 1, 1, 2, 1, 0, 0, 0, 0}

arr[7] = 2  → hash[2]++ → {0, 1, 2, 1, 1, 2, 1, 0, 0, 0, 0}```cpp

...continuing...int mocc_hash(int arr[], int n) {

    int hash[1000000] = {0}; // assumes bounded non-negative values

Final hash array:    for (int i = 0; i < n; i++) hash[arr[i]]++;

{0, 2, 2, 2, 2, 3, 2, 1, 1, 1, 1}    int max_count = 0, ele = -1;

 0  1  2  3  4  5  6  7  8  9  10    for (int i = 0; i < 1000000; i++) if (hash[i] > max_count) {

        max_count = hash[i]; ele = i;

Output:    }

0:0, 1:2, 2:2, 3:2, 4:2, 5:3, 6:2, 7:1, 8:1, 9:1, 10:1    return ele;

}

Visual:```

Element: 0  1  2  3  4  5  6  7  8  9  10

Freq:    0  2  2  2  2  3  2  1  1  1   1`unordered_map` alternative (safer for large/unbounded integers):

         

5 appears most frequently (3 times)```cpp

```int mocc_hash_umap(int arr[], int n) {

    unordered_map<int,int> freq;

### Advantages    for (int i = 0; i < n; i++) freq[arr[i]]++;

- **O(1) Query Time**: Instant frequency lookup    int max_count = 0, ele = -1;

- **Simple Implementation**: Easy to code    for (auto &p : freq) if (p.second > max_count) {

- **Fast**: Only one pass needed        max_count = p.second; ele = p.first;

    }

### Disadvantages    return ele;

- **Space Consumption**: Need array of size max_value}

- **Limited Range**: Only works for small integer ranges```

- **Sparse Data**: Wastes space if most values unused

### 3) Second Most Occurring Element — Hashing

---

Approach: Compute all frequencies, then track top-1 and top-2 counts. Finally, return an element whose frequency equals the second maximum.

## 2. Character Frequency (Lowercase Letters)

- Time: O(n + M)

### Problem Statement- Space: O(M)

Count frequency of lowercase letters in a string efficiently using space-optimized hashing.

```cpp

### Conceptint smocc_hash(int arr[], int n) {

```cpp    int hash[1000000] = {0};

// For lowercase letters 'a' to 'z'    for (int i = 0; i < n; i++) hash[arr[i]]++;

int hash[26] = {0};

    int max_count = 0, second_max_count = 0;

// Map 'a' to index 0, 'b' to index 1, ..., 'z' to index 25    for (int i = 0; i < 1000000; i++) {

hash[char - 'a']++;        if (hash[i] > max_count) {

            second_max_count = max_count;

// Example:            max_count = hash[i];

// 'a' - 'a' = 0 → hash[0]        } else if (hash[i] > second_max_count && hash[i] < max_count) {

// 'b' - 'a' = 1 → hash[1]            second_max_count = hash[i];

// 'z' - 'a' = 25 → hash[25]        }

```    }



### Code Example    int ele = -1;

```cpp    for (int i = 0; i < 1000000; i++) if (hash[i] == second_max_count) { ele = i; break; }

#include <bits/stdc++.h>    return ele;

using namespace std;}

```

int main()

{Edge cases and choices:

    string s = "helloworld";

    int hash[26] = {0};- If multiple elements tie for second-most frequency, this returns the first index found. You can adjust to collect all such elements.

    - If `second_max_count == 0`, interpret whether you want elements that appear zero times (usually no) or the smallest positive frequency greater than zero. Commonly we restrict to positive counts.

    // Count frequencies

    for (char ch : s)`unordered_map` variant to avoid scanning empty buckets:

    {

        hash[ch - 'a']++;```cpp

    }int smocc_hash_umap(int arr[], int n) {

        unordered_map<int,int> freq;

    // Print frequencies    for (int i = 0; i < n; i++) freq[arr[i]]++;

    for (int i = 0; i < 26; i++)    int max_count = 0, second_max_count = 0;

    {    for (auto &p : freq) {

        if (hash[i] > 0)        if (p.second > max_count) {

        {            second_max_count = max_count;

            cout << (char)('a' + i) << ": " << hash[i] << endl;            max_count = p.second;

        }        } else if (p.second > second_max_count && p.second < max_count) {

    }            second_max_count = p.second;

    return 0;        }

}    }

```    for (auto &p : freq) if (p.second == second_max_count) return p.first;

    return -1;

### Why Subtract 'a'?}

``````

ASCII Values:

'a' = 97### 4) Sum of Highest and Lowest Frequency

'b' = 98

'c' = 99Approach: Build frequencies, compute max and min frequency, and return their sum.

...

'z' = 122- Time: O(n + M)

- Space: O(M)

Mapping to Array:

'a' - 'a' = 97 - 97 = 0  → hash[0]```cpp

'b' - 'a' = 98 - 97 = 1  → hash[1]int sum_of_highest_and_lowest_frequency(int arr[], int n) {

'c' - 'a' = 99 - 97 = 2  → hash[2]    int hash[1000000] = {0};

...    for (int i = 0; i < n; i++) hash[arr[i]]++;

'z' - 'a' = 122 - 97 = 25 → hash[25]

    int max_count = 0;

This saves space! Only need array of size 26 instead of 256 (full ASCII)    int min_count = INT_MAX;

```    for (int i = 0; i < 1000000; i++) if (hash[i] > max_count) max_count = hash[i];

    for (int i = 0; i < 1000000; i++) if (hash[i] > 0) min_count = min(min_count, hash[i]);

### Dry Run (s = "hello")

```    if (min_count == INT_MAX) return 0; // no elements

s = "hello"    return max_count + min_count;

hash[26] = {0, 0, 0, ..., 0}}

```

Processing:

'h' → h - a = 7  → hash[7]++ → hash[7] = 1Important correction vs naive approach: When computing minimum frequency, consider only keys that appear (frequency > 0). Counting zeros would incorrectly make the minimum zero for all absent keys.

'e' → e - a = 4  → hash[4]++ → hash[4] = 1

'l' → l - a = 11 → hash[11]++ → hash[11] = 1`unordered_map` variant:

'l' → l - a = 11 → hash[11]++ → hash[11] = 2

'o' → o - a = 14 → hash[14]++ → hash[14] = 1```cpp

int sum_high_low_umap(int arr[], int n) {

Final:    unordered_map<int,int> freq;

hash[4] = 1  (e)    for (int i = 0; i < n; i++) freq[arr[i]]++;

hash[7] = 1  (h)    if (freq.empty()) return 0;

hash[11] = 2 (l)    int mx = 0, mn = INT_MAX;

hash[14] = 1 (o)    for (auto &p : freq) { mx = max(mx, p.second); mn = min(mn, p.second); }

    return mx + mn;

Output:}

e: 1```

h: 1

l: 2---

o: 1

```## End-to-End Example (Matches this folder)



### For Uppercase LettersInput array:

```cpp

// For uppercase 'A' to 'Z'```cpp

int hash[26] = {0};int arr[] = {1,2,3,4,5,5,6,2,1,3,4,5,6,7,8,9,10};

hash[ch - 'A']++;  // Map 'A' to 0, 'B' to 1, etc.```

```

Expected outputs from `hashing.cpp` main:

### For Both Cases

```cpp```

// For both uppercase and lowercaseMost occurring (brute):           5

int hash[52] = {0};Most occurring (hash):            5

Second most occurring (hash):     1

if (ch >= 'a' && ch <= 'z')Sum of highest + lowest freq:     3

    hash[ch - 'a']++;        // Lowercase: 0-25```

else if (ch >= 'A' && ch <= 'Z')

    hash[ch - 'A' + 26]++;   // Uppercase: 26-51These match the sample `output.txt`.

```

---

### Complexity Analysis

- **Time Complexity**: O(n) - Process each character once## Practical Tips and Pitfalls

- **Space Complexity**: O(1) - Fixed array of size 26

- Ensure the domain fits your chosen hashing structure:

---

  - Fixed arrays like `int hash[1000000]` only work when values are guaranteed to be within bounds and non-negative.

## 3. Map vs Unordered Map  - For large or negative keys, use `unordered_map`.



### Comparison Table- When computing minimum frequency, ignore zeros. Only consider elements that actually occur.



| Feature | `map` | `unordered_map` |- For ties, define expected behavior up-front: return any one, the smallest key, or collect all.

|---------|-------|-----------------|

| **Implementation** | Red-Black Tree | Hash Table |- Avoid gigantic static arrays inside small stack frames for very large bounds. Consider static/global arrays or vectors, or switch to hash maps.

| **Time (Average)** | O(log n) | O(1) |

| **Time (Worst)** | O(log n) | O(n) |- For character hashing, subtract base: `c - 'a'` for lowercase; for mixed case, map both ranges or normalize.

| **Order** | Sorted by key | No order |

| **Iteration** | In sorted order | Random order |---

| **Use Case** | Need sorted keys | Fast lookup |

| **Memory** | Lower overhead | Higher overhead |## Complexity Cheatsheet



### When to Use Map- Array frequency table (bounded domain):

```cpp

#include <map>  - Build: O(n)

using namespace std;  - Query frequency: O(1)

  - Space: O(M)

map<int, int> freq;

- `unordered_map` frequency:

// ✓ When you need sorted keys

// ✓ When order matters  - Build: O(n) average

// ✓ When you need range queries  - Query: O(1) average

// ✓ When worst-case O(log n) is acceptable  - Space: O(K) unique keys



// Example: Print frequencies in sorted order- `map` frequency:

for (auto& p : freq) {  - Build/Query: O(log K)

    cout << p.first << ": " << p.second << endl;  - Keys sorted; ordered traversal easy

}

// Output will be sorted by key---

```

## Quick Revision

### When to Use Unordered Map

```cpp- Use array hashing for small, known ranges (e.g., letters, small integers).

#include <unordered_map>- Use `unordered_map` for general integer keys or large/unbounded domains.

using namespace std;- Track first and second maximum frequencies in one pass over the frequency table.

- For minimum frequency, only count keys with freq > 0.

unordered_map<int, int> freq;- Be explicit about tie-breaking rules.



// ✓ When you need fastest lookup---

// ✓ When order doesn't matter

// ✓ When keys are not sorted## References and Further Reading

// ✓ For frequency counting

- C++ reference for `unordered_map` and `map` [cppreference]

// Example: Fast frequency counting- Hash table collision strategies: chaining vs open addressing

for (int x : arr) {- Load factor, rehashing, and performance tuning

    freq[x]++;

}You’re now set for quick frequency-based problem solving and confident hashing discussions in interviews.

```

### Code Example Comparison
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {5, 2, 8, 2, 5, 1, 8};
    
    // Using map (sorted)
    map<int, int> sorted_freq;
    for (int x : arr) sorted_freq[x]++;
    
    cout << "Map (sorted): ";
    for (auto& p : sorted_freq) {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;
    // Output: 1:1 2:2 5:2 8:2 (sorted by key)
    
    // Using unordered_map (faster)
    unordered_map<int, int> fast_freq;
    for (int x : arr) fast_freq[x]++;
    
    cout << "Unordered Map: ";
    for (auto& p : fast_freq) {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;
    // Output: 8:2 1:1 5:2 2:2 (random order)
    
    return 0;
}
```

### Visual Comparison
```
Array: {5, 2, 8, 2, 5, 1, 8}

Map (Red-Black Tree):
        2:2
       /   \
     1:1   5:2
             \
             8:2
(Maintains sorted structure)

Unordered Map (Hash Table):
Index: [0] [1] [2] [3] [4] ...
       1:1 2:2 5:2 8:2
(Direct hash access, no order)
```

### Performance Benchmark
```
For n = 1,000,000 insertions:

map:
- Insert: O(log n) each → ~20 million ops
- Lookup: O(log n) → ~20 comparisons

unordered_map:
- Insert: O(1) average → ~1 million ops
- Lookup: O(1) average → 1 operation

unordered_map is ~20x faster for this case!
```

---

## 4. Most Occurring Element - Brute Force

### Problem Statement
Find the element that appears most frequently in an array using nested loops.

### Code
```cpp
int mocc_brute(int arr[], int n)
{
    int vis[1000000] = {0};  // Visited array
    int max_count = 0;
    int ele = -1;
    
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        if (vis[arr[i]] == 0)  // If not visited
        {
            vis[arr[i]] = 1;  // Mark as visited
            
            // Count occurrences
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            
            // Update max
            if (count > max_count)
            {
                max_count = count;
                ele = arr[i];
            }
        }
    }
    return ele;
}
```

### Approach
1. Use visited array to avoid recounting
2. For each unvisited element:
   - Count its occurrences in entire array
   - Update max if this count is higher
3. Return element with maximum count

### Complexity Analysis
- **Time Complexity**: O(n²) - Nested loops
- **Space Complexity**: O(max_value) - Visited array

### Dry Run (arr = {1, 2, 3, 2, 1, 1, 4})
```
n = 7
arr[] = {1, 2, 3, 2, 1, 1, 4}
vis[] = {0, 0, 0, 0, 0, ...}
max_count = 0
ele = -1

i = 0: arr[0] = 1
    vis[1] = 0 (not visited)
    vis[1] = 1 (mark visited)
    Count occurrences of 1:
        j=0: arr[0]=1 ✓ count=1
        j=1: arr[1]=2 ✗
        j=2: arr[2]=3 ✗
        j=3: arr[3]=2 ✗
        j=4: arr[4]=1 ✓ count=2
        j=5: arr[5]=1 ✓ count=3
        j=6: arr[6]=4 ✗
    count = 3 > max_count (0)
    max_count = 3, ele = 1

i = 1: arr[1] = 2
    vis[2] = 0 (not visited)
    vis[2] = 1
    Count occurrences of 2:
        count = 2
    2 < 3, no update

i = 2: arr[2] = 3
    Count occurrences of 3:
        count = 1
    1 < 3, no update

i = 3: arr[3] = 2
    vis[2] = 1 (already visited, skip)

i = 4: arr[4] = 1
    vis[1] = 1 (already visited, skip)

...remaining also visited...

Result: ele = 1 (appears 3 times)

Visual:
1  2  3  2  1  1  4
↑        ↑  ↑
1 appears 3 times (most frequent)
```

### Problems with Brute Force
- ❌ **Slow**: O(n²) time complexity
- ❌ **Redundant**: Counts same element multiple times
- ❌ **Space**: Large visited array needed
- ❌ **Inefficient**: Not suitable for large arrays

---

## 5. Most Occurring Element - Using Hash

### Problem Statement
Find the most frequent element efficiently using hashing.

### Code
```cpp
int mocc_hash(int arr[], int n)
{
    int hash[1000000] = {0};
    
    // Count frequencies
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    
    // Find maximum frequency
    int max_count = 0;
    int ele = -1;
    for (int i = 0; i < 1000000; i++)
    {
        if (hash[i] > max_count)
        {
            max_count = hash[i];
            ele = i;
        }
    }
    return ele;
}
```

### Approach
1. **Count Phase**: Build frequency array in O(n)
2. **Find Max Phase**: Scan frequency array once
3. Return element with highest frequency

### Complexity Analysis
- **Time Complexity**: O(n + m) where m = max_value
  - O(n) to count frequencies
  - O(m) to find maximum
- **Space Complexity**: O(m) - Hash array

### Dry Run (arr = {1, 2, 3, 2, 1, 1, 4})
```
arr[] = {1, 2, 3, 2, 1, 1, 4}
n = 7
hash[1000000] = {0, 0, 0, ...}

Phase 1: Count frequencies
    arr[0] = 1 → hash[1]++ → hash[1] = 1
    arr[1] = 2 → hash[2]++ → hash[2] = 1
    arr[2] = 3 → hash[3]++ → hash[3] = 1
    arr[3] = 2 → hash[2]++ → hash[2] = 2
    arr[4] = 1 → hash[1]++ → hash[1] = 2
    arr[5] = 1 → hash[1]++ → hash[1] = 3
    arr[6] = 4 → hash[4]++ → hash[4] = 1

After counting:
hash[1] = 3
hash[2] = 2
hash[3] = 1
hash[4] = 1
(rest are 0)

Phase 2: Find maximum
    i=0: hash[0]=0, max_count=0, no update
    i=1: hash[1]=3 > 0, max_count=3, ele=1
    i=2: hash[2]=2 < 3, no update
    i=3: hash[3]=1 < 3, no update
    i=4: hash[4]=1 < 3, no update
    ...rest are 0...

Result: ele = 1, max_count = 3

Visual:
Element:  1  2  3  4
Freq:     3  2  1  1
          ↑
      Maximum (3)
```

### Comparison with Brute Force
```
For n = 1000 elements:

Brute Force:
- Time: O(n²) = 1,000,000 operations
- Space: O(max_value) visited array

Hash Method:
- Time: O(n) = 1000 operations
- Space: O(max_value) hash array

Hash is 1000x faster! 🚀
```

### Using Map (For Large or Unknown Range)
```cpp
int mocc_map(vector<int>& arr) {
    unordered_map<int, int> freq;
    
    // Count frequencies
    for (int x : arr) {
        freq[x]++;
    }
    
    // Find maximum
    int max_count = 0;
    int element = -1;
    for (auto& p : freq) {
        if (p.second > max_count) {
            max_count = p.second;
            element = p.first;
        }
    }
    return element;
}
// Works for any range of values!
```

---

## 6. Second Most Occurring Element

### Problem Statement
Find the element with second highest frequency in an array.

### Code
```cpp
int smocc_hash(int arr[], int n)
{
    int hash[1000000] = {0};
    
    // Count frequencies
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    
    // Find first and second maximum frequencies
    int max_count = 0;
    int second_max_count = 0;
    
    for (int i = 0; i < 1000000; i++)
    {
        if (hash[i] > max_count)
        {
            second_max_count = max_count;  // Old max becomes second
            max_count = hash[i];            // New max
        }
        else if (hash[i] > second_max_count && hash[i] < max_count)
        {
            second_max_count = hash[i];    // Update second max
        }
    }
    
    // Find element with second max frequency
    int ele = -1;
    for (int i = 0; i < 1000000; i++)
    {
        if (hash[i] == second_max_count)
        {
            ele = i;
            break;
        }
    }
    return ele;
}
```

### Approach
1. Count frequencies using hash array
2. Find both max and second_max frequencies
3. When finding new max:
   - Old max becomes second_max
   - Update max
4. When finding value between max and second_max:
   - Update second_max
5. Return element with second_max frequency

### Complexity Analysis
- **Time Complexity**: O(n + m) - Count + 2 scans
- **Space Complexity**: O(m) - Hash array

### Dry Run (arr = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4})
```
arr[] = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4}
n = 10

After counting:
hash[1] = 3
hash[2] = 2
hash[3] = 1
hash[4] = 4

Phase 1: Find max and second_max frequencies
max_count = 0
second_max_count = 0

i = 1: hash[1] = 3
    3 > 0 (max_count)
    second_max_count = 0 (old max)
    max_count = 3

i = 2: hash[2] = 2
    2 < 3 (not new max)
    2 > 0 (second_max) and 2 < 3 (max)
    second_max_count = 2

i = 3: hash[3] = 1
    1 < 3 (not new max)
    1 < 2 (not new second_max)
    No update

i = 4: hash[4] = 4
    4 > 3 (new max!)
    second_max_count = 3 (old max)
    max_count = 4

Final:
max_count = 4 (element 4 appears 4 times)
second_max_count = 3 (element 1 appears 3 times)

Phase 2: Find element with second_max frequency
Looking for frequency = 3
i = 1: hash[1] = 3 ✓
ele = 1

Result: 1 (second most frequent element)

Visual:
Element:  1  2  3  4
Freq:     3  2  1  4
          ↑        ↑
       2nd max   max
```

### Edge Cases
```cpp
// All same frequency
arr = {1, 2, 3}
Result: second_max_count = 0 (no second max)

// Only one unique element
arr = {1, 1, 1}
Result: -1 (no second max)

// Two elements with same max frequency
arr = {1, 1, 2, 2}
max_count = 2 (both have freq 2)
second_max_count = 0 (no distinct second)
```

---

## 7. Sum of Highest and Lowest Frequency

### Problem Statement
Find the sum of the highest and lowest non-zero frequencies in an array.

### Code
```cpp
int sum_of_highest_and_lowest_frequency(int arr[], int n)
{
    int hash[1000000] = {0};
    
    // Count frequencies
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    
    // Find maximum frequency
    int max_count = 0;
    for (int i = 0; i < 1000000; i++)
    {
        if (hash[i] > max_count)
        {
            max_count = hash[i];
        }
    }
    
    // Find minimum non-zero frequency
    int min_count = 1000000;
    for (int i = 0; i < 1000000; i++)
    {
        if (hash[i] > 0 && hash[i] < min_count)
        {
            min_count = hash[i];
        }
    }
    
    return max_count + min_count;
}
```

### Approach
1. Count frequencies
2. Find maximum frequency (scan all)
3. Find minimum **non-zero** frequency
4. Return sum

### Important Note
**Must check `hash[i] > 0`** when finding minimum, otherwise minimum would always be 0!

### Complexity Analysis
- **Time Complexity**: O(n + 2m) = O(n + m)
  - O(n) for counting
  - O(m) for finding max
  - O(m) for finding min
- **Space Complexity**: O(m) - Hash array

### Dry Run (arr = {1, 1, 1, 2, 2, 3})
```
arr[] = {1, 1, 1, 2, 2, 3}
n = 6

After counting:
hash[1] = 3
hash[2] = 2
hash[3] = 1
(rest are 0)

Phase 1: Find max frequency
max_count = 0
i=1: hash[1]=3 > 0, max_count = 3
i=2: hash[2]=2 < 3, no update
i=3: hash[3]=1 < 3, no update
max_count = 3

Phase 2: Find min non-zero frequency
min_count = 1000000 (initial large value)
i=1: hash[1]=3 > 0 and 3 < 1000000, min_count = 3
i=2: hash[2]=2 > 0 and 2 < 3, min_count = 2
i=3: hash[3]=1 > 0 and 1 < 2, min_count = 1
min_count = 1

Result: max_count + min_count = 3 + 1 = 4

Visual:
Element:  1  2  3
Freq:     3  2  1
          ↑     ↑
         max   min
         
Sum = 3 + 1 = 4
```

### Dry Run (arr = {5, 5, 5, 5, 2, 1, 3, 4, 5, 6, 2, 1, 3, 4, 5, 6, 7, 8, 9, 10})
```
After counting:
hash[1] = 2
hash[2] = 2
hash[3] = 2
hash[4] = 2
hash[5] = 6
hash[6] = 2
hash[7] = 1
hash[8] = 1
hash[9] = 1
hash[10] = 1

Find max: 6 (element 5 appears 6 times)
Find min: 1 (elements 7,8,9,10 appear 1 time each)

Result: 6 + 1 = 7
```

### Why Check `hash[i] > 0`?
```
Without check:
for (int i = 0; i < 1000000; i++)
{
    if (hash[i] < min_count)  // ❌ Wrong!
        min_count = hash[i];
}
// min_count would always be 0 (unused indices)

With check:
for (int i = 0; i < 1000000; i++)
{
    if (hash[i] > 0 && hash[i] < min_count)  // ✓ Correct
        min_count = hash[i];
}
// Only considers non-zero frequencies
```

---

## Hashing Patterns Summary

### Pattern 1: Direct Addressing (Array as Hash)
```cpp
int hash[MAX_VALUE] = {0};
hash[element]++;
// ✓ Fast: O(1) access
// ✗ Limited: Only for small integer ranges
```

### Pattern 2: Character Mapping
```cpp
int hash[26] = {0};
hash[ch - 'a']++;
// ✓ Space efficient: Only 26 elements
// ✓ Works for: Lowercase letters
```

### Pattern 3: Map/Unordered Map
```cpp
unordered_map<int, int> freq;
freq[element]++;
// ✓ Works for: Any range, negative numbers
// ✓ Flexible: Dynamic size
// ✗ Slower: O(1) average, O(n) worst case
```

---

## Choosing the Right Approach

### Decision Tree
```
Is the range of values small (< 10^6)?
├─ YES → Use array hashing
│         int hash[MAX] = {0};
│
└─ NO → Are values integers?
         ├─ YES → Use unordered_map
         │         unordered_map<int, int>
         │
         └─ NO → Use map/unordered_map
                   map<string, int>
```

### Array Hashing (Best When)
- ✓ Values are non-negative integers
- ✓ Range is small (< 10⁶)
- ✓ Need fastest possible access
- ✓ Memory is available

### Map (Best When)
- ✓ Need sorted output
- ✓ Range operations needed
- ✓ Guaranteed O(log n) acceptable

### Unordered Map (Best When)
- ✓ Large or unknown value range
- ✓ Negative numbers
- ✓ Non-integer keys (strings, pairs)
- ✓ Don't need sorted output

---

## Common Hashing Problems

### 1. Frequency Counting
```cpp
// Count character frequencies
unordered_map<char, int> freq;
for (char ch : s) freq[ch]++;
```

### 2. Find Duplicates
```cpp
// Check if array has duplicates
unordered_set<int> seen;
for (int x : arr) {
    if (seen.count(x)) return true;  // Duplicate found
    seen.insert(x);
}
return false;
```

### 3. Two Sum
```cpp
// Find pair with sum = target
unordered_map<int, int> seen;
for (int i = 0; i < n; i++) {
    int complement = target - arr[i];
    if (seen.count(complement)) {
        return {seen[complement], i};
    }
    seen[arr[i]] = i;
}
```

### 4. Anagram Check
```cpp
// Check if two strings are anagrams
int hash[26] = {0};
for (char ch : s1) hash[ch - 'a']++;
for (char ch : s2) hash[ch - 'a']--;
for (int i = 0; i < 26; i++)
    if (hash[i] != 0) return false;
return true;
```

### 5. First Non-Repeating Character
```cpp
unordered_map<char, int> freq;
for (char ch : s) freq[ch]++;
for (char ch : s)
    if (freq[ch] == 1) return ch;
return '\0';
```

---

## Optimization Techniques

### 1. Use Array When Possible
```cpp
// Slower (for small range)
unordered_map<int, int> freq;

// Faster (for small range)
int freq[1001] = {0};  // If values are 0-1000
```

### 2. Reserve Space for Maps
```cpp
unordered_map<int, int> freq;
freq.reserve(1000);  // Avoid rehashing
```

### 3. Use References in Loops
```cpp
// Slower (copies pair)
for (auto p : map) { ... }

// Faster (uses reference)
for (auto& p : map) { ... }
```

### 4. Early Exit
```cpp
// Find first element with frequency > k
for (auto& p : freq) {
    if (p.second > k) {
        return p.first;  // Exit early
    }
}
```

---

## Common Pitfalls

### 1. Not Checking for Zero
```cpp
// ❌ Wrong: includes zeros
int min_freq = INT_MAX;
for (int i = 0; i < MAX; i++)
    if (hash[i] < min_freq) min_freq = hash[i];

// ✓ Correct: only non-zero
int min_freq = INT_MAX;
for (int i = 0; i < MAX; i++)
    if (hash[i] > 0 && hash[i] < min_freq)
        min_freq = hash[i];
```

### 2. Array Size Too Large
```cpp
// ❌ May cause stack overflow
int hash[10000000] = {0};  // 40 MB on stack

// ✓ Better
vector<int> hash(10000000, 0);  // Heap allocation
```

### 3. Not Initializing
```cpp
// ❌ Undefined values
int hash[100];

// ✓ Initialized to zero
int hash[100] = {0};
```

### 4. Using Map When unordered_map Sufficient
```cpp
// ❌ Slower if order not needed
map<int, int> freq;

// ✓ Faster
unordered_map<int, int> freq;
```

---

## Practice Problems

### Easy
1. Find frequency of each element
2. Check if element exists
3. Find first non-repeating element
4. Count distinct elements

### Medium
5. Two sum problem
6. Subarray with given sum
7. Longest substring without repeating characters
8. Group anagrams

### Hard
9. Longest consecutive sequence
10. Count of subarrays with k different integers

---

## Time Complexity Summary

| Operation | Array Hash | Map | Unordered Map |
|-----------|-----------|-----|---------------|
| Insert | O(1) | O(log n) | O(1) avg |
| Search | O(1) | O(log n) | O(1) avg |
| Delete | O(1) | O(log n) | O(1) avg |
| Iteration | O(m) | O(n) | O(n) |
| Space | O(m) | O(n) | O(n) |

m = max value, n = number of elements

---

## Conclusion

Hashing is a fundamental technique for efficient problem-solving:

**Key Takeaways:**
- Use **array hashing** for small integer ranges
- Use **unordered_map** for general cases
- Use **map** when order matters
- Always consider space constraints
- Check for edge cases (zeros, negatives)

**When to Use Hashing:**
- Frequency counting
- Duplicate detection
- Fast lookups
- Caching results

**Master These Patterns:**
- Direct addressing
- Character mapping
- Map-based solutions
- Frequency analysis

Happy Coding! 🔑

---

**File Location**: `/dsa/Basic/hashing/hashing.cpp`

**Last Updated**: October 3, 2025
