#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};

class NestedIterator {
  public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        reverse(nestedList.begin(), nestedList.end());
        for (auto x : nestedList) {
            st.push(x);
        }
    }

    int next() {
        auto top = st.top();
        st.pop();
        return top.getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
            auto top = st.top();
            if (top.isInteger()) return true;
            st.pop();
            auto list = top.getList();
            for (int i = list.size() - 1; i >= 0; i--) {
                st.push(list[i]);
            }
        }
        return false;
    }

  private:
    stack<NestedInteger> st;
};

int main(int argc, char** argv) {

    return 0;
}
