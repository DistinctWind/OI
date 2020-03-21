/*from
LGOJ https://www.luogu.com.cn/problem/P5714
*/
#include <iostream>
using namespace std;
double m, h, b;
int main(){
    cin>>m>>h;
    b = m/(h*h);
    if (b<18.5) {
        cout<<"Underweight";
    } else if (18.5<=b&&b<24) {
        cout<<"Normal";
    } else if (b>=24) {
        cout<<b<<endl<<"Overweight";
    }
    return 0;
}