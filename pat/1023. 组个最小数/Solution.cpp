#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    int count[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &count[i]);
    }

    int i;
    for (i = 1; i < 10; ++i) {
        if (count[i] > 0) {
            count[i]--;
            break;
        }
    }

    vector<int> res;
    res.push_back(i);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count[i]; j++) {
            res.push_back(i);
        }
    }

    for (auto x : res) {
        cout << x;
    }
    cout << endl;
    return 0;
}
