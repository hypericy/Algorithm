[link](https://leetcode.com/problems/wildcard-matching/)
## 1.Find Recursive Relation
`i,j` represent matching index of string `s,p`  
there are two situation to check whether s and p match at `i,j`  
(a) 
```
if p[j]=='?' or p[j]==s[i] :
    return R(i-1,j-1)
```
(b)
```
if p[j]=='*' :
    return R(i,j-1) or R(i-1,j)
```
## 2.Recursive (top-down)
```
class Solution {
public:
    bool isMatch(string s, string p) {
        return Recursive(s,p,s.length()-1,p.length()-1);
    }
    bool Recursive(string s,string p,int i,int j){
        if(i==-1 && j==-1) return true;
        else if(j==-1) return false;
        else if(i==-1) return p[j]=='*' && Recursive(s,p,i,j-1);
        else if(p[j]=='?' || s[i]==p[j])
            return Recursive(s,p,i-1,j-1);
        else if(p[j]=='*')
            return Recursive(s,p,i,j-1) || Recursive(s,p,i-1,j);
        return false;
    }
};
```
## 3. Recursive + memo(top-down)
```
class Solution {
public:
    unordered_map<int,unordered_map<int,bool>> mem;
    bool isMatch(string s, string p) {
        return Recursive(s,p,s.length()-1,p.length()-1);
    }
    bool Recursive(string s,string p,int i,int j){
        if(mem[i].find(j)!=mem[i].end()) return mem[i][j];
        else if(i==-1 && j==-1){
            mem[i][j]=1;
            return mem[i][j];   
        }
        else if(j==-1){
            mem[i][j]=0;
            return mem[i][j];
        }
        else if(i==-1) {
            mem[i][j]= p[j]=='*' && Recursive(s,p,i,j-1);
            return mem[i][j];
        }
        else if(p[j]=='?' || s[i]==p[j]){
            mem[i][j]=Recursive(s,p,i-1,j-1);
            return mem[i][j];
        }
        else if(p[j]=='*'){
            mem[i][j]=Recursive(s,p,i,j-1) || Recursive(s,p,i-1,j);
            return mem[i][j];
        }
        return false;
    }
};
```
## 4.Iterative + memo (bottom-up)
```
class Solution {
public:
    bool isMatch(string s, string p) {
        int dp[s.length()+1][p.length()+1];
        for(int i=0;i<s.length()+1;i++)
        {
            for(int j=0;j<p.length()+1;j++)
            {
                if(i==0 && j==0) dp[i][j]=true;
                else if(j==0) dp[i][j]=false;
                else if(i==0)
                {
                    dp[i][j]=p[j-1]=='*' && dp[i][j-1];
                } 
                else if(p[j-1]=='?' || s[i-1]==p[j-1]) dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j]=false;
            }           
        }
        return dp[s.length()][p.length()];
    }
};
```


    

