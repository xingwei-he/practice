/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-03.cpp
* Date:2022-04-25 23:26:03
* Description:
**************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> dict;
        for (auto &num : nums) {
            if (dict.find(num) == dict.end()) {
                dict[num] = false;
            } else {
                dict[num] = true;
                return num;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    Solution s;
    int x = s.findRepeatNumber(nums);
    cout << x << endl;
    return 0;
}
