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
    
    //Approcah I TC-->O(N),SC-->O(N)
    // TreeNode* prev=NULL;
    // void flatten(TreeNode* root) {
    //  if(root==NULL) return;
    //     flatten(root->right);
    //     flatten(root->left);
    //     root->right=prev;
    //     root->left=NULL;
    //     prev=root;
    // }
    
    
    
    
    // Approach II  TC-->O(N), SC-->O(N)
    
//     void flatten(TreeNode* root){
//         stack<TreeNode*>st;
//         st.push(root);
//         while(!st.empty())
//         {
//            TreeNode* curr=st.top();
//             st.pop();
//             if(curr->right) st.push(curr->right);
//             if(curr->left) st.push(curr->left);
            
//             if(!st.empty())
//             {
//                 curr->right=st.top();
//                 curr->left=NULL;
//             }
//         }
//     }
    
    
    
    
    //Approach III  SC-->O(N) SC-->O(1)
    //MORIS TRVAVERSAL
    void flatten(TreeNode* root){
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
                TreeNode* prev= curr->left;
                while(prev->right!=NULL)
                {
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};