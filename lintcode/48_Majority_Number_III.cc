/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:48_Majority_Number_III.cc
 * Author:
 * Mail:
 * Created Time:星期一  1/15 12:42:18 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array.
 * Find it.
 *
 * Notice
 *   There is only one majority number in the array.
 *
 * Example
 * Given [3,1,2,3,2,3,3,4,4,4] and k=3, return 3.
 */

class Candidate{
public:
  int val;
  int count;
  Candidate(int x = 0, int y = 0): val(x), count(y){}
};

class Solution {
public:
  /*
   * @param nums: A list of integers
   * @param k: An integer
   * @return: The majority number
   */
  /*
  // O(n) time and O(n) extra space
  int majorityNumber(vector<int> &nums, int k) {
    unordered_map<int, int> counter_map;
    int n = nums.size();
    int max_occurence = 0;
    int max_number = 0;
    for (int i = 0; i < n; i++) {
      if (counter_map.find(nums[i]) != counter_map.end()) {
	counter_map[nums[i]] += 1;
      } else {
	counter_map.insert(pair<int, int>(nums[i], 1));
      }
      if (max_occurence < counter_map[nums[i]]) {
	max_occurence = counter_map[nums[i]];
	max_number = nums[i];
      }
    }
    if (max_occurence > n / k) {
      return max_number;
    }
  }
  */

  // O(n) time and O(1) extra space
  int majorityNumber(vector<int> nums, int k) {
    if(nums.size() == 0) return -1;
    int n = nums.size();
    vector<Candidate> m(k - 1, Candidate() );
    for(int i = 0; i < n; i++){
      int l;
      for(l = 0; l < k - 1; l++){
        if(m[l].val == nums[i]){
          m[l].count++;
	  break;
	}
      }
      if(l == k - 1){
	for(l = 0; l < k - 1; l++){
	  if(m[l].count == 0){
          m[l].val = nums[i];
	  m[l].count++;
	  break;
	  }
	}
	if(l == k - 1){
	  for(l = 0; l < k - 1; l++){
	    m[l].count--;
	  }
	}
      }
    }
    for(int j = 0; j < k - 1; j++){
      m[j].count = 0;
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < k - 1; j++){
	if(nums[i] == m[j].val){
	  m[j].count++;
	}
	if(m[j].count > n / k) return m[j].val;
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
