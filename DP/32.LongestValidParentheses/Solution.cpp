class Solution {
public:
    int longestValidParentheses(string s) {
        int* dp = new int[s.length()];
        int ans=0;
        memset(dp,0,sizeof(int)*s.length());
        for(int i=1;i<s.length();i++)
        {
            
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    dp[i] = i>=2?dp[i-2]+2:2;
                }    
                else if( i-dp[i-1]>0 && s[i-dp[i-1]-1]=='(')
                {
                    dp[i] = dp[i-1]+2+ (i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0);
                }
            }
            ans = max(ans,dp[i]);
        }      
        return ans;
    }
};
