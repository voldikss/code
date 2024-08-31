#include "../../include/global.hpp"
#include <bits/stdc++.h>

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
        fill(nestedList);
        // print();
    }

    void fill(const vector<NestedInteger>& nestedList) {
        for (auto x : nestedList) {
            if (x.isInteger()) {
                data.push_back(x.getInteger());
                // cout << x.getInteger() << endl;
            } else {
                fill(x.getList());
            }
        }
    }

    void print() {
        for (auto x : data) {
            cout << x << " ";
        }
        cout << endl;
    }

    int next() {
        return data[++index];
    }

    bool hasNext() {
        return index != data.size() - 1;
    }

  private:
    vector<int> data;
    int index = -1;
};

int main(int argc, char** argv) {

    return 0;
}
