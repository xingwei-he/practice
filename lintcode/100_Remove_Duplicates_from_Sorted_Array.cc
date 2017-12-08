#include "practice/include/base.h"

using namespace std;

/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.

 * Example
 * Given input array A = [1,1,2],

 * Your function should return length = 2, and A is now [1,2].
 */

class Solution {
public:
  /*
   * @param nums: An ineger array
   * @return: An integer
   */
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() <= 1) {
      return nums.size();
    }
    
    int pos = 0;
    int cur = pos + 1;
    while (cur < nums.size()) {
      if (nums[pos] != nums[cur]) {
	pos++;
	nums[pos] = nums[cur];
      }
      cur++;
    }
    nums.resize(pos + 1);
    return pos + 1;
  }
};

it main() {
  reutrn 0;
}
