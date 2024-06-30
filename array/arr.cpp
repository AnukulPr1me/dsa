#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void maxElement(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int largest = arr.back();
    cout << largest << endl;
}
//optimal
int largest(int arr[], int n) {
    int max = arr[0]; // Initialize max with the first element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void secondLargest(vector<int>& arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int largest = arr[n-1];
    if(largest>arr[n-2]){
        int secLarge = arr[n-2];
        cout << secLarge << endl;
    }
    else{
        arr[n--];
    }
}
//optimal
int print2largest(int arr[], int n) {
    int largest = arr[0];
    int secondLargest = -1; 

    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if(arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }
    
    return secondLargest;
}

void removeDup(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    while (i < n - 1) {
        if (arr[i] == arr[i + 1]) {
            arr.erase(arr.begin() + i);
            n--; 
        } else {
            i++; 
        }
    }
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

//checking if the following array is sorted or not 
bool checkSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

//taking the first element of the array and placeing it at the end and the adjusting the rest of the elements.

void leftRot_Arr_1_palce(vector<int>& arr){
    int n = arr.size();
    int firstElement = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i]; // Shift each element one position to the left
    }
    arr[n - 1] = firstElement; // Place the first element at the end
    for(int i: arr){
        cout << i << " ";
    }
}

void leftRot_Arr_N_place(vector<int>& arr){
    int n = arr.size();
    int d;
    d = d%n;
    int temp[d];
    for(int i=0; i<d; i++){
        temp[i] = arr[i];
    }
    for (int i = d; i < n; i++)
    {
        arr[i-d] = arr[i]; 
    }
    for(int i =n-d; i<n; i++) {
        arr[i] = temp[i-(n-d)];
    }
    
    
}

void moveZero(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            swap(arr[i], arr[n-1]);
            n--;
        }
    }
    for(int i: arr){
        cout << i << " ";
    }
}

void linearSearch(vector<int>& arr, int n) {
    bool found = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == n) {
            cout << "Element " << n << " found at index " << i << endl;
            found = true;
            break;  // Exit the loop since we found the element
        }
    }
    
    if (!found) {
        cout << "Element " << n << " not found in the array." << endl;
    }
}


vector<int> noDupUnion(const vector<int>& arr1, const vector<int>& arr2) {
    unordered_set<int> uniqueElements;
    
    // Insert all elements of arr1 into uniqueElements
    for (int num : arr1) {
        uniqueElements.insert(num);
    }
    
    // Insert elements of arr2 into uniqueElements
    for (int num : arr2) {
        uniqueElements.insert(num);
    }
    
    // Convert uniqueElements back to a vector
    vector<int> result(uniqueElements.begin(), uniqueElements.end());
    sort(result.begin(), result.end());
    
    return result;
}

int main() {
    vector<int> arr = {10, 20, 5, 8, 25, 8};
    vector<int> arr1 = {10, 0, 5, 2, 9, 1, 12, 0, 19, 3};
    maxElement(arr);

    cout << endl;
    removeDup(arr);

    cout << endl;
    secondLargest(arr);

    cout << endl;
    cout << " " << checkSort(arr);
    cout << endl;

    cout << endl;
    leftRot_Arr_1_palce(arr);
    cout << endl;

    cout << endl;
    leftRot_Arr_N_place(arr);
    for(int i: arr){
        cout << i << " ";
    }
    cout << endl;

    moveZero(arr1);
    cout<<endl;

    linearSearch(arr1, 0);
    cout << endl;

    vector<int> merged = noDupUnion(arr, arr1);

    for(int num:merged){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
