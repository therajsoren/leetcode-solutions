#include <iostream>

using namespace std;

// print from n to 1
void print(int i, int n) {
    // base case
   if ( i < 1) return;
   cout << i << endl;
   print(i - 1,n);
}

int main() {
    int n;
    cin >> n;
    print(n,n);
    return 0;
}
