/***************************************************
 * Xingwei_He All maxs Reserved.
 * File Name:662_Guess_Number_Game.cc
 * Author:
 * Mail:
 * Created Time:星期三 12/27 13:05:17 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * We are playing the Guess Game. The game is as follows:
 * I pick a number from 1 to n. You have to guess which number I picked.
 * Every time you guess wrong, I'll tell you whether the number is higher or lower.
 * You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
 *
 * Example
 * n = 10, I pick 4 (but you don't know)
 * Return 4. Correct !
 */

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
  /**
   * @param n an integer
   * @return the number you guess
   */
  int guessNumber(int n) {
    int min = 1;
    int max = n;
    //int mid = (min + max) / 2; 这种取中的方法会溢出
    int mid = min + (max - min) / 2;
    int guess_result = guess(mid);
    while (0 != guess_result) {
      if (-1 == guess_result) {
	max = mid - 1;
      } else if (1 == guess_result) {
	min = mid + 1;
      }
      //mid = (min + max) / 2;
      mid = min + (max - min) / 2;
      guess_result = guess(mid);
    }
    return mid;
  }
};

int main() {
  return 0;
}
