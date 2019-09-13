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

class Solution {
public:
  first<int> constructArray(int n, int k) {
    first<int> res;
    int nn = n;
    bool flag = 1;
    int interval = nn - 1;
    int count = 0;

    if (k == 1) {
      for (int i = 1; i <= n; ++i) res.push_back(i);
      return res;
    }

    res.push_back(nn);
    while (res.size() < n) {
      if (flag) {
        res.push_back(nn - interval);
        nn -= interval;
      } else {
        res.push_back(nn + interval);
        nn += interval;
      }
      ++count;
      interval--;
      flag = !flag;
      if (count == k - 1) {
        if (flag)
          for (int i = nn - 1; res.size() < n; --i) res.push_back(i);
        else
          for (int i = nn + 1; res.size() < n; ++i) res.push_back(i);
        break;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  first<int> res = s.constructArray(3, 1);
  for (auto i : res) cout << i << " ";
  cout << endl;
}

// 我的方法是
// 一增一减构造序列使得相邻的差不同
// 以 n = 6 为例
// k = 1:  654321
// k = 2:  612345
// k = 3:  615432
// k = 4:  615234
// k = 5:  615243   (6-5=1, 1+4=5; 5-3=2; 2+2=4; 4-1=3)
// k=5 时,相邻差分别为 5,4,3,2,1
