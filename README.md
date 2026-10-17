# DSA Domain - Technical Task

This repository contains 4 C++ array problems and their solutions for the Data Structures and Algorithms (DSA) Technical Task. 

All 4 problems are solved using fundamental C++ concepts (arrays, `for` loops, and `if-else` statements) combined with class 11th and 12th mathematics (Permutations and Combinations, Sequence and Series, Algebraic Identities, and Modulus properties) to reduce slow nested-loop approaches into a single loop.

---

## Files in this Repository

1. `Problem1_SubarraySum.cpp` - Sum of All Possible Subarrays
2. `Problem2_MissingAndRepeating.cpp` - Find the Missing and the Repeating Number
3. `Problem3_PairwiseProductSum.cpp` - Sum of Products of All Unique Pairs in an Array
4. `Problem4_MaxAbsoluteExpression.cpp` - Maximum Value of |arr[i] - arr[j]| + |i - j|

---

## Problem Explanations & Logic

### Problem 1: Sum of All Possible Subarrays
* **Problem Statement:** Given an integer array `arr[]` of size `N`, find the total sum of elements of all possible continuous subarrays.
* **Logic & Approach:** A basic approach uses 2 or 3 nested loops to pick every starting and ending point of a subarray and add its elements, which makes the program run `N*N` or `N*N*N` times. Instead of finding each subarray one by one, we use Permutations and Combinations to count how many times each element `arr[i]` gets added to the final sum. For any subarray to contain index `i`, its starting index can be chosen from `0` to `i` (`i + 1` choices) and its ending index can be chosen from `i` to `N - 1` (`N - i` choices). By the fundamental principle of counting, `arr[i]` appears in `(i + 1) * (N - i)` subarrays. Multiplying each element by how many times it appears gives the total sum in just one loop.
* **Time & Memory Analysis:**
  * **Time Taken:** Only 1 single `for` loop is used, so the loop runs `N` times instead of `N*N` times.
  * **Memory Used:** No extra array is created. Only 2 normal variables are used to store the count and total sum.
* **Variation:** The same counting logic works to find the product of all subarrays, where each element `arr[i]` is raised to the power `(i + 1) * (N - i)`.

---

### Problem 2: Find the Missing and the Repeating Number
* **Problem Statement:** Given an array of size `N` containing numbers from `1` to `N`, one number `X` is missing and one number `Y` is repeated twice. Find `X` and `Y` without modifying the array or creating a second array.
* **Logic & Approach:** Checking each number from `1` to `N` using nested loops takes `N*N` steps, and creating another array to count frequencies uses extra memory. Instead, we use Sequence and Series formulas. First, we find the sum of array elements (`S`) and the sum of squares of array elements (`S2`) using one `for` loop.
  * Sum of first `N` natural numbers = `N(N + 1)/2`
  * Sum of squares of first `N` natural numbers = `N(N + 1)(2N + 1)/6`
  * Subtracting the expected sum from the actual sum cancels out all other numbers and gives Equation 1: `Y - X = S - N(N + 1)/2` (let this be `A`).
  * Subtracting the expected sum of squares from the actual sum of squares gives Equation 2: `Y^2 - X^2 = S2 - N(N + 1)(2N + 1)/6` (let this be `B`).
  * Since `Y^2 - X^2 = (Y - X)(Y + X)`, dividing `B` by `A` gives `Y + X = B / A`. Solving these two linear equations directly gives `X` and `Y`.
* **Time & Memory Analysis:**
  * **Time Taken:** The loop runs only `N` times (1 single pass through the array).
  * **Memory Used:** No extra array is used, only basic integer variables to store the sums and equation values.

---

### Problem 3: Sum of Products of All Unique Pairs in an Array
* **Problem Statement:** Given an array `arr[]` of `N` integers, find the sum of products of all unique pairs `(arr[i] * arr[j])` where `0 <= i < j < N`.
* **Logic & Approach:** Multiplying all pairs using two nested `for` loops takes around `N*N/2` steps. We can do this in a single loop using the algebraic expansion of the square of a sum of `N` terms:
  `(a1 + a2 + ... + an)^2 = (a1^2 + a2^2 + ... + an^2) + 2 * (sum of all pairs ai * aj)`
  Rearranging this formula, the sum of products of all unique pairs is:
  `((Sum of all elements)^2 - (Sum of squares of all elements)) / 2`
  We calculate both the sum and the sum of squares in one simple `for` loop and put them into the formula.
* **Time & Memory Analysis:**
  * **Time Taken:** Reduced from two nested loops (`N*N` steps) to 1 single loop that runs `N` times.
  * **Memory Used:** Constant memory, as we only use two variables to store the sum and sum of squares.

---

### Problem 4: Maximum Value of |arr[i] - arr[j]| + |i - j|
* **Problem Statement:** Given an array `arr[]` of `N` integers, find the maximum value of `|arr[i] - arr[j]| + |i - j|` between any two indices `i` and `j`.
* **Logic & Approach:** Checking every pair of indices `(i, j)` with two nested loops takes `N*N` steps. We can solve this in a single loop by opening the modulus sign using case analysis. Since the expression is symmetric for `i` and `j`, we can assume `i >= j` so that `|i - j|` becomes `(i - j)`. Now there are two cases for `|arr[i] - arr[j]|`:
  * **Case 1 (`arr[i] >= arr[j]`):** The expression becomes `(arr[i] - arr[j]) + (i - j)`. Grouping each element with its own index gives `(arr[i] + i) - (arr[j] + j)`.
  * **Case 2 (`arr[i] < arr[j]`):** The expression becomes `(arr[j] - arr[i]) + (i - j)`. Grouping each element with its own index gives `(arr[j] - j) - (arr[i] - i)`.
  Because `i` and `j` are separated into individual terms, we run one `for` loop and use basic `if-else` conditions to find the maximum and minimum values of `(arr[k] + k)` and `(arr[k] - k)`. The larger difference between the two cases is our final answer.
* **Time & Memory Analysis:**
  * **Time Taken:** Only 1 single `for` loop running `N` times instead of two nested loops.
  * **Memory Used:** No extra array is needed; only 4 variables are used to track the minimum and maximum values.
