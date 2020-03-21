/*from
LGOJ https://www.luogu.com.cn/problem/P5710
*/
#include <cstdio>
using namespace std;
bool c1, c2;
int x;
int main(){
    scanf("%d", &x);
    c1 = !(x&1) ;
    //原写法~(x&1)，但是这样~1有问题，还是改成!(x&1)
    c2 = 4<x && x<=12 ;
    printf("%d %d %d %d", c1&&c2, c1||c2, (c1&&!c2)||(!c1&&c2), !c1&&!c2);
    return 0;
}