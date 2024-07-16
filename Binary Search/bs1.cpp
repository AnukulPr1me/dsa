
#include <iostream>
#include <vector>
using namespace std;


//Iterative method  
int search(vector<int> & nums){
    int n = nums.size();
    int target = 8;
    int low=0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(target>nums[mid]){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = { 1, 4, 5, 8, 9, 10};
    
    int result = search(nums);

    cout << result;
    return 0;
}