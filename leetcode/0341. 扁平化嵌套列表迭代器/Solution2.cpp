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
        // fill(nestedList);
        // print();
        reverse(nestedList.begin(), nestedList.end());
        for (auto x : nestedList) {
            st.push(x);
        }
    }

    int next() {
        auto top = st.top();
        st.pop();
        if (top.isInteger()) {
            return top.getInteger();
        } else {
            auto subNestedIntegerList = top.getList();
            reverse(subNestedIntegerList.begin(), subNestedIntegerList.end());
            for (auto x : subNestedIntegerList) {
                st.push(x);
            }
            return next();
        }
    }

    bool empty(const NestedInteger& subNestedInteger) {
        if (subNestedInteger.isInteger()) {
            return false;
        } else {
            for (const auto& x : subNestedInteger.getList()) {
                if (!(empty(x))) return false;
            }
            return true;
        }
    }

    bool hasNext() {
        if (st.empty()) return false;
        do {
            auto top = st.top();
            if (empty(top)) {
                st.pop();
            } else {
                return true;
            }
        } while (!st.empty());
        return false;
    }

  private:
    stack<NestedInteger> st;
};

int main(int argc, char** argv) {

    return 0;
}
