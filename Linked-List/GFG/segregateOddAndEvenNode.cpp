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
    int getSize(ListNode * head){
        int cnt = 0;
        while(head != NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* oddEvenList(ListNode* head) {
        int sz = getSize(head);
        ListNode * temp = head;
        ListNode * oddDummy = new ListNode();
        ListNode * evenDummy = new ListNode();
        ListNode * odd = oddDummy;
        ListNode * even = evenDummy;
        if(head == NULL) return NULL;
        for(int i = 0; i < sz; i++){
            if(temp->val & 1) {
                odd->next = new ListNode(temp->val);
                odd = odd->next;
            } 
            temp = temp->next;
        }
        temp = head;
         for(int i = 0; i < sz; i++){
            if(temp->val % 2 == 0) {
                even->next = new ListNode(temp->val);
                even = even->next;
            } 
            temp = temp->next;
        }
        odd->next = evenDummy->next;
        return oddDummy->next;
    }
};