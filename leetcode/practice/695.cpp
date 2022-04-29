/**************************************
* He Xingwei, All Rights Reserved.
* Filename:695.cpp
* Date:2022-04-21 10:48:57
* Description:
**************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	 * 深度优先搜索
	 */
	int dfs(vector<vector<int>> &grid, int i, int j) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
			return 0;
		}
		if (grid[i][j] == 0) {
			return 0;
		}
		grid[i][j] = 0;
		return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1); // 探测四个方向
	}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	if (grid.empty() || grid[0].empty()) {
    		return 0;
    	}
    	int row = grid.size();
    	int col = grid[0].size();
    	int max_area = 0;
    	for (int i = 0; i < row; i++) {
    		for (int j = 0; j < col; j++) {
    			if (grid[i][j] == 1) {
    				int area = dfs(grid, i, j);
    				max_area = max_area > area ? max_area : area;
    			}
    		} 
    	}
    	return max_area;
    }
};

int main() {
	vector<vector<int>> grid{
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},
		{0,1,0,0,1,1,0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0}};
	/*
	vector<vector<int>> grid{
		{0,1,0},
		{0,1,1},
		{0,0,0}
	};
	*/
	Solution s;
	int max_area = s.maxAreaOfIsland(grid);
	cout << max_area << endl;
	return 0;
}