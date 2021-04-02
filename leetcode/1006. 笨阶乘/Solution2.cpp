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

class Solution {
  public:
    int clumsy(int N) {
        stack<int> st;
        st.push(N);
        int index = 1;
        while (index < N) {
            int cur = N - index;
            switch (index % 4) {
            case 0:
                st.push(-cur);
                break;
            case 1:
                st.top() *= cur;
                break;
            case 2:
                st.top() /= cur;
                break;
            case 3:
                st.push(cur);
                break;
            default:
                break;
            }
            index++;
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    int N = 4;
    auto res = s.clumsy(N);
    cout << res << endl;
    return 0;
}
