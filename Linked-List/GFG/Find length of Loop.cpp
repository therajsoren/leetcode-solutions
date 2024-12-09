class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int findLength(Node *slow, Node *fast){
        int cnt = 1;
        fast = fast->next;
        while(slow != fast){
            cnt++;
            fast = fast->next;
        }
        return cnt;
    }
    int countNodesinLoop(Node *head) {
        // Code here
        Node *slow = head, *fast = head;
        int cnt = 0;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            cnt++;
            if(slow == fast){
                return findLength(slow,fast);
            }
        }
        return 0;
    }
};
