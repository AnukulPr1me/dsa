#include <iostream>
#include <vector>

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

int newlowerBond(vector<int>& arr, int num){
    int lb = lower_bound(arr.begin(), arr.end(), num) - arr.begin();

    return lb;
}
int main()
{
    vector<int> arr = {3, 5, 6, 7, 9, 13, 15, 17};
    int num = 8;
    int index = lowerBound(arr, num);
    cout << index << " ";

    int new_index = newlowerBond(arr, num);
    cout << new_index << " ";
    return 0;
}
