/*from
LGOJ https://www.luogu.com.cn/problem/P2181
*/
#include <cstdio>
using namespace std;
int main(){
    unsigned long long n, ans;
    //没开long long错了一次
    //没用unsigned long long又错了一次
    //啊啊啊好坑啊
    scanf("%llu", &n);
    ans = n*(n-1)/2*(n-2)/3*(n-3)/4;
    printf("%llu", ans);
    return 0;
}