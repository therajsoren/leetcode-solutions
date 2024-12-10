#include <iostream>

using namespace std;

void printName(int cnt, int n) {
    // base case
    if (cnt == n) return; 
    cout << "Raj Soren" << endl;
    printName(cnt + 1, n); 
}

int main() {
    int n;
    cin >> n;
    printName(0, n); 
    return 0;
}
