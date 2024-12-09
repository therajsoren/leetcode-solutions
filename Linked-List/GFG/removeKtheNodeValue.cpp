#include <bits/stdc++.h>

using namespace std;

struct Node {
        public:
        int data;
        Node *next;
        
        public:
        Node(int data1, Node* next1){
                data = data1;
                next = next1;
        }
        
        public:
        Node(int data1){
                data = data1;
                next = nullptr;
        }
};

Node* convertArrToLL(vector<int>& arr){
        Node *head = new Node(arr[0]);
        Node *mover = head;
        for(int i = 1; i < arr.size(); i++){
                Node * temp = new Node(arr[i]);
                mover->next = temp;
                mover = temp;
        }
        return head;
}

void print(Node * head){
    Node * temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node * removeKthNode(Node * head,int value){
    if(head == NULL){
        return head;
    }
   if(head->data == value){
    Node * temp = head;
    head = head->next;
    delete temp;
    return head;
   }
   Node * temp = head;
   Node * prev = NULL;
   while(temp != NULL){
    if(temp->data == value){
        prev->next = prev->next->next;
        delete temp;
        break;
    }
    prev = temp;
    temp = temp->next;
   }
   return head;
}
int main() {
  vector<int> arr = {2,5,8,7};
  Node *head = convertArrToLL(arr);
//   cout << head->data;
  int value = 2;
  head = removeKthNode(head,value);
  print(head);
}