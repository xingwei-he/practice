/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:max_map_sum.cc
 * Author:
 * Mail:
 * Created Time:2018年04月07日 星期六 10时06分59秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * 有 n 个字符串，每个字符串都是由 A-J 的大写字符构成。现在你将每个字符映射为一个 0-9 的数字，不同字符映射为不同的数字。这样每个字符串就可以看做一个整数，唯一的要求是这些整数必须是正整数且它们的字符串不能有前导零。现在问你怎样映射字符才能使得这些字符串表示的整数之和最大？
 *
 * 输入描述:
 *   每组测试用例仅包含一组数据，每组数据第一行为一个正整数 n ， 接下来有 n 行，每行一个长度不超过 12 且仅包含大写字母 A-J 的字符串。 n 不大于 50，且至少存在一个字符不是任何字符串的首字母。
 *
 * 输出描述:
 *   输出一个数，表示最大和是多少。
 *
 * 输入例子:
 *   2
 *   ABC
 *   BCA
 *
 * 输出例子:
 *   1875
 */

class Solution {
private:
  static bool cmp(const pair<char, int> &x, const pair<char, int> &y) {
    return x.second > y.second;
  }

  vector<pair<char, int> > sort_map_to_vec(map<char, int> &weight_map) {
    vector<pair<char, int> > vec;
    for (map<char, int>::iterator iter = weight_map.begin();
	 iter != weight_map.end();
	 iter++) {
      vec.push_back(pair<char, int>(iter->first, iter->second));
    }
    sort(vec.begin(), vec.end(), cmp);
    return vec;
  }

public:
  int getMaxMapSum(vector<string> &strs) {
    if (strs.size() == 0) {
      return 0;
    }
    map<char, int> weight;
    for (int i = 0; i < strs.size(); i++) {
      for (int j = 0; j < strs[i].size(); j++) {
	int w = strs[i].size() - j;
	if (weight.find(strs[i][j]) == weight.end()) {
	  weight.insert(pair<char, int>(strs[i][j], w));
	} else {
	  weight[strs[i][j]] += w;
	}
      }
    }
    vector<pair<char, int> > sorted_vec = sort_map_to_vec(weight);
    for (int i = 0; i < sorted_vec.size(); i++) {
      weight[sorted_vec[i].first] = 9 - i;
    }
    int sum = 0;
    for (int i = 0; i < strs.size(); i++) {
      int val = 0;
      for (int j = 0; j < strs[i].size(); j++) {
	val *= 10;
	val += weight[strs[i][j]];
      }
      cout << val << "\t*" << endl;
      sum += val;
    }
    return sum;
  }
};

int main() {
  string arr[] = {"ABC", "BCA"};
  vector<string> strs(arr, arr + sizeof(arr)/sizeof(string));
  Solution sl;
  int sum = sl.getMaxMapSum(strs);
  cout << sum << endl;
  return 0;
}
