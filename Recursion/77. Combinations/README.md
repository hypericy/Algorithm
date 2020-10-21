link[https://leetcode.com/problems/combinations/]
# iterative (too slow)
The idea is each time select front vector in the queue and add each number behind the last number of the front vector.  
If the size of new vector is k, push it in the answer vector.Then pop the front vector.  

Input: n = 4, k = 2
[[]]  
[[1],[2],[3],[4]]  
[[2],[3],[4]] ans=[1,2],[1,3],[1,4]  


```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans={};
        queue<vector<int>> q;
        q.push({});
        while(!q.empty())
        {
            int i=q.front().empty()?1:q.front().back()+1;
            for(i;i<=n;i++)
            {
                vector<int> t= q.front();
                t.push_back(i);
                if(t.size()==k) ans.push_back(move(t));
                else q.push(move(t));
            }
            q.pop();
        }
        return ans;
    }
};

```
put too much effort on copying something we don't need
# backtrack

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans={};
        vector<int> temp;
        back(n,k,0,ans,temp);
        return ans;
    }
    void back(int n,int k,int index,vector<vector<int>>&ans,vector<int>& temp)
    {     
        if(n-index<k-temp.size()) return;
        for(int i=index+1;i<=n;i++)
        {
            temp.push_back(i);
            if(temp.size()==k) ans.push_back(temp);
            else back(n,k,i,ans,temp);
            temp.pop_back();
        }
        return;
    }
};
```
