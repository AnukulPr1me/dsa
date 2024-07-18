#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(vector<int> &arr, int num)
{
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

int newlowerBound(vector<int>& arr, int num){
    int lb = lower_bound(arr.begin(), arr.end(), num) - arr.begin();

    return lb;
}
int upperBound(vector<int>& arr, int num) {
    int n = arr.size();
    int left = 0;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= num) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
int newupperBound(vector<int>& arr, int num){
    int ub = upper_bound(arr.begin(), arr.end(), num) - arr.begin();
    return ub;
}
vector <int> firstAndLast(vector<int>& arr, int num){
    int n = arr.size();
    int first = -1;
    int last = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == num){
            if(first == -1){

                first = i;
            }
            last = i = i;
        }
    }
    return vector<int>({first,last});
}
int main()
{
    vector<int> arr = {3, 5, 6, 7, 9, 13, 15, 17};
    int num = 8;
    int lowIndex = lowerBound(arr, num);
    cout << lowIndex << " ";

    int new_low_index = newlowerBound(arr, 7);


    cout << new_low_index << " ";

    int new_up_Index = newupperBound(arr, num);
    cout << new_up_Index << " ";

    int upIndex = upperBound(arr, 14);
    cout << upIndex << " ";

    vector<int> from = firstAndLast(arr, 3);
    for(int i: from){
        cout << i << " ";
    }

    return 0;
}
