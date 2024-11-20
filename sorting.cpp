#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

// Insertion Sort
void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) { // Start from index 1
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && temp < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

// Quick Sort
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Merge Sort
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = array[left + i];
    for (int i = 0; i < n2; i++) R[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) array[k++] = L[i++];
        else array[k++] = R[j++];
    }
    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

// Helper function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int myArray[] = {6, 4, 2, 5, 1, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    // Bubble Sort
    int bubbleArray[] = {6, 4, 2, 5, 1, 3};
    bubbleSort(bubbleArray, size);
    cout << "Bubble Sort: ";
    printArray(bubbleArray, size);

    // Selection Sort
    int selectionArray[] = {6, 4, 2, 5, 1, 3};
    selectionSort(selectionArray, size);
    cout << "Selection Sort: ";
    printArray(selectionArray, size);

    // Insertion Sort
    int insertionArray[] = {6, 4, 2, 5, 1, 3};
    insertionSort(insertionArray, size);
    cout << "Insertion Sort: ";
    printArray(insertionArray, size);

    // Quick Sort
    int quickArray[] = {6, 4, 2, 5, 1, 3};
    quickSort(quickArray, 0, size - 1);
    cout << "Quick Sort: ";
    printArray(quickArray, size);

    // Merge Sort
    int mergeArray[] = {6, 4, 2, 5, 1, 3};
    mergeSort(mergeArray, 0, size - 1);
    cout << "Merge Sort: ";
    printArray(mergeArray, size);

    return 0;
}
