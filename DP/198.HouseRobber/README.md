[link](https://leetcode.com/problems/house-robber/)  
1.Find recusive relation  
Every house robber have two choices (a) rob current house `N` (b) not rob  
*    if (a) then can't rob previous house. Max profit will be the optimized moves of robbing `N - 2` houses + `N`
*    if (b) then it will be same value of robbing `N-1` houses  
rob(N) = Math.max( rob(N - 2) + currentHouseValue, rob(N - 1) )

2. Recursive (top-down)
```
class Solution {
public:
    int rob(vector<int>& nums) {
        return rob(nums,nums.size()-1);
    }
    int rob(vector<int>& nums, int n)
    {
        if(n<0) return 0;
        return max(rob(nums,n-2)+nums[n],rob(nums,n-1));
    }
};
```
3. Recursive + memo(top-down)
```
class Solution {
    unordered_map<int,int>hash;
public:
    int rob(vector<int>& nums) {
        return rob(nums,nums.size()-1);
    }
    int rob(vector<int>& nums, int n)
    {
        if(n<0) return 0;
        if(hash.find(n)==hash.end())
            hash[n] = max(rob(nums,n-1),rob(nums,n-2)+nums[n]);
        return hash[n];
    }
};
```
4.Iterative + memo (bottom-up)
```
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int *DP = new int[n+1];
        DP[0] = 0;
        DP[1] = nums[0];
        for(int i=1';i<n;i++)  
        {  
            DP[i+1] = max(DP[i-1]+nums[i],DP[i]);
        }
        return DP[n];
    }
};
```

5.Iterative + 2 variables (bottom-up)  
```
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int pre2=0,pre1=nums[0];
        for(int i=1;i<n;i++)
        {  
            int t = max(pre2+nums[i],pre1);
            pre2 = pre1;
            pre1 = t;
        }
        return pre1;
    }
};
```
Time Complexity: O(n)
Space Complexity: O(1)
