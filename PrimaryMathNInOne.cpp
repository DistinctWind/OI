/*from
LGOJ https://www.luogu.com.cn/problem/P2433
*/
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const double p = 3.141593;
double r;
int main(){
    int c;
    scanf("%d", &c);
    switch (c){
    case 1:
        printf("I love Luogu!");
        break;
    case 2:
        printf("%d %d", 2+4, 10-(2+4));
        break;
    case 3:
        printf("%d\n%d\n%d", 3, 12, 2);
        break;
    case 4:
        printf("%.3f", 500/3);
        break;
    case 5:
        printf("%d", int((220+260)/(12+20)));
        break;
    case 6:
        cout<<sqrt(6*6+9*9);
        break;
    case 7:
        printf("%d\n%d\n%d", 110, 90, 0);
        break;
    case 8:
        r=5;
        cout<<2*p*r<<endl<<p*r*r<<endl<<4*p*r*r*r/3;
        break;
    case 9:
        printf("%d", (((1+1)*2+1)*2+1)*2);
        break;
    case 10:
        printf("%d", 9);
        break;
    case 11:
        cout<<100.0/(8-5);
        break;
    case 12:
        cout<<int('M'-'A'+1)<<endl<<char('A'+18-1);
        break;
    case 13:
        cout<<(int)(pow(4/3*p*(4*4*4+10*10*10),1.0*1/3));
    case 14:
        cout<<50;
    }
}