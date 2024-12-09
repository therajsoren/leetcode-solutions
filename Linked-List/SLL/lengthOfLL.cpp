int getCount(struct Node* head) {
        Node * temp = head;
        int cnt = 0;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }