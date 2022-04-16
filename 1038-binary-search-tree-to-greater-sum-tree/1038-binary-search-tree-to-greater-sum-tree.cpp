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

// First traverse right sub tree(having greater value then node) and then left sub tree(having lesser value then node)
// Take a variable named as total which store sum of node values up to which we traverse
// And assign total value to root value.
// Time Complexcity O(N)

class Solution {
public:
    
    void solve(TreeNode* root,int &totalsum)
    {
        if(!root) return ;
        solve(root->right,totalsum);
        totalsum+=root->val;
        root->val=totalsum;
        solve(root->left,totalsum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int totalsum=0;
        solve(root,totalsum);
        return root;
    }
};