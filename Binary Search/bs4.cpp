#include <iostream>
#include <vector>
#include <algorithm>

int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int maxRot(vector<int>& nums){
    int ans = INT_MAX;
    int n = nums.size();
    int left = 0, right = n - 1;
    while (nums[left] < nums[right]){
        int mid = left + (right - left) / 2;
        if (nums[right] < nums[mid]){
            ans = max(ans, nums[left]);
            left = mid + 1;
        } else {
            ans = min(ans, nums[mid]);
            right = mid -1;
        }
    }
}