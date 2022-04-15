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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
//   If the root->val is lower than the range, then return the right node because
//   all nodes to the right are higher.

// If the root->val is higher than the range, then return the left node because
//all nodes to the left are lower.then recurse on node->left and node->right.
        
        
        if(root==NULL) return NULL;
        
        if(root->val<low)
        {
            return trimBST(root->right,low,high);
        }
        
        else if(root->val>high)
        {
            return trimBST(root->left,low,high);
        }
        
        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);
        return root;
    }
};