/*from
LGOJ https://www.luogu.com.cn/problem/P4414
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[3];
char A, B, C;
int main(){
    cin>>a[0]>>a[1]>>a[2];
    cin>>A>>B>>C;
    sort(a, a+3);
    cout<<a[A-'A']<<' '<<a[B-'A']<<' '<<a[C-'A'];
    //惨痛的教训：要把样例过完qwq
    return 0;
}