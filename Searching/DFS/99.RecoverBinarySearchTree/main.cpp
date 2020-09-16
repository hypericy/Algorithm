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
    TreeNode* pre;
    TreeNode* s1=NULL;
    TreeNode* s2=NULL;
public:
    void recoverTree(TreeNode* root) {
        traversal(root);
        swap(s1->val,s2->val);
        return;
    }
    void traversal(TreeNode* node)A
    {
        if(!node) return;
        traversal(node->left);
        if(pre && !s1 && pre->val > node->val)
            s1 = pre; 
        if(s1 && node->val < pre->val)
            s2 = node;
        pre = node;
        traversal(node->right);
        return;
    }
};
