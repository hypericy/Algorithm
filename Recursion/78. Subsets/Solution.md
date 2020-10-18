[link](https://leetcode.com/problems/subsets/)
# Iterative
The idea is Using [1,2,3] for an example, the process is like:  
1.  Initially, add an empty list `[]`
2.  add `1` to all the copies of list and push back to the list `[[], [1]]`  
3.  add `2` to all the copies of list and push back to the list `[[], [1], [2], [1,2]]`
4.  add `3` to all the copies of list and push back to the list `[[], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]]`

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans={{}};
        for(int i=0;i<nums.size();i++)
        {
            int a=ans.size();
            for(int j=0;j<a;j++)
            {
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
        }
        return ans;
    }
};
```
**std::vector always makes a copy of whatever is being stored in the vector.

##
