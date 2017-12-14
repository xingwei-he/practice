/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:81_Data_Stream_Median.cc
 * Author:
 * Mail:
 * Created Time:星期四 12/14 10:25:43 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Numbers keep coming, return the median of numbers at every time a new number added.
 *
 * Clarification
 * What's the definition of Median?
 * - Median is the number that in the middle of a sorted array. If there are n numbers in a sorted array A, the median is A[(n - 1) / 2]. For example, if A=[1,2,3], median is 2. If A=[1,19], median is 1.
 *
 * Example
 * For numbers coming list: [1, 2, 3, 4, 5], return [1, 1, 2, 2, 3].
 *
 * For numbers coming list: [4, 5, 1, 3, 2, 6, 0], return [4, 4, 4, 3, 3, 3, 3].
 *
 * For numbers coming list: [2, 20, 100], return [2, 2, 20].
 */

class Solution {
public:
  /*
   * @param nums: A list of integers
   * @return: the median of numbers
   */

  void swap(vector<int>& vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
  }

  // 向上建堆 - 小根堆
  void buildMinHeap(vector<int>& heap) {
    for (int t = heap.size()/2 - 1; t >= 0; t--) {
      adjustDownMinHeap(heap, t, heap.size());
    }
  }

  // 向下调整堆 - 小根堆
  void adjustDownMinHeap(vector<int>& heap, int top, int len) {
    int i = top;
    while (i < len/2) {
      int j = 2*i + 1;
      if (j + 1 < len) {
	if (heap[j + 1] < heap[j]) {
	  j += 1;
	}
      }
      if (heap[i] > heap[j]) {
	swap(heap, i, j);
	i = j;
      } else {
	break;
      }
    }
  }

  // 向上调整堆 - 小根堆
  void adjustUpMinHeap(vector<int>& heap, int k) {
    int i = k;
    while (i > 0) {
      if (heap[(i-1)/2] > heap[i]) {
	swap(heap, (i-1)/2, i);
	i = (i-1)/2;
      } else {
	break;
      }
    }
  }
    
  // 向上建堆 - 大根堆
  void buildMaxHeap(vector<int>& heap) {
    for (int t = heap.size()/2 - 1; t >= 0; t--) {
      adjustDownMaxHeap(heap, t, heap.size());
    }
  }

  // 向下调整堆 - 大根堆
  void adjustDownMaxHeap(vector<int>& heap, int top, int len) {
    int i = top;
    while (i < len/2) {
      int j = 2*i + 1;
      if (j + 1 < len) {
	if (heap[j + 1] > heap[j]) {
	  j += 1;
	}
      }
      if (heap[i] < heap[j]) {
	swap(heap, i, j);
	i = j;
      } else {
	break;
      }
    }
  }

  // 向上调整堆 - 小根堆
  void adjustUpMaxHeap(vector<int>& heap, int k) {
    int i = k;
    while (i > 0) {
      if (heap[(i-1)/2] < heap[i]) {
	swap(heap, (i-1)/2, i);
	i = (i-1)/2;
      } else {
	break;
      }
    }
  }
 
  vector<int> medianII(vector<int> &nums) {
    vector<int> median;
    vector<int> left_max_heap;
    vector<int> right_min_heap;
    int left_counter = 0;
    int right_counter = 0;
    if (nums.size() == 0) {
      return median;
    }
    median.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > median.back()) {
	right_counter++;
	right_min_heap.push_back(nums[i]);
	adjustUpMinHeap(right_min_heap, right_min_heap.size() - 1);
      } else {
	left_counter++;
	left_max_heap.push_back(nums[i]);
	adjustUpMaxHeap(left_max_heap, left_max_heap.size() - 1);
      }
      if (right_counter - left_counter > 1) {
	left_max_heap.push_back(median.back());
	adjustUpMaxHeap(left_max_heap, left_max_heap.size() - 1);
	median.push_back(right_min_heap[0]);
	swap(right_min_heap, 0, right_min_heap.size() - 1);
	right_min_heap.pop_back();
	adjustDownMinHeap(right_min_heap, 0, right_min_heap.size());
	right_counter--;
	left_counter++;
      } else if (left_counter - right_counter >= 1) {
	right_min_heap.push_back(median.back());
	adjustUpMinHeap(right_min_heap, right_min_heap.size() - 1);
	median.push_back(left_max_heap[0]);
	swap(left_max_heap, 0, left_max_heap.size() - 1);
	left_max_heap.pop_back();
	adjustDownMaxHeap(left_max_heap, 0, left_max_heap.size());
	left_counter--;
	right_counter++;
      } else {
	median.push_back(median.back());
      }
    }
    return median;
  }
};

int main() {
  //int arr[] = {1,2,3,4,5,6,7};
  int arr[] = {1,2,3,4,5,6,7,100,200,1000};
  vector<int> nums(begin(arr), end(arr));
  cout << "nums:" << endl;
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "  ";
  }
  cout << endl;
  Solution sl;
  vector<int> median = sl.medianII(nums);
  cout << "median:" << endl;
  for (int i = 0; i < median.size(); i++) {
    cout << median[i] << "  ";
  }
  cout << endl;
  return 0;
}
