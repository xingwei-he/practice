/**************************************
* He Xingwei, All Rights Reserved.
* Filename:169.cpp
* Date:2022-04-23 13:13:00
* Description:
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (auto &i : nums) {
            counter[i] += 1;
            if (counter[i] > nums.size() / 2) {
                return i;
            }
        }
        return 0;
    }
};