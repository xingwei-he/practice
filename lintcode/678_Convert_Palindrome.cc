/***************************************************
 Xingwei_He All Rights Reserved.
 * File Name:678_Convert_Palindrome.cc
 * Author:
 * Mail:
 * Created Time:星期2017年12月10日 星期日 15时26分15秒
 ***************************************************/
#include <iostream>

using namespace std;

class Solution {
public:
  /*
   * @param : String
   * @return: String
   */
  bool isPalindrome(string& str) {
    int i = 0;
    int j = str.size() - 1;
    bool res = true;
    while (i < j) {
      if (str[i] != str[j]) {
	res = false;
	break;
      }
      i++;
      j--;
    }
    return res;
  }

  string convertPalindrome(string str) {
    int substr_len = str.size();
    while (substr_len > 0) {
      string substr(str, 0, substr_len);
      if (isPalindrome(substr)) {
	break;
      }
      substr_len--;
    }
    string res;
    for (int i = str.size() - 1; i >= substr_len; i--) {
      res.append(str, i, 1);
    }
    res += str;
    return res;
  }
};

int main() {
  return 0;
}
