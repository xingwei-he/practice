/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:50_Product_of_Array_Exclude_Itself.cc
 * Author:
 * Mail:
 * Created Time:星期三  1/17 16:51:03 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an integers array A.
 * Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B WITHOUT divide operation.
 *
 * Example
 * For A = [1, 2, 3], return [6, 3, 2].
 */

class Solution {
public:
  /*
   * @param nums: Given an integers array A
   * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
   */
  vector<long long> productExcludeItself(vector<int> &nums) {
    vector<long long> res;
    if (nums.size() == 0) {
      return res;
    }
    int n = nums.size();
    vector<long long> product(n + 1, 1);
    for (int i = n - 1; i >= 0; i--) {
      product[i] = product[i + 1] * nums[i];
    }
    long long temp = 1;
    for (int i = 0; i < n; i++) {
      res.push_back(temp * product[i + 1]);
      temp *= nums[i];
    }
    return res;
  }
};

int main() {
  //int arr[] = {0,0,9,9,1,2,3,4,901,55};//expected:[0,0,0,0,0,0,0,0,0,0]
  int arr[] = {1,2,3};//expected:[6,3,2]
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  vector<long long> res = sl.productExcludeItself(nums);
  for (int i = 0; i < res.size(); i++) {
    cout  << res[i] << endl;
  }
  cout << endl;
  return 0;
}
