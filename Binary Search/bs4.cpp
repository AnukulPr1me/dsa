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

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else if (nums[mid] < nums[right])
        {
            right = mid;
        }
        else
        {
            right--;
        }
    }
    return nums[left];
}

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (mid % 2 == 1)
        {
            mid--;
        }
        if (nums[mid] == nums[mid + 1])
        {
            left = mid + 2;
        }
        else
        {
            right = mid;
        }
    }
    return nums[left];
}

// koko eating banana

class Solution
{
public:
    int findMax(vector<int> &piles)
    {
        int maxi = INT_MIN;
        for (int pile : piles)
        {
            maxi = max(maxi, pile);
        }
        return maxi;
    }

    long long CalculateTotalHour(vector<int> &piles, int k)
    {
        long long totalHour = 0;
        for (int pile : piles)
        {
            totalHour += (pile + k - 1) / k; // This is a more efficient way to calculate the ceiling of pile/k
        }
        return totalHour;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = findMax(piles);
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long long totalHour = CalculateTotalHour(piles, mid);
            if (totalHour <= h)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
//