# Mathematical Operations - Complete Guide 🔢

A comprehensive collection of fundamental mathematical algorithms with detailed explanations, complexity analysis, and visual demonstrations for effective revision.

## Table of Contents

1. [Introduction to Math Operations](#introduction-to-math-operations)
2. [Count Digits](#1-count-digits)
3. [Reverse a Number](#2-reverse-a-number)
4. [Palindrome Number](#3-palindrome-number)
5. [Armstrong Number](#4-armstrong-number)
6. [Prime Number Check](#5-prime-number-check)
7. [GCD - Brute Force](#6-gcd---brute-force)
8. [GCD - Euclidean Algorithm](#7-gcd---euclidean-algorithm)
9. [Sieve of Eratosthenes - Count Primes](#8-sieve-of-eratosthenes---count-primes)
10. [Sieve of Eratosthenes - List Primes](#9-sieve-of-eratosthenes---list-primes)
11. [Largest Digit](#10-largest-digit)
12. [Factorial](#11-factorial)
13. [Perfect Number](#12-perfect-number)

---

## Introduction to Math Operations

Mathematical operations form the foundation of many algorithmic problems. Understanding these concepts is crucial for:

- **Number Theory**: Properties of integers
- **Optimization**: Efficient algorithms for common operations
- **Problem Solving**: Building blocks for complex problems

### Key Concepts:

1. **Digit Manipulation**: Extracting and processing individual digits
2. **Modular Arithmetic**: Operations with remainders
3. **Prime Numbers**: Building blocks of integers
4. **Divisibility**: Understanding factors and multiples
5. **Algorithmic Optimization**: From brute force to efficient solutions

---

## 1. Count Digits

### Problem Statement

Count the number of digits in a given integer (positive or negative).

### Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n < 0)
    {
        n = -n;
    }
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    cout << count << endl;
    return 0;
}
```

### Approach

1. Handle special case: 0 has 1 digit
2. Convert negative numbers to positive (sign doesn't count as digit)
3. Repeatedly divide by 10 until number becomes 0
4. Count the number of divisions

### Complexity Analysis

- **Time Complexity**: O(log₁₀ n) - Number of digits in n
- **Space Complexity**: O(1) - Only using counter variable

### Dry Run (n = 12345)

```
n = 12345
count = 0

Iteration 1: n = 12345
             n / 10 = 1234
             count = 1

Iteration 2: n = 1234
             n / 10 = 123
             count = 2

Iteration 3: n = 123
             n / 10 = 12
             count = 3

Iteration 4: n = 12
             n / 10 = 1
             count = 4

Iteration 5: n = 1
             n / 10 = 0
             count = 5

n = 0, loop ends
Result: 5 digits

Visual:
12345 → 1234 → 123 → 12 → 1 → 0
  ↓      ↓     ↓     ↓    ↓
  1      2     3     4    5 (count)
```

### Alternative Approach (Mathematical)

```cpp
// Using logarithm
int countDigits(int n) {
    if (n == 0) return 1;
    if (n < 0) n = -n;
    return floor(log10(n)) + 1;
}
// Time: O(1), but may have precision issues for very large numbers
```

### Edge Cases

```cpp
countDigits(0)       → 1
countDigits(5)       → 1
countDigits(-123)    → 3
countDigits(1000000) → 7
```

---

## 2. Reverse a Number

### Problem Statement

Reverse the digits of a given integer while preserving the sign.

### Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    bool negative = n < 0;
    if (negative)
    {
        n = -n;
    }
    long long reversed = 0;
    while (n > 0)
    {
        int lastDigit = (int)(n % 10);
        reversed = reversed * 10 + lastDigit;
        n = n / 10;
    }
    if (negative)
    {
        reversed = -reversed;
    }
    cout << reversed << endl;
    return 0;
}
```

### Approach

1. Store the sign (negative flag)
2. Work with absolute value
3. Extract last digit using modulo 10
4. Build reversed number: `reversed = reversed * 10 + lastDigit`
5. Remove last digit by dividing by 10
6. Restore sign if negative

### Complexity Analysis

- **Time Complexity**: O(log₁₀ n) - Process each digit once
- **Space Complexity**: O(1) - Only using variables

### Dry Run (n = 12345)

```
n = 12345
negative = false
reversed = 0

Iteration 1:
    lastDigit = 12345 % 10 = 5
    reversed = 0 * 10 + 5 = 5
    n = 12345 / 10 = 1234

Iteration 2:
    lastDigit = 1234 % 10 = 4
    reversed = 5 * 10 + 4 = 54
    n = 1234 / 10 = 123

Iteration 3:
    lastDigit = 123 % 10 = 3
    reversed = 54 * 10 + 3 = 543
    n = 123 / 10 = 12

Iteration 4:
    lastDigit = 12 % 10 = 2
    reversed = 543 * 10 + 2 = 5432
    n = 12 / 10 = 1

Iteration 5:
    lastDigit = 1 % 10 = 1
    reversed = 5432 * 10 + 1 = 54321
    n = 1 / 10 = 0

Result: 54321

Visual:
Original:  1  2  3  4  5
           ↓  ↓  ↓  ↓  ↓
Reversed:  5  4  3  2  1

Building process:
0 → 5 → 54 → 543 → 5432 → 54321
```

### Dry Run (n = -123)

```
n = -123
negative = true
n = 123
reversed = 0

Iteration 1: lastDigit = 3, reversed = 3, n = 12
Iteration 2: lastDigit = 2, reversed = 32, n = 1
Iteration 3: lastDigit = 1, reversed = 321, n = 0

Apply negative: reversed = -321
Result: -321
```

### Edge Cases

```cpp
reverse(0)     → 0
reverse(123)   → 321
reverse(-123)  → -321
reverse(1200)  → 21 (trailing zeros removed)
reverse(5)     → 5
```

### Important Note

**Overflow Risk**: For very large numbers, reversed value might exceed integer limits. Use `long long` or check for overflow.

---

## 3. Palindrome Number

### Problem Statement

Check if a number reads the same forwards and backwards. Negative numbers are not palindromes.

### Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n < 0)
    {
        cout << "No" << endl;
        return 0;
    }
    long long original = n;
    long long reversed = 0;
    while (n > 0)
    {
        int lastDigit = (int)(n % 10);
        reversed = reversed * 10 + lastDigit;
        n = n / 10;
    }
    cout << (original == reversed ? "Yes" : "No") << endl;
    return 0;
}
```

### Approach

1. **Base Case**: Negative numbers are not palindromes
2. Store original number
3. Reverse the number (same logic as previous problem)
4. Compare original with reversed
5. If equal → palindrome, else not

### Complexity Analysis

- **Time Complexity**: O(log₁₀ n) - Process each digit
- **Space Complexity**: O(1) - Constant space

### Dry Run (n = 12321)

```
n = 12321
original = 12321
reversed = 0

Iteration 1: lastDigit = 1, reversed = 1, n = 1232
Iteration 2: lastDigit = 2, reversed = 12, n = 123
Iteration 3: lastDigit = 3, reversed = 123, n = 12
Iteration 4: lastDigit = 2, reversed = 1232, n = 1
Iteration 5: lastDigit = 1, reversed = 12321, n = 0

Compare: original (12321) == reversed (12321) ✓
Result: Yes (Palindrome)

Visual:
1  2  3  2  1
↑           ↑
└─── same ──┘
   ↓     ↓
   └same─┘
      ↓
   (center)
```

### Dry Run (n = 12345)

```
n = 12345
original = 12345
reversed = 54321 (after reversal process)

Compare: 12345 != 54321 ✗
Result: No (Not a Palindrome)

Visual:
1  2  3  4  5
↑           ↑
1  ≠  5  (not same)
```

### Edge Cases

```cpp
isPalindrome(0)      → Yes (single digit)
isPalindrome(7)      → Yes (single digit)
isPalindrome(-121)   → No  (negative)
isPalindrome(121)    → Yes
isPalindrome(10)     → No  (01 != 10)
```

### Optimization (Half Comparison)

```cpp
bool isPalindrome(int n) {
    if (n < 0 || (n % 10 == 0 && n != 0)) return false;
    int reversed = 0;
    while (n > reversed) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return n == reversed || n == reversed / 10;
}
// Only reverse half the digits
```

---

## 4. Armstrong Number

### Problem Statement

Check if a 3-digit number is an Armstrong number (sum of cubes of its digits equals the number itself).

Example: 153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ✓

### Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int original = n;
    int sum = 0;
    while (n > 0)
    {
        int lastDigit = n % 10;
        sum = sum + lastDigit * lastDigit * lastDigit;
        n = n / 10;
    }
    cout << (original == sum ? "Yes" : "No") << endl;
    return 0;
}
```

### Approach

1. Store original number
2. Extract each digit using modulo 10
3. Cube the digit and add to sum
4. Remove last digit by dividing by 10
5. Compare sum with original number

### Complexity Analysis

- **Time Complexity**: O(d) - Where d is number of digits (O(1) for 3-digit)
- **Space Complexity**: O(1) - Only using variables

### Dry Run (n = 153)

```
n = 153
original = 153
sum = 0

Iteration 1:
    lastDigit = 153 % 10 = 3
    sum = 0 + 3³ = 0 + 27 = 27
    n = 153 / 10 = 15

Iteration 2:
    lastDigit = 15 % 10 = 5
    sum = 27 + 5³ = 27 + 125 = 152
    n = 15 / 10 = 1

Iteration 3:
    lastDigit = 1 % 10 = 1
    sum = 152 + 1³ = 152 + 1 = 153
    n = 1 / 10 = 0

Compare: original (153) == sum (153) ✓
Result: Yes (Armstrong Number)

Visual:
153 = 1³ + 5³ + 3³
    = 1  + 125 + 27
    = 153 ✓

Breakdown:
  1³ = 1 × 1 × 1 = 1
  5³ = 5 × 5 × 5 = 125
  3³ = 3 × 3 × 3 = 27
  Sum = 1 + 125 + 27 = 153
```

### Dry Run (n = 123)

```
n = 123
original = 123
sum = 0

Iteration 1: lastDigit = 3, sum = 27, n = 12
Iteration 2: lastDigit = 2, sum = 27 + 8 = 35, n = 1
Iteration 3: lastDigit = 1, sum = 35 + 1 = 36, n = 0

Compare: 123 != 36 ✗
Result: No (Not an Armstrong Number)

Visual:
123 ≟ 1³ + 2³ + 3³
    ≟ 1  + 8  + 27
    ≟ 36
123 ≠ 36 ✗
```

### Armstrong Numbers (3-digit)

```
153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ✓
370 = 3³ + 7³ + 0³ = 27 + 343 + 0 = 370 ✓
371 = 3³ + 7³ + 1³ = 27 + 343 + 1 = 371 ✓
407 = 4³ + 0³ + 7³ = 64 + 0 + 343 = 407 ✓
```

### Generalized Armstrong (n-digit)

```cpp
// For any number of digits
bool isArmstrong(int n) {
    int original = n;
    int digits = to_string(n).length();
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += pow(digit, digits);
        n /= 10;
    }
    return original == sum;
}
```

---

## 5. Prime Number Check

### Problem Statement

Determine if a given number is prime (divisible only by 1 and itself).

### Code

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n <= 1)
    {
        cout << "No" << endl;
        return 0;
    }
    bool isPrime = true;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    cout << (isPrime ? "Yes" : "No") << endl;
    return 0;
}
```

### Approach

1. **Base Cases**: Numbers ≤ 1 are not prime
2. **Optimization**: Only check divisors up to √n
3. Check if n is divisible by any number from 2 to √n
4. If divisible → composite (not prime)
5. If no divisor found → prime

### Why Check Only Up to √n?

```
If n = a × b, then:
- Either a ≤ √n or b ≤ √n
- If a > √n and b > √n, then a × b > n (contradiction)
- So we only need to check up to √n

Example: n = 36
√36 = 6
Factors: (1,36), (2,18), (3,12), (4,9), (6,6)
All factor pairs have at least one element ≤ 6
```

### Complexity Analysis

- **Time Complexity**: O(√n) - Check divisors up to square root
- **Space Complexity**: O(1) - Only using boolean flag

### Dry Run (n = 17)

```
n = 17
isPrime = true

Check i = 2: 2² = 4 ≤ 17
             17 % 2 = 1 (not divisible)

Check i = 3: 3² = 9 ≤ 17
             17 % 3 = 2 (not divisible)

Check i = 4: 4² = 16 ≤ 17
             17 % 4 = 1 (not divisible)

Check i = 5: 5² = 25 > 17
             Stop loop

No divisor found → isPrime remains true
Result: Yes (17 is Prime)

Visual:
17 ÷ 2 = 8.5  ✗
17 ÷ 3 = 5.67 ✗
17 ÷ 4 = 4.25 ✗
√17 ≈ 4.12, stop checking
→ PRIME ✓
```

### Dry Run (n = 15)

```
n = 15
isPrime = true

Check i = 2: 15 % 2 = 1 (not divisible)
Check i = 3: 15 % 3 = 0 (divisible!) ✗
             isPrime = false
             break

Result: No (15 is not Prime)

Visual:
15 = 3 × 5
Found divisor 3
→ COMPOSITE ✗
```

### Prime Numbers (First 20)

```
2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
31, 37, 41, 43, 47, 53, 59, 61, 67, 71
```

### Edge Cases

```cpp
isPrime(0)  → No (not prime)
isPrime(1)  → No (not prime by convention)
isPrime(2)  → Yes (smallest prime)
isPrime(4)  → No (2 × 2)
```

### Further Optimization

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;  // Check even numbers

    // Only check odd numbers from 3
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
// Reduces checks by half
```

---

## 6. GCD - Brute Force

### Problem Statement

Find the Greatest Common Divisor (GCD) of two numbers using brute force approach.

### Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    int start = a < b ? a : b;
    int gcd = 1;
    for (int i = start; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break;
        }
    }
    cout << gcd << endl;
    return 0;
}
```

### Approach

1. Handle edge cases (zeros, negatives)
2. Start from min(a, b) and go downwards
3. Check if current number divides both a and b
4. First such number is the GCD (largest)
5. Break immediately when found

### Complexity Analysis

- **Time Complexity**: O(min(a, b)) - Worst case check all numbers
- **Space Complexity**: O(1) - Only using variables

### Dry Run (a = 48, b = 18)

```
a = 48, b = 18
start = min(48, 18) = 18
gcd = 1

Check i = 18:
    48 % 18 = 12 (not zero) ✗

Check i = 17:
    48 % 17 = 14 (not zero) ✗

...skipping non-divisors...

Check i = 6:
    48 % 6 = 0 ✓
    18 % 6 = 0 ✓
    Both divisible!
    gcd = 6
    break

Result: 6

Visual:
Factors of 48: 1, 2, 3, 4, 6, 8, 12, 16, 24, 48
Factors of 18: 1, 2, 3, 6, 9, 18
                           ↑
Common factors: 1, 2, 3, 6
Greatest: 6
```

### Dry Run (a = 14, b = 28)

```
a = 14, b = 28
start = 14

Check i = 14:
    14 % 14 = 0 ✓
    28 % 14 = 0 ✓
    gcd = 14
    break

Result: 14

Visual:
14 = 14 × 1
28 = 14 × 2
GCD = 14
```

### Edge Cases

```cpp
gcd(0, 0)   → 0  (undefined, but returns 0)
gcd(0, 5)   → 5  (gcd(0, n) = n)
gcd(12, 12) → 12 (gcd(n, n) = n)
gcd(1, 100) → 1  (coprime)
```

### Why Brute Force is Inefficient

```
For large numbers like gcd(1000000, 999999)
- Need to check from 999999 down
- Very slow for large inputs
- Better approach: Euclidean algorithm
```

---

## 7. GCD - Euclidean Algorithm

### Problem Statement

Find GCD using the efficient Euclidean algorithm based on the principle: gcd(a, b) = gcd(b, a mod b)

### Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    cout << a << endl;
    return 0;
}
```

### Approach

1. **Key Principle**: gcd(a, b) = gcd(b, a mod b)
2. Repeatedly replace (a, b) with (b, a mod b)
3. Continue until b becomes 0
4. When b = 0, a contains the GCD

### Why It Works

```
If d divides both a and b:
- Then d divides (a - k×b) for any integer k
- So d divides a mod b
- Therefore: divisors of (a, b) = divisors of (b, a mod b)
- And: gcd(a, b) = gcd(b, a mod b)
```

### Complexity Analysis

- **Time Complexity**: O(log(min(a, b))) - Much faster than brute force
- **Space Complexity**: O(1) - Only using variables

### Dry Run (a = 48, b = 18)

```
a = 48, b = 18

Iteration 1:
    temp = 18
    b = 48 % 18 = 12
    a = 18
    State: (18, 12)

Iteration 2:
    temp = 12
    b = 18 % 12 = 6
    a = 12
    State: (12, 6)

Iteration 3:
    temp = 6
    b = 12 % 6 = 0
    a = 6
    State: (6, 0)

b = 0, loop ends
Result: a = 6

Visual Step-by-Step:
gcd(48, 18)
= gcd(18, 48 % 18)
= gcd(18, 12)
= gcd(12, 18 % 12)
= gcd(12, 6)
= gcd(6, 12 % 6)
= gcd(6, 0)
= 6
```

### Dry Run (a = 100, b = 35)

```
a = 100, b = 35

Iteration 1: (100, 35) → (35, 30)  [100 % 35 = 30]
Iteration 2: (35, 30)  → (30, 5)   [35 % 30 = 5]
Iteration 3: (30, 5)   → (5, 0)    [30 % 5 = 0]

Result: 5

Visual:
gcd(100, 35) = gcd(35, 30) = gcd(30, 5) = gcd(5, 0) = 5
```

### Comparison: Brute Force vs Euclidean

```
For gcd(1000000, 999999):

Brute Force:
- Check from 999999 down to 1
- Could take up to 999999 operations
- Time: O(min(a, b))

Euclidean:
- Only ~30 iterations
- Time: O(log(min(a, b)))
- Much faster!
```

### Recursive Version

```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
```

### LCM Using GCD

```cpp
// LCM(a, b) = (a × b) / GCD(a, b)
long long lcm(int a, int b) {
    return (long long)a * b / gcd(a, b);
}
```

---

## 8. Sieve of Eratosthenes - Count Primes

### Problem Statement

Count the number of prime numbers less than or equal to n using the Sieve of Eratosthenes algorithm.

### Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 2)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
```

### Approach

1. Create boolean array of size n+1, initialize all as true
2. Mark 0 and 1 as not prime
3. For each prime i from 2 to √n:
   - Mark all multiples of i starting from i² as not prime
4. Count remaining true values (primes)

### Why Start from i²?

```
For i = 5:
- 5×2 = 10 (already marked by 2)
- 5×3 = 15 (already marked by 3)
- 5×4 = 20 (already marked by 2)
- 5×5 = 25 (first unmarked multiple)

All multiples < i² are already marked by smaller primes
```

### Complexity Analysis

- **Time Complexity**: O(n log log n) - Very efficient for finding multiple primes
- **Space Complexity**: O(n) - Boolean array

### Dry Run (n = 20)

```
Initial array (indices 0-20):
isPrime: [F, F, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T]
          0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

Step 1: i = 2 (prime)
        Mark multiples: 4, 6, 8, 10, 12, 14, 16, 18, 20
isPrime: [F, F, T, T, F, T, F, T, F, T, F, T, F, T, F, T, F, T, F, T, F]

Step 2: i = 3 (prime)
        Mark multiples: 9, 15 (others already marked)
isPrime: [F, F, T, T, F, T, F, T, F, F, F, T, F, T, F, F, F, T, F, T, F]

Step 3: i = 4 (not prime, skip)

Step 4: i = 5 > √20, stop outer loop

Count primes: 2, 3, 5, 7, 11, 13, 17, 19
Result: 8 primes

Visual:
Numbers: 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
Prime:   ✓  ✓  ✗  ✓  ✗  ✓  ✗  ✗  ✗  ✓  ✗  ✓  ✗  ✗  ✗  ✓  ✗  ✓  ✗

Marking process:
2: X X X X X X X X X (mark 4,6,8,10,12,14,16,18,20)
3:       X     X   X (mark 9,15)
5: (5² = 25 > 20, done)
```

### Detailed Marking for i = 2

```
i = 2, start from j = 2² = 4
Mark: 4, 6, 8, 10, 12, 14, 16, 18, 20
      (all even numbers except 2)

2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20
✓  ✓  ✗  ✓  ✗  ✓  ✗  ?  ✗  ✓  ✗  ✓  ✗  ?  ✗  ✓  ✗  ✓  ✗
```

### Why Sieve is Better Than Individual Checks

```
To find all primes up to n:

Individual checks: O(n × √n)
- Check each number: O(n)
- Each check takes: O(√n)

Sieve: O(n log log n)
- Much faster for large n
- Example: n = 1000000
  - Individual: ~1 billion operations
  - Sieve: ~10 million operations
```

---

## 9. Sieve of Eratosthenes - List Primes

### Problem Statement

List all prime numbers less than or equal to n using the Sieve of Eratosthenes.

### Code

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 2)
    {
        return 0;
    }
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}
```

### Approach

Same as count primes, but print each prime instead of counting.

### Complexity Analysis

- **Time Complexity**: O(n log log n) - Sieve algorithm
- **Space Complexity**: O(n) - Boolean array

### Dry Run (n = 30)

```
After sieving process:
isPrime array shows: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 are prime

Output: 2 3 5 7 11 13 17 19 23 29

Visual marking process:
Numbers: 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
After 2: ✓  ✓  ✗  ✓  ✗  ✓  ✗  ?  ✗  ✓  ✗  ✓  ✗  ?  ✗  ✓  ✗  ✓  ✗  ?  ✗  ✓  ✗  ?  ✗  ?  ✗  ✓  ✗
After 3: ✓  ✓  ✗  ✓  ✗  ✓  ✗  ✗  ✗  ✓  ✗  ✓  ✗  ✗  ✗  ✓  ✗  ✓  ✗  ✗  ✗  ✓  ✗  ?  ✗  ✗  ✗  ✓  ✗
After 5: ✓  ✓  ✗  ✓  ✗  ✓  ✗  ✗  ✗  ✓  ✗  ✓  ✗  ✗  ✗  ✓  ✗  ✓  ✗  ✗  ✗  ✓  ✗  ✗  ✗  ✗  ✗  ✓  ✗

Primes found: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
```

### Prime Distribution

```
Range       Primes
0-10:       2, 3, 5, 7
11-20:      11, 13, 17, 19
21-30:      23, 29
31-40:      31, 37
41-50:      41, 43, 47

Note: Primes become less frequent as numbers grow
      (Prime Number Theorem)
```

---

## 10. Largest Digit

### Problem Statement

Find the largest digit in a given number.

### Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n < 0)
    {
        n = -n;
    }
    int largest = 0;
    if (n == 0)
    {
        largest = 0;
    }
    while (n > 0)
    {
        int lastDigit = (int)(n % 10);
        if (lastDigit > largest)
        {
            largest = lastDigit;
        }
        n = n / 10;
    }
    cout << largest << endl;
    return 0;
}
```

### Approach

1. Handle negative numbers (work with absolute value)
2. Initialize largest = 0
3. Extract each digit using modulo 10
4. Update largest if current digit is greater
5. Remove last digit by dividing by 10

### Complexity Analysis

- **Time Complexity**: O(log₁₀ n) - Process each digit
- **Space Complexity**: O(1) - Only tracking largest

### Dry Run (n = 54729)

```
n = 54729
largest = 0

Iteration 1:
    lastDigit = 54729 % 10 = 9
    9 > 0 → largest = 9
    n = 5472

Iteration 2:
    lastDigit = 5472 % 10 = 2
    2 < 9 → largest stays 9
    n = 547

Iteration 3:
    lastDigit = 547 % 10 = 7
    7 < 9 → largest stays 9
    n = 54

Iteration 4:
    lastDigit = 54 % 10 = 4
    4 < 9 → largest stays 9
    n = 5

Iteration 5:
    lastDigit = 5 % 10 = 5
    5 < 9 → largest stays 9
    n = 0

Result: 9

Visual:
5  4  7  2  9
         ↑
      largest = 9
```

### Dry Run (n = 1234)

```
Digits: 4, 3, 2, 1
Checking: 4 > 0 → largest = 4
          3 < 4 → largest = 4
          2 < 4 → largest = 4
          1 < 4 → largest = 4

Result: 4
```

### Edge Cases

```cpp
largestDigit(0)      → 0
largestDigit(9)      → 9
largestDigit(-123)   → 3
largestDigit(11111)  → 1
largestDigit(90125)  → 9
```

### Optimization (Early Exit)

```cpp
int largestDigit(int n) {
    if (n < 0) n = -n;
    int largest = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit == 9) return 9;  // Can't be larger
        if (digit > largest) largest = digit;
        n /= 10;
    }
    return largest;
}
```

---

## 11. Factorial

### Problem Statement

Calculate the factorial of a non-negative integer (n! = n × (n-1) × ... × 2 × 1).

### Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 0)
    {
        cout << -1 << endl; // undefined for negative integers
        return 0;
    }
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial = factorial * i;
    }
    cout << factorial << endl;
    return 0;
}
```

### Approach

1. Handle negative input (factorial undefined)
2. Initialize factorial = 1
3. Multiply by each number from 1 to n
4. Use `unsigned long long` for larger values

### Complexity Analysis

- **Time Complexity**: O(n) - Multiply n times
- **Space Complexity**: O(1) - Only using one variable

### Dry Run (n = 5)

```
n = 5
factorial = 1

Iteration 1: i = 1
    factorial = 1 × 1 = 1

Iteration 2: i = 2
    factorial = 1 × 2 = 2

Iteration 3: i = 3
    factorial = 2 × 3 = 6

Iteration 4: i = 4
    factorial = 6 × 4 = 24

Iteration 5: i = 5
    factorial = 24 × 5 = 120

Result: 120

Visual:
5! = 5 × 4 × 3 × 2 × 1
   = 5 × 4!
   = 5 × 24
   = 120

Building process:
1 → 1 → 2 → 6 → 24 → 120
    ×1  ×2  ×3   ×4    ×5
```

### Factorial Values

```
0! = 1    (by definition)
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120
6! = 720
7! = 5,040
8! = 40,320
9! = 362,880
10! = 3,628,800
20! = 2,432,902,008,176,640,000
```

### Overflow Warning

```
Factorials grow very quickly!
- 20! is near the limit of unsigned long long
- 21! causes overflow
- For larger n, use:
  - BigInteger libraries
  - Modular arithmetic
  - Logarithms (for counting digits)
```

### Recursive Version

```cpp
unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

---

## 12. Perfect Number

### Problem Statement

A perfect number equals the sum of its proper divisors (divisors excluding the number itself).
Example: 6 = 1 + 2 + 3

### Code

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 1)
    {
        cout << "No" << endl;
        return 0;
    }
    int sum = 1;  // 1 is always a divisor
    for (int i = 2; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += i;
            int other = n / i;
            if (other != i)  // Avoid counting same divisor twice
            {
                sum += other;
            }
        }
    }
    cout << (sum == n ? "Yes" : "No") << endl;
    return 0;
}
```

### Approach

1. **Optimization**: Check divisors only up to √n
2. For each divisor i found, also add n/i (complementary divisor)
3. Start sum with 1 (always a proper divisor)
4. Avoid adding n itself or counting √n twice
5. Compare sum with n

### Why Check Up to √n?

```
For n = 36:
- Divisors come in pairs: (1,36), (2,18), (3,12), (4,9), (6,6)
- When i = 6, we find (6, 6) - only add once
- For i < √n, we find both i and n/i
- Efficient: O(√n) instead of O(n)
```

### Complexity Analysis

- **Time Complexity**: O(√n) - Check up to square root
- **Space Complexity**: O(1) - Only sum variable

### Dry Run (n = 6)

```
n = 6
sum = 1  (1 is always a divisor)

Check i = 2:
    6 % 2 = 0 ✓ (divisible)
    sum += 2 → sum = 3
    other = 6 / 2 = 3
    3 ≠ 2, so sum += 3 → sum = 6

i = 3: 3² = 9 > 6, stop loop

Compare: sum (6) == n (6) ✓
Result: Yes (Perfect Number)

Visual:
Divisors of 6: 1, 2, 3, 6
Proper divisors (excluding 6): 1, 2, 3
Sum: 1 + 2 + 3 = 6 = n ✓
```

### Dry Run (n = 28)

```
n = 28
sum = 1

Check i = 2:
    28 % 2 = 0 ✓
    sum += 2 → sum = 3
    other = 28 / 2 = 14
    sum += 14 → sum = 17

Check i = 4:
    28 % 4 = 0 ✓
    sum += 4 → sum = 21
    other = 28 / 4 = 7
    sum += 7 → sum = 28

i = 6: 6² = 36 > 28, stop

Compare: sum (28) == n (28) ✓
Result: Yes (Perfect Number)

Visual:
Divisors of 28: 1, 2, 4, 7, 14, 28
Proper divisors: 1, 2, 4, 7, 14
Sum: 1 + 2 + 4 + 7 + 14 = 28 ✓
```

### Dry Run (n = 12)

```
n = 12
sum = 1

i = 2: sum = 1 + 2 + 6 = 9
i = 3: sum = 9 + 3 + 4 = 16

Compare: 16 ≠ 12 ✗
Result: No

Proper divisors of 12: 1, 2, 3, 4, 6
Sum: 1 + 2 + 3 + 4 + 6 = 16 ≠ 12
```

### Perfect Numbers

```
First few perfect numbers:
6 = 1 + 2 + 3
28 = 1 + 2 + 4 + 7 + 14
496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248
8128 = 1 + 2 + 4 + 8 + 16 + 32 + 64 + 127 + 254 + 508 + 1016 + 2032 + 4064

They are extremely rare!
Only 51 known perfect numbers (as of 2024)
```

### Avoiding Double Count for Perfect Square

```
For n = 36:
When i = 6:
    36 % 6 = 0
    other = 36 / 6 = 6
    i == other (both are 6)
    Only add once: sum += 6
    Don't add: sum += other (would be duplicate)
```

---

## Mathematical Techniques Summary

### 1. Digit Manipulation

- **Extract Last Digit**: `n % 10`
- **Remove Last Digit**: `n / 10`
- **Build Number**: `result = result * 10 + digit`
- **Count Digits**: O(log₁₀ n) iterations

### 2. Divisibility Checking

- **Check Prime**: Test divisors up to √n
- **Find GCD**: Euclidean algorithm
- **Find Divisors**: Check up to √n, add pairs

### 3. Optimization Patterns

- **Early Exit**: Return immediately when answer found
- **√n Limit**: Many problems only need checking up to square root
- **Sieve**: Precompute for multiple queries

### 4. Number Properties

- **Even/Odd**: `n % 2`
- **Perfect Square**: `i * i == n`
- **Powers**: `a^b` using repeated multiplication or exponentiation

---

## Common Problem Patterns

### Pattern 1: Digit Processing

- Count digits
- Reverse number
- Sum of digits
- Armstrong number
- **Approach**: Extract using mod, remove using division

### Pattern 2: Prime-Related

- Check prime
- List primes
- Count primes
- **Approach**: Trial division or Sieve

### Pattern 3: Divisor-Based

- GCD/LCM
- Perfect numbers
- Factor counting
- **Approach**: Check up to √n

### Pattern 4: Mathematical Properties

- Factorial
- Palindrome
- Perfect power
- **Approach**: Apply definition directly

---

## Complexity Comparison

| Operation             | Naive       | Optimized       |
| --------------------- | ----------- | --------------- |
| Count Digits          | O(log n)    | O(1) with log₁₀ |
| Prime Check           | O(n)        | O(√n)           |
| GCD                   | O(min(a,b)) | O(log min(a,b)) |
| List Primes (up to n) | O(n²)       | O(n log log n)  |
| Find Divisors         | O(n)        | O(√n)           |

---

## Optimization Tips

### 1. Use Appropriate Data Types

```cpp
// For large factorials
unsigned long long factorial;

// For counting
int count;

// For large inputs
long long n;
```

### 2. Early Termination

```cpp
// Stop when answer is found
if (found) break;

// Largest digit can't exceed 9
if (digit == 9) return 9;
```

### 3. Mathematical Insights

```cpp
// Only check odd numbers after 2
for (int i = 3; i <= sqrt(n); i += 2)

// Start from i*i in sieve
for (int j = i * i; j <= n; j += i)
```

### 4. Avoid Redundant Computations

```cpp
// Precompute sqrt
int sqrtN = sqrt(n);
for (int i = 2; i <= sqrtN; i++)
```

---

## Common Pitfalls

### 1. Integer Overflow

```cpp
// Factorial grows quickly!
// Use unsigned long long or check overflow
unsigned long long factorial = 1;
```

### 2. Edge Cases

```cpp
// Zero, negative numbers, single digit
if (n == 0) return 1;  // 0 has 1 digit
if (n < 0) n = -n;     // Handle negatives
```

### 3. Off-by-One Errors

```cpp
// Include or exclude boundary?
for (int i = 2; i <= n; i++)  // Include n
for (int i = 2; i < n; i++)   // Exclude n
```

### 4. Division by Zero

```cpp
// Check before dividing
if (b != 0) a = a / b;
```

---

## Practice Tips

1. **Master Digit Extraction**

   - Practice with mod and division
   - Understand building numbers

2. **Understand Prime Algorithms**

   - Know why √n optimization works
   - When to use Sieve vs individual checks

3. **Learn GCD Thoroughly**

   - Euclidean algorithm is fundamental
   - Used in many advanced problems

4. **Handle Edge Cases**

   - Zero, negative, single digit
   - Very large numbers (overflow)

5. **Complexity Analysis**
   - Always analyze time/space
   - Know when optimization matters

---

## Interview Tips

### Common Questions

- "Why check only up to √n?"
- "What's the time complexity of Sieve?"
- "How does Euclidean GCD work?"
- "What's the largest factorial you can compute?"

### Best Practices

- Explain your approach before coding
- Discuss optimizations
- Handle edge cases explicitly
- Analyze complexity

---

## Conclusion

Mathematical operations are fundamental to computer science and competitive programming. Master these concepts:

- **Digit manipulation** for number processing
- **Prime algorithms** for number theory
- **GCD/LCM** for divisibility problems
- **Optimization techniques** like √n and Sieve

**Key Takeaways:**

- Always consider edge cases (0, negatives, overflow)
- Use mathematical insights for optimization
- Understand why algorithms work, not just how
- Practice complexity analysis
- Choose right data types for the problem

Happy Coding! 🚀

---

**File Location**: `/dsa/Basic/math/`

**Last Updated**: October 3, 2025
