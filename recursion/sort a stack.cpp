#include <bits/stdc++.h>

using namespace std;

void insert(stack<int>&st, int top){
    // insert the last element at its correct position in the sorted array
    if(st.empty() || st.top() <= top){
        st.push(top);
        return;
    }
    int value = st.top();
    st.pop();
    insert(st,top);
    st.push(value);
}

void sortStack(stack<int>&st){
    // sort the array except the last element
    if(st.size() <= 1) return;

    int top = st.top();
    st.pop();
    sortStack(st);
    insert(st,top);
}

int main(){
    stack<int> st(deque<int>{3,1,5,2,4});
    sortStack(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}