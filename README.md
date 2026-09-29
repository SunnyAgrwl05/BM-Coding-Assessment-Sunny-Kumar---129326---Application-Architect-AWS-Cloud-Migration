# IBM Coding Assessment — Sunny Kumar

Application: 129326 — Application Architect - AWS Cloud Migration

This repository contains solutions and detailed explanations for the two assessment problems.

## Question 1 — Plus/Multiply Parity

### Problem

Given an array of integers, split the elements into two sequences based on their positions:
- Even-indexed sequence: positions 0, 2, 4, ...
- Odd-indexed sequence: positions 1, 3, 5, ...

For each sequence, start with multiplication of the first two elements and then alternate between addition and multiplication for the remaining elements.

Example:

    A = [2, 3, 5, 7, 13, 12]
    Even positions -> [2, 5, 13]
    Odd positions  -> [3, 7, 12]

The implementation calculates the parity of each resulting value. It then returns EVEN, ODD, or NEUTRAL according to the comparison of the two parity values.

### Approach

1. Traverse the array starting at index 0 to process even positions.
2. Traverse the array starting at index 1 to process odd positions.
3. Start each calculation with multiplication of the first two selected elements.
4. Alternate addition and multiplication for the remaining elements.
5. Take the result modulo 2 because only parity is required.
6. Compare the two parity values.

### Complexity

- Time: O(n)
- Auxiliary space: O(n), because the implementation stores the selected elements.

### Solution

See question1.cpp.

## Question 2 — Customer Site Metrics

### Problem

Given a customers table containing customer id and email, and a site_metrics table containing customer_id, CPU usage, memory usage and disk usage, find customers whose average CPU, memory, or disk usage is greater than 50.

For every matching customer, return:
- Customer email
- Average CPU usage
- Average memory usage
- Average disk usage

The averages are rounded to 2 decimal places and the final result is ordered by email.

### Approach

1. JOIN customers with site_metrics using customers.id = site_metrics.customer_id.
2. GROUP BY customer id and email so metrics are aggregated per customer.
3. Calculate AVG for CPU, memory and disk usage.
4. Use ROUND(..., 2) for two decimal places.
5. Use HAVING because the filtering conditions depend on aggregate values.
6. Keep a customer when at least one average is greater than 50.
7. Sort the result by customer email in ascending order.

### Complexity

The exact runtime depends on the database engine, table size, indexes and query optimizer. The query performs a join, grouping and three aggregate calculations.

### Solution

See question2.sql.

## Repository Structure

    .
    ├── README.md
    ├── question1.cpp
    └── question2.sql

## Technologies

- C++
- SQL
- JOIN and aggregation
- GROUP BY and HAVING
- Algorithmic problem solving
