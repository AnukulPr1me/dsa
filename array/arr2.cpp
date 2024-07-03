#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void missingNum(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int appear = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                appear = 1;
                break;
            }
        }
        if (appear == 0)
        {
            cout << i << " ";
        }
    }
}
// optimal solution using xor
void missingNUM(vector<int> &arr)
{
    int x1 = 0;
    int x2 = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        x1 = x1 ^ i;
    }
    for (int i = 0; i < n; i++)
    {
        x2 = x2 ^ arr[i];
    }

    int missing = x1 ^ x2;
    cout << missing << " ";
}

void findMaxConsecutiveOnes(vector<int> arr)
{
    int count = 0;
    int maximum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count++;
            maximum = max(maximum, count);
        }
        else
        {
            count = 0;
        }
    }
    cout << maximum << " ";
}
void singleNum(vector<int> &arr)
{
    int count = 0;
    for (int i : arr)
    {
        count ^= i;
    }
    cout << count;
}

int longestSubarrayWithSumK(vector<int> &arr, int k)
{

    int length = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
}

// int twoSum(vector<int>& arr, int target, vector<int>& result){
//     for(int i = 0; i<arr.size(); i++){
//         for(int j = i+1; j<arr.size(); j++){
//             if(arr[i]+arr[j] == target){
//                result = vector<int>{i , j};
//                return 1;
//             }
//         }
       
//     }
//     result = vector<int>{};
//     return 0;
// }


int main()
{
    vector<int> arr = {1, 2, 3, 5, 1, 1};
    vector<int> arr1 = {1, 1, 2, 3, 3, 4, 4, 5, 5};
    vector<int> arr2 = {1, 2, 1, 1, 1, 2, 1, 3, 5, 7};
    vector<int> arr3 = {1,3,4,7,9,2};
    
    int k = 3;
    missingNum(arr);
    cout << endl;
    missingNUM(arr);
    cout << endl;
    findMaxConsecutiveOnes(arr);
    cout << endl;
    singleNum(arr1);
    cout << endl;
    longestSubarrayWithSumK(arr2, k);
    cout << endl;
}
