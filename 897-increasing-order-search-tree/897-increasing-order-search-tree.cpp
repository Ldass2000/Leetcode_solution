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
    
    stack<TreeNode*>st;
    void reverse_inorder(TreeNode* root)
    {
        if(!root) return;
        reverse_inorder(root->right);
        st.push(root);
        reverse_inorder(root->left);
    }
    
    //creation of increasing order  search with value of stack
    
    TreeNode*  inc_helper()
    {
        if(st.empty()) return NULL;
        TreeNode* root=new TreeNode(st.top()->val);
        st.pop();
        root->right= inc_helper();
        return root;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        // TreeNode* ans;
        reverse_inorder(root);
        TreeNode* ans=inc_helper();
        return ans;
    }
    
    //TC_>O(n),SC-->(O(n))
};