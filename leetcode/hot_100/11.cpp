/**************************************
* He Xingwei, All Rights Reserved.
* Filename:11.cpp
* Date:2022-04-18 20:59:04
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int len = height.size();
    	if (len <= 1) {
    		return 0;
    	}
    	int left = 0, right = len - 1;
    	int max_volume = 0;
    	while (left < right) {
            int l = right - left;
            int h = height[left] < height[right] ? height[left] : height[right];
    		int volume = l * h;
    		if (max_volume < volume) {
    			max_volume = volume;
    		}
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
    	}
    	return max_volume;
    }
};