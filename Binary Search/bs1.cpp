
#include <iostream>
#include <vector>
using namespace std;

// Iterative method
int search(vector<int> &nums)
{
    int n = nums.size();
    int target = 8;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// recursive function
int newSearch(vector<int> &arr, int left,  int right , int target)
{
    if (left > right)
    {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (target > arr[mid])
    {
        return newSearch(arr , mid+1, right,  target);
    }
    else{
        return newSearch(arr, left, mid-1, target);
    }
}

int  recursiveSearch(vector<int>& arr, int left, int right, int target){
    return newSearch(arr,  0, arr.size() - 1, target);
}
int main()
{
    vector<int> nums = {1, 4, 5, 8, 9, 10};

    int result = search(nums);

    cout << result;
    
    cout << endl;

    int newResult = recursiveSearch(nums, 0 , nums.size() - 1, 9);
    cout << newResult;

    return 0;
}