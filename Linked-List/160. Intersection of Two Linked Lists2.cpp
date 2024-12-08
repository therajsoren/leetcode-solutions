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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
            return NULL;
        }
        ListNode * temp1 = headA, * temp2 = headB;
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
            if(temp1 == temp2){
                return temp1;
            }
            if(temp1 == NULL) {
                temp1 = headB;
            }
            if(temp2 == NULL){
                temp2 = headA;
            }
        }
        return temp1;
    }
};