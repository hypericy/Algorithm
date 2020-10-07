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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *n =new TreeNode(val);
        
        TreeNode *it=root;
        while(it!=NULL)
        {
            if(val>it->val)
            {
                if(!it->right){
                    it->right = n;
                    break;
                }
                else
                    it = it->right;
            }
            else
            {
                if(!it->left){
                    it->left = n;
                    break;
                }
                else
                    it = it->left;
            }
        }
    
        return root?root:n;
    }
};
