[link](https://leetcode.com/problems/longest-valid-parentheses/)
## 1. Find Recursive relation
We know that every valid Parenthese ends with `)` and there are two types of ending  
(a) s[i-1]=='('  &&  s[i]==')'  
so the length of longest parenthese at `i` will be the length of longest parenthese at `i-2` + 2
```
  xxxx()
  ---↑--
```
(b) s[i-1]==')'  && s[i]==')'  
so if this type of string is valid , we should find if the previous first letter of longest parenthese at `i-1` is '('  
if so then these whole block of letter will be longest(i-1)+2
```
   ((xxxx))
   ↑-------
```
furthurmore, there might be some valid string in front of our closest one
```
  -----i  
  ()(())
  -↑0024
```
therefore, valid(i) = valid(i-1)+2 + valid(i-valid(i-1)-2)

