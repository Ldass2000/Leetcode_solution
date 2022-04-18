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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        int count=0;
        while(true)
        {
            if(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            
            else
            {
                if(st.empty())
                    break;
                root=st.top();
                st.pop();
                count++;
                
                if(count==k) return root->val;
                root=root->right;
            }
        }
        return -1;
    }
};