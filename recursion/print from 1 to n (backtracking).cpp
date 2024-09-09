#include <iostream>

using namespace std;

// print from 1 to n (backtracking)
void print(int i, int n) {
   if(i < 1) return;
   
   print(i - 1, n);
   cout << i << endl;
}

int main() {
    int n;
    cin >> n;
    print(n,n);
    return 0;
}
