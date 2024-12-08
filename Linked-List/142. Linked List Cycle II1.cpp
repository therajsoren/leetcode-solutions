/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * collisionPoint(ListNode * slow, ListNode * fast,ListNode * head){
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head, * fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return collisionPoint(slow,fast,head);
            }
        }
        return NULL;
    }
};