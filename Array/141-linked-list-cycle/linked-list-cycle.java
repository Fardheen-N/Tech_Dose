/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    List <ListNode > list = new ArrayList();
    public boolean hasCycle(ListNode head) {
        if(head==null) return false;
        if(list.contains(head)) return true;
        list.add(head);
        return hasCycle(head.next);
    }
}