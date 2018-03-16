/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:143_Sort_Colors_II.cc
 * Author:
 * Mail:
 * Created Time:星期五  3/16 10:32:53 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.
 *
 * Notice
 *   You are not suppose to use the library's sort function for this problem.
 *   k <= n
 *
 * Example
 *   Given colors=[3, 2, 2, 1, 4], k=4, your code should sort colors in-place to [1, 2, 2, 3, 4].
 */

class Solution {
public:
  /**
   * @param colors: A list of integer
   * @param k: An integer
   * @return: nothing
   */
  void sortColors2(vector<int> &colors, int k) {
    int len = colors.size();
    if (len <= 0 || len < k) {
      return;
    }
    int i = 0;
    int pos = 0;
    while (i < len) {
      if (colors[i] > 0) {
	pos = colors[i] - 1;
	if (colors[pos] > 0) {
	  colors[i] = colors[pos];
	  colors[pos] = -1;
	} else {
	  colors[i] = 0;
	  colors[pos] -= 1;
	}
      } else {
	i++;
      }
    }
    pos = len - 1;
    i = pos;
    while (pos >= 0) {
      while (colors[i] >= 0) {
	i--;
      }
      while (colors[i] < 0) {
	colors[pos] = i + 1;
	if (pos != i) {
	  colors[i] += 1;
	}
	pos--;
      }
    }
  }
};

int main() {
  int arr[] = {3,2,2,1,4};
  vector<int> colors(arr, arr + sizeof(arr)/sizeof(int));
  int k = 4;
  Solution sl;
  sl.sortColors2(colors, k);
  debug1DVector<int>(colors, 3);
  return 0;
}
