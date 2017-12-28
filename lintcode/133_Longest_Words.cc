/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:133_Longest_Words.cc
 * Author:
 * Mail:
 * Created Time:星期四 12/28 10:19:48 2017
 ***************************************************/
#include <iostream>

#include "practice/include/base.h"

using namespace std;

/**
 * Given a dictionary, find all of the longest words in the dictionary.
 *
 * Example
 * Given
 * {
 *   "dog",
 *   "google",
 *   "facebook",
 *   "internationalization",
 *   "blabla"
 * }
 * the longest words are(is) ["internationalization"].
 *
 * Given
 * {
 *   "like",
 *   "love",
 *   "hate",
 *   "yes"
 * }
 * the longest words are ["like", "love", "hate"].
 **/

class Solution {
public:
  /*
   * @param dictionary: an array of strings
   * @return: an arraylist of strings
   */
  vector<string> longestWords(vector<string> &dictionary) {
    unordered_map<int, vector<string> > len_map;
    int max_len = 0;
    for (vector<string>::iterator iter = dictionary.begin();
	 iter != dictionary.end();
	 iter++) {
      int len = iter->size();
      if (len_map.find(len) != len_map.end()) {
	len_map[len].push_back(*iter);
      } else {
	if (max_len < len) {
	  max_len = len;
	}
	len_map.insert(pair<int, vector<string> >(len, vector<string>(0)));
	len_map[len].push_back(*iter);
      }
    }
    return len_map[max_len];
  }
};

int main() {
  string arr[] = {"like", "love", "hate", "yes"};
  vector<string> dictionary(begin(arr), end(arr));
  Solution sl;
  vector<string> res = sl.longestWords(dictionary);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << "  ";
  }
  cout << endl;
  return 0;

}
