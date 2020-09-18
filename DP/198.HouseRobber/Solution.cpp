class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int pre2=0,pre1=nums[0];
        for(int i=1;i<n;i++)
        {  
            int t = max(pre2+nums[i],pre1);
            pre2 = pre1;
            pre1 = t;
        }
        return pre1;
    }
};
