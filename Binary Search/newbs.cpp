#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

int samllestDiv(vector<int>& arr, int limit) {
    int n = arr.size();
    int maximum = *max_element(arr.begin(), arr.end());
    for(int b = 1; b<=maximum; b++){
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += ceil((double)(arr[i])/ double(b));
        }
        if(sum <=limit){
            return b;
        }
    }
    return -1;
}

int sum(vector<int>& arr, int div){
    int n = arr.size();
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += ceil((double)(arr[i])/ (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size();
    if(n > limit) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());
    while (low<=high)
    {
        int mid = low + (high - low) / 2;
        if(sum(arr, mid) <= limit){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
    //painter partition function
    bool isPossible(vector<int> &boards, int n, int k, int mid) {
    int paintersRequired = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > mid) return false;

        if (currentSum + boards[i] > mid) {
            paintersRequired++;
            currentSum = boards[i];

            if (paintersRequired > k) return false;
        } else {
            currentSum += boards[i];
        }
    }

    return true;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int n = boards.size();
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = low + (low - high) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}
//end
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 10;
    int result = samllestDiv(arr, limit);
    cout << "Smallest divisor that satisfies the condition: " << result << endl;
    return 0;
}