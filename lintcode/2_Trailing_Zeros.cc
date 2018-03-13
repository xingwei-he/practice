#include "practice/include/base.h"

using namespace std;

/**
 * Write an algorithm which computes the number of trailing zeros in n factorial.
 *
 * Example
 *   11! = 39916800, so the out should be 2
 */

class Solution {
public:
  /*
   * @param n: A long integer
   * @return: An integer, denote the number of trailing zeros in n!
   */
  /*
  // Time Limit Exceeded
  long long trailingZeros(long long n) {
    long long t = 1;
    for (int i = n; i >= 1; i--) {
      t = t*i;
    }
    cout << t << endl;
    int counter_5 = 0;
    for (long long i = n; i >= 0; i--) {
      long long temp = i;
      while (temp != 0) {
	if (temp % 5 == 0) {
	  counter_5++;
	  temp /= 5;
	} else {
	  break;
	}
      }
    }
    return counter_5;
  }
  */

  /*
  // optimization v1
  // Time Limit Exceeded
  // 1001171717
  long long trailingZeros(long long n) {
    int counter_5 = 0;
    map<int, int> counter_map;
    // 初始化counter_map
     counter_map[1] = 0;
    for (long long i = 2; i <= n; i++) {
      counter_5 = 0;
      long long temp = i;
      while (temp != 0) {
	if (temp % 5 == 0) {
	  counter_5++;
	  temp /= 5;
	} else {
	  break;
	}
      }
      counter_map[i] = counter_5 + counter_map[i - 1];
    }

    // debug
    for (map<int, int>::iterator iter = counter_map.begin();
	 iter != counter_map.end();
	 iter++) {
      cout << iter->first << "\t" << iter->second << endl;
    }

    return counter_map[n];
  }
  */

  /*
  // optimization v2
  // Time Limit Exceeded
  // 1001171717
  long long trailingZeros(long long n) {
    int res = 0;// 记录结果，包括对上次计算的暂存
    for (long long i = 1; i <= n; i++) {
      long long temp = i;
      long long single_counter = 0;
      while (temp != 0) {
	if (temp % 5 == 0) {
	  single_counter++;
	  temp /= 5;
	} else {
	  break;
	}
      }
      res += single_counter;
    }
    return res;
  }
  */

  // optimization v3
  // Accepted
  long long trailingZeros(long long n) {
    long long result = 0;
    long long temp = n;
    while (temp != 0) {
      temp /= 5;
      result += temp;
    }
    return result;
  }
};

int main() {
  Solution sl;
  //cout << sl.trailingZeros(1001171717) << endl;
  cout << sl.trailingZeros(5) << endl;
  return 0;
}
