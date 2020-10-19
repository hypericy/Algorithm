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
the idea is each time we push back a element after index then backtrack  
if enconter the duplicate numbers then skip it  
```
subsets([1,2,3,4]) = []
                     // push(1)
                     [1, subsets([2,3,4])] // if push N times in subsets([2,3,4]), the pop times is also N, so vec is also [1] after backtrack.
                     // pop(), push(2)
                     [2, subsets([3,4])]
                     // pop(), push(3)
                     [3, subsets([4])]
                     // pop(), push(4)
                     [4, subsets([])]
                     // pop()
```
 Solution:
```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(nums,ans,0,temp);
        return ans;
    }
    void backtrack(vector<int>&nums,vector<vector<int>>&ans,int index,vector<int>&temp)
    {
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            backtrack(nums,ans,i+1,temp);
            temp.pop_back();
        }
        return;
    }
};
```


