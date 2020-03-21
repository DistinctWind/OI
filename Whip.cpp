/*from
LGOJ https://www.luogu.com.cn/problem/P5720
*/
#include <cstdio>
using namespace std;
int a, x;
int main() {
    scanf("%d", &a);
    for (x=1; ; x++) {
        if (a==1) {
            printf("%d",x);
            return 0;
        }
        a/=2;
    }
    return 0;
}