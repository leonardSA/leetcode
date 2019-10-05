## Longest Substring Without Repeating Characters : **[link to problem](https://leetcode.com/problems/longest-substring-without-repeating-characters/)**


### Problem :

Given a string, find the length of the longest substring without repeating characters.

**Example 1:**

```
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
```

**Example 2:**

```
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**

```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

### Solutions :

##### C :

No solution implemented yet.

##### Python :

1. Keeps a dictionary of characters with their indexes in which we check if we've 
encountered the character already. If we have, we then clear the said dictionary 
and start again right after the index of the reencountered character as found in 
the dictionary. While this process happens, we are also calculating the maximum 
length found.  
**Runtime:** 684 ms.  
**Memory:** 13.9 MB.

_Notes:_ 
   - not an expert (yet) in algorithmic complexity, they are 
    simply an amateurish indication ;
   - runtime and memory are measurements given by leetcode.
