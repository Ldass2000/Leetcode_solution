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
    ListNode* swapNodes(ListNode* head, int k) {
        
          //Example-->  (1) -> (2) -> (3)-> (4)-> (5)
         //            | |
        //         slow fast
       //
        
         //step1: loop until K-1 
        //        (1)->  (2) -> (3)-> (4)-> (5)
       //        |      |   |
      //         slow fast first
        
        
         //step2:-> loop until first->next!=NULL we get our last k-1 point
        //         (1)->(2)->(3)-> (4)-> (5)
       //                |          |     |
      //               first      slow    fast
        
        
        //step3:-> swap the val of first and slow node, we get
       //          ( 1 )-> ( 4 )-> ( 3 )-> ( 2 )-> ( 5 )
        
        
       ListNode* slow=head;
       ListNode* fast=head;
       ListNode* first;
        
        // step1:
        for(int i=0;i<k-1;i++)
        {
            fast=fast->next;
            first=fast;
        }
        
        //step2:-
        
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        swap(first->val,slow->val);
        
        return head;
    }
};