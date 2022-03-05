/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " "+ serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         istringstream ss(data);
         return helper(ss);  
    }
    private:
     TreeNode* helper(istringstream& ss){
        string s;
        ss >> s;
        if(s == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(s));
        node->left = helper(ss);
        node->right = helper(ss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));