/*from
LGOJ https://www.luogu.com.cn/problem/P5711
*/
#include <cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    if (((n%100==0)&&(n%400==0))||((n%100!=0)&&(n%4==0))){
        printf("1");
    } else {
        printf("0");
    }
    return 0;
}