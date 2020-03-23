/*from
LGOJ https://www.luogu.com.cn/problem/P5723
*/
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXL = 100001;
int l;
int c = 0;
int prime[MAXL];
bool isPrime[MAXL];
inline void init() {
    for (int i=0; i<MAXL; i++)
        isPrime[i] = true;
}
void calc() {
    init();
    for (int i=2; i<=sqrt(MAXL); i++) {
        for (int j=2; i*j<MAXL; j++) {
            isPrime[i*j] = false;
        }
    }
    for (int i=2; i<MAXL ;i++) {
        if (isPrime[i]) {
            prime[++c] = i;
        }
    }
}
int main() {
    scanf("%d", &l);
    calc();
    int ans=0, sum=0; 
    for (int i=1; i<=c; i++) {
        if (prime[i]+sum<=l) {
            sum += prime[i];
            printf("%d\n", prime[i]);
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}