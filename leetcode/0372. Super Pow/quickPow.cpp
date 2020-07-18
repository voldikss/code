//////////////////////////////////////////////////////////////////////////////
// FileName: quickPow.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

// reference: https://oi-wiki.org/math/quick-pow/

#include <iostream>
using namespace std;

// 递归实现
int quickPow1(int a, int b) {
  if (a == 1) return 1;
  if (b == 1) return a;
  if (a == 0) return 0;
  if (b == 0) return 1;
  return quickPow1(a, b / 2) * quickPow1(a, b - b / 2);
}

// 循环实现
int quickPow2(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

// 循环，和第二个一样的
int quickPowMod3(int a, int b) {
  int ans = 1;
  while (b) {
    if (b % 2 == 1) {
      b--;
      ans *= a;
    } else {
      a = a * a;
      b /= 2;
    }
  }
  return ans;
}

int main() {
  cout << quickPow1(2, 4) << endl;
  cout << quickPow2(2, 4) << endl;
  cout << quickPowMod3(2, 4) << endl;
}
