# String Manipulation - Complete Guide 📝

A comprehensive collection of fundamental string problems with detailed explanations, complexity analysis, and visual demonstrations for effective revision.

## Table of Contents

1. [Introduction to Strings](#introduction-to-strings)
2. [Reverse a String](#1-reverse-a-string)
3. [Check if String is Palindrome](#2-check-if-string-is-palindrome)
4. [Largest Odd Number in String](#3-largest-odd-number-in-string)
5. [Longest Common Prefix](#4-longest-common-prefix)
6. [Isomorphic Strings](#5-isomorphic-strings)
7. [Rotate String](#6-rotate-string)
8. [Valid Anagram](#7-valid-anagram)
9. [Sort Characters by Frequency](#8-sort-characters-by-frequency)

---

## Introduction to Strings

**Strings** are sequences of characters used to represent text. In C++, strings are mutable and provide various built-in functions for manipulation.

### Common String Operations:

- **Indexing**: Access characters using `str[i]`
- **Length**: Get size using `str.size()` or `str.length()`
- **Concatenation**: Combine strings using `+`
- **Substring**: Extract portion using `str.substr(start, length)`
- **Comparison**: Compare strings lexicographically

### Key Concepts:

1. **Two-Pointer Technique**: Use two indices to traverse string
2. **Frequency Counting**: Use arrays/maps to count character occurrences
3. **String Hashing**: Map characters to indices for quick access
4. **In-place Modification**: Modify string without extra space

---

## 1. Reverse a String

### Problem Statement

Reverse a given string using STL functions.

### Code

```cpp
string reverseString(string str)
{
    reverse(str.begin(), str.end());
    return str;
}
```

### Approach

1. Use STL `reverse()` function
2. Pass begin and end iterators
3. Returns reversed string

### Complexity Analysis

- **Time Complexity**: O(n) - Where n is the length of string
- **Space Complexity**: O(1) - In-place reversal (though string is passed by value here)

### Dry Run (str = "hello")

```
Initial: "hello"
         ↓
Apply reverse(begin, end)
         ↓
Result: "olleh"

Character-by-character swap:
Step 1: Swap str[0] and str[4]  → "oellh"
Step 2: Swap str[1] and str[3]  → "olleh"
Step 3: Middle character stays  → "olleh"

Visual:
h  e  l  l  o
↓           ↓
└─── SWAP ──┘
o  e  l  l  h
   ↓     ↓
   └SWAP─┘
o  l  l  e  h
      ↓
   (center)
```

### Alternative Approaches

```cpp
// Manual reversal using two pointers
string reverseString(string str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        swap(str[left++], str[right--]);
    }
    return str;
}

// Using recursion
void reverseHelper(string& str, int left, int right) {
    if (left >= right) return;
    swap(str[left], str[right]);
    reverseHelper(str, left + 1, right - 1);
}
```

---

## 2. Check if String is Palindrome

### Problem Statement

Determine if a string reads the same forwards and backwards using two-pointer technique.

### Code

```cpp
bool isPalindrome(string str)
{
    int i = 0;
    int j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
```

### Approach

1. Use two pointers: `i` at start, `j` at end
2. Compare characters at both pointers
3. If any pair doesn't match → not palindrome
4. Move pointers towards center: `i++`, `j--`
5. If all pairs match → palindrome

### Complexity Analysis

- **Time Complexity**: O(n) - Check n/2 pairs of characters
- **Space Complexity**: O(1) - Only using two pointer variables

### Dry Run (str = "racecar")

```
str = "racecar"
       0123456

Iteration 1: i=0, j=6
             str[0]='r', str[6]='r' ✓ Match
             i++, j-- → i=1, j=5

Iteration 2: i=1, j=5
             str[1]='a', str[5]='a' ✓ Match
             i++, j-- → i=2, j=4

Iteration 3: i=2, j=4
             str[2]='c', str[4]='c' ✓ Match
             i++, j-- → i=3, j=3

Iteration 4: i=3, j=3
             i >= j → Stop
             Return TRUE (Palindrome!)

Visual:
r  a  c  e  c  a  r
↑                 ↑
i=0              j=6
✓ Match
   ↓           ↓
   i=1        j=5
   ✓ Match
      ↓     ↓
      i=2  j=4
      ✓ Match
         ↓
       i=j=3
```

### Example of Non-Palindrome (str = "hello")

```
Iteration 1: i=0, j=4
             str[0]='h', str[4]='o' ✗ Don't Match
             Return FALSE immediately

h  e  l  l  o
↑           ↑
h ≠ o → NOT PALINDROME
```

### Edge Cases

```cpp
// Empty string: palindrome
isPalindrome("") → true

// Single character: palindrome
isPalindrome("a") → true

// Two same characters: palindrome
isPalindrome("aa") → true

// Two different characters: not palindrome
isPalindrome("ab") → false
```

---

## 3. Largest Odd Number in String

### Problem Statement

Find the largest odd number that can be formed from a string of digits. Return the number as a string without leading zeros. If no odd number exists, return empty string.

### Code - Approach 1

```cpp
string largestOddNumber(string str)
{
    int n = str.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] % 2 != 0)  // Found odd digit
        {
            return str.substr(0, i + 1).erase(0, str.find_first_not_of('0'));
        }
    }
    return "";  // No odd number found
}
```

### Code - Approach 2 (Cleaner)

```cpp
string largeOddNum(string &s)
{
    int refs = 0;  // Start index
    int refe = -1; // End index

    // Find rightmost odd digit
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 != 0)
        {
            refe = i;
            break;
        }
    }

    // Remove leading zeros
    int j = 0;
    while (refs <= refe && s[j] == '0')
    {
        refs++;
        j++;
    }

    return s.substr(refs, refe - refs + 1);
}
```

### Approach

1. **Key Insight**: For largest odd number, we need rightmost odd digit
2. Traverse string from right to left
3. Find first (rightmost) odd digit
4. Take substring from start to that odd digit (inclusive)
5. Remove leading zeros
6. If no odd digit found, return empty string

### Why This Works?

- A number is odd if its last digit is odd
- To maximize the number, keep as many leftmost digits as possible
- Rightmost odd digit gives us the largest odd substring

### Complexity Analysis

- **Time Complexity**: O(n) - Single traversal from right to left
- **Space Complexity**: O(n) - For creating substring (can be O(1) with indices)

### Dry Run (str = "52367")

```
str = "52367"
       01234

Step 1: Start from right, find odd digit
        i=4: str[4]='7' → 7 % 2 = 1 (ODD!)

Step 2: Take substring from 0 to 4 (inclusive)
        substr(0, 5) = "52367"

Step 3: Check for leading zeros
        No leading zeros

Result: "52367"

Visual:
5  2  3  6  7
            ↑
         (odd digit)
Take everything up to here
         ↓
     "52367"
```

### Dry Run (str = "52468")

```
str = "52468"
       01234

Step 1: Start from right
        i=4: str[4]='8' → 8 % 2 = 0 (EVEN)
        i=3: str[3]='6' → 6 % 2 = 0 (EVEN)
        i=2: str[2]='4' → 4 % 2 = 0 (EVEN)
        i=1: str[1]='2' → 2 % 2 = 0 (EVEN)
        i=0: str[0]='5' → 5 % 2 = 1 (ODD!)

Step 2: Take substring from 0 to 0 (inclusive)
        substr(0, 1) = "5"

Result: "5"

Visual:
5  2  4  6  8
↑  x  x  x  x
(odd)  (all even)
Take only this
     ↓
    "5"
```

### Dry Run (str = "00352467")

```
str = "00352467"
       01234567

Step 1: Find rightmost odd digit
        i=7: str[7]='7' → 7 % 2 = 1 (ODD!)

Step 2: Take substring from 0 to 7
        substr(0, 8) = "00352467"

Step 3: Remove leading zeros
        Find first non-zero: index 2 ('3')
        refs = 2
        substr(2, 6) = "352467"

Result: "352467"

Visual:
0  0  3  5  2  4  6  7
↑  ↑                 ↑
(leading zeros)   (odd)
Remove these, take rest
         ↓
    "352467"
```

### Dry Run (str = "2468")

```
str = "2468"

Step 1: Find odd digit
        i=3: '8' → EVEN
        i=2: '6' → EVEN
        i=1: '4' → EVEN
        i=0: '2' → EVEN

No odd digit found!
Result: "" (empty string)
```

### Edge Cases

```cpp
largestOddNumber("35427")  → "35427" (already odd)
largestOddNumber("2468")   → ""      (no odd digit)
largestOddNumber("000123") → "123"   (leading zeros removed)
largestOddNumber("52")     → "5"     (rightmost odd is best)
largestOddNumber("1")      → "1"     (single odd digit)
largestOddNumber("0")      → ""      (zero is even)
```

---

## 4. Longest Common Prefix

### Problem Statement

Find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string.

### Code

```cpp
string longestCommonPrefix(vector<string> &str)
{
    // Edge case: empty vector
    if (str.empty())
        return "";

    // Sort to get lexicographically smallest and largest strings
    sort(str.begin(), str.end());

    // First string (smallest)
    string first = str[0];
    // Last string (largest)
    string last = str[str.size() - 1];

    // Compare characters of first and last strings
    int minLength = min(first.size(), last.size());
    string ans = "";

    for (int i = 0; i < minLength; i++)
    {
        if (first[i] != last[i])
        {
            return ans;  // Characters don't match
        }
        ans += first[i];  // Add matching character
    }

    return ans;  // Return longest common prefix
}
```

### Approach

1. **Key Insight**: After sorting, if there's a common prefix:
   - First string has it (lexicographically smallest)
   - Last string has it (lexicographically largest)
   - All middle strings will also have it!
2. **Algorithm**:
   - Sort the vector of strings
   - Compare only first and last strings
   - Find common prefix between them
   - This will be common to all strings

### Why Sorting Works?

- Sorting brings lexicographically similar strings together
- If first and last have common prefix, all middle strings must have it
- Example: ["flower", "flow", "flight"] sorts to ["flight", "flow", "flower"]
  - Common between "flight" and "flower" = "fl"
  - Middle string "flow" also has "fl"

### Complexity Analysis

- **Time Complexity**: O(n log n + m)
  - O(n log n) for sorting n strings
  - O(m) for comparing first and last string (m = length of shorter string)
- **Space Complexity**: O(1) - Excluding output string (sorting is in-place)

### Dry Run (str = ["flower", "flow", "flight"])

```
Step 1: Original array
        ["flower", "flow", "flight"]

Step 2: Sort lexicographically
        ["flight", "flow", "flower"]
         ↑                      ↑
        first                 last

Step 3: Compare first and last
        first = "flight"
        last  = "flower"
        minLength = 6

        i=0: first[0]='f', last[0]='f' ✓ Match → ans="f"
        i=1: first[1]='l', last[1]='l' ✓ Match → ans="fl"
        i=2: first[2]='i', last[2]='o' ✗ Mismatch → return "fl"

Result: "fl"

Visual:
flight
flow
flower
↑↑
fl (common prefix)
```

### Dry Run (str = ["dog", "racecar", "car"])

```
Step 1: Original array
        ["dog", "racecar", "car"]

Step 2: Sort lexicographically
        ["car", "dog", "racecar"]
         ↑               ↑
        first          last

Step 3: Compare first and last
        first = "car"
        last  = "racecar"

        i=0: first[0]='c', last[0]='r' ✗ Mismatch
             return ""

Result: "" (no common prefix)

Visual:
car
dog
racecar
↑
No common starting character
```

### Dry Run (str = ["apple", "app", "application"])

```
Step 1: Sort
        ["app", "apple", "application"]
         ↑                    ↑
        first               last

Step 2: Compare "app" and "application"
        i=0: 'a'='a' ✓ → ans="a"
        i=1: 'p'='p' ✓ → ans="ap"
        i=2: 'p'='p' ✓ → ans="app"
        i=3: Out of bounds for "app"
             return "app"

Result: "app"

Visual:
app
apple
application
↑↑↑
app (common prefix)
```

### Alternative Approach (Without Sorting)

```cpp
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}
// Time: O(n * m) where n = number of strings, m = average length
```

### Edge Cases

```cpp
longestCommonPrefix([])                    → ""
longestCommonPrefix(["a"])                 → "a"
longestCommonPrefix(["abc", "abc"])        → "abc"
longestCommonPrefix(["", "abc"])           → ""
longestCommonPrefix(["abc", "xyz"])        → ""
```

---

## 5. Isomorphic Strings

### Problem Statement

Two strings `s` and `t` are isomorphic if characters in `s` can be replaced to get `t`. All occurrences of a character must be replaced with another character while preserving the order. No two characters may map to the same character, but a character may map to itself.

### Code

```cpp
bool isomorphicString(string s, string t)
{
    int m1[256] = {0}, m2[256] = {0};  // ASCII mapping arrays
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (m1[s[i]] != m2[t[i]])
        {
            return false;  // Mapping conflict
        }
        m1[s[i]] = i + 1;  // Store position + 1
        m2[t[i]] = i + 1;
    }
    return true;
}
```

### Approach

1. **Two Mapping Arrays**: Track when each character was last seen
   - `m1[256]`: Maps characters from string `s`
   - `m2[256]`: Maps characters from string `t`
2. **Position Tracking**: Store `i + 1` (not just `i`) to differentiate from initial 0
3. **Validation**: At each position:
   - Both mappings should have same value
   - If different → character mapping conflict → not isomorphic
4. **Why This Works**:
   - If `s[i]` maps to `t[i]`, they should appear at same positions
   - Arrays track last occurrence position
   - Mismatch means one-to-one mapping is violated

### Complexity Analysis

- **Time Complexity**: O(n) - Single pass through strings
- **Space Complexity**: O(1) - Fixed size arrays (256 for ASCII)

### Dry Run (s = "egg", t = "add")

```
s = "egg"
t = "add"

Initial: m1[256] = {0}, m2[256] = {0}

Iteration 1: i=0
    s[0]='e', t[0]='a'
    m1['e']=0, m2['a']=0 → Same ✓
    m1['e']=1, m2['a']=1

Iteration 2: i=1
    s[1]='g', t[1]='d'
    m1['g']=0, m2['d']=0 → Same ✓
    m1['g']=2, m2['d']=2

Iteration 3: i=2
    s[2]='g', t[2]='d'
    m1['g']=2, m2['d']=2 → Same ✓
    m1['g']=3, m2['d']=3

Result: TRUE (Isomorphic)

Mapping:
e → a
g → d

Visual:
e  g  g
↓  ↓  ↓
a  d  d

Position tracking:
     m1    m2
i=0: e→1  a→1 ✓
i=1: g→2  d→2 ✓
i=2: g→3  d→3 ✓ (g was at 2, d was at 2, consistent!)
```

### Dry Run (s = "foo", t = "bar")

```
s = "foo"
t = "bar"

Iteration 1: i=0
    s[0]='f', t[0]='b'
    m1['f']=0, m2['b']=0 → Same ✓
    m1['f']=1, m2['b']=1

Iteration 2: i=1
    s[1]='o', t[1]='a'
    m1['o']=0, m2['a']=0 → Same ✓
    m1['o']=2, m2['a']=2

Iteration 3: i=2
    s[2]='o', t[2]='r'
    m1['o']=2, m2['r']=0 → Different! ✗

    'o' was last seen at position 1 (value=2)
    'r' was never seen (value=0)

    Conflict: 'o' should map to 'a', but trying to map to 'r'

Result: FALSE (Not Isomorphic)

Visual:
f  o  o
↓  ↓  ↓
b  a  r
      ✗
'o' can't map to both 'a' and 'r'
```

### Dry Run (s = "paper", t = "title")

```
s = "paper"
t = "title"

i=0: p→t  m1['p']=1, m2['t']=1 ✓
i=1: a→i  m1['a']=2, m2['i']=2 ✓
i=2: p→t  m1['p']=1, m2['t']=1
          Wait! m1['p'] was 1, m2['t'] was 1 → Same ✓
          Update: m1['p']=3, m2['t']=3 ✓
i=3: e→l  m1['e']=4, m2['l']=4 ✓
i=4: r→e  m1['r']=5, m2['e']=5 ✓

Result: TRUE

Mapping:
p → t
a → i
e → l
r → e

Visual:
p  a  p  e  r
↓  ↓  ↓  ↓  ↓
t  i  t  l  e
```

### Why Use i+1 Instead of i?

```
If we used just i:
At i=0, both arrays would have value 0 (not updated yet)
Can't distinguish between "not seen" and "seen at position 0"

Using i+1:
- 0 means "not seen"
- 1 means "seen at position 0"
- 2 means "seen at position 1"
- etc.
```

### Edge Cases

```cpp
isomorphicString("", "")         → true  (empty strings)
isomorphicString("a", "a")       → true  (same character)
isomorphicString("ab", "aa")     → false (two chars map to one)
isomorphicString("ab", "ca")     → true  (one-to-one mapping)
isomorphicString("badc", "baba") → false (mapping conflict)
```

---

## 6. Rotate String

### Problem Statement

Given two strings `s` and `goal`, return true if and only if `s` can become `goal` after some number of shifts. A shift consists of moving the leftmost character to the rightmost position.

Example: "abcde" → "bcdea" (one shift)

### Code

```cpp
bool rotateString(string &s, string &goal)
{
    // Different lengths can't be rotations
    if (s.length() != goal.length())
        return false;

    // Concatenate s with itself
    s = s + s;

    // Check if goal is a substring of s+s
    int res = s.find(goal);
    if (res != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}
```

### Approach

1. **Key Insight**: All rotations of a string appear in `s + s`
2. **Algorithm**:

   - Check if lengths are equal (necessary condition)
   - Concatenate `s` with itself: `s + s`
   - Check if `goal` is a substring of `s + s`
   - If yes → `goal` is a rotation of `s`

3. **Why This Works**:

   ```
   s = "abcde"
   s + s = "abcdeabcde"

   All rotations:
   "abcde" (0 shifts) ← substring at index 0
   "bcdea" (1 shift)  ← substring at index 1
   "cdeab" (2 shifts) ← substring at index 2
   "deabc" (3 shifts) ← substring at index 3
   "eabcd" (4 shifts) ← substring at index 4
   ```

### Complexity Analysis

- **Time Complexity**: O(n) - `find()` uses KMP/efficient algorithm
- **Space Complexity**: O(n) - Creating concatenated string

### Dry Run (s = "abcde", goal = "cdeab")

```
Step 1: Check lengths
        s.length() = 5
        goal.length() = 5
        Same ✓

Step 2: Concatenate s with itself
        s = "abcde"
        s = s + s = "abcdeabcde"

Step 3: Search for goal in s+s
        s = "abcdeabcde"
        goal = "cdeab"

        Search: "abcdeabcde".find("cdeab")
                   01234567 89
                     ↓↓↓↓↓
                     cdeab (found at index 2!)

        res = 2 (not string::npos)

Result: TRUE (goal is a rotation of original s)

Visual:
Original: a b c d e
Rotate 2: c d e a b ← This is our goal!

In s+s:
a b c d e a b c d e
    └─────┘
    c d e a b (goal found!)
```

### Dry Run (s = "abcde", goal = "abced")

```
Step 1: Check lengths
        Both length = 5 ✓

Step 2: Concatenate
        s = "abcde" + "abcde" = "abcdeabcde"

Step 3: Search for goal
        s = "abcdeabcde"
        goal = "abced"

        "abcdeabcde".find("abced")
        → Not found! (string::npos)

        "abced" is NOT a rotation of "abcde"
        (characters are rearranged, not rotated)

Result: FALSE

Visual:
Original: a b c d e
Goal:     a b c e d ← Not a rotation, it's a permutation!
                 ↑↑ (e and d swapped)
```

### All Rotations Visualization (s = "abcde")

```
s + s = "abcdeabcde"

Rotation 0 (0 shifts): "abcde" → index 0
Rotation 1 (1 shift):  "bcdea" → index 1
Rotation 2 (2 shifts): "cdeab" → index 2
Rotation 3 (3 shifts): "deabc" → index 3
Rotation 4 (4 shifts): "eabcd" → index 4

All appear as substrings:
a b c d e a b c d e
└─────┘          0
  └─────┘        1
    └─────┘      2
      └─────┘    3
        └─────┘  4
```

### Edge Cases

```cpp
rotateString("", "")           → true  (empty strings)
rotateString("a", "a")         → true  (single char, 0 shifts)
rotateString("ab", "ba")       → true  (one shift)
rotateString("ab", "ab")       → true  (zero shifts)
rotateString("abc", "bca")     → true  (rotation)
rotateString("abc", "acb")     → false (not rotation)
rotateString("abc", "abcd")    → false (different lengths)
```

### Alternative Approach (Simulate Rotations)

```cpp
bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) return false;

    for (int i = 0; i < s.length(); i++) {
        if (s == goal) return true;
        s = s.substr(1) + s[0];  // Rotate by 1
    }
    return false;
}
// Time: O(n²), Space: O(n)
```

---

## 7. Valid Anagram

### Problem Statement

Given two strings `s` and `t`, return true if `t` is an anagram of `s`. An anagram is formed by rearranging the letters of a different word, using all original letters exactly once.

### Code

```cpp
bool anagramStrings(string &s, string t)
{
    // Different lengths can't be anagrams
    if (s.length() != t.length())
        return false;

    int n = s.length();
    int freq[26] = {0};  // Frequency array for 'a' to 'z'

    // Count frequency of characters in s
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }

    // Decrease frequency for characters in t
    for (int j = 0; j < n; j++)
    {
        freq[t[j] - 'a']--;
    }

    // Check if all frequencies are zero
    for (int k = 0; k < n; k++)
    {
        if (freq[s[k] - 'a'] != 0)
            return false;
    }

    return true;
}
```

### Approach

1. **Frequency Counting**: Use array to count character occurrences
   - Index 0 = 'a', Index 1 = 'b', ..., Index 25 = 'z'
2. **Algorithm**:

   - Check if lengths are equal (necessary condition)
   - Increment frequency for each character in `s`
   - Decrement frequency for each character in `t`
   - If all frequencies are 0 → anagram
   - If any frequency is non-zero → not anagram

3. **Why This Works**:
   - Anagrams have same character frequencies
   - Incrementing for s and decrementing for t
   - If same characters with same counts → all become 0

### Complexity Analysis

- **Time Complexity**: O(n) - Three linear passes
- **Space Complexity**: O(1) - Fixed array of size 26

### Dry Run (s = "anagram", t = "nagaram")

```
s = "anagram"
t = "nagaram"

Step 1: Check lengths
        Both length = 7 ✓

Step 2: Initialize frequency array
        freq[26] = {0}

Step 3: Count frequencies in s = "anagram"
        s[0]='a' → freq[0]++ → freq[0]=1
        s[1]='n' → freq[13]++ → freq[13]=1
        s[2]='a' → freq[0]++ → freq[0]=2
        s[3]='g' → freq[6]++ → freq[6]=1
        s[4]='r' → freq[17]++ → freq[17]=1
        s[5]='a' → freq[0]++ → freq[0]=3
        s[6]='m' → freq[12]++ → freq[12]=1

        freq: [3,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0]
               a              g        m n          r

Step 4: Decrease frequencies for t = "nagaram"
        t[0]='n' → freq[13]-- → freq[13]=0
        t[1]='a' → freq[0]-- → freq[0]=2
        t[2]='g' → freq[6]-- → freq[6]=0
        t[3]='a' → freq[0]-- → freq[0]=1
        t[4]='r' → freq[17]-- → freq[17]=0
        t[5]='a' → freq[0]-- → freq[0]=0
        t[6]='m' → freq[12]-- → freq[12]=0

        freq: [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
               (all zeros!)

Step 5: Check all frequencies
        All are 0 ✓

Result: TRUE (Valid Anagram)

Visual:
s: a n a g r a m
   ↓ ↓ ↓ ↓ ↓ ↓ ↓
t: n a g a r a m
   (rearranged, but same characters)

Character count:
a: 3, g: 1, m: 1, n: 1, r: 1
Both strings have same counts ✓
```

### Dry Run (s = "rat", t = "car")

```
s = "rat"
t = "car"

Step 1: Length check
        Both length = 3 ✓

Step 2: Count frequencies in s = "rat"
        r → freq[17]=1
        a → freq[0]=1
        t → freq[19]=1

        freq: [1,0,0,...,1,...,1,0,0]
               a         r   t

Step 3: Decrease for t = "car"
        c → freq[2]-- → freq[2]=-1 ⚠️
        a → freq[0]-- → freq[0]=0
        r → freq[17]-- → freq[17]=0

Step 4: Check frequencies
        freq[2] = -1 (not zero!) ✗

Result: FALSE (Not an Anagram)

Visual:
s: r a t
t: c a r
   ↑     ↑
   different characters

Character count:
s: a:1, r:1, t:1
t: a:1, c:1, r:1
Different! ✗
```

### Better Check Method

```cpp
// Instead of checking freq[s[k]-'a'], check all 26 positions
for (int k = 0; k < 26; k++) {
    if (freq[k] != 0)
        return false;
}
```

### Brute Force Approach (Sorting)

```cpp
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
// Time: O(n log n), Space: O(1)
```

### Visual Comparison

```
s = "listen"
t = "silent"

After sorting:
s = "eilnst"
t = "eilnst"
Same → Anagram ✓

Frequency approach:
e:1, i:1, l:1, n:1, s:1, t:1
Both have same frequencies ✓
```

### Edge Cases

```cpp
anagramStrings("", "")              → true  (empty strings)
anagramStrings("a", "a")            → true  (same char)
anagramStrings("a", "b")            → false (different)
anagramStrings("ab", "ba")          → true  (anagram)
anagramStrings("abc", "abcd")       → false (different lengths)
anagramStrings("aab", "aba")        → true  (anagram)
```

---

## 8. Sort Characters by Frequency

### Problem Statement

Return an array of unique characters from a string, sorted by highest to lowest frequency. If two characters have the same frequency, arrange them in alphabetic order.

### Code

```cpp
// Custom comparator function
static bool comparator(pair<int, char> p1, pair<int, char> p2)
{
    if (p1.first > p2.first)  // Higher frequency comes first
        return true;
    if (p1.first < p2.first)  // Lower frequency comes later
        return false;
    return p1.second < p2.second;  // Same frequency: alphabetical order
}

vector<char> frequencySort(string &s)
{
    // Initialize pairs: (frequency, character)
    pair<int, char> freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = {0, i + 'a'};  // {0, 'a'}, {0, 'b'}, ..., {0, 'z'}
    }

    // Count frequency of each character
    for (char ch : s)
    {
        freq[ch - 'a'].first++;
    }

    // Sort based on custom comparator
    sort(freq, freq + 26, comparator);

    // Collect characters with non-zero frequency
    vector<char> ans;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i].first > 0)
            ans.push_back(freq[i].second);
    }

    return ans;
}
```

### Approach

1. **Data Structure**: Array of pairs `{frequency, character}`
2. **Algorithm**:

   - Initialize 26 pairs for 'a' to 'z' with frequency 0
   - Count frequency of each character in string
   - Sort using custom comparator:
     - Primary: Higher frequency first
     - Secondary: Alphabetical order for same frequency
   - Collect characters with frequency > 0

3. **Comparator Logic**:
   ```
   If freq(p1) > freq(p2) → p1 comes first
   If freq(p1) < freq(p2) → p2 comes first
   If freq(p1) = freq(p2) → alphabetical order
   ```

### Complexity Analysis

- **Time Complexity**: O(n + 26 log 26) = O(n)
  - O(n) to count frequencies
  - O(26 log 26) to sort (constant)
- **Space Complexity**: O(1) - Fixed array of 26 elements

### Dry Run (s = "tree")

```
Step 1: Initialize freq array
        freq[0] = {0, 'a'}
        freq[1] = {0, 'b'}
        ...
        freq[25] = {0, 'z'}

Step 2: Count frequencies
        s = "tree"

        ch='t' → freq['t'-'a'].first++ → freq[19].first = 1
        ch='r' → freq['r'-'a'].first++ → freq[17].first = 1
        ch='e' → freq['e'-'a'].first++ → freq[4].first = 1
        ch='e' → freq['e'-'a'].first++ → freq[4].first = 2

        After counting:
        freq[4] = {2, 'e'}
        freq[17] = {1, 'r'}
        freq[19] = {1, 't'}
        (rest are {0, char})

Step 3: Sort using comparator
        Compare {2,'e'} and {1,'r'}:
            2 > 1 → {2,'e'} comes first

        Compare {1,'r'} and {1,'t'}:
            1 = 1 → alphabetical: 'r' < 't'
            → {1,'r'} comes first

        After sorting:
        freq[0] = {2, 'e'}
        freq[1] = {1, 'r'}
        freq[2] = {1, 't'}
        freq[3] = {0, 'a'}
        ...

Step 4: Collect non-zero frequencies
        ans = ['e', 'r', 't']

Result: ['e', 'r', 't']

Visual:
String: t r e e
Count:  t:1, r:1, e:2

Sorted by frequency (then alphabetically):
e (freq=2)
r (freq=1, 'r' < 't')
t (freq=1)
```

### Dry Run (s = "cccaaa")

```
Step 1: Count frequencies
        c → 3
        a → 3

        freq[0] = {3, 'a'}
        freq[2] = {3, 'c'}

Step 2: Sort
        Compare {3,'a'} and {3,'c'}:
            3 = 3 → alphabetical: 'a' < 'c'
            → {3,'a'} comes first

        After sorting:
        freq[0] = {3, 'a'}
        freq[1] = {3, 'c'}
        freq[2] = {0, 'b'}
        ...

Step 3: Collect
        ans = ['a', 'c']

Result: ['a', 'c']

Visual:
String: c c c a a a
Count:  a:3, c:3 (tie!)

Same frequency → alphabetical:
a (comes before c)
c
```

### Dry Run (s = "Aabb")

```
Note: Code works for lowercase only!
If s has uppercase, use freq[52] and handle separately.

Assuming lowercase "aabb":

Step 1: Count
        a → 2
        b → 2

        freq[0] = {2, 'a'}
        freq[1] = {2, 'b'}

Step 2: Sort
        Same frequency → alphabetical
        'a' < 'b'

        After sorting:
        freq[0] = {2, 'a'}
        freq[1] = {2, 'b'}

Result: ['a', 'b']
```

### Comparator Detailed Example

```
Pairs to compare:
p1 = {3, 'b'}
p2 = {2, 'a'}

comparator(p1, p2):
    p1.first (3) > p2.first (2) → return true
    → p1 comes before p2

Result: {3,'b'} is ordered before {2,'a'}

---

p1 = {2, 'b'}
p2 = {2, 'a'}

comparator(p1, p2):
    p1.first (2) NOT > p2.first (2) → check next
    p1.first (2) NOT < p2.first (2) → check next
    p1.second ('b') < p2.second ('a')? NO
    → return false
    → p2 comes before p1

Result: {2,'a'} is ordered before {2,'b'}
```

### Alternative: Using Map and Vector

```cpp
vector<char> frequencySort(string &s) {
    unordered_map<char, int> freq;
    for (char ch : s) freq[ch]++;

    vector<pair<int, char>> pairs;
    for (auto& p : freq) {
        pairs.push_back({p.second, p.first});
    }

    sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    vector<char> ans;
    for (auto& p : pairs) ans.push_back(p.second);
    return ans;
}
```

### Edge Cases

```cpp
frequencySort("")              → []      (empty)
frequencySort("a")             → ['a']   (single char)
frequencySort("aaa")           → ['a']   (same char)
frequencySort("abc")           → ['a','b','c'] (all freq=1, alphabetical)
frequencySort("aaabbc")        → ['a','b','c'] (a:3, b:2, c:1)
frequencySort("aabbcc")        → ['a','b','c'] (all freq=2, alphabetical)
```

---

## String Manipulation Techniques Summary

### 1. Two-Pointer Technique

- **Use Cases**: Palindrome check, reverse string, finding pairs
- **Pattern**: Start from both ends, move towards center
- **Examples**: Problems #2, #1
- **Complexity**: Usually O(n) time, O(1) space

### 2. Frequency Counting

- **Use Cases**: Anagram, character counting, pattern matching
- **Pattern**: Use array/map to count occurrences
- **Examples**: Problems #7, #8
- **Complexity**: O(n) time, O(k) space (k = alphabet size)

### 3. Sorting-Based Solutions

- **Use Cases**: Finding common elements, comparing strings
- **Pattern**: Sort and compare/process
- **Examples**: Problems #4, #7
- **Complexity**: O(n log n) time

### 4. String Concatenation Tricks

- **Use Cases**: Rotation detection, cyclic patterns
- **Pattern**: Concatenate string with itself
- **Examples**: Problem #6
- **Complexity**: O(n) time, O(n) space

### 5. Character Mapping

- **Use Cases**: Isomorphic strings, pattern matching
- **Pattern**: Map characters to positions/values
- **Examples**: Problem #5
- **Complexity**: O(n) time, O(k) space

---

## Common String Problems Patterns

### Pattern 1: Validation

- Palindrome check
- Anagram validation
- Isomorphic strings
- **Approach**: Compare, count, or map characters

### Pattern 2: Transformation

- Reverse string
- Rotate string
- Sort characters
- **Approach**: Rearrange or modify in-place/new string

### Pattern 3: Extraction

- Longest common prefix
- Largest odd number
- Substring finding
- **Approach**: Search, compare, or scan

### Pattern 4: Frequency-Based

- Sort by frequency
- Character counting
- Most common element
- **Approach**: Count and sort/process

---

## Optimization Tips

### 1. Space Optimization

```cpp
// Instead of creating new string
string reversed = reverse(s);  // O(n) space

// Use two pointers in-place
reverse(s.begin(), s.end());   // O(1) space
```

### 2. Early Exit

```cpp
// Check length first
if (s.length() != t.length()) return false;  // Before heavy computation
```

### 3. Use Right Data Structure

```cpp
// For 26 letters: array is faster than map
int freq[26] = {0};  // O(1) access, cache-friendly

// For any characters: use map
unordered_map<char, int> freq;  // O(1) average access
```

### 4. STL Functions

```cpp
// Use built-in functions when available
s.find(sub)           // Substring search (KMP algorithm)
reverse(s.begin(), s.end())  // Optimized reversal
sort(s.begin(), s.end())     // Optimized sorting
```

---

## Common Pitfalls

### 1. Case Sensitivity

```cpp
// Problem: 'A' != 'a'
// Solution: Convert to lowercase first
transform(s.begin(), s.end(), s.begin(), ::tolower);
```

### 2. ASCII vs Alphabet Size

```cpp
// For all ASCII: use 256
int freq[256] = {0};

// For lowercase only: use 26
int freq[26] = {0};
// Access: freq[ch - 'a']
```

### 3. Empty String Handling

```cpp
// Always check for empty strings
if (s.empty()) return "";
if (s.length() == 0) return false;
```

### 4. String Immutability Confusion

```cpp
// In C++, strings are mutable
s[0] = 'A';  // ✓ Valid

// In some languages, strings are immutable
// Always verify language-specific behavior
```

---

## Practice Tips

1. **Master Two-Pointer Technique**

   - Very common in string problems
   - Practice with palindromes, reversals

2. **Understand Frequency Arrays**

   - Essential for character counting
   - Know when to use array vs map

3. **Learn String STL Functions**

   - `find()`, `substr()`, `erase()`
   - `reverse()`, `sort()`, `transform()`

4. **Consider Edge Cases**

   - Empty strings
   - Single character
   - All same characters
   - Special characters

5. **Optimize Space**
   - Try in-place solutions first
   - Use indices instead of creating substrings

---

## Time Complexity Cheat Sheet

| Operation     | Complexity | Notes                             |
| ------------- | ---------- | --------------------------------- |
| Access s[i]   | O(1)       | Direct indexing                   |
| Length        | O(1)       | Cached value                      |
| Concatenation | O(n)       | Creates new string                |
| Substring     | O(k)       | k = length of substring           |
| Find          | O(n×m)     | n=string, m=pattern (KMP: O(n+m)) |
| Reverse       | O(n)       | In-place or new string            |
| Sort          | O(n log n) | Using comparison sort             |
| Compare       | O(n)       | Character by character            |

---

## Conclusion

String manipulation is a fundamental skill in programming. Master these patterns:

- **Two pointers** for palindromes and reversals
- **Frequency counting** for anagrams and character analysis
- **Sorting** for comparison and ordering
- **String tricks** like concatenation for rotations

**Key Takeaways:**

- Choose the right data structure (array vs map)
- Consider space-time tradeoffs
- Use STL functions when available
- Always handle edge cases
- Practice common patterns repeatedly

Happy Coding! 🚀

---

**File Location**: `/dsa/Basic/string/str.cpp`

**Last Updated**: October 3, 2025
