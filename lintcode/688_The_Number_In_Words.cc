/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:688_The_Number_In_Words.cc
 * Author:
 * Mail:
 * Created Time:星期四  3/15 17:18:14 2018
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * Given a non-negative integer n, print the number in words.
 *
 * Notice
 *   n <= 2147483647

 * Example
 *   Given n = 125
 *   Return one hundred twenty five
 */

// Time Limit Exceeded
class Solution {
public:
  /**
   * @param number: the number
   * @return: the number in words
   */
  int getNumLen(int num) {
    int len = 1;
    while (num / 10 != 0) {
      len /= 10;
      len++;
    }
    return len;
  }

  // 从右往左第n个逗号
  // 例如，2,334,423,454，三个逗号的位置分别是 billion million thousand
  string getSplitWord(int n) {
    if (1 == n) {
      return "thousand";
    } else if (2 == n) {
      return "million";
    } else if (3 == n) {
      return "billion";
    } else {
      return "";
    }
  }

  string get1NumWord(int n) {
    if (n >= 10) {
      return "";
    }
    if (1 == n) {
      return "one";
    } else if (2 == n) {
      return "two";
    } else if (3 == n) {
      return "three";
    } else if (4 == n) {
      return "four";
    } else if (5 == n) {
      return "five";
    } else if (6 == n) {
      return "six";
    } else if (7 == n) {
      return "seven";
    } else if (8 == n) {
      return "eight";
    } else if (9 == n) {
      return "nine";
    } else {
      return "";
    }
  }

  string get2NumWord(int n) {
    if (n >= 100) {
      return "";
    } else if (n < 10) {
      return get1NumWord(n);
    }
    int x = n / 10;
    int y = n % 10;
    if (1 == x) {
      if (0 == y) {
	return "ten";
      } else if (1 == y) {
	return "eleven";
      } else if (2 == y) {
	return "twelve";
      } else if (3 == y) {
	return "thirteen";
      } else if (4 == y) {
	return "fourteen";
      } else if (5 == y) {
	return "fifteen";
      } else if (6 == y) {
	return "sixteen";
      } else if (7 == y) {
	return "seventeen";
      } else if (8 == y) {
	return "eighteen";
      } else if (9 == y) {
	return "nineteen";
      } else {
	return "";
      }
    } else if (2 == x) {
      return "twenty " + get1NumWord(y);
    } else if (3 == x) {
      return "thirty " + get1NumWord(y);
    } else if (4 == x) {
      return "forty " + get1NumWord(y);
    } else if (5 == x) {
      return "fifty " + get1NumWord(y);
    } else if (6 == x) {
      return "sixty " + get1NumWord(y);
    } else if (7 == x) {
      return "seventy " + get1NumWord(y);
    } else if (8 == x) {
      return "eighty " + get1NumWord(y);
    } else if (9 == x) {
      return "ninety " + get1NumWord(y);
    } else {
      return "";
    }
  }

  string get3NumWord(int n) {
    if (n >= 1000) {
      return "";
    } else if (n < 100) {
      return get2NumWord(n);
    }
    int x = n / 100;
    int yz = n % 100;
    return get1NumWord(x) + " hundred " + get2NumWord(yz);
  } 

  string convertWords(int number) {
    stack<string> st;
    int len = getNumLen(number);
    int sp_counter = 0;
    while (number != 0) {
      int last_3_num = number % 1000;
      number = number / 1000;
      if (number != 0) {
	sp_counter++;
      } else {
	sp_counter = 0;
      }
      string last_3_str = get3NumWord(last_3_num);
      st.push(last_3_str);
      string sp = getSplitWord(sp_counter);
      if (!sp.empty()) {
	st.push(sp);
      }
    }
    string res;
    while (st.size() > 1) {
      res.append(st.top());
      st.pop();
      res.append(" ");
    }
    res.append(st.top());
    st.pop();
    return res;
  }
};

int main() {
  int num = 12345678;
  Solution sl;
  string res = sl.convertWords(num);
  cout << res << endl;
  return 0;
}
