/*from
LGOJ https://www.luogu.com.cn/problem/P1009
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXL = 10000;
int n;
struct Bignum{
    int len;
    int num[MAXL];
    Bignum() {
        len = 0;
        memset(num, 0, sizeof(num));
    }
    void read() {
        int tmp;
        len = 0;
        scanf("%d", &tmp);
        while (tmp) {
            len++;
            num[len] = tmp%10;
            tmp/=10;
        }
    }
    void write() {
        if (len==0) {
            printf("0");
        }
        for (int i=len; i>=1; i--) {
            printf("%d", num[i]);
        }
    }
}sum[51], ans;
//一开始的我还想用unsigned long long蒙混过关，结果被阶乘之大打脸了qwq
Bignum translate(int x) {
    Bignum a;
    while (x) {
        a.len++;
        a.num[a.len]=x%10;
        x/=10;
    }
    return a;
}
Bignum operator * (Bignum a, Bignum b) {
    Bignum c;
    c.len = a.len+b.len-1;
    for (int i=1; i<=a.len; i++) {
        for (int j=1; j<=b.len; j++) {
            int pos = i+j-1;
            c.num[pos]+=a.num[i]*b.num[j];
            if (c.num[pos] > 9) {
                c.num[pos+1]+=c.num[pos]/10;
                c.num[pos]%=10;
            }
        }
    }
    if (c.num[c.len+1]>0) {
        c.num[c.len+1]+=c.num[c.len]/10;
        c.num[c.len]%=10;
        c.len++;
    }
    return c;
}
Bignum operator + (Bignum a, Bignum b) {
    Bignum c;
    c.len = max(a.len, b.len);
    for (int i=1; i<=c.len ;i++) {
        c.num[i] += a.num[i]+b.num[i];
        if (c.num[i] > 9) {
            c.num[i+1] += c.num[i]/10;
            c.num[i] %= 10;
        }
    }
    if (c.num[c.len+1]>0) c.len++;
    return c;
}
Bignum fac(int x) {
    if (sum[x].len>0) return sum[x];
    else if (x==1) return sum[x]=translate(1);
    else return sum[x]=fac(x-1)*translate(x);
}
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        ans = ans + fac(i);
    }
    ans.write();
    return 0;
}