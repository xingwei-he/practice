/**************************************
* He Xingwei, All Rights Reserved.
* Filename:offer-11.cpp
* Date:2022-04-27 17:45:54
* Description:
**************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() == 1) {
            return numbers[0];
        }
        int left = 0, right = numbers.size() - 1;
        int mid = 0;
        while (left < right) {
            // mid = (left + right) / 2; // 可能会溢出
            mid = left + (right - left) / 2; // 安全，不会溢出
            if (numbers[mid] > numbers[right]) { // 左侧递增，折叠点在右侧
                left = mid + 1;
            } else if (numbers[mid] < numbers[left]) { // 右侧递增，折叠点在左侧
                right = mid;
            } else { // 无法判断折叠点，则丢掉 right 再判断
                right--;
            }
        }
        return numbers[left];
    }
};

int main() {
    vector<int> nums{2,2,2,0,1};
    Solution s;
    int minimum = s.minArray(nums);
    cout << minimum << endl;
    return 0;
}