[link](https://leetcode.com/problems/house-robber-ii/)
# Find Recursive Relation
The idea is that the maximum profit of robbing N houses is the best solution of robbing N-1 house and robbing N-2 houses plus current one.  
But if first house is robbed then `N`th house can't be robbed. So we can consider it as two cases.  
(a)first house is considered and last is not
(a)last house is considered and first is not
# Top down Recursive 
``` cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
       return max(recursive_first(nums,nums.size()-2),recursive_last(nums,nums.size()-1));
    }
    int recursive_first(vector<int>& nums,int n)
    {
        if(n<0) return 0;
        return max(recursive_first(nums,n-1),nums[n]+recursive_first(nums,n-2));
    }
    int recursive_last(vector<int>& nums,int n)
    {
        if(n<=0) return 0;
        return max(recursive_last(nums,n-1),nums[n]+recursive_last(nums,n-2));
    }
};
```
# DP buttom-up


