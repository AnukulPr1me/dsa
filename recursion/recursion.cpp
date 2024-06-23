#include <iostream>

using namespace std;

void printName(string name,  int n){
    if(n < 5){
        cout << name << endl;
        printName(name, n = n+1);
        
    }
}

void printNum(int i, int n) {
    if(i<n) {
        cout << i << endl;
        
        printNum(i=i+1, n);
    }
}

void printNumDec(int i, int n) {
    if(i<0) {
        return;
    }
    cout << i << endl;
    printNumDec(i = i-1, n);
}


//parameterised
void sumOfN(int n, int i) {
    if(n<=0){
        cout << i << endl;
        return;
    }
    else{
        sumOfN(n-1, i+n);
    }
}
//functional
int sumOfNF(int n) {
    if (n == 0) return 0;
    return n + sumOfNF(n-1);
}

int factOfN(int n) {
    if (n == 0) return 1;
    return n * factOfN(n-1);
}

void swapingArr(int i,int arr[], int n ){
    if(i>n/2) {
        return;
    }
    swap(arr[i], arr[n-i-1]);
    swapingArr(i+1, arr, n);
}

bool isPalindrom(int i, string &name){
    if(i>=name.size()/2) {
        return true;
    }
    if(name[i]!=name[name.size()-i-1]) return false;
    return isPalindrom(i+1, name);
}

int fib(int n) {
    if(n<=1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}
int main() {
    int i = 0;
    int n;
    cin >> n;
    // int arr[n];
    // for(int i = 0; i<n;i++) cin >> arr[i];
    // swapingArr(0, arr, n);
    // for(int i = 0; i<n; i++) cout << arr[i] << " ";
    // cout << factOfN(n);
    // string name = "madam";
    // cout << isPalindrom(0,name);  //bool function is palindrom or not 
    cout << fib(n);
    
    return 0;

}