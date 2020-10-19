[link](https://leetcode.com/problems/subsets-ii/)
# iterative
The idea is we push every number into previos list but if it is a duplicate we only push into the newly list we insert from last time  
  
[1,2,2] for example  
[]  
1:`1`->`[[],[1]]`  
2:`2`->`[[],[1],[2],[1,2]]`  
3.`2` dup->`[[],[1],[2],[1,2],[2,2],[1,2,2]]`  ([2],[1,2] are inserted last time)
```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans={{}};
        int start;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0 || nums[i]!=nums[i-1]) start=0;
            int cnt=ans.size();
            for(int j=start;j<cnt;j++)
            {
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
            start=cnt;
            
        }
        return ans;
    }
};
```
# Backtracking


