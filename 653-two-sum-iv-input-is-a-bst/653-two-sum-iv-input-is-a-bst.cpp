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
    
//           Using Hashmap
//              ------------------------------
  
//   we keep a set to remember  the previouselement in the tree. while 
//   travelling the tree , If we see already  k-root->val, then we have 
//   a Two Sum ,return true, otherwise insert val into set and keep 
//   traverse.
    
    private: 
              unordered_set<int>s;
    
public:
    
        bool findTarget(TreeNode* root, int k) {
         if (!root) 
            return false;
        if (s.count(k - root->val)) 
            return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

  


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
