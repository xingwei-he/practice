#include "base.h"

using namespace std;

/**
 * Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *
 * Example:
 *
 * Given nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 */

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (0 == nums.size()) {
      return 0;
    }
    int i = 0;// 初始状态，i记录已经处理过的位置
    //int processed_num = nums[0];
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] == nums[j]) {
	continue;
      } else {
	i++;
	nums[i] = nums[j];
      }
    }
    return (i + 1);
  }
};

int main() {
  return 0;
}
