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

//INTUITION:
//1-->Create a stack first to traverse on left part of every node and store in it.
//2--> When BST Iterator will call very firsttime .do step 1;
//3--> When next() function call. pop out the top element from stack and now traverse and insert right 
//     subtree of that node into stack.
//4--> When hasNext() function is call, just check stack is empty or not.
//  SC--> O(N) ->Height of Tree
//  TC--> )(N) ->number of nodes


class BSTIterator {
    
    private:
       stack<TreeNode*>st;

    void  store(TreeNode *node)
    {
        while(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        store(root);
    }
    
    int next() {
        TreeNode* curr=st.top();
        st.pop();
        store(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
       return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */