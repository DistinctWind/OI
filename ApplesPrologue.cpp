/*from
LGOJ https://www.luogu.com.cn/problem/P5709
*/
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int m, t, s;
    scanf("%d%d%d", &m, &t, &s);
    int ans = m-(int)(ceil(double(s)/t));
    //double没加导致精度丢失
    printf("%d", ans<0 ? 0 : ans);
    return 0;
}