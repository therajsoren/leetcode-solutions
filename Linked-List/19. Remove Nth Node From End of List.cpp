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
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = getSize(head);
        int k = sz - n;
        if(k == 0){
            ListNode * temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int cnt = 0;
        ListNode * temp = head;
        while(temp){
            if(cnt == k - 1){
                temp->next = temp->next->next;
                break;
            }
            cnt++;
            temp = temp->next;
        }
        return head;
    }
};