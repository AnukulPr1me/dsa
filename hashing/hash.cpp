#include <iostream>

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


int main() {
    int arr[] = {4, 5, 7, 4, 10};
    int n = 4;
    counterNum(n, arr);
    return 0;

}