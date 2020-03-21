/*from
LGOJ https://www.luogu.com.cn/problem/P5717
*/
#include <iostream>
#include <algorithm>
using namespace std;
int x[4];
int main(){
    for (int i=1; i<=3; i++) {
        cin>>x[i];
    }
    sort(x+1,x+4);
    if (x[1]+x[2]<=x[3]){
        cout<<"Not triangle";
        return 0;
    }
    if (x[1]*x[1]+x[2]*x[2]==x[3]*x[3])
        cout<<"Right triangle"<<endl;
    if (x[1]*x[1]+x[2]*x[2]>x[3]*x[3])
        cout<<"Acute triangle"<<endl;
    if (x[1]*x[1]+x[2]*x[2]<x[3]*x[3])
        cout<<"Obtuse triangle"<<endl;
    if (x[1]==x[2] || x[2]==x[3])
        cout<<"Isosceles triangle"<<endl;
    if (x[1]==x[2] && x[2]==x[3])
        cout<<"Equilateral triangle"<<endl;
    return 0;
}