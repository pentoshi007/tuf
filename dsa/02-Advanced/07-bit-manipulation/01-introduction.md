# 🧠 Bit Manipulation – Complete Notes (C++)

> Everything in a computer is stored as **0s and 1s**. Bit manipulation lets you
> work directly on those bits — making code blazing fast with O(1) tricks.

---

## 📦 1. Binary Number System

Every number can be written in binary (base-2). Each position is a power of 2:

```
Position:  7    6    5    4    3    2    1    0
Power:    2^7  2^6  2^5  2^4  2^3  2^2  2^1  2^0
Value:    128   64   32   16    8    4    2    1
```

So `13` in binary = `1101` because: 8 + 4 + 0 + 1 = **13**

---

## 🔄 2. Decimal ↔ Binary Conversion

### ➡️ Decimal → Binary

Divide by 2 repeatedly, collect remainders, then **read bottom to top**.

```
13 ÷ 2 = 6  remainder  1  ↑ (read last)
 6 ÷ 2 = 3  remainder  0  ↑
 3 ÷ 2 = 1  remainder  1  ↑
 1 ÷ 2 = 0  remainder  1  ↑ (read first)

Result (bottom to top): 1 1 0 1 → 1101 ✅
```

```cpp
string decimalToBinary(int n) {
    string result = "";
    while (n > 0) {
        result += (n % 2 == 1) ? '1' : '0';
        n = n / 2;
    }
    reverse(result.begin(), result.end());
    return result;
}
// decimalToBinary(13) → "1101"
```

⏱ Time: O(log N) | 💾 Space: O(log N)

---

### ⬅️ Binary → Decimal

Multiply each bit by `2^(its position index)`, **sum everything up**.

```
Binary:    1    1    0    1
Position:  3    2    1    0
Value:    1×8  1×4  0×2  1×1
           8  + 4  + 0  + 1  = 13 ✅
```

```cpp
int binaryToDecimal(string str) {
    int len = str.length(), val = 1, num = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '1') num += val;
        val *= 2;
    }
    return num;
}
// binaryToDecimal("1101") → 13
```

⏱ Time: O(n) | 💾 Space: O(1)

---

## 🔁 3. One's & Two's Complement

### One's Complement → Flip every bit

```
 13  =  0000 1101
~13  =  1111 0010   ← one's complement (all bits flipped)
```

### Two's Complement → One's complement + 1

Used by computers to store **negative numbers**.

```
 13         =  0000 1101
one's comp  =  1111 0010
           +         1
two's comp  =  1111 0011   ← this is how -13 is stored!
```

> 💡 In C++:
>
> - `~n` gives **one's complement**
> - `-n` gives **two's complement**
> - That's why `~5 = -6` (not -5!)

---

## ⚙️ 4. Bitwise Operators

### AND `&` — 1 only if BOTH bits are 1

```
  13 →  1 1 0 1
   7 →  0 1 1 1
  &  →  0 1 0 1  = 5
```

> Think of AND as a **filter** — only lets through bits where both agree on 1.

### OR `|` — 1 if ANY bit is 1

```
  13 →  1 1 0 1
   7 →  0 1 1 1
  |  →  1 1 1 1  = 15
```

> OR is a **merger** — combines all the 1s from both numbers.

### XOR `^` — 1 if bits are DIFFERENT

```
  13 →  1 1 0 1
   7 →  0 1 1 1
  ^  →  1 0 1 0  = 10
```

> XOR is a **difference detector** — same bits cancel out, different bits stay.

### NOT `~` — Flips every single bit

```
   5 →  0000 0101
  ~5 →  1111 1010  = -6 (in two's complement)
```

### Right Shift `>>` — Divide by 2 (shift bits right, fill 0s on left)

```
13 >> 1  →  1101 >> 1  =  0110  =  6   (13 / 2 = 6)
13 >> 2  →  1101 >> 2  =  0011  =  3   (13 / 4 = 3)
```

### Left Shift `<<` — Multiply by 2 (shift bits left, fill 0s on right)

```
13 << 1  →  1101 << 1  =  11010  =  26   (13 × 2 = 26)
13 << 2  →  1101 << 2  = 110100  =  52   (13 × 4 = 52)
```

> 🚀 **Shift shortcut:** `n >> k` = n ÷ 2^k, `n << k` = n × 2^k

---

## 🛠️ 5. Bit Tricks & Techniques

---

### Trick 1 — Swap Without Temp Variable

Uses XOR magic: same bits cancel out (`a ^ a = 0`), anything XOR 0 stays (`a ^ 0 = a`).

```
A = 5  →  0101
B = 6  →  0110

Step 1: A = A ^ B  →  0101 ^ 0110  =  0011  (A = 3)
Step 2: B = A ^ B  →  0011 ^ 0110  =  0101  (B = 5 ✅)
Step 3: A = A ^ B  →  0011 ^ 0101  =  0110  (A = 6 ✅)
```

```cpp
int A = 5, B = 6;
A = A ^ B;   // A = 3
B = A ^ B;   // B = 5
A = A ^ B;   // A = 6
// A=6, B=5 — swapped!
```

⏱ Time: O(1) | 💾 Space: O(1)

---

### Trick 2 — Check if i-th Bit is Set

Create a **mask** with only the i-th bit = 1, then AND with n. If result ≠ 0, the bit is set.

```
n = 13  →  1 1 0 1
i = 2   →  mask = 1 << 2 = 0 1 0 0

1 1 0 1
0 1 0 0   &
─────────
0 1 0 0   ≠ 0  →  bit IS set ✅

i = 1   →  mask = 1 << 1 = 0 0 1 0

1 1 0 1
0 0 1 0   &
─────────
0 0 0 0   = 0   →  bit NOT set ✅
```

```cpp
bool isBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}
// isBitSet(13, 2) → true
// isBitSet(13, 1) → false
```

⏱ Time: O(1) | 💾 Space: O(1)

---

### Trick 3 — Set the i-th Bit (force to 1)

OR with a mask — OR never turns a 1 into 0.

```
n = 9  →  1 0 0 1
i = 2  →  mask = 1 << 2 = 0 1 0 0

1 0 0 1
0 1 0 0   |
─────────
1 1 0 1   = 13  ✅  (bit 2 is now 1)
```

```cpp
int setBit(int n, int i) {
    return n | (1 << i);
}
// setBit(9, 2) → 13
```

⏱ Time: O(1) | 💾 Space: O(1)

---

### Trick 4 — Clear the i-th Bit (force to 0)

AND with the **complement** of the mask — the mask has 0 at position i, so AND clears it.

```
n = 13  →  1 1 0 1
i = 2   →  mask = 1 << 2  = 0 1 0 0
           ~mask           = 1 0 1 1

1 1 0 1
1 0 1 1   &
─────────
1 0 0 1   = 9  ✅  (bit 2 is now 0)
```

```cpp
int clearBit(int n, int i) {
    return n & ~(1 << i);
}
// clearBit(13, 2) → 9
```

⏱ Time: O(1) | 💾 Space: O(1)

---

### Trick 5 — Toggle the i-th Bit (flip it)

XOR with a mask — XOR flips the bit at position i (1→0 or 0→1).

```
n = 13  →  1 1 0 1
i = 1   →  mask = 1 << 1 = 0 0 1 0

1 1 0 1
0 0 1 0   ^
─────────
1 1 1 1   = 15  ✅  (bit 1 flipped from 0 → 1)

Try again on 15:
1 1 1 1
0 0 1 0   ^
─────────
1 1 0 1   = 13  ✅  (bit 1 flipped back from 1 → 0)
```

```cpp
int toggleBit(int n, int i) {
    return n ^ (1 << i);
}
// toggleBit(13, 1) → 15
// toggleBit(15, 1) → 13
```

⏱ Time: O(1) | 💾 Space: O(1)

---

### Trick 6 — Remove the Last Set Bit (rightmost 1)

`n & (n-1)` always wipes out the rightmost 1-bit. Why?
Subtracting 1 flips the rightmost 1 to 0 and all trailing 0s to 1s — so AND zeroes them all out.

```
n   = 13  →  1 1 0 1
n-1 = 12  →  1 1 0 0

1 1 0 1
1 1 0 0   &
─────────
1 1 0 0   = 12  ✅  (rightmost 1 at bit 0 is gone)

Next: n = 12  →  1 1 0 0
      n-1 = 11 →  1 0 1 1

1 1 0 0
1 0 1 1   &
─────────
1 0 0 0   = 8   ✅  (rightmost 1 at bit 2 is gone)
```

```cpp
int removeLastSetBit(int n) {
    return n & (n - 1);
}
// removeLastSetBit(13) → 12
// removeLastSetBit(12) → 8
```

⏱ Time: O(1) | 💾 Space: O(1)

---

### Trick 7 — Check if Number is a Power of 2

Powers of 2 have **exactly ONE set bit**. So `n & (n-1)` = 0 for all powers of 2.

```
Powers of 2 in binary:
 1  →  0001   (1 set bit)
 2  →  0010   (1 set bit)
 4  →  0100   (1 set bit)
 8  →  1000   (1 set bit)
16  →  10000  (1 set bit)

Check n = 16:
n   = 16  →  1 0 0 0 0
n-1 = 15  →  0 1 1 1 1

1 0 0 0 0
0 1 1 1 1   &
───────────
0 0 0 0 0   = 0  ✅  → IS a power of 2

Check n = 13:
n   = 13  →  1 1 0 1
n-1 = 12  →  1 1 0 0

1 1 0 1
1 1 0 0   &
─────────
1 1 0 0   ≠ 0  ✅  → NOT a power of 2
```

```cpp
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}
// isPowerOfTwo(16) → true
// isPowerOfTwo(13) → false
// Note: n > 0 handles edge case of n = 0
```

⏱ Time: O(1) | 💾 Space: O(1)

---

### Trick 8 — Count Set Bits (popcount)

#### Method 1 — Loop & check each bit

Check last bit with `& 1`, then right shift.

```
n = 13  →  1 1 0 1

Step 1: 1101 & 0001 = 1  → count=1,  n = 0110 (right shift)
Step 2: 0110 & 0001 = 0  → count=1,  n = 0011
Step 3: 0011 & 0001 = 1  → count=2,  n = 0001
Step 4: 0001 & 0001 = 1  → count=3,  n = 0000  → STOP

Set bits = 3 ✅
```

```cpp
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);  // check last bit
        n >>= 1;           // shift right
    }
    return count;
}
```

⏱ Time: O(log N) | 💾 Space: O(1)

---

#### Method 2 — Optimized using `n & (n-1)` ⚡

Each step removes ONE set bit, so we only loop **K** times (K = total set bits).

```
n = 13  →  1 1 0 1   count = 0

Step 1: n & (n-1) = 1101 & 1100 = 1100 = 12  count = 1
Step 2: n & (n-1) = 1100 & 1011 = 1000 =  8  count = 2
Step 3: n & (n-1) = 1000 & 0111 = 0000 =  0  count = 3  → STOP

Set bits = 3 ✅ (only 3 iterations vs 4 before!)
```

```cpp
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // remove rightmost set bit
        count++;
    }
    return count;
}
```

⏱ Time: O(K) — faster when few bits are set | 💾 Space: O(1)

#### Method 3 — Built-in (use in competitive coding)

```cpp
int count = __builtin_popcount(n);    // for int
int count = __builtin_popcountll(n);  // for long long
```

---

## 📋 Quick Reference Cheatsheet

```
Operation              | Code               | Effect
-----------------------|--------------------|---------------------------
Check i-th bit         | n & (1 << i)       | Non-zero = bit is set
Set i-th bit           | n | (1 << i)       | Forces bit i to 1
Clear i-th bit         | n & ~(1 << i)      | Forces bit i to 0
Toggle i-th bit        | n ^ (1 << i)       | Flips bit i
Remove last set bit    | n & (n - 1)        | Kills rightmost 1
Check power of 2       | n>0 && !(n&(n-1))  | True if power of 2
Count set bits (fast)  | n &= (n-1) loop    | Counts 1s in binary
Multiply by 2^k        | n << k             | Left shift
Divide by 2^k          | n >> k             | Right shift
One's complement       | ~n                 | Flip all bits
```

---

## 🧠 Key XOR Properties to Remember

```
a ^ a = 0       → same values cancel out
a ^ 0 = a       → XOR with 0 changes nothing
a ^ b ^ a = b   → used in swap trick
XOR is commutative & associative
```

---

## ⚠️ Common Edge Cases

| Situation            | What to Watch Out For                           |
| -------------------- | ----------------------------------------------- |
| `~n` result          | Always equals `-(n+1)` due to two's complement  |
| `n & (n-1)` when n=0 | Returns 0, don't loop infinitely                |
| Left shift overflow  | Shifting beyond 31 bits for `int` is undefined  |
| Power of 2 check     | Must add `n > 0` guard (0 would pass otherwise) |
