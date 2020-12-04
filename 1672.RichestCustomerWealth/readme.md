## Richest Customer Wealth : **[link to problem](https://leetcode.com/problems/richest-customer-wealth/)**


### Problem :


You are given an `m x n` integer grid `accounts` where `accounts[i][j]`
is the amount of money the `ith` customer has in the `jth` bank. 
_Return the __wealth__ that the richest customer has._


A customer's __wealth__ is the amount of money they have in all their bank accounts. 
The richest customer is the customer that has the maximum __wealth__.

**Example:**  

```
Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.
```

### Solutions :

##### C :
1. Iterate other customers (var accounts), sum each amount in the account 
and return the highest.
**Time Complexity:** n^2.  
**Runtime:** 4 ms.  
**Memory:** 6.3 MB.
