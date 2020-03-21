/*from
LGOJ https://www.luogu.com.cn/problem/P5719
*/
#include <cstdio>
using namespace std;
int n, k;
double a, b;
int a_cnt, b_cnt;
int main(){
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++) {
        if (i%k==0) {
            a += i;
            a_cnt++;
        } else {
            b += i;
            b_cnt++;
        }
    }
    printf("%.1f %.1f", a/a_cnt, b/b_cnt);
    return 0;
}