/*from
LGOJ https://www.luogu.com.cn/problem/P2669
*/
#include <cstdio>
using namespace std;
int n, ans;
int main() {
    scanf("%d", &n);
    for (int i=1, cnt=0; cnt<=n; i++) {
        for (int j=1; j<=i; j++) {
            if (++cnt > n) {
                break;
            }
            ans += i;
        }
    }
    printf("%d", ans);
    return 0;
}