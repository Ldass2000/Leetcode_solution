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
    int ans=0;
    
    void helper(TreeNode* root, int val)
    {
        if(root==NULL) return ;
         //if it is a leaf node then add value till leaf to the answer
        if(root->left==NULL and root->right==NULL)
        {
            ans+=(val*10+root->val);
            return;
        }
        helper(root->left,val*10+root->val);
         helper(root->right,val*10+root->val);
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        
        //if there is only one node then return root->val
        if(root->left==NULL and root->right==NULL)
        {
            return root->val;
        }
        
        //recursively call  to left and right of tree
        helper(root->left,root->val);
        helper(root->right,root->val);
        return ans;
    }
};