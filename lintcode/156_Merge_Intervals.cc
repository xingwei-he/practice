/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:156_Merge_Intervals.cc
 * Author:
 * Mail:
 * Created Time:星期四 12/28 17:32:12 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example
 * Given intervals => merged intervals:
 * [                     [
 *   [1, 3],               [1, 6],
 *   [2, 6],      =>       [8, 10],
 *   [8, 10],              [15, 18]
 *   [15, 18]            ]
 * ]
 */

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * };
 */


class Solution {
public:
  /*
   * @param intervals: interval list.
   * @return: A new interval list.
   */
  static bool interval_compare(const Interval& iv1, const Interval& iv2) {
    return iv1.start < iv2.start;
  }

  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> merged_intervals;
    if (intervals.size() == 0) {
      return merged_intervals;
    }
    sort(intervals.begin(), intervals.end(), interval_compare);
    merged_intervals.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      Interval& miv = merged_intervals.back();
      if (intervals[i].start > miv.end) {
	merged_intervals.push_back(intervals[i]);
      } else {
	if (intervals[i].end > miv.end) {
	  miv.end = intervals[i].end;
	}
      }
    }
    return merged_intervals;
  }
};

int main() {
  return 0;
}
