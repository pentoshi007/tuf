## String Problems – Comprehensive Guide

This directory contains classic string problems implemented in C++. Each section below provides:

- Problem statement and key idea
- Approach and reasoning
- Well-commented code
- Time and space complexity
- Step-by-step dry run (with visuals where useful)

All code uses the C++ standard library. You can find the source file at `dsa/Basic/string/str.cpp`.

---

### 1) Reverse a String

**Problem**: Given a string, return its reverse.

**Approach**: Use `std::reverse` on the full range `[begin, end)`.

```cpp
string reverseString(string str) {
    // In-place reverse of the string's characters
    reverse(str.begin(), str.end());
    return str;
}
```

**Complexity**:

- Time: O(n)
- Space: O(1) (in-place)

**Dry Run**:

- Input: "abcd" → reverse → "dcba"

---

### 2) Palindrome Check (Two Pointers)

**Problem**: Check if a string reads the same forwards and backwards.

**Approach**: Two-pointer technique from both ends; compare and move inward.

```cpp
bool isPalindrome(string str) {
    int i = 0;
    int j = str.size() - 1;
    while (i < j) {
        if (str[i] != str[j]) return false; // mismatch
        i++; j--;                            // move inward
    }
    return true; // all matched
}
```

**Complexity**:

- Time: O(n)
- Space: O(1)

**Dry Run**:

- "racecar": r==r, a==a, c==c, e center → true
- "hello": h!=o → false

---

### 3) Largest Odd Number (as Prefix of Numeric String)

Given a numeric string, return the largest-valued substring prefix that is odd. If none, return an empty string. Also ensure there is no leading zero in the returned result.

There are two implementations shown.

#### 3.1) Scan From Right and Trim Leading Zeros

```cpp
// Note: Return type should be string (not int) since we return a substring
string largestOddNumber(string str) {
    int n = str.size();
    // Find rightmost odd digit; prefix up to that index is the largest odd
    for (int i = n - 1; i >= 0; i--) {
        if ((str[i] - '0') % 2 != 0) {
            string ans = str.substr(0, i + 1);
            // Remove leading zeros
            size_t pos = ans.find_first_not_of('0');
            return (pos == string::npos) ? string("") : ans.erase(0, pos);
        }
    }
    return ""; // no odd digit present
}
```

**Complexity**:

- Time: O(n)
- Space: O(1) extra (beyond output)

**Dry Run**:

- Input: "0012406" → scan right: 6(even), 0, 4, 2, 1(odd at idx=3). Prefix: "0012" → trim → "12"
- Input: "4200" → no odd → ""

#### 3.2) Two-Index Approach (Find rightmost odd, then skip leading zeros)

```cpp
string largeOddNum(string &s) {
    int left = 0;           // start index after trimming leading zeros
    int rightmostOdd = -1;  // right bound (inclusive)

    // Find rightmost odd digit
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        if ((s[i] - '0') % 2 != 0) { rightmostOdd = i; break; }
    }
    if (rightmostOdd == -1) return ""; // no odd digit

    // Move left to first non-zero while staying within [left, rightmostOdd]
    while (left <= rightmostOdd && s[left] == '0') left++;

    return s.substr(left, rightmostOdd - left + 1);
}
```

**Complexity**:

- Time: O(n)
- Space: O(1) extra

**Dry Run**:

- Input: "0001350" → rightmostOdd at '5' (idx=4), left skips zeros to idx=3 → substring [3..4] = "15"

---

### 4) Longest Common Prefix (Across Strings)

**Problem**: Given an array of strings, return the longest common prefix.

**Approach**: Sort the array; only the first and last strings can bound the common prefix. Compare character-by-character.

```cpp
string longestCommonPrefix(vector<string> &str) {
    if (str.empty()) return "";

    sort(str.begin(), str.end());   // lexicographic
    string first = str.front();
    string last  = str.back();

    int minLength = min(first.size(), last.size());
    string ans = "";
    for (int i = 0; i < minLength; i++) {
        if (first[i] != last[i]) return ans; // mismatch ends prefix
        ans += first[i];
    }
    return ans;
}
```

**Complexity**:

- Time: O(k log k + L), where k is number of strings and L is the comparison length between first and last
- Space: O(1) extra (ignoring sort overhead)

**Dry Run**:

- ["flower", "flow", "flight"] → sorted: ["flight","flow","flower"]. Compare first="flight", last="flower": "fl" → result "fl"

---

### 5) Isomorphic Strings

**Problem**: Determine if strings `s` and `t` are isomorphic. Characters from `s` must map one-to-one and positionally to characters in `t`.

**Approach**: Maintain last-seen positions for characters from both strings in two arrays/maps. If at an index the last-seen positions differ, mapping is inconsistent.

```cpp
bool isomorphicString(string s, string t) {
    if (s.size() != t.size()) return false;

    int m1[256] = {0}, m2[256] = {0}; // last positions (1-based) for ASCII
    for (int i = 0; i < (int)s.size(); i++) {
        if (m1[(unsigned char)s[i]] != m2[(unsigned char)t[i]]) return false;
        m1[(unsigned char)s[i]] = i + 1;
        m2[(unsigned char)t[i]] = i + 1;
    }
    return true;
}
```

**Complexity**:

- Time: O(n)
- Space: O(1) (fixed 256 arrays)

**Dry Run**:

- s="egg", t="add": e→a ok, g→d ok, g→d consistent → true
- s="foo", t="bar": f→b ok, o→a ok, o→r mismatch (last-seen differs) → false

---

### 6) Rotate String (Cyclic Shift)

**Problem**: Can string `s` be rotated (by moving the leftmost character to the end some number of times) to become `goal`?

**Approach**: If lengths match, check if `goal` is a substring of `s + s`.

```cpp
bool rotateString(string &s, string &goal) {
    if (s.length() != goal.length()) return false;
    string doubled = s + s;                 // all rotations are substrings of s+s
    return doubled.find(goal) != string::npos;
}
```

**Complexity**:

- Time: O(n) average for substring search (depending on implementation)
- Space: O(n) for the doubled string

**Dry Run**:

- s="abcde", goal="cdeab" → s+s="abcdeabcde" contains "cdeab" → true
- s="abc", goal="acb" → not a substring → false

---

### 7) Valid Anagram

**Problem**: Check if `t` is an anagram of `s` (rearrangement using all characters exactly once).

**Approach**: Count character frequencies for `s`, subtract frequencies using `t`, and verify all counts end at zero.

```cpp
bool anagramStrings(string &s, string t) {
    if (s.length() != t.length()) return false;

    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;
    for (char c : t) freq[c - 'a']--;

    for (int count : freq) if (count != 0) return false;
    return true;
}
```

**Assumption**: Inputs are lowercase a–z. If Unicode or mixed case is possible, adapt counts accordingly.

**Complexity**:

- Time: O(n)
- Space: O(1) (26-sized array)

**Dry Run**:

- s="anagram", t="nagaram" → final freq all zeros → true
- s="rat", t="car" → mismatch at 'r'/'c' → false

---

### 8) Sort Characters by Frequency (Return Unique Characters)

**Problem**: Given a lowercase string `s`, return the array of unique characters sorted by descending frequency. For ties, sort alphabetically.

**Approach**:

- Maintain an array of pairs `(frequency, character)` for a–z.
- Count frequencies, sort with a custom comparator: higher frequency first; if equal, smaller character first.
- Collect characters with non-zero frequency in order.

```cpp
static bool comparator(pair<int, char> p1, pair<int, char> p2) {
    if (p1.first > p2.first) return true;   // higher frequency first
    if (p1.first < p2.first) return false;
    return p1.second < p2.second;           // tie-break: alphabetical
}

vector<char> frequencySort(string &s) {
    pair<int, char> freq[26];
    for (int i = 0; i < 26; i++) freq[i] = {0, (char)(i + 'a')};

    for (char ch : s) freq[ch - 'a'].first++; // count

    sort(freq, freq + 26, comparator);

    vector<char> ans;
    for (int i = 0; i < 26; i++) {
        if (freq[i].first > 0) ans.push_back(freq[i].second);
    }
    return ans;
}
```

**Complexity**:

- Time: O(n + 26 log 26) ≈ O(n)
- Space: O(1) extra (fixed arrays) plus output

**Dry Run**:

- s="banana" → counts: a:3, n:2, b:1 → sorted unique: ['a','n','b']
- s="aabbcc" → counts all 2 → alphabetical tie-break: ['a','b','c']

---

## How to Compile and Run

You can use the single `main` in `str.cpp` for quick testing. For example, to test the "Largest Odd Number" routine (as currently in `main`):

```bash
g++ -std=c++17 str.cpp -o string_problems && ./string_problems
```

Provide input on stdin if the selected routine expects it in `main`.

---

## Tips for Revision

- Rehearse the intuition behind each approach rather than memorizing code.
- For two-pointer and prefix problems, visualize indices moving.
- For frequency-based problems, quickly sketch a small frequency table.
- For rotations, remember the `s + s` trick.
- For isomorphism, think "same shape" → last-seen positions must match.
