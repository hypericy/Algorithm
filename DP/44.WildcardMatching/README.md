[link](https://leetcode.com/problems/wildcard-matching/)
## Find Recursive Relation
`i,j` represent matching index of string `s,p`  
there are two situation to check whether s and p match at `i,j`  
(a) 
```
if p[j]=='?' or p[j]==s[i] :
    return R(i-1,j-1)
```
(b)
```
if p[j]=='*' :
    return R(i,j-1) || R(i-1,j)
```

    

