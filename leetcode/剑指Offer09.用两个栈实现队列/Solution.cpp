#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class CQueue {
  private:
    stack<int> s1;
    stack<int> s2;

  public:
    CQueue() {
    }

    void appendTail(int value) {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(value);
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int deleteHead() {
        if (s2.empty()) return -1;
        auto val = s2.top();
        s2.pop();
        return val;
    }
};

int main(int argc, char** argv) {
    /**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
    return 0;
}
