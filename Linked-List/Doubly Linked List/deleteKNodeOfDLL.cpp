#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node * back;
    
    Node(int data1, Node * next1,Node * back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

Node * convertArr2DLL(vector<int> & arr){
    Node * head = new Node(arr[0]);
    Node * prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node * temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node *deleteHead(Node * head){
    if(!head || !head->next){
        return NULL;
    }
    Node * prev = head;
    head = head->next;
    head->back = NULL;
    prev ->next = NULL;
    delete prev;
    return head;
}
Node *deleteTail(Node * head){
    if(!head || !head->next){
        return NULL;
    }
    Node * tail = head;
    Node * prev = NULL;
    while(tail->next){
        tail = tail->next;
   }
   prev = tail->back;
   prev->next = NULL;
   tail->back = NULL;
   delete tail;
   return head;
}

Node *deleteK(Node * head,int k){
    Node * temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    Node * prev = temp->back;
    Node * front = temp->next;
    
    if(!prev && !front){
        delete temp;
        return NULL;
    } else if(!prev){
        return deleteHead(head);
    } else if(!front){
        return deleteTail(head);
    } else{
        prev->next = front;
        front->back = prev;
        temp->next = NULL;
        temp->back = NULL;
        delete temp;
        return head;
    }
}
void print(Node * head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    vector<int> arr = {12,5,8,7};
    Node * head = convertArr2DLL(arr);
    head = deleteK(head,1);
    print(head);
}