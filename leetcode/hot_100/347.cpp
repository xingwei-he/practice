/**************************************
* He Xingwei, All Rights Reserved.
* Filename:347.cpp
* Date:2022-05-03 18:20:50
* Description:
**************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	unordered_map<int, int> counter;
    	for (auto &n : nums) {
    		counter[n] += 1;
    	}

    	vector<vector<int>> heap;
    	heap.reserve(k + 1);
    	auto iter = counter.begin();
    	for (int i = 0; i < k; i++) {
    		heap.emplace_back(vector<int>{iter->first, iter->second});
    		iter++;
    	}
    	auto heap_cmp = [](vector<int> &v1, vector<int> &v2)->bool {
    				return v1[1] > v2[1];
    			};
    	make_heap(heap.begin(), heap.end(), heap_cmp); // 找最大的k个则需要小根堆
    	while (iter != counter.end()) {
    		//heap.emplace_back(vector<int>{iter->first, iter->second});
    		//push_heap(heap.begin(), heap.end(), heap_cmp);
    		if (iter->second > heap.front()[1]) {
    			heap.emplace_back(vector<int>{iter->first, iter->second});
    			push_heap(heap.begin(), heap.end(), heap_cmp);
    			pop_heap(heap.begin(), heap.end(), heap_cmp);
    			heap.pop_back();
    		}
            iter++;
    	}
    	vector<int> res;
    	res.reserve(k);
    	for (int i = 0; i < heap.size(); i++) {
    		res.emplace_back(heap[i][0]);
    	}
    	return res;
    }
};

int main() {
	vector<int> nums{1,1,1,2,2,3};
	int k = 2;
	Solution s;
	auto v = s.topKFrequent(nums, k);
	for (auto &n : v) {
		cout << n << "  ";
	}
	cout << endl;
	return 0;
}