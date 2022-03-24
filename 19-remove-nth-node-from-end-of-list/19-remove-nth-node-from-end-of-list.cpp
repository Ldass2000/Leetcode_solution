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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        /*Idea
            find length of list len then delete( l-n+1)th  Node.
        */
        
        ListNode* temp=head;
        int len=0,i=1;
        
        //find length of linked list
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
        
        if(len==n) return head->next;   //if head itself to be deleted just return head->next;
        
        //iterate fist len-n nodes
        for(temp=head;i<len-n;i++)
        {
            temp=temp->next;
           
        }
        
         temp->next=temp->next->next;   //remove the nth node from end
        return head;
    }
};