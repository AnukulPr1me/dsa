#include <iostream>
#include <algorithm>
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

void insertionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
    }

}


// Merge sort 

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void MergeSort(vector<int>& arr, int n) {
    mergeSort(arr, 0, n - 1);
}

int main() {

    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();
    selectionSort(arr);

    for(int i : arr){
        cout << i << " ";
    }

    cout << endl;

    bubbleSort(arr);
    for(int i: arr){
        cout << i << " ";
    }

    cout << endl;

    insertionSort(arr);
    for(int j: arr){
        cout << j << " ";
    }

    cout << endl;

    MergeSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;


}