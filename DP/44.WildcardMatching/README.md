[link](https://leetcode.com/problems/wildcard-matching/)
## Find Recursive Relation
`i,j` represent matching index of string `s,p`  
there are three situation for matching  
(a) 
```
if p[j] is a to z
    if s[i] == p[j]
        i++;j++;
    else
      return false;
else if p[j] is '?'
    i++;j++;
else if p[j] is '*'
     
    
```
