#include "practice/include/base.h"

using namespace std;

/**
 * Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int bar[MAX_BITS] = {0};
    for (int i = 0; i < nums.size(); i++) {
      int temp = nums[i];
      int j = MAX_BITS - 1;
      while (j >= 0) {
	if(1 == (temp & 1)) {
	  bar[j] += 1;
	}
	j--;
	temp >>= 1;
      }
    }
   
    int res = 0;
    for (int i = 0; i < MAX_BITS; i++) {
      bar[i] %= 3;
    }
    for (int i = 0; i < MAX_BITS; i++) {
      res = res * 2 + bar[i];
    }
    
    return res;
  }

 private:
  static const int MAX_BITS = 64;
};

int main() {
  // {-2,-2,1,1,-3,1,-3,-3,-4,-2}
  int arr_1[] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};

  vector<int> nums_1(begin(arr_1), end(arr_1));

  Solution solution_handler;
  cout << solution_handler.singleNumber(nums_1) << endl;

  return 0;
}
