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