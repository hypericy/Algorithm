[link](https://leetcode.com/problems/combination-sum/)
# backtracking
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        back(candidates,ans,0,temp,target);
        return ans;
    }
    void back(vector<int>& candidates,vector<vector<int>> &ans,int index,vector<int> &temp,int target)
    {
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(target>=candidates[i]){
                temp.push_back(candidates[i]);
                back(candidates,ans,i,temp,target-candidates[i]);
                temp.pop_back();
            }
            else break;
        }
        return;
    }
    
};
```

