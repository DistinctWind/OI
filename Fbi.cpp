/*from
LGOJ https://www.luogu.com.cn/problem/P1720
*/
#include <cstdio>
using namespace std;
int n;
long long fbi[50];
int main() {
    scanf("%d", &n);
    fbi[1]=1, fbi[2]=1;
    for (int i=3; i<=n; i++) {
        fbi[i] = fbi[i-1]+fbi[i-2];
    }
    printf("%.2f", double(fbi[n]));
    return 0;
}