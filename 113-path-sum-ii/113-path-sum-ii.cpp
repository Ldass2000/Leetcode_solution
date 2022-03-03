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
    void helper(TreeNode* root, int targetSum,vector<int>v,vector<vector<int>>&ans,int sum)
    {
        if(!root) return;
        sum+=root->val;
        v.push_back(root->val);
        
        if(!root->left && !root->right && targetSum==sum)
        {
            ans.push_back(v);
            v.pop_back();
            return;
        }
        helper(root->left,targetSum,v,ans,sum);
        helper(root->right,targetSum,v,ans,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        helper(root,targetSum,v,ans,0);
        return ans;
    }
};