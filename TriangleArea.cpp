/*from
LGOJ https://www.luogu.com.cn/problem/P5708
*/
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    double a, b, c, p, s;
    scanf("%lf%lf%lf", &a, &b, &c);
    p = (a+b+c)/2;
    s = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.1f", s);
    return 0;
}