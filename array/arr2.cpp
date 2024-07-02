#include <iostream>
#include <vector>
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
//optimal solution using xor
void missingNUM(vector<int>& arr) {
    int x1 = 0;
    int x2 = 0;
    int n = arr.size();
    for(int i=1; i<n; i++){
        x1 = x1^i;
    }
    for(int i=0; i<n; i++){
        x2 = x2^arr[i];
    }

    int missing = x1^x2;
    cout<< missing << " ";
}

void findMaxConsecutiveOnes(vector<int> arr){
    int count = 0;
    int maximum =0; 
    for(int i = 0; i<arr.size(); i++){
        if(arr[i]==1){
            count++;
            maximum = max(maximum, count);
        }
        else{
            count = 0;
        }
    }
    cout <<  maximum << " ";
}
void singleNum(vector<int> & arr){
    int count =0;
    for(int i : arr){
        count^= i;
    }
    cout << count;
}
int main()
{
    vector<int> arr = {1, 2, 3, 5,1,1};
    vector<int> arr1 ={1,1,2,3,3,4,4,5,5};

    missingNum(arr);
    cout<<endl;
    missingNUM(arr);
    cout<<endl;
    findMaxConsecutiveOnes(arr);
    cout << endl;
    singleNum(arr1);
    
}
