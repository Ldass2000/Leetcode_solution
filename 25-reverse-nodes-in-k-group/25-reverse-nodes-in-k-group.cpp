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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //Recursive Approcah
//1) The first step is to check whether the Head is NULL or Not, if its NULL then we can directly return NULL,
//2) If the Head is not NULL, then we need to check the length of Linked List starting from current Head.
//3) If it is not a multiple of K(Less than K) , then there is no need to reverse it and hence we can directly return head,
//4) Else if its a multiple of K, then we have to reverse the K elements starting from current Head,
//5) We will follow the same steps for the rest of the elements Recursively.
        
        if(!head)  return NULL;
        ListNode *len=head;
        
        for(int i=0;i<k;i++)
        {
            if(len==NULL) return head; 
            len=len->next;
        }
        
        int count=0;
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *next=NULL;
        
        while(curr && count<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next)
        {
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
};