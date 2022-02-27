/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
	    //APPROACH
	    //1--> we will place a dummyNode before the head node.
	    //2-->Now, let the head be our currNode. That means the node with value 1 is the currNode, and we have to swap it with the node with value 2. So for this, we will also have to keep track of the node previous to the currNode, let it be prevNode, 
	    //as it's next pointer value will have to change after we swap the currNode and the node next to currNode.
	    //3-->Now the very first thing to do is change the next pointer of prevNode to point to currNode->next. Why?? Because in the answer we want the node with value 2 after the dummyNode. Right? So we will have to connect
	    //dummyNode (prevNode) to the node with value 2 (currNode->next). This means   prevNode->next = currNode->next
	    //4-->Now, in our finl answer node with value 1 should be at the place of node with value 2. So the next pointer of node with value 1 should point to whatever the node with value 2 is pointing to originally. That means we will have to change
	    //currNode->next to the the to the next of next of prevNode, as currently prevNode is dummyNode, prevNode->next is node with value 2 and prevNode->next->next = next of node with value 2. This means
            // currNode->next = prevNode->next->next
	    //5-->Now, as in the answer the node with value 2 should point to node with value 1. That means
            //prevNode->next->next = currNode
	    //6-->After this iteration, nodes 1 and 2 will get swapped and our linked list will look like this.
	    //7-->Now for the next iteration, we have to swap nodes with values 3 and 4. For that the prevNode should point to
	    //node with value 1 and the currNode should point to node with value 3. This means
	    //8-->We should stop this procedure when either there is no nodes left to swap or there is only one node left which cannot be swapped with any node.
	    //9-->At the end, as we can see that our head of the list has been misplaced in the procedure of swapping, so we can return dummyNode->next to return the swapped linked list.
	    
	    
        //TC-->>O(N)
        //TC-->O(N)
       //If there are less than 2 nodes
        //in the given nodes, then no need to do anything just return the list as it is.
		 if(!head || !head->next) return head; 
         ListNode* dummyNode = new ListNode();
        
        ListNode* prev=dummyNode;
        ListNode* curr=head;
        
        while(curr && curr->next){
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;
            
            prev= curr;
            curr = curr->next;
        }
        
        return dummyNode->next;
    }
};
