/*from
LGOJ https://www.luogu.com.cn/problem/P5715
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a[4];
    for (int i=1; i<=3; i++) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+4);
    for (int i=1; i<=3; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}