# IBM Coding Assessment — Solutions

This repository contains detailed solutions for two coding assessment problems.

## Question 1 — Maximum XOR Sum

### Problem Statement

Given two integer arrays arr1 and arr2 of equal length n, consider every possible pair of elements:

arr1[i] XOR arr2[j]

for all 0 <= i,j < n.

Calculate the sum of all these XOR values and return the result modulo 10^9 + 7.

A direct approach would construct an n × n matrix and take O(n²) time.

### Example

arr1 = [1, 2, 3]
arr2 = [10, 10, 10]

The XOR matrix is:

[ 11  11  11 ]
[  8   8   8 ]
[  9   9   9 ]

Answer = 11 + 11 + 11 + 8 + 8 + 8 + 9 + 9 + 9 = 84

### Approach — Bit Counting

XOR can be calculated independently for every bit.

1. Count the elements of arr1 having the current bit set.
2. Count the elements of arr2 having the current bit set.
3. An XOR bit is 1 when the two corresponding bits are different.
4. If x elements of arr1 and y elements of arr2 have the bit set, the number of pairs producing XOR bit 1 is:

x × (n-y) + (n-x) × y

5. Multiply this count by the bit value and add it to the answer.

This avoids constructing the full n × n matrix.

### Complexity

Time: O(31 × n), effectively O(n)
Space: O(1)

### Solution

See Question1_MaximumXorSum.cpp.

---

## Question 2 — Checksum Aggregation

### Problem Statement

For every pair of packet identifiers i and j:

C(i,j) = i % j + j % i

where 1 <= i <= n and 1 <= j <= n.

Calculate the sum of C(i,j) for all pairs and return it modulo 10^9 + 7.

### Examples

n = 2  -> 2
n = 3  -> 10
n = 4  -> 24

For n = 2:

C(1,1) = 0
C(1,2) = 1
C(2,1) = 1
C(2,2) = 0

Total = 2

### Approach

The checksum is symmetric:

C(i,j) = C(j,i)

Therefore, calculate only pairs where i > j and multiply the result by 2.

For i > j:

j % i = j

so C(i,j) = i % j + j.

For a fixed j, instead of calculating i % j for every i, use quotient and remainder:

q = n / j
r = n % j

The sum of remainders for i = 1 ... n is:

q × j × (j-1) / 2 + r × (r+1) / 2

Remove the contribution for i <= j, add j for every i > j, and finally multiply by 2 for the symmetric half.

### Complexity

Time: O(n)
Space: O(1)

### Solution

See Question2_ChecksumAggregation.cpp.

---

## Repository Structure

README.md
Question1_MaximumXorSum.cpp
Question2_ChecksumAggregation.cpp

## Concepts Covered

- Bit Manipulation
- XOR Properties
- Modular Arithmetic
- Quotient and Remainder
- Mathematical Optimization
- Complexity Optimization

## Language

C++