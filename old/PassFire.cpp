#include <cstdio>
#include <limits.h>
using namespace std;
const int MAXN=2*1e5+1;
struct tower{
	int f,pos;
}minq[MAXN];
int n,m,fee[MAXN],f[MAXN*2+1];
int min(int a,int b)
{
	return a>b?b:a;
}
inline void dp()
{
	int head=1,tail=0;
	for (int i=1;i<=m;i++)
	{
		f[i]=fee[i]; 
		while (minq[head].pos<i-m&&head<=tail) head++;
		while (minq[tail].f>=fee[i]&&head<=tail) tail--;
		minq[++tail].pos=i;
		minq[tail].f=fee[i];
	}
	for (int i=m+1;i<=n;i++)
	{
		while (minq[head].pos<i-m&&head<=tail) head++;
		f[i]=minq[head].f+fee[i];
		while (minq[tail].f>=f[i]&&head<=tail) tail--;
		minq[++tail].pos=i;
		minq[tail].f=f[i];
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&fee[i]);
	dp();
	int ans=INT_MAX;
	for (int i=0;i<=m-1;i++)
		ans=min(ans,f[n-i]);
	printf("%d",ans);
}
//DHOJ http://47.104.154.247/problem.php?cid=1100&pid=2
//LOJ https://loj.ac/problem/10180
