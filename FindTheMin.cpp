/*from
LGOJ https://www.luogu.com.cn/problem/P5718
*/
#include <cstdio>
#include <climits>
using namespace std;
int n, m=INT_MAX;
int main(){
    scanf("%d", &n);
    for (int i=1, tmp; i<=n; i++) {
        scanf("%d", &tmp);
        if (tmp<m)
            m=tmp;
    }
    printf("%d", m);
    return 0;
}