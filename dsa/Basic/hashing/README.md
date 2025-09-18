This section is a concise yet comprehensive guide to hashing for DSA: concepts, visuals, trade-offs, and multiple solved problems with code and explanations. It is optimized for quick revision and interview prep.

### Why Hashing?

Hashing lets us map a value/key to an index in constant expected time. It enables O(1) average-time inserts, lookups, and deletions, which is critical for frequency counting, deduplication, set membership, and many more problems.

```
key ──hash(key)──► index ──► store/get value
```

### Core Ideas

- **Hash function**: Maps a key to an integer index. Good hash functions distribute keys uniformly to minimize collisions.
- **Collision**: Two different keys map to the same index. Handled via chaining or open addressing.
- **Load factor (α)**: α = number_of_elements / number_of_buckets. High α increases collisions; resizing helps keep O(1) average time.

### Collision Handling (Visual)

```
Chaining (linked lists at each bucket):

 bucket[0]:  →  10 → 20 → 30
 bucket[1]:  →  11
 bucket[2]:  →  2  → 12

Open Addressing (probing for next free slot):

 h(k) = index; if occupied, try index+1 (linear), or index+1^2, index+2^2 (quadratic), or double hashing.
```

### In C++: `unordered_map` vs `map`

- **unordered_map**: average O(1), not sorted. Backed by a hash table.
- **map**: O(log n), keys sorted. Backed by a balanced BST (red–black tree).

Prefer `unordered_map` when order doesn’t matter and you need speed; use `map` when sorted order or ordered traversal is needed.

---

## Frequency Hashing Patterns

Common use-cases: counting occurrences of integers, characters, strings, or general objects.

#### Fixed-range integer frequency (array hashing)

If you know values are in a bounded non-negative range [0..M], you can use a fixed array of size M+1 for very fast constant-time access.

Example: lowercase letters only

```cpp
int freq[26] = {0};
for (char c : s) freq[c - 'a']++;
```

Constraints matter: If elements may be as large as 1e9 or negative, prefer `unordered_map<int,int>`.

#### General frequency map

```cpp
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> freq;
for (int x : arr) freq[x]++;
```

---

## Problems Implemented in this Folder

We work with the sample array:

```cpp
int arr[] = {1,2,3,4,5,5,6,2,1,3,4,5,6,7,8,9,10};
int n = 17;
```

### 1) Most Occurring Element — Brute Force

Approach: For each unique element, count occurrences by scanning the whole array. Track the max.

- Time: O(n^2)
- Space: O(U) to track visited (with U as the range bound you choose), or O(1) if you re-count without visited and handle duplicates carefully.

```cpp
int mocc_brute(int arr[], int n) {
    int vis[1000000] = {0}; // assumes arr[i] in [0..1e6)
    int max_count = 0, ele = -1;
    for (int i = 0; i < n; i++) {
        if (vis[arr[i]] == 0) {
            vis[arr[i]] = 1;
            int count = 0;
            for (int j = 0; j < n; j++) if (arr[i] == arr[j]) count++;
            if (count > max_count) { max_count = count; ele = arr[i]; }
        }
    }
    return ele;
}
```

Notes:

- The `vis` array bounds must cover possible values of `arr[i]`. If not guaranteed, replace with `unordered_set<int>` or compress coordinates.

### 2) Most Occurring Element — Hashing

Approach: Build a frequency table in one pass, then scan for the maximum.

- Time: O(n + M) where M is hash size (or keys iterated), typically O(n)
- Space: O(M) or O(K) unique values

```cpp
int mocc_hash(int arr[], int n) {
    int hash[1000000] = {0}; // assumes bounded non-negative values
    for (int i = 0; i < n; i++) hash[arr[i]]++;
    int max_count = 0, ele = -1;
    for (int i = 0; i < 1000000; i++) if (hash[i] > max_count) {
        max_count = hash[i]; ele = i;
    }
    return ele;
}
```

`unordered_map` alternative (safer for large/unbounded integers):

```cpp
int mocc_hash_umap(int arr[], int n) {
    unordered_map<int,int> freq;
    for (int i = 0; i < n; i++) freq[arr[i]]++;
    int max_count = 0, ele = -1;
    for (auto &p : freq) if (p.second > max_count) {
        max_count = p.second; ele = p.first;
    }
    return ele;
}
```

### 3) Second Most Occurring Element — Hashing

Approach: Compute all frequencies, then track top-1 and top-2 counts. Finally, return an element whose frequency equals the second maximum.

- Time: O(n + M)
- Space: O(M)

```cpp
int smocc_hash(int arr[], int n) {
    int hash[1000000] = {0};
    for (int i = 0; i < n; i++) hash[arr[i]]++;

    int max_count = 0, second_max_count = 0;
    for (int i = 0; i < 1000000; i++) {
        if (hash[i] > max_count) {
            second_max_count = max_count;
            max_count = hash[i];
        } else if (hash[i] > second_max_count && hash[i] < max_count) {
            second_max_count = hash[i];
        }
    }

    int ele = -1;
    for (int i = 0; i < 1000000; i++) if (hash[i] == second_max_count) { ele = i; break; }
    return ele;
}
```

Edge cases and choices:

- If multiple elements tie for second-most frequency, this returns the first index found. You can adjust to collect all such elements.
- If `second_max_count == 0`, interpret whether you want elements that appear zero times (usually no) or the smallest positive frequency greater than zero. Commonly we restrict to positive counts.

`unordered_map` variant to avoid scanning empty buckets:

```cpp
int smocc_hash_umap(int arr[], int n) {
    unordered_map<int,int> freq;
    for (int i = 0; i < n; i++) freq[arr[i]]++;
    int max_count = 0, second_max_count = 0;
    for (auto &p : freq) {
        if (p.second > max_count) {
            second_max_count = max_count;
            max_count = p.second;
        } else if (p.second > second_max_count && p.second < max_count) {
            second_max_count = p.second;
        }
    }
    for (auto &p : freq) if (p.second == second_max_count) return p.first;
    return -1;
}
```

### 4) Sum of Highest and Lowest Frequency

Approach: Build frequencies, compute max and min frequency, and return their sum.

- Time: O(n + M)
- Space: O(M)

```cpp
int sum_of_highest_and_lowest_frequency(int arr[], int n) {
    int hash[1000000] = {0};
    for (int i = 0; i < n; i++) hash[arr[i]]++;

    int max_count = 0;
    int min_count = INT_MAX;
    for (int i = 0; i < 1000000; i++) if (hash[i] > max_count) max_count = hash[i];
    for (int i = 0; i < 1000000; i++) if (hash[i] > 0) min_count = min(min_count, hash[i]);

    if (min_count == INT_MAX) return 0; // no elements
    return max_count + min_count;
}
```

Important correction vs naive approach: When computing minimum frequency, consider only keys that appear (frequency > 0). Counting zeros would incorrectly make the minimum zero for all absent keys.

`unordered_map` variant:

```cpp
int sum_high_low_umap(int arr[], int n) {
    unordered_map<int,int> freq;
    for (int i = 0; i < n; i++) freq[arr[i]]++;
    if (freq.empty()) return 0;
    int mx = 0, mn = INT_MAX;
    for (auto &p : freq) { mx = max(mx, p.second); mn = min(mn, p.second); }
    return mx + mn;
}
```

---

## End-to-End Example (Matches this folder)

Input array:

```cpp
int arr[] = {1,2,3,4,5,5,6,2,1,3,4,5,6,7,8,9,10};
```

Expected outputs from `hashing.cpp` main:

```
Most occurring (brute):           5
Most occurring (hash):            5
Second most occurring (hash):     1
Sum of highest + lowest freq:     3
```

These match the sample `output.txt`.

---

## Practical Tips and Pitfalls

- Ensure the domain fits your chosen hashing structure:

  - Fixed arrays like `int hash[1000000]` only work when values are guaranteed to be within bounds and non-negative.
  - For large or negative keys, use `unordered_map`.

- When computing minimum frequency, ignore zeros. Only consider elements that actually occur.

- For ties, define expected behavior up-front: return any one, the smallest key, or collect all.

- Avoid gigantic static arrays inside small stack frames for very large bounds. Consider static/global arrays or vectors, or switch to hash maps.

- For character hashing, subtract base: `c - 'a'` for lowercase; for mixed case, map both ranges or normalize.

---

## Complexity Cheatsheet

- Array frequency table (bounded domain):

  - Build: O(n)
  - Query frequency: O(1)
  - Space: O(M)

- `unordered_map` frequency:

  - Build: O(n) average
  - Query: O(1) average
  - Space: O(K) unique keys

- `map` frequency:
  - Build/Query: O(log K)
  - Keys sorted; ordered traversal easy

---

## Quick Revision

- Use array hashing for small, known ranges (e.g., letters, small integers).
- Use `unordered_map` for general integer keys or large/unbounded domains.
- Track first and second maximum frequencies in one pass over the frequency table.
- For minimum frequency, only count keys with freq > 0.
- Be explicit about tie-breaking rules.

---

## References and Further Reading

- C++ reference for `unordered_map` and `map` [cppreference]
- Hash table collision strategies: chaining vs open addressing
- Load factor, rehashing, and performance tuning

You’re now set for quick frequency-based problem solving and confident hashing discussions in interviews.
