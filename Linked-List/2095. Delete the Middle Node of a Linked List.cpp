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
    int getSize(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int sz = getSize(head);
        int middle = sz/2;
        int cnt = 0;
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        while(temp){
            if(cnt == middle - 1){
                temp->next = temp->next->next;
                break;
            }
            cnt++;
            temp = temp->next;
        }
        return head;
    }
};