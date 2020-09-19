class Solution {
    
public:
    int climbStairs(int n) {
        int pre1=1 ,pre2 =1;
        for(int i=2;i<=n;i++)
        {
            int t = pre1 + pre2;
            pre2 = pre1;
            pre1 = t;
        }
        return pre1;
    }
    
};
