/*from
LGOJ https://www.luogu.com.cn/problem/P5721
*/
#include <cstdio>
using namespace std;
int n;
int main() {
    scanf("%d", &n);
    for (int i=1, cnt=1; i<=n; i++) {
        for (int j=i; j<=n; j++, cnt++) {
            printf("%02d", cnt);
        }
        putchar('\n');
    }
    return 0;
}