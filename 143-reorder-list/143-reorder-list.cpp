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
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        ListNode* curr=head;
        
        // calculating the size of linked list
       // and pushing all the nodes to stack so
      // that we can access in reverse too
        
        int len=0;
        while(curr)
        {
            st.push(curr);
                curr=curr->next;
            len++;
        }
        curr=head;
        ListNode *end;
        ListNode *next;
        
        //Reordering the list
        for(int i=0;i<len/2;i++)
        {
            end=st.top();
            st.pop();
            next=curr->next;
            curr->next=end;
            end->next=next;
            curr=next;
        }
        curr->next=NULL;
    }
};