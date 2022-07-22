/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        
        // the basic idea is to maintain two queues, the first one stores all nodes with val less than x , and the second queue stores all the rest nodes. Then concat these two queues. Remember to set the tail of second queue a null next, or u will get TLE.
        
        //dummy heads of the 1st and 2nd queues
        
        ListNode dummy1 =new ListNode(0);
        ListNode  dummy2=new ListNode(0);
        
        //current tails of the two queues;
        ListNode curr1=dummy1;
        ListNode curr2= dummy2;
        
        
        while(head!=null)
        {
            if(head.val<x)
            {
                curr1.next=head;
                curr1=head;
            }
            
            else
            {
                curr2.next=head;
                curr2=head;
            }
            
            head=head.next;
        }
        
        curr2.next=null;  //important! avoid cycle in linked list. otherwise u will get TLE.
        
        curr1.next=dummy2.next;
        
        return dummy1.next;
    }
}