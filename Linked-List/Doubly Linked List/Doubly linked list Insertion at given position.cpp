class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        if(pos == 0){
            Node * newNode = new Node (data);
            Node * front = head->next;
            front->prev = newNode;
            newNode->next = front;
            newNode->prev = head;
            head->next = newNode;
            return head;
        }
        Node * temp = head;
        int cnt = 0;
        while(temp->next){
            cnt = cnt + 1;
            temp = temp->next;
            if(cnt == pos){
                break;
            }
        }
        // cout << cnt << endl;
        if(!temp->next){
            Node * front = new Node(data);
            temp->next = front;
            front->prev = temp;
            return head;
        }
        Node * front = new Node(data);
        Node * tail = temp->next;
        temp->next = front;
        front->prev = temp;
        front->next = tail;
        tail->prev = front;
        return head;
    }
};