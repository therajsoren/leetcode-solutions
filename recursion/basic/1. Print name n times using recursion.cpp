#include <iostream>

using namespace std;

void printName(int i, int n) {
    // base case
    if (i > n) return;
    cout << "Raj Soren" << endl;
    printName(i + 1, n); 
}
int main() {
    int n;
    cin >> n;
    printName(1, n); // Start with i = 1
    return 0;
}
