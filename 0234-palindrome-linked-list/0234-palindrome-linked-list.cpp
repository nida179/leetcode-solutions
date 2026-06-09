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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *pvs = NULL;
        ListNode *curr = slow;

        while(curr!=NULL){
            ListNode *temp = curr->next;
            curr->next = pvs;
            pvs = curr;
            curr = temp;
        }
        ListNode *left = head;
        ListNode *right = pvs;
        while(right!=NULL){
           if(left->val != right->val){
                return false;
           }
           left = left->next;
           right = right->next;
        }
        return true;
    }
};