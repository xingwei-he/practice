/**************************************
* He Xingwei, All Rights Reserved.
* Filename:4.cpp
* Date:2022-04-18 15:09:21
* Description:
**************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// 获取第k个元素
	int getKthItem(vector<int> &nums1, vector<int> &nums2, int k) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		int index1 = 0, index2 = 0;
		while (true) {
			// 越界
			if (index1 == len1) {
				return nums2[index2 + k - 1];
			}
			if (index2 == len2) {
				return nums1[index1 + k - 1];
			}
			// 边界条件，k为1时返回最小的（第一个）元素
			if (1 == k) {
				return min(nums1[index1], nums2[index2]);
			}

			int new_index1 = min(index1 + k / 2, len1) - 1;
			int new_index2 = min(index2 + k / 2, len2) - 1;
			int val1 = nums1[new_index1];
			int val2 = nums2[new_index2];
			// 比较nums1[k/2 - 1]和nums2[k/2 - 1]
			// 如果 nums1[k/2 - 1] 更小，则 nums1[0] - nums1[k/2 - 1] 都不满足
			// 同理对 nums2 亦然
			if (val1 <= val2) {
				k = k - (new_index1 - index1 + 1);
				index1 = new_index1 + 1;
			} else {
				k = k - (new_index2 - index2 + 1);
				index2 = new_index2 + 1;
			}
		}
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int len1 = nums1.size();
    	int len2 = nums2.size();
    	int total_len = len1 + len2;
    	
    	double res = 0.0;
    	if (total_len % 2 == 1) { // 1个中位数
    		int mid = total_len / 2 + 1;
    		res = getKthItem(nums1, nums2, mid);
    	} else { // 2个中位数
    		int mid1 = total_len / 2;
    		int mid2 = total_len / 2 + 1;
    		res = (getKthItem(nums1, nums2, mid1) + getKthItem(nums1, nums2, mid2)) / 2.0;
    	}
    	return res;
    }
};

int main() {

    vector<int> nums1{1,2};
    vector<int> nums2{3,4};

    Solution sl;
    double res = sl.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
    return 0;
}

