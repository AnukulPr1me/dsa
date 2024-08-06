#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        // Ensure that nums1 is the smaller array
        if (size1 > size2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0, high = size1, halfLength = (size1 + size2 + 1) / 2;
        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = halfLength - partition1;

            // Check if partition1 is too small
            if (partition1 < size1 && nums1[partition1] < nums2[partition2 - 1]) {
                low = partition1 + 1;
            }
            // Check if partition1 is too big
            else if (partition1 > 0 && nums1[partition1 - 1] > nums2[partition2]) {
                high = partition1 - 1;
            }
            // Partition is perfect
            else {
                int maxLeft = 0;
                if (partition1 == 0) {
                    maxLeft = nums2[partition2 - 1];
                } else if (partition2 == 0) {
                    maxLeft = nums1[partition1 - 1];
                } else {
                    maxLeft = max(nums1[partition1 - 1], nums2[partition2 - 1]);
                }

                // If the total length is odd
                if ((size1 + size2) % 2 == 1) {
                    return maxLeft;
                }

                int minRight = 0;
                if (partition1 == size1) {
                    minRight = nums2[partition2];
                } else if (partition2 == size2) {
                    minRight = nums1[partition1];
                } else {
                    minRight = min(nums1[partition1], nums2[partition2]);
                }

                // If the total length is even
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "The median of the two sorted arrays is: " << median << endl;

    return 0;
}
