#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void getNext_cpp_update (const string& pattern_str, vector<int>& next) {
  next[0] = -1;
  int i = -1;
  int j = 0;
  int pattern_len = pattern_str.size();
  while (j < pattern_len - 1) {
    if (i == -1 || pattern_str[i] == pattern_str[j]) {
      i++;
      j++;
      if (pattern_str[i] != pattern_str[j]) {
	next[j] = i;
      } else {
	next[j] = next[i];
      }
    } else {
      i = next[i];
    }
  }
}

bool find_str_kmp (const string& target, const string& pattern, const vector<int>& next) {
  int i = 0;// 指向target
  int j = 0;// 指向pattern
  int target_length = target.size();
  int pattern_length = pattern.size();
  bool match = false;
  while (i < target_length) {
    // target剩余字符串长度小于模式串剩余长度，必然不能匹配
    if ((target_length - i) < (pattern_length - j)) {
      match = false;
      break;
    }
    if (j == -1 || target[i] == pattern[j]) {
      if (j == pattern_length - 1) {
	// 模式串最后一个字符已经匹配，则可以返回true
	match = true;
	break;
      }
      i++;
      j++;
    } else {
      // 如果字符不匹配，则需要通过next数组找到模式串的下一个探测位置
      j = next[j];
    }
  }
  return match;
}

void getNext_cpp (const string& pattern_str, vector<int>& next) {
  next[0] = -1;
  int left = -1;
  int right = 0;
  int pattern_len = pattern_str.size();
  while (right < pattern_len - 1) {
    if (left == -1 || pattern_str[left] == pattern_str[right]) {
      left++;
      right++;
      next[right] = left;
    }else {
      left = next[left];
    }
  }
}

void getNext (char* pstr, int next[]) {
  int length = strlen(pstr);
  next[0] = -1;
  int k = -1;
  int j = 0;
  while (j < length - 1) {
    // p[k]表示前缀，p[j]表示后缀
    if (k == -1 || pstr[j] == pstr[k]) {
      k++;
      j++;
      next[j] = k;
    } else {
      k = next[k];
    }
  }
}

int main () {
  cout << endl << endl;
  //int next[9] = {0};
  //char pattern_str[10] = {'D','A','B','C','D','A','B','D','E'};
  //getNext(pattern_str, next);// -1 0 0 0 0 1 2 3 1 
  //for (int i = 0; i < strlen(pattern_str); i++) {
  //  cout << next[i] << " ";
  //}
  //cout << endl;

  string str("DABCDABDE");
  int pattern_len = str.size();
  //string str("ABAB");

  cout << "pattern:" << endl;
  for (int i = 0; i < pattern_len; i++) {
    cout << str.at(i) << "\t";
  }
  cout << endl;
  vector<int> next_vec(str.size());// -1 0 0 0 0 1 2 3 1 
  getNext_cpp(str, next_vec);
  for (size_t i = 0; i < next_vec.size(); i++) {
    cout << next_vec[i] << "\t";
  }
  cout << endl;

  vector<int> newvec(str.size());
  getNext_cpp_update(str, newvec);
  for (size_t i = 0; i < newvec.size(); i++) {
    cout << newvec[i] << "\t";
  }
  cout << endl;
  cout << "*****************************" << endl;

  //string target_1 = "DABCDABDE2";
  //string target_2 = "123DABCDABDEOPQ";
  //string target_3 = "DABCDA";

  //bool is_match_1 = false;
  //is_match_1 = find_str_kmp(target_1, str, newvec);
  //bool is_match_2 = false;
  //is_match_2 = find_str_kmp(target_2, str, newvec);
  //bool is_match_3 = false;
  //is_match_3 = find_str_kmp(target_3, str, newvec);
  
  //cout << is_match_1 << endl;
  //cout << is_match_2 << endl;
  //cout << is_match_3 << endl;

  //if (is_match_1) {
  //  cout << "is_match_1:true" << endl;
  //}
  /*
  if (is_match_2) {
    cout << "is_match_2:true" << endl;
  }
  if (is_match_3) {
    cout << "is_match_3:true" << endl;
  }
  */

  // kmp test 
  // pattern:DABCDABDE
  string pattern = str;
  vector<int> mvec(pattern.size());
  getNext_cpp(pattern, mvec);
  vector<int> nvec(pattern.size());
  getNext_cpp_update(pattern, nvec);

  cout << "patter:" << pattern << endl;
  cout << "next_v1:";
  for (size_t i = 0; i < mvec.size(); i++) {
    cout << mvec[i] << "\t";
  }
  cout << endl;
  cout << "next_v2:";
  for (size_t i = 0; i < nvec.size(); i++) {
    cout << nvec[i] << "\t";
  }
  cout << endl;

  string test_str_1 = "DABC";
  string test_str_2 = "DABCAABDE";
  string test_str_3 = "DABCDABDX";
  string test_str_4 = "";
  string test_str_5 = "SDABCDABDE";
  string test_str_6 = "DABCDABDEX";
  string test_str_7 = "SDABCDABDEX";
  cout << "test_str_1:" << test_str_1 << endl;
  if (find_str_kmp(test_str_1, pattern, mvec)) {
    cout << "v1 ok!" << endl;
  } else {
    cout << "v1 no!" << endl;
  }
  if (find_str_kmp(test_str_1, pattern, nvec)) {
    cout << "v2 ok!" << endl;
  } else {
    cout << "v2 no!" << endl;
  }
 
  
  cout << "test_str_2:" << test_str_2 << endl;
  if (find_str_kmp(test_str_2, pattern, mvec)) {
    cout << "v1 ok!" << endl;
  } else {
    cout << "v1 no!" << endl;
  }
  if (find_str_kmp(test_str_2, pattern, nvec)) {
    cout << "v2 ok!" << endl;
  } else {
    cout << "v2 no!" << endl;
  }

  cout << "test_str_3:" << test_str_3 << endl;
  if (find_str_kmp(test_str_3, pattern, mvec)) {
    cout << "v1 ok!" << endl;
  } else {
    cout << "v1 no!" << endl;
  }
  if (find_str_kmp(test_str_3, pattern, nvec)) {
    cout << "v2 ok!" << endl;
  } else {
    cout << "v2 no!" << endl;
  }

  cout << "test_str_4:" << test_str_4 << endl;
  if (find_str_kmp(test_str_4, pattern, mvec)) {
    cout << "v1 ok!" << endl;
  } else {
    cout << "v1 no!" << endl;
  }
  if (find_str_kmp(test_str_4, pattern, nvec)) {
    cout << "v2 ok!" << endl;
  } else {
    cout << "v2 no!" << endl;
  }

  cout << "test_str_5:" << test_str_5 << endl;
  if (find_str_kmp(test_str_5, pattern, mvec)) {
    cout << "v1 ok!" << endl;
  } else {
    cout << "v1 no!" << endl;
  }
  if (find_str_kmp(test_str_5, pattern, nvec)) {
    cout << "v2 ok!" << endl;
  } else {
    cout << "v2 no!" << endl;
  }

  cout << "test_str_6:" << test_str_6 << endl;
  if (find_str_kmp(test_str_6, pattern, mvec)) {
    cout << "v1 ok!" << endl;
  } else {
    cout << "v1 no!" << endl;
  }
  if (find_str_kmp(test_str_6, pattern, nvec)) {
    cout << "v2 ok!" << endl;
  } else {
    cout << "v2 no!" << endl;
  }


  cout << "test_str_7:" << test_str_7 << endl;
  if (find_str_kmp(test_str_7, pattern, mvec)) {
    cout << "v1 ok!" << endl;
  } else {
    cout << "v1 no!" << endl;
  }
  if (find_str_kmp(test_str_7, pattern, nvec)) {
    cout << "v2 ok!" << endl;
  } else {
    cout << "v2 no!" << endl;
  }


  return 0;
}
