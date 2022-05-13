/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // 1.Pushing the first element of the tree into a queue
    // 2.Running a loop until the queue is empty
    // 3.Separately, Traversing each level in tree using a for loop with size equal to number of nodes in           current level
    // 4.Pushing the left and right child of curr node into the queue
    // 5.Using a prev node to make it next equal to curr node
    // 6.At the end of each level in tree(end is denoted by for loop end), making prev->next = NULL, as it is       the last node in current level.
    // 7.Since, each node is traversed only once the time complexity is still equal to O(n), where n is number       of nodes in tree (even when a nested loop is used).
    
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root != NULL) q.push(root);
        
        while(!q.empty()){
            
            int sz = q.size();
            Node* prev = q.front();
            
            for(int i = 0; i < sz; i++){
                
                Node* curr = q.front();   q.pop();
                prev->next = curr;
                prev = curr;
                
                if(curr->left != NULL)  q.push(curr->left);
                if(curr->right != NULL)  q.push(curr->right);
            }
            prev->next = NULL;
        }
        
        return(root);
    }
};