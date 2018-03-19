/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:424_Evaluate_Reverse_Polish_Notation.cc
 * Author:
 * Mail:
 * Created Time:星期一  3/19 17:16:15 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Example
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

class Solution {
public:
  /**
   * @param tokens: The Reverse Polish Notation
   * @return: the value
   */
  enum OP{PLUS, MINUS, MULTIPLY, DEVIDE, OTHER};

  int getNum(const string& n) {
    int res = 0;
    bool is_positive = true;
    for (int i = 0; i < n.size(); i++) {
      if (n[i] == '-') {
	is_positive = false;
	continue;
      }
      res = res * 10 + (n[i] - '0');
    }
    if (!is_positive) {
      res *= -1;
    }
    return res;
  }

  OP getOperator(const string& s) {
    if ("+" == s) {
      return PLUS;
    } else if ("-" == s) {
      return MINUS;
    } else if ("*" == s) {
      return MULTIPLY;
    } else if ("/" == s) {
      return DEVIDE;
    } else {
      return OTHER;
    }
  }

  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++) {
      OP op = getOperator(tokens[i]);
      if (OTHER == op) {
	st.push(getNum(tokens[i]));
	continue;
      } else {
	int y = st.top();
	st.pop();
	int x = st.top();
	st.pop();
	if (PLUS == op) {
	  st.push(x + y);
	} else if (MINUS == op) {
	  st.push(x - y);
	} else if (MULTIPLY == op) {
	  st.push(x * y);
	} else if (DEVIDE == op) {
	  st.push(x / y);
	} else {
	  return -1;
	}
      }
    }
    int res = st.top();
    st.pop();
    return res;
  }
};

int main() {
  //string arr[] = {"4", "13", "5", "/", "+"};
  string arr[] = {"3","-4","+"};
  vector<string> strs(arr, arr + sizeof(arr)/sizeof(string));
  Solution sl;
  int res = sl.evalRPN(strs);
  cout << res << endl;
  return 0;
}
