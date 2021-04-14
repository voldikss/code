#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回对于每一天，要等待下一个客流量更大的日期，至少需要的天数
     * @param customers int整型vector 每天的客流量
     * @return int整型vector
     */
    vector<int> nextMoreCustomersInterval(vector<int>& cm) {
        int n = cm.size();
        vector<int> res(n);
        stack<pair<int, int>> st;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 0;
            while (!st.empty() && st.top().second <= cm[i]) {
                st.pop();
                cnt++;
            }
            if (st.empty()) {
                res[i] = 0;
            } else {
                res[i] = st.top().first - i;
            }
            st.push(make_pair(i, cm[i]));
        }

        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> customers{199, 221, 230, 212, 210, 225, 245, 255, 240};
    auto res = s.nextMoreCustomersInterval(customers);
    cout << res << endl;
    return 0;
}
