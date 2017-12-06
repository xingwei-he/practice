#include "practice/include/base.h"

using namespace std;

class Solution {
public:
  /*
   * @param strs: A list of strings
   * @return: The longest common prefix
   */
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
      return string("");
    } else if (strs.size() == 1) {
      return strs[0];
    }
    int i = 0;// 初始化位置标号
    int j = 0;// 初始化字符串标号
    string tempstr = string("");
    char tempchar;
    bool flag = true;
    while (flag) {
      tempchar = strs[0][i];
      for (j = 0; j < strs.size(); j++) {
	if (i >= strs[j].size() || tempchar != strs[j][i]) {
	  flag = false;
	  break;
	}
      }
      if (flag) {
	tempstr.append(string(&tempchar));
	i++;
      }
    }
    return tempstr;
  }
};

int main() {

  return 0;
}

