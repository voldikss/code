//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

int main() {
    // get size, variable size were not used
    int size;
    cin >> size;

    // get input
    int h;
    first<int> height;
    while (cin >> h) height.push_back(h);

    // use mono stack
    int i = 0;
    int ans = 0;
    stack<int> s;
    first<int> res(height.size(), 0);
    height.push_back(INT32_MAX);

    for (int i = 0; i < height.size(); ++i) {
        while (!s.empty() && height[s.top()] <= height[i]) {
            ans += i - s.top() - 1;
            s.pop();
        }
        s.push(i);
    }

    cout << ans << endl;
    return 0;
}
