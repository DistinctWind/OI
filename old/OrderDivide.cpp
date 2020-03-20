#include <cstdio>
#include <iostream>
#include <limits.h>
#include <cstring>
using namespace std;
const int MAXN=1e5+1;
const int MAXT=201;
int n,t,q[MAXN];
int path[MAXN][MAXT];
long long s[MAXN],f[MAXN],g[MAXN];
long long pow(long long x)
{
    return x*x;
}
void printp(int pos,int time)
{
	if (time==0) return;
	printp(path[pos][time],time-1);
	printf("%d ",path[pos][time]);
}
long long k(int pos1,int pos2)
{
    long long y=pow(s[pos1])-g[pos1]-(pow(s[pos2])-g[pos2]);
    long long x=s[pos1]-s[pos2];
    if (x==0) return LLONG_MIN;
    return y/x;
}
inline void dp()
{
    for (int j=1;j<=t;j++)
    {
        int head=1,tail=1;
        memset(q,0,sizeof(q));
        for (int i=1;i<=n;i++)
        {
            while (head<tail&&s[i]>k(q[head],q[head+1]))
                head++;
            f[i]=g[q[head]]+s[q[head]]*(s[i]-s[q[head]]);
            path[i][j]=q[head];
            while (head<tail&&(k(q[tail],q[tail-1])>k(q[tail],i)))
                tail--;
            q[++tail]=i;
        }
        memcpy(g,f,sizeof(f));
    }
    printf("%lld\n",f[n]);
    printp(n,t);
}
/*Fake Force DP Unaccepted;
inline void dp()
{
    memset(f,0xef,sizeof(f));
    for (int i=2;i<=n;i++)
    {
        for (int j=0;j<i;j++)
            f[i]=max(f[i],g[j]+s[j]*(s[i]-s[j])); 
        memcpy(g,f,sizeof(f));
    }
    printf("%lld",f[n]);
}
*/
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&t);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i]);
        s[i]+=s[i-1];
    }
    dp();
}
//DHOJ http://47.104.154.247/problem.php?cid=1101&pid=6
//LGOJ https://www.luogu.org/problemnew/show/P3648
