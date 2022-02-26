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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = new ListNode(-1);
        tmp->next = head;
        ListNode* prev = tmp;
    while(head != NULL && head->next != NULL)
    {
        if(head->val == head->next->val)
        {
            while(head->next != NULL && head->val == head->next->val)
                head = head->next;
            head = head->next;
            prev->next = head;
        }
        else
        {
            prev = head;
            head = head->next;
        }
    }
    
    return tmp->next;
    }
};