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
    int getSize(ListNode * head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode *collisionPoint(ListNode * headA, ListNode * headB, int d){
        while(d){
            d--;
            headB = headB->next;
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int headASize = getSize(headA);
        int headBSize = getSize(headB);

        if(headASize < headBSize){
            return collisionPoint(headA,headB,headBSize - headASize);
        } else{
            return collisionPoint(headB,headA,headASize - headBSize);
        }
        return NULL;
    }
};