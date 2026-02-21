# 🔢 Count Pairs with Modular Condition

## 📋 Problem Statement

Given an array `A` of `N` **distinct** elements, a **prime number** `P`, and an integer `K`, find the number of pairs of indices `(i, j)` such that:

- `1 ≤ i < j ≤ N`
- `(A[i] + A[j]) × (A[i]² + A[j]²) ≡ K (mod P)`

### Constraints

| Variable  | Range                 |
| --------- | --------------------- |
| `N`       | `2 ≤ N ≤ 10⁵`         |
| `K, A[i]` | `0 ≤ K, A[i] ≤ P − 1` |
| `P`       | `2 ≤ P ≤ 10⁵` (prime) |

---

## 🐢 Approach 1 — Brute Force `O(N²)`

### 💡 Intuition

The simplest approach: iterate over **every pair** `(i, j)` where `i < j`, compute the expression `(A[i] + A[j]) × (A[i]² + A[j]²)`, take `mod P`, and check if it equals `K`.

### 🧩 Strategy

```
1. For each i from 0 to N-2:
     For each j from i+1 to N-1:
       Compute val = (A[i] + A[j]) * (A[i]^2 + A[j]^2) mod P
       If val == K, increment count
2. Return count
```

### ⚠️ Modular Arithmetic Pitfall

Since `A[i]` can be up to `P - 1 ≈ 10⁵`, the intermediate product `A[i]² + A[j]²` can be as large as `~2 × 10¹⁰`, and the full product can reach `~2 × 10¹⁵`. This **overflows** a 32-bit integer. We must use `long long` and take `mod P` at **every** multiplication step.

### 💻 Code — Brute Force

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, P, K;
    cin >> N >> P >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    long long count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Compute (A[i] + A[j]) mod P
            long long sum = (A[i] + A[j]) % P;

            // Compute (A[i]^2 + A[j]^2) mod P
            long long sq_sum = ((A[i] % P) * (A[i] % P) % P
                             +  (A[j] % P) * (A[j] % P) % P) % P;

            // Compute product mod P
            long long val = (sum * sq_sum) % P;

            if (val == K) count++;
        }
    }

    cout << count << endl;
    return 0;
}
```

### 🔍 Dry Run — Brute Force

**Input:** `N = 4, P = 5, K = 2, A = [0, 1, 2, 3]`

| Pair (i, j) | A[i] | A[j] | A[i]+A[j] | A[i]²+A[j]² | Product | mod 5 | == K? |
| ----------- | ---- | ---- | --------- | ----------- | ------- | ----- | ----- |
| (0, 1)      | 0    | 1    | 1         | 1           | 1       | **1** | ❌    |
| (0, 2)      | 0    | 2    | 2         | 4           | 8       | **3** | ❌    |
| (0, 3)      | 0    | 3    | 3         | 9           | 27      | **2** | ✅    |
| (1, 2)      | 1    | 2    | 3         | 5           | 15      | **0** | ❌    |
| (1, 3)      | 1    | 3    | 4         | 10          | 40      | **0** | ❌    |
| (2, 3)      | 2    | 3    | 5         | 13          | 65      | **0** | ❌    |

**Answer:** `1` (only the pair `(0, 3)`)

### ⏱️ Complexity

|           | Complexity                                |
| --------- | ----------------------------------------- |
| **Time**  | `O(N²)` — two nested loops over all pairs |
| **Space** | `O(N)` — storing the array                |

> ⛔ **Verdict:** With `N = 10⁵`, this gives `~5 × 10⁹` operations → **TLE (Time Limit Exceeded)**

---

## 🚀 Approach 2 — Optimal `O(N)`

### 💡 The Key Mathematical Insight

This is where the magic happens. Let's denote `a = A[i]` and `b = A[j]`. We need:

```
(a + b)(a² + b²) ≡ K (mod P)
```

**Trick:** Multiply both sides by `(a - b)`:

```
(a - b)(a + b)(a² + b²) ≡ K·(a - b) (mod P)
```

Now observe the left side:

```
(a - b)(a + b) = a² - b²       ... difference of squares
(a² - b²)(a² + b²) = a⁴ - b⁴  ... difference of squares again!
```

So we get:

```
a⁴ - b⁴ ≡ K·(a - b) (mod P)
```

Rearranging:

```
a⁴ - K·a ≡ b⁴ - K·b (mod P)
```

### 🔐 Why Is Multiplying by `(a - b)` Valid?

This is the crucial step that makes or breaks the proof. We multiplied both sides by `(a - b)`. This is a **reversible operation** (i.e., an "if and only if" equivalence) **because:**

1. **Elements are distinct:** `a ≠ b`, so `a - b ≠ 0`
2. **P is prime:** Since `0 < |a - b| < P` and `P` is prime, `gcd(a - b, P) = 1`
3. Therefore `(a - b)` has a **modular inverse** mod `P`
4. Multiplying by `(a - b)` is equivalent to multiplying by an invertible element → **no information is lost**

> 💎 If `P` were not prime, `(a - b)` could share a factor with `P`, and multiplying would **destroy** solutions. The primality of `P` is essential!

### 🏗️ Strategy

Define a function:

```
f(x) = (x⁴ - K·x) mod P
```

Then the condition `(a + b)(a² + b²) ≡ K (mod P)` is equivalent to:

```
f(a) ≡ f(b) (mod P)
```

**Algorithm:**

```
1. For each element A[i], compute f(A[i]) = (A[i]⁴ − K·A[i]) mod P
2. Use a hash map to count how many elements share the same f-value
3. For each group of size c, the number of valid pairs = C(c, 2) = c·(c−1)/2
4. Sum over all groups → answer
```

### 💻 Code — Optimal

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, P, K;
    cin >> N >> P >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // Hash map: f(x) value → count of elements with that f-value
    unordered_map<long long, long long> freq;

    for (int i = 0; i < N; i++) {
        long long x = A[i] % P;

        // Compute x^2 mod P
        long long x2 = (x * x) % P;

        // Compute x^4 mod P
        long long x4 = (x2 * x2) % P;

        // Compute f(x) = (x^4 - K*x) mod P
        // Add P before mod to handle negative values
        long long fx = ((x4 - (K % P) * x % P) % P + P) % P;

        freq[fx]++;
    }

    // Count pairs: for each group of size c, add C(c, 2) = c*(c-1)/2
    long long count = 0;
    for (auto& [val, c] : freq) {
        count += c * (c - 1) / 2;
    }

    cout << count << endl;
    return 0;
}
```

### 🔍 Dry Run — Optimal

**Input:** `N = 4, P = 5, K = 2, A = [0, 1, 2, 3]`

**Step 1: Compute `f(x) = (x⁴ − 2x) mod 5` for each element**

```
f(0) = (0⁴ − 2·0) mod 5 = (0 − 0) mod 5 = 0
f(1) = (1⁴ − 2·1) mod 5 = (1 − 2) mod 5 = (−1 + 5) mod 5 = 4
f(2) = (2⁴ − 2·2) mod 5 = (16 − 4) mod 5 = 12 mod 5 = 2
f(3) = (3⁴ − 2·3) mod 5 = (81 − 6) mod 5 = 75 mod 5 = 0
```

**Step 2: Build Frequency Map**

| f-value | Elements       | Count |
| ------- | -------------- | ----- |
| 0       | A[0]=0, A[3]=3 | 2     |
| 4       | A[1]=1         | 1     |
| 2       | A[2]=2         | 1     |

**Step 3: Count Pairs**

```
f-value 0 → C(2, 2) = 2 × 1 / 2 = 1
f-value 4 → C(1, 2) = 0
f-value 2 → C(1, 2) = 0
────────────────────────────────────
Total = 1
```

✅ **Answer: `1`** — matches brute force! The single valid pair is `(0, 3)`.

---

### 🧪 Dry Run — Another Example

**Input:** `N = 3, P = 5, K = 0, A = [1, 2, 3]`

**Step 1: Compute `f(x) = (x⁴ − 0·x) mod 5 = x⁴ mod 5`**

```
f(1) = 1⁴ mod 5 = 1
f(2) = 2⁴ mod 5 = 16 mod 5 = 1
f(3) = 3⁴ mod 5 = 81 mod 5 = 1
```

All three map to `f = 1`!

**Step 2: Frequency Map → {1: 3}**

**Step 3: Count Pairs → C(3, 2) = 3**

**Verification (all 3 pairs with K=0):**

| Pair  | (a+b)(a²+b²) | mod 5 |
| ----- | ------------ | ----- |
| (1,2) | 3 × 5 = 15   | 0 ✅  |
| (1,3) | 4 × 10 = 40  | 0 ✅  |
| (2,3) | 5 × 13 = 65  | 0 ✅  |

✅ All valid!

---

### ⏱️ Complexity

|           | Complexity                                                      |
| --------- | --------------------------------------------------------------- |
| **Time**  | `O(N)` — single pass to compute f-values + single pass over map |
| **Space** | `O(N)` — hash map storing at most N entries                     |

---

## 🧠 In-Depth Explanation: Why This Works

### The Algebra — Step by Step

Let's trace the full algebraic chain formally:

```
We want:  (a + b)(a² + b²) ≡ K  (mod P)   ... (1)

Multiply both sides by (a − b):

LHS = (a − b)(a + b)(a² + b²)
    = (a² − b²)(a² + b²)          ← difference of squares
    = a⁴ − b⁴                      ← difference of squares again

RHS = K(a − b)

So:       a⁴ − b⁴ ≡ K(a − b)  (mod P)
⟹        a⁴ − Ka ≡ b⁴ − Kb   (mod P)
⟹        f(a) ≡ f(b)           (mod P)     where f(x) = x⁴ − Kx
```

### Why "If and Only If"?

We went from equation `(1)` to `f(a) = f(b)` by multiplying by `(a − b)`.

- **Forward (⟹):** If `(1)` holds, then `f(a) = f(b)` holds. ✅
- **Backward (⟸):** If `f(a) = f(b)`, does `(1)` hold?
  - `f(a) = f(b)` ⟹ `a⁴ − b⁴ ≡ K(a − b) (mod P)`
  - ⟹ `(a − b)(a + b)(a² + b²) ≡ K(a − b) (mod P)`
  - Since `a ≠ b` and `P` is prime, `(a − b)` is **invertible** mod `P`
  - Multiply both sides by `(a − b)⁻¹`:
  - ⟹ `(a + b)(a² + b²) ≡ K (mod P)` ✅

Both directions work → **biconditional equivalence**.

### Visual Summary

```
                    ┌─────────────────────────────────┐
                    │    Original Condition            │
                    │  (a+b)(a²+b²) ≡ K (mod P)       │
                    └──────────────┬──────────────────┘
                                   │
                    ×(a−b)  [valid: a≠b, P prime]
                                   │
                                   ▼
                    ┌─────────────────────────────────┐
                    │    Transformed Condition         │
                    │  a⁴ − b⁴ ≡ K(a−b) (mod P)       │
                    └──────────────┬──────────────────┘
                                   │
                            rearrange terms
                                   │
                                   ▼
                    ┌─────────────────────────────────┐
                    │    Separable Form                │
                    │  a⁴ − Ka  ≡  b⁴ − Kb (mod P)    │
                    │     f(a)  ≡  f(b)     (mod P)    │
                    └──────────────┬──────────────────┘
                                   │
                         group by f-value
                                   │
                                   ▼
                    ┌─────────────────────────────────┐
                    │    Counting                      │
                    │  Hash map + C(n,2) per group     │
                    └─────────────────────────────────┘
```

### Why the Constraints Matter

| Constraint                | Why it matters                                                              |
| ------------------------- | --------------------------------------------------------------------------- |
| **P is prime**            | Ensures `(a−b)` is always invertible mod P → algebraic trick is valid       |
| **Elements are distinct** | Guarantees `a ≠ b` → `a − b ≢ 0 (mod P)`                                    |
| **0 ≤ A[i] ≤ P−1**        | Ensures `\|a − b\| < P`, so `a − b ≢ 0 (mod P)` even for modular arithmetic |

---

## 🆚 Comparison

|                      | Brute Force      | Optimal                        |
| -------------------- | ---------------- | ------------------------------ |
| **Time**             | O(N²)            | O(N)                           |
| **Space**            | O(N)             | O(N)                           |
| **Idea**             | Check every pair | Algebraic reduction + hashing  |
| **Key Insight**      | None needed      | `(a+b)(a²+b²) = (a⁴−b⁴)/(a−b)` |
| **Works for N=10⁵?** | ❌ TLE           | ✅ Fast                        |

---

## 🏷️ Tags

`#math` `#number-theory` `#modular-arithmetic` `#hashing` `#algebra` `#prime`
