
#include <bits/stdc++.h>

using namespace std;

void generateSubsequence(int index,vector<int> & ds, int arr[],int n){
    if(index == n){
        for(auto it : ds){
            cout << it << " ";
        }
        if(ds.size() == 0){
            cout << "{ }" << " ";
        }
        cout << endl;
        return;
    }
    
    generateSubsequence(index + 1,ds,arr,n);
    ds.push_back(arr[index]);
    
    generateSubsequence(index + 1, ds, arr, n);
    ds.pop_back();
}

int main()
{
    // generate all susequence
    int arr[] = {3,1,2};
    int n = 3;
    vector<int> ds;
    generateSubsequence(0,ds,arr,n);
}