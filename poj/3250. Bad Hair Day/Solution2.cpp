#include <bits/stdc++.h>

#define Inf 0xfffff

using namespace std;

int main() {
    int n, i;
    long long h, sum;
    while (scanf("%d", &n) != EOF) {
        stack<int> s;
        sum = 0;
        for (i = 0; i < n; ++i) {
            scanf("%lld", &h);
            while (!s.empty() && h >= s.top()) s.pop();
            // 这个妙，以被看见的为研究对象，看能被前面的几头牛看到头发
            // 这个太妙了
            sum += s.size();
            s.push(h);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
