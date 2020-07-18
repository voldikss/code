//============================================================================
// FileName: Solution.cpp
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long width, height;
        if (A > E) {
            swap(&A, &E);
            swap(&B, &F);
            swap(&C, &G);
            swap(&D, &H);
        }
        if (E >= A && E <= C) {
            if (G >= A && G <= C) {
                width = G - E;
                if (H >= B && H <= D && F <= B) {
                    height = H - B;
                } else if (F >= B && F <= D && H >= D) {
                    height = D - F;
                } else if (F >= B && H <= D) {
                    height = H - F;
                } else if (F <= B && H >= D) {
                    height = D - B;
                } else {
                    height = 0;
                }
            } else {
                width = C - E;
                if (F <= D && F >= B && H >= D) {
                    height = D - F;
                } else if (H >= B && H <= D && F <= B) {
                    height = H - B;
                } else if (H <= D && F >= B) {
                    height = H - F;
                } else if (F <= B && H >= D) {
                    height = D - B;
                } else {
                    height = 0;
                }
            }
        } else {
            height = 0;
            width = 0;
        }

        return (long)(C - A) * (D - B) + (G - E) * (H - F) - width * height;
    }

    void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};

int main() {
    Solution s;
    // int ans = s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
    // int ans = s.computeArea(-3, 0, 3, 4, -3, 0, 3, 4);
    // int ans = s.computeArea(0, 0, 50000, 40000, 0, 0, 50000, 40000);
    // int ans = s.computeArea(0, 0, 0, 0, -1, -1, 1, 1);
    int ans = s.computeArea(-2, -2, 2, 2, 1, -3, 3, 3);
    cout << ans << endl;
}
