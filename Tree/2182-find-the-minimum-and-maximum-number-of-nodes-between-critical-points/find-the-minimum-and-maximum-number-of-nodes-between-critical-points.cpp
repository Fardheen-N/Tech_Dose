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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL) return {-1,-1};
        int maxi = 0;
        int mini = INT_MAX;
        int ind = -1,cur=-1,par=2;
        ListNode *prev=head;
        ListNode *next=head->next->next;
        ListNode *curr=head->next;
        while(next!=NULL){
            if(prev->val<curr->val && curr->val>next->val || prev->val>curr->val && curr->val<next->val){
                if(ind==-1) ind = par;
                else{
                maxi = max(maxi,abs(ind-par));
                mini = min(mini,abs(cur-par));
                }
                cur = par;
            }
            par++;
            prev = curr;
            curr = next;
            next = next->next;
        }
        if(maxi==0 && mini==INT_MAX) return {-1,-1};
        return {mini,maxi};
    }
};