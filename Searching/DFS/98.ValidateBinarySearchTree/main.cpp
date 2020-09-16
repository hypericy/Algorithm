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
    bool isValidBST(TreeNode* root) {
       return recursive(root,NULL,NULL);
    }
    bool recursive(TreeNode* node ,TreeNode* lower, TreeNode* upper)
    {     
        if(!node) return true;
        if((lower && node->val <= lower->val) || (upper && node->val >= upper->val))
            return false;
        if(!recursive(node->left,lower,node)) return false;
        if(!recursive(node->right,node,upper)) return false;
        
        return true;
    }
    
};
