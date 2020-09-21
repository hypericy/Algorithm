[link](https://leetcode.com/problems/longest-valid-parentheses/)
## 1. Find Recursive relation
We know that every valid Parenthese ends with `)` and there are two types of ending  
(a) s[i]==')' && s[i-1]=='('  
so the length of longest parenthese at `i` will be the length of longest parenthese at `i-2` + 2
```
  xxxx()
  ---↑--
```


