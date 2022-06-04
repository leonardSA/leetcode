## Palindrome Number : **[link to problem](https://leetcode.com/problems/palindrome-number/)**


### Problem :

Determine whether an integer is a palindrome. An integer is a 
palindrome when it reads the same backward as forward.

**Example 1:**  

```
Input: 121
Output: true
```

**Example 2:**  

```
Input: -121  
Output: false  
Explanation: From left to right, it reads -121. From right to left, 
it becomes 121-. Therefore it is not a palindrome.
```

**Example 3:**  

```
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

**Follow up:**  
Coud you solve it without converting the integer to a string?

### Solutions :

##### C :
1. Converts the integer as a list of digits then compares each 
digit that should match.
Note: it does not convert the integer to a string but an array of ints.
**Time Complexity:** 3n/2.  
**Runtime:** 12 ms.  
**Memory:** 10.2 MB.

##### Python :  
No solution implemented yet.

_Notes:_ 
   - not an expert (yet) in algorithmic complexity, they are 
    simply an amateurish indication ;
   - runtime and memory are measurements given by leetcode.
