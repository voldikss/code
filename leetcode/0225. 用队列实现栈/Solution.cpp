#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MyStack {
  public:
    /** Initialize your data structure here. */
    MyStack() {
        while (!oqueue.empty()) oqueue.pop();
        while (!iqueue.empty()) iqueue.pop();
    }

    /** Push element x onto stack. */
    void push(int x) {
        iqueue.push(x);
        while (!oqueue.empty()) {
            iqueue.push(oqueue.front());
            oqueue.pop();
        }
        swap(oqueue, iqueue);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = oqueue.front();
        oqueue.pop();
        return top;
    }

    /** Get the top element. */
    int top() {
        return oqueue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return oqueue.empty() && iqueue.empty();
    }

  private:
    queue<int> oqueue;
    queue<int> iqueue;
};

int main(int argc, char** argv) {

    return 0;
}
