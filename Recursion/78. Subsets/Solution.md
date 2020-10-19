[link](https://leetcode.com/problems/subsets/)
# Iterative
The idea is Using [1,2,3] for an example, the process is like:  
1.  Initially, add an empty list `[]`
2.  add `1` to all the copies of list and push back to the list `[[], [1]]`  
3.  add `2` to all the copies of list and push back to the list `[[], [1], [2], [1,2]]  
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

## Backtracking 1
The idea is that we pass a temporary vector to `index+1` with and without adding `nums[index]`  
[1,2,3] for example  
[N,N,N] -> []  
[N,N,Y] -> [3]  
[N,Y,N] -> [2]  
[N,Y,Y] -> [2,3]  
[Y,N,N] -> [1]  
[Y,N,Y] -> [1,3]  
[Y,Y,N] -> [1,2]...    


```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
        vector<int> temp={};
        backtracking(nums,ans,0,temp);
        return ans;
    }
    void backtracking(vector<int>&nums,vector<vector<int>> &ans,int index,vector<int>& temp)
    {
        if(index==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        backtracking(nums,ans,index+1,temp);
        temp.push_back(nums[index]);
        backtracking(nums,ans,index+1,temp);
        temp.pop_back();
       
        return;
    }
};
```

## Backtracking 2
The idea is each time push back an element after `index` then update index and recursive again 
[1,2,3] for example  
1.index = 0: add `1` [1]  
    1-1. index = 1: add `2` [1,2]  
            1-1-1. index = 2: add `3` [1,2,3]   
    1-2. index = 1: add `3` [1,3]  
2.index = 0: add `2` [2]  
    2-1. index = 2: add `3` [2,3]  
3.index = 0: add `3` [3]  

            
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
        vector<int> temp={};
        backtracking(nums,ans,0,temp);
        return ans;
    }
    void backtracking(vector<int>&nums,vector<vector<int>> &ans,int index,vector<int>& temp)
    {
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            backtracking(nums,ans,i+1,temp);
            temp.pop_back();
        }
        return;
    }
};
```
 
