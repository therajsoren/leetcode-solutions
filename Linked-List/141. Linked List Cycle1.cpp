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
    bool hasCycle(ListNode *head) {
       map<ListNode *, int> mp;
       ListNode * temp = head;
       while(temp){
        if(mp.find(temp) != mp.end()){
            return true;
        }
        mp[temp]++;
        temp = temp->next;
       }
       return false;
    }
};