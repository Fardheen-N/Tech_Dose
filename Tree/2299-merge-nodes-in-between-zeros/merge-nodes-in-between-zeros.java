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
    public ListNode mergeNodes(ListNode head) {
        ListNode temp=head,prev=null;
        int zero = 0,sum = 0;
        while(temp!=null)
        {   
            if(temp.val==0){zero++;}
            if(temp.val==0&&zero!=1){
               temp.val=sum;
               sum=0;
               if(zero==2){head=temp;}
               else prev.next=temp;
               prev=temp;
               temp=temp.next;
            }
            else{
                sum+=temp.val;
                ListNode carry=temp;
                temp=temp.next;
            }
        }
        return head;
    }
}