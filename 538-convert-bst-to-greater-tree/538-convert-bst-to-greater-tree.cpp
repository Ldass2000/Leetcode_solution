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
    
    void helper(TreeNode *root, int &sum)
    {
        if(!root) return  ;
        helper(root->right,sum);
        sum+=root->val;
        root->val=sum;
        helper(root->left,sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        return root;
    }
};