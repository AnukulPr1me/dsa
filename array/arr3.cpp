#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> zeroOneTwo(vector<int>& arr) {
    int zero = 0, one = 0, two = 0;

    // Count the number of 0s, 1s, and 2s
    for(int i = 0; i< arr.size(); i++){
        if(arr[i] == 0){
            zero++;
        } else if(arr[i] == 1){
            one++;
        } else if(arr[i] == 2){
            two++;
        }
    }

    // Overwrite the array with 0s, 1s, and 2s based on the counts
    int index = 0;
    for(int i = 0; i < zero; i++) {
        arr[index++] = 0;
    }
    for(int i = 0; i < one; i++) {
        arr[index++] = 1;
    }
    for(int i = 0; i < two; i++) {
        arr[index++] = 2;
    }

    return arr;
}

int main() {
    vector<int> arr4 = {1,0,0,1,1,2,1,0,2,1,2};
    zeroOneTwo(arr4);
    
    // Output the sorted array
    for(int num : arr4) {
        cout << num << " ";
    }

    return 0;
}
