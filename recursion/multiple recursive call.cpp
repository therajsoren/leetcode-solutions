#include <iostream>

using namespace std;

int f(int n){
    if(n <= 1 ) return n;
    int last = f(n - 1);
    int slast = f(n - 2);
    return last + slast;
}

int main(){
   // multiple recursion call
   // for example fibonanci number in order to find 
   // f(n) , we have to know f(n - 1) and f(n - 2)
   int n; cin >> n;
   cout << f(n) << endl;
}

// tc O(2^n)