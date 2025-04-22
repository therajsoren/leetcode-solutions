#include <bits/stdc++.h>

using namespace std;

void deleteMiddle(stack<int>&st, int current, int size){
    if(current == size / 2){
        st.pop();
        return;
    }
    int top = st.top();
    st.pop();
    deleteMiddle(st,current + 1, size);
    st.push(top);
}

void deleteMiddleElement(stack<int>& st){
    int size = st.size();
    deleteMiddle(st,0,size);
}

int main(){
    stack<int> st(deque<int>{3,1,5,2,4});
    deleteMiddleElement(st);
    
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}