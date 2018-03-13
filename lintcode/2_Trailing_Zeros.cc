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
  // 对于 n! 可以展开为 n * (n-1) * (n-2) * ... * 1
  // 在该序列中，每个 5 都可以和前面的 x2 相乘得到一个尾数至少有一个 0 的数，则 n/5 可得序列中 5 的个数（一个 0 的个数）
  // 同理，每个 25 都可以和前面的 x4 相乘得到一个尾数至少有两个 0 的数，则 n/25 可得序列中 25 的个数（两个 0 的个数）
  // 其实整个过程无需关注 5、25、125 等和谁相乘，只需要关注这些“5”的个数即可！
  // 注意，在计算 5 的时候，已经计算过一次 25 了，所以只需 n/5 + (n/5)/5 即可
  // 这是个递推过程，n/5 + (n/5)/5 + ((n/5)/5)/5 + ... 即为最后结果
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
  cout << sl.trailingZeros(25) << endl;
  return 0;
}
