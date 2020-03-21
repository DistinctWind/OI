/*from
LGOJ https://www.luogu.com.cn/problem/P5712
*/
#include <cstdio>
using namespace std;
int main(){
    int x;
    scanf("%d", &x);
    if (x<=1){
        printf("Today, I ate %d apple.", x);
    } else {
        printf("Today, I ate %d apples.", x);
    }
    return 0;
}