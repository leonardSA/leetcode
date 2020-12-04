## The Kth Factor Of N: **[link to problem](https://leetcode.com/problems/the-kth-factor-of-n/)**


### Problem :

Given two positive integers `n` and `k`.

A factor of an integer `n`   is defined as an integer `i` where `n % i == 0`.

Consider a list of all factors of `n` sorted in __ascending order__, return the 
`kth` factor in this list or return __-1__ if `n` has less than `k` factors.

**Example:**  

```
Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
```

### Solutions :

##### C :
1. Loop i from 1 to n and decrement k each time `i % n == 0`:
**Time Complexity:** n.  
**Runtime:** 0 ms.  
**Memory:** 5.6 MB.
