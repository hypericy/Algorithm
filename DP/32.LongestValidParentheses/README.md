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
So if this type of string is valid ,we should check if the previous first letter of longest parenthese at `i-1` is '('  
which means `i-valid(i-1)-1` is '('  
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

## This problem isn't intuitive to be solved by recursive

## 4. Iterative(down-top)
```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int* dp = new int[s.length()];
        int ans=0;
        memset(dp,0,sizeof(int)*s.length());
        for(int i=1;i<s.length();i++)
        {
            
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    dp[i] = i>=2?dp[i-2]+2:2;
                }    
                else if( i-dp[i-1]>0 && s[i-dp[i-1]-1]=='(')
                {
                    dp[i] = dp[i-1]+2+ (i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0);
                }
            }
            ans = max(ans,dp[i]);
        }      
        return ans;
    }
};
```

