# Algorithmic Efficiency Comparison

Program: comparison_algorithms.c (ARRAY_SIZE = 50000)

- Implementation A: naive algorithm, O(n^2)
- Implementation B: single-pass algorithm, O(n)

Compiled with: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long

## Raw measurements (5 runs)

| Run | Naive time (s) | Single-pass time (s) |
|-----|----------------|----------------------|
| 1 | 0.666856 | 0.000029 |
| 2 | 0.667425 | 0.000028 |
| 3 | 0.668638 | 0.000029 |
| 4 | 0.666126 | 0.000041 |
| 5 | 0.667582 | 0.000029 |

## Results

- Average naive time: 0.667325 seconds
- Average single-pass time: 0.000031 seconds
- Relative difference: the naive implementation is ~21389 times slower than the single-pass implementation

## Notes

- Both implementations return the correct count of even numbers for the data they scan (the naive one counts repeatedly, so its result is much larger).
- The naive version does about n^2 / 2 operations, the single-pass version does n, so the gap grows quickly as n increases.
- Less runtime means less CPU activity, which is used here as a proxy for lower energy usage.
