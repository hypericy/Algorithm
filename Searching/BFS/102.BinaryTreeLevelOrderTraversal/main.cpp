/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //BFS using queue
        queue<TreeNode*> q;
        //push root to queue
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        while(!q.empty())
        {
            vector<int> t;
            
            //record element number by level
            int s=q.size();
            //pop element number by level
            for(int i=0;i<s;i++)
            {
                auto qfront = q.front();
                t.push_back(qfront->val);
                q.pop();
                if(qfront->left!=NULL) q.push(qfront->left);
                if(qfront->right!=NULL) q.push(qfront->right);                
            }
            ans.push_back(t);
        }
        return ans;
    }
};
