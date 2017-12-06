#include "practice/include/base.h"

using namespace std;

class MyQueue {
public:
  MyQueue() {
    // do intialization if necessary
  }

  /*
   * @param element: An integer
   * @return: nothing
   */
  void push(int element) {
    st_push.push(element);
  }

  /*
   * @return: An integer
   */
  int pop() {
    if (st_pop.empty()) {
      while(!st_push.empty()) {
	int temp = st_push.top();
	st_pop.push(temp);
	st_push.pop();
      }
    }
    int res = st_pop.top();
    st_pop.pop();
    return res;
  }

  /*
   * @return: An integer
   */
  int top() {
    if (st_pop.empty()) {
      while (!st_push.empty()) {
	int temp = st_push.top();
	st_pop.push(temp);
	st_push.pop();
      }
    }
    int res = st_pop.top();
    return res;
  }

private:
  stack<int> st_push;
  stack<int> st_pop;
};

int main() {
  return 0;
}
