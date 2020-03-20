/*from
LGOJ https://www.luogu.com.cn/problem/P5706
*/
#include <cstdio>
using namespace std;
int main(){
    double t;
    int n;
    scanf("%lf%d", &t, &n);
    printf("%.3f\n%d", t/n, 2*n);
    return 0;
}