/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
  struct ListNode *slow_ptr = head, *fast_ptr = head;
    struct ListNode *second_half, *prev_of_slow_ptr = head;
    struct ListNode* midnode = NULL; 
    bool res = true; 
 
    if (head != NULL && head->next != NULL) {

        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        if (fast_ptr != NULL) {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        second_half = slow_ptr;
        prev_of_slow_ptr->next= NULL; 
        reverse(&second_half); 
        res = compareLists(head, second_half); 
        reverse( &second_half); 
        if (midnode != NULL) {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else
            prev_of_slow_ptr->next = second_half;
    }
    return res;}
 void reverse(struct ListNode** head_ref)
{
    struct ListNode* prev = NULL;
    struct ListNode* current = *head_ref;
    struct ListNode* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
int compareLists(struct ListNode* head1, struct ListNode* head2)
{
    struct ListNode* temp1 = head1;
    struct ListNode* temp2 = head2;
 
    while (temp1 && temp2) {
        if (temp1->val == temp2->val) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }
    if (temp1 == NULL && temp2 == NULL)
        return 1;
    return 0;
}
 
