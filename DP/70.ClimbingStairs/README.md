[link](https://leetcode.com/problems/climbing-stairs/)
## 1.Find recursive relation
two ways to reach `N` step from last step  
(a) Climb 1 step from `N-1`  
(b) Climb 2 steps from `N-2`  
Ways(N) = Ways(N-1) + Ways(n-2)
## 2.Recursive (top-down)
``` cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n<0) return 0;
        if(n<=2) return n;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};
```
## 3. Recursive + memo(top-down)
```cpp
class Solution {
    int *memo;
public:
    int climbStairs(int n) {
        memo = new int[n+1];
        memset(memo,0,(n+1)*sizeof(int));
        memo[0] = 1;
        memo[1] = 1;
        return recursive(n);
    }
    int recursive(int n)
    {
        if(memo[n]!=0)
            return memo[n];
        memo[n] = recursive(n-1)+recursive(n-2);
        return memo[n];
    }
};
```
## 4.Iterative + memo (bottom-up)
```cpp
class Solution {
    
public:
    int climbStairs(int n) {
        int *memo=new int[n+1];
        memo[0] =1;
        memo[1] =1;
        for(int i=2;i<=n;i++)
        {
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }
    
};
```
## 5.Iterative + 2 variables (bottom-up)
```cpp
class Solution {
    
public:
    int climbStairs(int n) {
        int pre1=1 ,pre2 =1;
        for(int i=2;i<=n;i++)
        {
            int t = pre1 + pre2;
            pre2 = pre1;
            pre1 = t;
        }
        return pre1;
    }
    
};
```
