#include <iostream>

#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i=0; i<n-2; i++){
        int min = i;
        for(int j=i; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }

        }
        if(min!=i){
            swap(arr[i], arr[min]);
        }
    }
}

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main() {

    vector<int> arr = {64, 25, 12, 22, 11};

    selectionSort(arr);

    for(int i : arr){
        cout << i << " ";
    }

    cout << endl;

    bubbleSort(arr);
    for(int i: arr){
        cout << i << " ";
    }


}