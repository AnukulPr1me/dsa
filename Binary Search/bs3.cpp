#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int>& arr, int num){
    int n = arr.size();
    int left = 0;
    int right = n;
    while(left < right){
        int mid = left+(right-left)/2;
        if(arr[mid]<num){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

int upperBound(vector<int>& arr, int num){
    int n = arr.size();
    int left = 0;
    int right = n;
    while(left<right){
        int mid = left+(right-left)/2;
        if(arr[mid]<=num){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

vector<int>newPair(vector<int>& arr, int num){
    int low;
    int high;
    low = lowerBound(arr,num);
    high = upperBound(arr,num) - 1;
    return vector<int>({low,high});
}

int main(){
    vector<int> arr = {1,2,4,7,7,7,15,18};
    int num = 7;
    vector<int> lw = newPair(arr, num);
    for(int i : lw){
        cout <<  i << " ";
    }

}