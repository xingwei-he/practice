/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:61_Search_for_a_Range.cc
 * Author:
 * Mail:
 * Created Time:星期一 12/18 12:32:26 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a sorted array of n integers, find the starting and ending position of a given target value.
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

class Solution {
public:
  /*
   * @param A: an integer sorted array
   * @param target: an integer to be inserted
   * @return: a list of length 2, [index1, index2]
   */
  vector<int> searchRange(vector<int> &A, int target) {
    vector<int> range;
    if (A.size() < 1) {
      range.push_back(-1);
      range.push_back(-1);
      return range;
    }

    int left = 0;
    int right = A.size() - 1;
    int mid = 0;
    while (left <= right) {
      mid = (left + right) / 2;
      if (A[mid] == target) {
	break;
      } else if (A[mid] < target) {
	left = mid + 1;
      } else {
	right = mid - 1;
      }
    }
    if (A[mid] == target) {
      int i;
      for (i = mid; i >= 0; i--) {
	if (A[i] == target) {
	  continue;
	} else {
	  break;
	}
      }
      range.push_back(i + 1);
      for (i = mid; i < A.size(); i++) {
	if (A[i] == target) {
	  continue;
	} else {
	  break;
	}
      }
      range.push_back(i - 1);
    } else {
      range.push_back(-1);
      range.push_back(-1);
    }
    return range;
  }
};

int main() {
  //int arr[] = {1,2,3,3,3,4,5,5,6,7,7,8,8,8,9,9,10,11,12,13,14,14,15,15,15};
  int arr[] = {1};
  int target = 1;
  vector<int> nums(begin(arr), end(arr));
  Solution sl;
  vector<int> range = sl.searchRange(nums, target);
  for (int i = 0; i < range.size(); i++) {
    cout << range[i] << "  ";
  }
  cout << endl;
  return 0;
}

