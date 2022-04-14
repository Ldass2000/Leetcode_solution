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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* dass=root;
        if(root==NULL)
            {
                return NULL;
            }
            
        while(dass)
        {
            
             if(dass->val==val)
            {
                return dass;
            }
            else if(dass->val>val)
            {
                dass=dass->left;
            }
            else if(dass->val<val)
            {
                 dass=dass->right;
            }
        }
        return dass;
    }
};