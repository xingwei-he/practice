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
  // 整体思想是用 colors 数组存储颜色出现的次数
  void sortColors2(vector<int> &colors, int k) {
    int len = colors.size();
    if (len <= 0 || len < k) {
      return;
    }
    int i = 0;
    int pos = 0;// 统计时颜色要放进的桶号
    while (i < len) {// 该循环用来统计各颜色的个数
      if (colors[i] > 0) {// 如果大于 0，则该位置有一个要去选桶的颜色，否则，如果小于等于 0，该位置没有要选桶的颜色，值是桶内颜色的个数的负数
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
