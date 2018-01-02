/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:172_Remove_Element.cc
 * Author:
 * Mail:
 * Created Time:星期二  1/ 2 10:22:04 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array and a value, remove all occurrences of that value in place and return the new length.
 * The order of elements can be changed, and the elements after the new length don't matter.
 *
 * Example
 * Given an array [0,4,4,0,0,2,4,4], value=4
 * return 4 and front four elements of the array is [0,0,0,2]
 */

class Solution {
public:
  /*
   * @param A: A list of integers
   * @param elem: An integer
   * @return: The new length after remove
   */
  /*
  int removeElement(vector<int> &A, int elem) {
    int left = 0;
    int right = A.size() - 1;
    while (left < right) {
      while (left < right && A[left] != elem) {
	left++;
      }
      while (left < right && A[right] == elem) {
	right--;
      }
      int temp = A[left];
      A[left] = A[right];
      A[right] = temp;
    }
    return left + 1;
  }
  */
  int removeElement(vector<int> &A, int elem) {
    int start = 0;
    int n = A.size();
    for(int i = 0; i < n; i++) {
      if (elem != A[i]) {
	A[start++] = A[i];
      }
    }
    A.resize(start);
    return start;
  }
};

int main() {
  int arr[] = {1,2,8,3,8,8,8,4,5,8,8,6};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
  cout << "nums:" << endl;
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "  ";
  }
  cout << endl;
  Solution sl;
  int len = sl.removeElement(nums, 8);
  cout << "len:" << len << endl;
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "  ";
  }
  cout << endl;
  return 0;
}
