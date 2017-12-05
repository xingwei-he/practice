#include "practice/include/base.h"

using namespace std;

/**
 * 给定一个字符串所表示的括号序列，包含以下字符： '(', ')', '{', '}', '[' and ']'， 判定是否是有效的括号序列。
 *
 * 样例
 * 括号必须依照 "()" 顺序表示， "()[]{}" 是有效的括号，但 "([)]"则是无效的括号。
 */

class Solution {
public:
  /*
   * @param s: A string
   * @return: whether the string is a valid parentheses
   */

  const string bracket = "()[]{}";
  bool isValidParentheses(string &s) {
    stack<char> st;
    // 定义两个括号映射表
    map<char, char> left_right_map;
    for (int i = 0; i < bracket.size(); i += 2) {
      left_right_map[bracket[i]] = bracket[i + 1];
    }
    map<char, char> right_left_map;
    for (int i = 1; i < bracket.size(); i += 2) {
      right_left_map[bracket[i]] = bracket[i - 1];
    }
    
    for (int i = 0; i < s.size(); i++) {
      if (left_right_map.find(s[i]) != left_right_map.end()) {
	st.push(s[i]);
      } else if (right_left_map.find(s[i]) != right_left_map.end()) {
	char temp = st.top();
	if (temp == right_left_map[s[i]]) {
	  st.pop();
	} else {
	  return false;
	}
      } else {
	continue;
      }
    }
    if (st.size() != 0) {
      return false;
    } else {
      return true;
    }
  }

};

int main() {
  return 0;
}
