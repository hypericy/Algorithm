[link](https://leetcode.com/problems/house-robber/)  
1.Find recusive relation  
Every house robber have two choices (a) rob current house `N` (b) not rob  
*    if (a) then can't rob previous house. Max profit will be the optimized moves of robbing `N - 2` houses + `N`
*    if (b) then it will be same value of robbing `N-1` houses  
rob(N) = Math.max( rob(N - 2) + currentHouseValue, rob(N - 1) )

2. Recursive (top-down)
<pre>
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
</pre>
3. Recursive + memo(top-down)
<pre>
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
</pre>
4.Iterative + memo (bottom-up)
<pre>
</pre>
