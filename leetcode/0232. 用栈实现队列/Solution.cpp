#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class MyQueue {
  public:
    /** Initialize your data structure here. */
    MyQueue() {
        while (!istack.empty()) istack.pop();
        while (!ostack.empty()) ostack.pop();
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        istack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (ostack.empty()) {
            while (!istack.empty()) {
                ostack.push(istack.top());
                istack.pop();
            }
        }
        int top = ostack.top();
        ostack.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        if (ostack.empty()) {
            while (!istack.empty()) {
                ostack.push(istack.top());
                istack.pop();
            }
        }
        return ostack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return istack.empty() && ostack.empty();
    }

  private:
    stack<int> istack;
    stack<int> ostack;
};

int main(int argc, char** argv) {

    return 0;
}
