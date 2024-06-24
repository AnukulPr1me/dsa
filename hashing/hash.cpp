#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void counterNum(int n, int arr[]){
    int counter = 0;
    for(int i=0; i<=n; i++) {
        if(arr[i] == n){
            counter = counter + 1;
        }
    }
    cout << counter;
}

void stringHash(){
    string s;
    cin>>s;

    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]++];
    }

    int q;
    cin>>q;
    while(q--) {
        char c;
        cin >> c;
        cout << hash[c] << endl;
    }
    

}
void mapHash() {
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int,int>mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    int q;
    cin >>q;
    while(q--) {
        int number;
        cin>>number;
        cout << mpp[number] << endl;
    }
    
    
}


int main() {
    // int arr[] = {4, 5, 7, 4, 10};
    // int n = 4;
    // counterNum(n, arr);
    mapHash();
    return 0;

}