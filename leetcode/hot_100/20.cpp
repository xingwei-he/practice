/**************************************
* He Xingwei, All Rights Reserved.
* Filename:20.cpp
* Date:2022-04-21 16:13:59
* Description:
**************************************/

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, char> left{{'(',')'},{'[',']'},{'{','}'}};
    unordered_map<char, char> right{{')','('},{']',']'},{'}','{'}};
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        std::stack<char> char_stack;
        for (const char &c : s) {
            if (left.find(c) != left.end()) {
                char_stack.push(c);
            } else if (right.find(c) != right.end()) {
                if (!char_stack.empty()) {
                    if (left[char_stack.top()] != c) {
                        return false;
                    } else {
                        char_stack.pop();
                    }
                } else {
                    return false;
                }
            } else {
                continue;
            }
        }

        if (char_stack.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    string test = "([)]";
    Solution s;
    bool res = s.isValid(test);
    cout << res << endl;
    return 0;
}