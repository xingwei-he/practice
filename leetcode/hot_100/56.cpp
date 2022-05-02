/**************************************
* He Xingwei, All Rights Reserved.
* Filename:56.cpp
* Date:2022-05-01 20:46:14
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	vector<vector<int>> res;
    	if (intervals.empty()) {
    		return res;
    	}
    	if (intervals.size() == 1) {
    		res.emplace_back(intervals[0]);
    		return res;
    	}
    	
    	auto sort_intervals =
    			[](vector<int> &a, vector<int> &b)->bool {
    				return a[0] < b[0];
    			};
    	sort(intervals.begin(), intervals.end(), sort_intervals);
        
    	//sort(intervals.begin(), intervals.end());

    	int cur_left = intervals[0][0];
    	int cur_right = intervals[0][1];
    	for (int i = 1; i < intervals.size(); i++) {
    		if (cur_right < intervals[i][0]) {
    			res.emplace_back(vector<int>{cur_left, cur_right});
    			cur_left = intervals[i][0];
    			cur_right = intervals[i][1];
    		} else {
    			cur_right = max(cur_right, intervals[i][1]);
    		}
    		if (i == intervals.size() - 1) {
    			res.emplace_back(vector<int>{cur_left, cur_right});
    		}
    	}
    	return res;
    }
};