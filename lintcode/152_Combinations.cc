/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:152_Combinations.cc
 * Author:
 * Mail:
 * Created Time:星期四  1/18 15:17:09 2018
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * Example
 * For example,
 * If n = 4 and k = 2, a solution is:
 * [[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]
 */

class Solution {
public:
  /*
   * @param n: Given the range of numbers
   * @param k: Given the numbers of combinations
   * @return: All the combinations of k numbers out of 1..n
   */
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > res;
    vector<int> out;
    dfs(n, k, 1, out, res);
    return res;
  }

  void dfs(int n, int k, int level, vector<int>& out, vector<vector<int> >& res) {
    if (out.size() == k) {
      res.push_back(out);
    }
    for (int i = level; i <= n; ++i) {
      out.push_back(i);
      dfs(n, k, i + 1, out, res);
      out.pop_back();
    }
  }
};

int main() {
  int n = 5;
  int k = 3;
  Solution sl;
  vector<vector<int> > res = sl.combine(n, k);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << setw(4) << res[i][j];
    }
    cout << endl;
  }
  return 0;
}

