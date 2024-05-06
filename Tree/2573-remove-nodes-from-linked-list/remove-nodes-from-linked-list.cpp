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
    ListNode* removeNodes(ListNode* head) {
        int prev = -1;
        return solve(head,prev);
    }
    ListNode* solve(ListNode *head,int &prev){
        if(head==NULL) return NULL;
        head->next=solve(head->next,prev);
        if(prev>head->val){
            head=head->next;
        }else{
            prev=head->val;
        }
        return head;
    }
};