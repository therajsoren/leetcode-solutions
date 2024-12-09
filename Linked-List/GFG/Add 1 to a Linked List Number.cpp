class Solution {
  public:
    int addHelper(Node* temp){
        if(!temp){
            return 1;
        }
        int carry = addHelper(temp->next);
        temp->data = temp->data + carry;
        if(temp->data > 9){
            temp->data = 0;
            return 1;
        }
        return 0;
        
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        int carry = addHelper(head);
        if(carry == 1){
            Node * newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};
