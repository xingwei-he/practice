#include <iostream>
#include <vector>

using namespace std;

//const int MAX_BITS = 32;

int getOneOfTwo(const vector<int>& vec) {
  int res = 0;
  for (int i = 0; i < vec.size(); i++) {
    res = res ^ vec[i];
  }
  return res;
}

int getOneOfThree(const vector<int>& vec) {
  int bar[32] = {0};// 最大存32位整数
  int vec_len = vec.size();
  int t = 0;
  int j = 0;
  for (int i = 0; i < vec_len; i++) {
    t = vec[i];
    j = 31;
    while (0 != t) {
      if(1 == t % 2) {
	bar[j] += 1;
      }
      j--;
      t >>= 1;
    }
  }

  /*
  for (int i = 0; i < 32; i++) {
    cout << bar[i] << " ";
  }
  cout << endl;
  */
  int res = 0;
  for (int i = 0; i < 32; i++) {
    bar[i] %= 3;
  }
  for (int i = 0; i < 32; i++) {
    res = res * 2 + bar[i];
  }
 
  return res;
}

int main() {
  int arr13[10] = {5,9,7,5,8,7,9,7,5,9};// one of three
  int arr12[7] = {1,6,5,1,5,8,6};
  vector<int> vec(std::begin(arr13), std::end(arr13));
  int one = getOneOfThree(vec);
  cout << one << endl;
  vector<int> vec_2(std::begin(arr12), std::end(arr12));
  one = getOneOfTwo(vec_2);
  cout << one << endl;

  return 0;
}
