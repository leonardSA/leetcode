## Two Sum : **[link to problem](https://leetcode.com/problems/two-sum/)**


### Problem :

Given an array of integers, return **indices** of the two 
numbers such that they add up to a specific target.  

You may assume that each input would have **_exactly_** one solution,
and you may not use the _same_ element twice.  

**Example:**  

```
Given nums = [2, 7, 11, 15], target = 9,  

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

### Solutions :

##### C :
1. Simply two embedded for loops, easiest solution.  
**Time Complexity:** n^2.  
**Runtime:** 220 ms.  
**Memory:** 7.6 MB.

2. Searches for an element in an array after determining a 
targetted number. Attempt to modify the quicksort algorithm 
in order to optimize the target searching operation.  
**Time Complexity:** n^2 log n.  
**Runtime:** 208 ms.  
**Memory:** 7.8 MB.

3. Stores elements into a hash table with their indexes. This 
hash table stores them as nodes in order to chain them if there 
are collisions (a.k.a. closed addressing).  
**Runtime:** 4 ms.    
**Memory:** 8.8 MB.  

##### Python :
1. Searches for an element in an array after determining a 
targetted number.   
**Runtime:** 772 ms.  
**Memory:** 13.6 MB.  

2. Stores elements into a hash table with their indexes then 
searches for the complement into the hash table.  
**Time Complexity:** 2n.  
**Runtime:** 36 ms.  
**Memory:** 14.9 MB.  


_Notes:_ 
   - not an expert (yet) in algorithmic complexity, they are 
    simply an amateurish indication ;
   - runtime and memory are measurements given by leetcode.
