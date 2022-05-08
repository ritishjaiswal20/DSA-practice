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
    bool ismax(TreeNode *root,long min,long max)
    {
       if(root==NULL) return true;
        
        if(root->val>= max || root->val <=min)
        {
            return false;
        }
        
        return ismax(root->left,min,root->val) && ismax(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        return ismax(root,LONG_MIN, LONG_MAX); 
    }
};