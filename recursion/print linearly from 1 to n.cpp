#include <iostream>

using namespace std;

// print linearly from 1 to n
void print(int i, int n) {
    // base case
    if(i > n) return;
    cout << i << endl;
    print(i + 1, n);
}

int main() {
    int n;
    cin >> n;
    print(1,n);
    return 0;
}
