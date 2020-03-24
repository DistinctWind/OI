/*from
LGOJ https://www.luogu.com.cn/problem/P5724
*/
#include <cstdio>
#include <climits>
#include <iostream>
using namespace std;
const int MAXN = 101;
int n, num, mmax=-1, mmin=INT_MAX;
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &num);
        mmax = max(mmax, num);
        mmin = min(mmin, num);
    }
    printf("%d", mmax-mmin);
    return 0;
}