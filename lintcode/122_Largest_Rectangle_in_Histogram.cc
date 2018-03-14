/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:122_Largest_Rectangle_in_Histogram.cc
 * Author:
 * Mail:
 * Created Time:星期三  3/14 11:13:24 2018
 ***************************************************/
#include <iostream>

#include "../include/base.h"

using namespace std;

/**
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 * Example
 * Given height = [2,1,5,6,2,3],
 * return 10.
 */

/**
  我们从左向右遍历每个矩形，并通过一个栈来存储这些矩形高度在输入数组中的索引。每个矩形（索引）仅压入栈中一次。当输入的矩形高度小于栈顶矩形的高度，那么栈顶矩形将会被弹出，然后计算矩形面积，其中矩形面积的高为弹出单个矩形条的高。现在得到了高，接下来得到左右边界后便可计算出宽度。由于当前输入的矩形i的高度小于栈顶矩形，那么以栈顶为高的矩形右边界为i。而在当前栈中若非空，那么栈中矩形条的高度一定是小于等于弹出的矩形的高度，因此左边界就确定了。(当有多个连续的高度一样的矩形条时，计算最后一个出栈的矩形时会得到最终的面积)

  最终算法步骤归纳为：

  1. 创建一个空栈
  2. 从第一个矩形条开始，对每个矩形条的高度height[i] (i的取值范围是[0,n-1])执行下面两步 
    a) 如果栈为空，或height[i]大于等于栈顶元素，那么将矩形条i压入栈中。 
    b) 如果输入的矩形条高度小于栈顶元素高度，那么将栈顶元素在输入数组中的索引tp出栈，然后计算矩形面积。矩形的高为height[tp]，而右边界为i，左边界为当前栈顶元素对应的索引，若栈为空，则宽度就是i。
  3. 经过计算后，栈非空，然后将栈中元素逐个弹出，并按照步骤2计算矩形面积，并且更新最大值。
  
  总结：若输入序列是是升序，那么依次入栈，让入栈元素小于栈顶，以栈顶元素为高的矩形左边界必然是将高出栈后新的栈顶元素的位置(因为是按升序入栈)。而栈中元素是按升序排列那么以栈中任意一个元素为高，必然可以和栈顶元素构成矩形，所以当即将入栈元素小于栈顶元素时，那么右边界即是这个入栈元素的索引位置。
 */

class Solution {
public:
  /**
   * @param height: A list of integer
   * @return: The area of largest rectangle in the histogram
   */
  int largestRectangleArea(vector<int> &height) {
    stack<int> st;
    int max_area = 0; // 最大矩形面积
    int tp; // 栈顶
    int area_with_top;

    int i = 0;
    int n = height.size();
    while (i < n) {
      if (st.empty() || height[st.top()] <= height[i]) {// 当前矩形高度大于等于栈顶的矩形高度，则直接入栈
	st.push(i);
	i++;
      } else {// 如果当前矩形高度小于栈顶矩形高度，则将栈顶矩形出栈，并计算面积
	tp = st.top();
	st.pop();
	area_with_top = height[tp] * (st.empty() ? i : i - st.top() - 1);
	int k = st.empty() ? i : (i - st.top() - 1);
	max_area = max(max_area, area_with_top);
      }
    }
    while (!st.empty()) {
      tp = st.top();
      st.pop();
      area_with_top = height[tp] * (st.empty() ? i : i - st.top() - 1);
      max_area = max(max_area, area_with_top);
    }
    return max_area;
  }
};

int main() {
  int arr[] = {2,1,5,6,2,3};
  vector<int> height(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int res = sl.largestRectangleArea(height);
  cout << "res:" << res << endl;
  return 0;
}
