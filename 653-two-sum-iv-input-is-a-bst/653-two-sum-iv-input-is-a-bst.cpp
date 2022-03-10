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
    
    void helper(TreeNode* root, vector<int>&ans)
    {
        if(root==NULL) return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    
    bool findTarget(TreeNode* root, int k) {
        // INORDER + TWO POINTER
        //Do inorder traverse of BST  which give us back a sorted vector of all the tree's value.
        //Then use two pointre to find  a Two Sum
        //TC-->O(Recursive)
        //SC-->O(N)
        vector<int>ans;
        helper(root,ans);
        int i=0;
        int j=ans.size()-1;
         while(i<j)
         {
             int sum=ans[i]+ans[j];
             if(sum==k) return 1;
             if(sum>k) j--;
             else  i++;
         }
        return 0;
    }
};