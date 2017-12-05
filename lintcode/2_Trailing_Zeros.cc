#include "practice/include/base.h"

using namespace std;

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
};

int main() {
  Solution sl;
  cout << sl.trailingZeros(1001171717) << endl;

  return 0;
}
