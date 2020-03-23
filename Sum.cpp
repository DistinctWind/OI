/*from
LGOJ https://www.luogu.com.cn/problem/P5722
*/
#include <cstdio>
using namespace std;
int n, ans;
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        ans += i;
    }
    printf("%d", ans);
    return 0;
}