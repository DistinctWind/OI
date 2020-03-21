/*from
LGOJ https://www.luogu.com.cn/problem/P5713
*/
#include <cstdio>
using namespace std;
int main(){
    int x;
    scanf("%d", &x);
    int local = 5*x;
    int luogu = 3*x+11;
    if (local<luogu) {
        printf("Local");
    } else {
        printf("Luogu");
    }
    return 0;
}