/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:433_Number_of_Islands.cc
 * Author:
 * Mail:
 * Created Time:星期二 12/26 10:11:10 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;


/**
 * Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.
 * Find the number of islands.
 *
 * Example
 * Given graph:
 * [
 *   [1, 1, 0, 0, 0],
 *   [0, 1, 0, 0, 1],
 *   [0, 0, 0, 1, 1],
 *   [0, 0, 0, 0, 0],
 *   [0, 0, 0, 0, 1]
 * ]
 * return 3.
 */

class Solution {
public:
  /*
   * @param grid: a boolean 2D matrix
   * @return: an integer
   */
  void DFS(vector<vector<bool> >& grid, int x, int y) {
    if (grid[x][y] == 1) {
      grid[x][y] = 0;
    }
    if (x - 1 >= 0 && grid[x - 1][y] == 1) {
      DFS(grid, x - 1, y);
    }
    if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
      DFS(grid, x + 1, y);
    }
    if (y - 1 >= 0 && grid[x][y - 1] == 1) {
      DFS(grid, x, y - 1);
    }
    if (y + 1 < grid[x].size() && grid[x][y + 1] == 1) {
      DFS(grid, x, y + 1);
    }
  }
  int numIslands(vector<vector<bool> > &grid) {
    int counter = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
	if (grid[i][j] == 1) {
	  counter++;
	  DFS(grid, i, j);
	}
      }
    }
    return counter;
  }
};

int main() {
  bool arr1[] = {1, 1, 0, 0, 1};
  bool arr2[] = {0, 1, 0, 0, 0};
  bool arr3[] = {0, 0, 0, 1, 0};
  bool arr4[] = {1, 1, 0, 0, 1};
  bool arr5[] = {0, 0, 0, 1, 1};
  vector<bool> vec1(begin(arr1), end(arr1));
  vector<bool> vec2(begin(arr2), end(arr2));
  vector<bool> vec3(begin(arr3), end(arr3));
  vector<bool> vec4(begin(arr4), end(arr4));
  vector<bool> vec5(begin(arr5), end(arr5));
  vector<vector<bool> > grid;
  grid.push_back(vec1);
  grid.push_back(vec2);
  grid.push_back(vec3);
  grid.push_back(vec4);
  grid.push_back(vec5);
  Solution sl;
  int num = sl.numIslands(grid);
  cout << "num:" << num << endl;
  return 0;
}
