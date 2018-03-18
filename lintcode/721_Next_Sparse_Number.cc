/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:721_Next_Sparse_Number.cc
 * Author:
 * Mail:
 * Created Time:2018年03月18日 星期日 14时51分16秒
 ***************************************************/
#include <iostream>
#include "../include/base.h"

using namespace std;

/**
 * A number is Sparse if there are no two adjacent 1s in its binary representation. Given a number n, find the smallest Sparse number which greater than or equal to n.
 * eg. 5 (binary representation: 101) is sparse, but 6 (binary representation: 110) is not sparse.
 *
 * Example
 *
 *   Given n = 6, return 8
 *   Next Sparse Number is 8
 *
 *   Given n = 4, return 4
 *   Next Sparse Number is 4
 *
 *   Given n = 38, return 40
 *   Next Sparse Number is 40
 *
 *   Given n = 44, return 64
 *   Next Sparse Number is 64
 */

class Solution {
public:
  /**
   * @param x: a number
   * @return: return the next sparse number behind x
   */
  static const int BIT_LIMIT = 64;

  vector<int> encodeBinaryBits(int x) {
    vector<int> bits(BIT_LIMIT + 1, 0);
    int i = BIT_LIMIT;
    while (0 != x) {
      bits[i] = x % 2;
      x /= 2;
      i--;
    }
    return bits;
  }
  int decodeBinaryBits(const vector<int>& bits) {
    int res = 0;
    if (1 == bits[BIT_LIMIT]) {
      res = 1;
    }
    for (int i = BIT_LIMIT - 1; i >= 0; i--) {
      if (1 == bits[i]) {
	int temp = 1;
	for (int j = BIT_LIMIT - i; j > 0; j--) {
	  temp *= 2;
	}
	res += temp;
      }
    }
    return res;
  }

  // 解法：
  // 从后往前扫描，当遇到连续的两个 1 时（计为 bits[i] 和 bits[i + 1]），需要进位（bits[i - 1] += 1），然后从 i 位开始一直到最后都赋值 0
  int nextSparseNum(int x) {
    vector<int> bits = encodeBinaryBits(x);
    for (int i = BIT_LIMIT - 1; i >= 0; i--) {
      if (1 == bits[i] && 1 == bits[i + 1] && i > 0) {
	bits[i - 1] += 1;
	for (int j = i; j <= BIT_LIMIT; j++) {
	  bits[j] = 0;
	}
      }
      for (int j = i - 1; j >= 0; j--) {
	if (bits[j] == 2) {
	  bits[j] = 0;
	  if (0 == j) {
	    return -1;
	  }
	  bits[j - 1] += 1;
	}
      }
    }
    int res = decodeBinaryBits(bits);
    return res;
  }
};

int main() {
  int x = 372228240;
  Solution sl;
  int res = sl.nextSparseNum(x);
  cout << "x:" << x << endl;
  vector<int> vec1 = sl.encodeBinaryBits(x);
  debug1DVector<int>(vec1, 2);
  cout << "res:" << res << endl;
  vector<int> vec2 = sl.encodeBinaryBits(res);
  debug1DVector<int>(vec2, 2);

  return 0;
}
