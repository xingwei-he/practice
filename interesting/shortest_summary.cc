/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:shortest_summary.cc
 * Author:
 * Mail:
 * Created Time:星期二  3/13 14:36:27 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"
using namespace std;

/**
 * 在搜索结果中，标题和URL之间的内容就是我们所说的摘要。这些摘要是怎么样生成的呢？我们对问题做如下简化。
 * 给定一段描述w和一组关键字q，我们从这段描述中找出包含所有关键字的最短字符序列。
 * 需要注意两点：
 * 1.最短字符序列必须包含所有的关键字
 * 2.最短字符序列中关键字的顺序可以是随意的
 */

class Solution {
public:
  int getMinPos(unordered_map<string, int> pos) {
    int min_pos = INT_MAX;
    for (unordered_map<string, int>::iterator iter = pos.begin();
	 iter != pos.end();
	 iter++) {
      if (min_pos > iter->second) {
	min_pos = iter->second;
      }
    }
    return min_pos;
  }

  vector<string> getShortestSummary(vector<string> content, vector<string> key) {
    vector<string> res;
    if (content.size() <= 0 || key.size() <= 0) {
      return res;
    }
    unordered_map<string, int> key_pos_map;
    for (int i = 0; i < key.size(); i++) {
      key_pos_map.insert(pair<string, int>(key[i], -1));
    }

    int min_len = INT_MAX;
    int start = -1;
    int end = -1;
    for (int i = 0; i < content.size(); i++) {
      if (key_pos_map.find(content[i]) != key_pos_map.end()) {
	key_pos_map[content[i]] = i;
	int max_pos = i;
	int min_pos = getMinPos(key_pos_map);
	if (min_pos != -1) {
	  if (min_len > max_pos - min_pos + 1) {
	    min_len = max_pos - min_pos + 1;
	    start = min_pos;
	    end = max_pos;
	  }
	}
      }
    }
    for (int i = start; i <= end; i++) {
      res.push_back(content[i]);
    }
    return res;
  }
};

int main() {
  string keyword[] = { "微软", "计算机", "亚洲", "交流"};
  string str[] = {
    "微软","亚洲","研究院","成立","于","1998","年","，","我们","的","使命",
    "是","使","未来","的","计算机","能够","看","、","听","、","学","，",
    "能","用","自然语言","与","人类","进行","交流","。","在","此","基础","上",
    "，","微软","亚洲","研究院","还","将","促进","计算机","在","亚太","地区",
    "的","普及","，","改善","亚太","用户","的","计算","体验","。","”"};
  vector<string> content(str, str + sizeof(str)/sizeof(string));
  vector<string> key(keyword, keyword + sizeof(keyword)/sizeof(string));
  Solution sl;
  vector<string> res = sl.getShortestSummary(content, key);
  cout << "size:" << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << "\t" << res[i];
  }
  cout << endl;
  return 0;
}
