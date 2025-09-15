## Math and Number Theory Toolkit (C++)

This folder is a concise, practical guide to classic number problems implemented in C++. Each concept has:

- Clear problem statement and intuition
- Pseudocode and time/space complexity
- Edge cases and examples
- A standalone C++ program with `main()`

### Quick Setup (macOS)

Use either `clang++` (default) or Homebrew `g++`.

```
clang++ -std=c++17 file.cpp -o bin && ./bin
```

To install GNU g++ (optional): `brew install gcc`

### Program Index

- `count_digits.cpp`: Count digits of an integer
- `reverse_number.cpp`: Reverse digits (preserve sign)
- `palindrome_number.cpp`: Palindrome check (non-negative)
- `largest_digit.cpp`: Largest digit in an integer
- `factorial.cpp`: Iterative factorial (n ≥ 0)
- `armstrong.cpp`: 3-digit Armstrong number check
- `perfect_number.cpp`: Perfect number test in O(√n)
- `prime_check.cpp`: Primality test in O(√n)
- `sieve_list_primes.cpp`: List primes up to n (Sieve)
- `sieve_count_primes.cpp`: Count primes up to n (Sieve)
- `gcd_bruteforce.cpp`: GCD by descending search
- `gcd_euclid.cpp`: GCD by Euclidean algorithm
- `basic.cpp`: Stub note (historical multi-main migrated into files above)

---

## Concepts and Explanations

### 1) Count number of digits

Goal: Print number of decimal digits of integer n.

Pseudocode:

```
if n == 0: return 1
if n < 0: n = -n
count = 0
while n > 0:
  n = n / 10
  count++
return count
```

Complexity: O(d), d = digits.
Edge cases: n = 0 → 1; negatives handled via abs.
File: `count_digits.cpp`

Example:

```
Input: 50200
Output: 5
```

---

### 2) Reverse a number

Goal: Reverse digits (retain sign).

Pseudocode:

```
neg = (n < 0)
n = abs(n)
rev = 0
while n > 0:
  rev = rev * 10 + (n % 10)
  n = n / 10
print -rev if neg else rev
```

Complexity: O(d).
Edge cases: -120 → -21; watch overflow (using 64-bit here).
File: `reverse_number.cpp`

---

### 3) Palindrome number

Goal: Check if non-negative n reads same forward/backward.

Approach: Reverse and compare to original.
Complexity: O(d).
Edge cases: Negative → No; 0 → Yes.
File: `palindrome_number.cpp`

---

### 4) Largest digit

Goal: Max digit among decimal digits of n.

Approach: Scan digits, track max.
Complexity: O(d).
Edge cases: n = 0 → 0; negatives → abs.
File: `largest_digit.cpp`

---

### 5) Factorial (iterative)

Goal: Compute n! with a loop.

Notes:

- Use `unsigned long long` (exact up to 20!)
- For n < 0, prints -1 (undefined in integers)
  Complexity: O(n). Space: O(1).
  File: `factorial.cpp`

---

### 6) Armstrong number (3-digit)

Definition: Sum of cubes of digits equals number (e.g., 153 = 1^3 + 5^3 + 3^3).

Complexity: O(d) (here d=3). Space: O(1).
File: `armstrong.cpp`

---

### 7) Perfect number

Definition: Sum of proper divisors equals n (e.g., 28 → 1+2+4+7+14).

Pseudocode:

```
if n <= 1: return No
sum = 1
for i in 2..floor(sqrt(n)):
  if n % i == 0:
    sum += i
    if i != n/i: sum += n/i
return Yes if sum == n else No
```

Complexity: O(√n). Space: O(1).
File: `perfect_number.cpp`

---

### 8) Prime check (trial division)

Rule: If any i in [2..√n] divides n, then composite; else prime.

Complexity: O(√n). Space: O(1).
Edge cases: n ≤ 1 → No.
File: `prime_check.cpp`

---

### 9) Sieve of Eratosthenes (list primes)

Idea: Start with all true; for each prime i, mark multiples j = i*i, i*i+i, ... as false.

ASCII visual for n = 30:

```
Index:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
isPrime: F  F  T  T  F  T  F  T  F  F  F  T  F  T  F  F  F  T  F  T  F  F  F  T  F  F  F  F  F  T  F
```

Why start from i*i? Smaller multiples already crossed by earlier primes.
Stop at i*i ≤ n.

Complexity: O(n log log n). Space: O(n).
File: `sieve_list_primes.cpp`

---

### 10) Count primes up to n (sieve)

Same sieve; instead of printing primes, count them.

Complexity: O(n log log n). Space: O(n).
File: `sieve_count_primes.cpp`

---

### 11) GCD (brute force)

Method: from min(a,b) down to 1; first common divisor is the GCD.

Complexity: O(min(a,b)). Space: O(1).
Use only for small numbers.
File: `gcd_bruteforce.cpp`

---

### 12) GCD (Euclidean algorithm)

Identity: gcd(a,b) = gcd(b, a mod b); repeat until b = 0.

Walkthrough (48,18):

```
48 % 18 = 12 → (18,12)
18 % 12 = 6  → (12,6)
12 % 6  = 0  → (6,0) ⇒ gcd = 6
```

Complexity: ~O(log min(a,b)). Space: O(1).
File: `gcd_euclid.cpp`

---

## Build and Run

Compile and run one (example: prime check):

```
clang++ -std=c++17 prime_check.cpp -o prime_check
echo 97 | ./prime_check
```

Compile all in one go:

```
clang++ -std=c++17 count_digits.cpp -o count_digits && \
clang++ -std=c++17 reverse_number.cpp -o reverse_number && \
clang++ -std=c++17 palindrome_number.cpp -o palindrome_number && \
clang++ -std=c++17 largest_digit.cpp -o largest_digit && \
clang++ -std=c++17 factorial.cpp -o factorial && \
clang++ -std=c++17 armstrong.cpp -o armstrong && \
clang++ -std=c++17 perfect_number.cpp -o perfect_number && \
clang++ -std=c++17 prime_check.cpp -o prime_check && \
clang++ -std=c++17 sieve_list_primes.cpp -o sieve_list_primes && \
clang++ -std=c++17 sieve_count_primes.cpp -o sieve_count_primes && \
clang++ -std=c++17 gcd_bruteforce.cpp -o gcd_bruteforce && \
clang++ -std=c++17 gcd_euclid.cpp -o gcd_euclid
```

---

## Pitfalls and Tips

- Use 64-bit integers (`long long`/`unsigned long long`) where needed.
- Palindrome and reverse: treat negatives explicitly.
- Sieve: remember `isPrime[0] = isPrime[1] = false`.
- Perfect numbers: avoid double-adding when i\*i == n.
- Prefer Euclid’s GCD for performance; brute force is only for tiny inputs.
