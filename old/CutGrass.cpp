#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=1e5+1;
struct maxq{
	long long res,pos;
}q[MAXN];
long long f[MAXN][2],sum[MAXN];
int n,k,cow[MAXN];
inline void setup()
{
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+cow[i];
}
inline void dp()
{
	int head=1,tail=1;
	for (int i=1;i<=n;i++)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		while (q[head].pos<i-k&&head<=tail) head++;
		f[i][1]=q[head].res+sum[i];
		while (f[i][0]-sum[i]>=q[tail].res&&head<=tail) tail--;
		tail++;
		q[tail].res=f[i][0]-sum[i];
		q[tail].pos=i;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&cow[i]);
	setup();
	dp();
	printf("%lld",max(f[n][0],f[n][1]));
}
/* Force DFS : 30
int n,k,cow[MAXN];
unsigned long long ans;
int max(int a,int b)
{
	return a>b?a:b;
}
void dfs(int pos,int cnt,int sum)
{
	if (cnt>k) return;
	if (pos>n)
	{
		ans=max(ans,sum);
		return;
	}
	ans=max(ans,sum);
 	dfs(pos+1,cnt+1,sum+cow[pos]);
	dfs(pos+1,0,sum);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&cow[i]);
	dfs(1,0,0);
	printf("%lld",ans);
}
*/

/* Error
int n,k,cow[MAXN],f[MAXN][2];
int max(int a,int b)
{
	return a>b?a:b;
}
inline void dp()
{
	f[1][0]=0,f[1][1]=cow[1];
	for (int i=2;i<=n;i++)
	{
		int temp=0;
		for (int cnt=0;cnt<=k&&i-cnt-1>=1;cnt++)
			temp=max(temp,f[i-cnt-1][1]);
		f[i][0]=temp+cow[i];
		temp=0;
		for (int cnt=1;cnt<=k&&i-cnt>=1;cnt++)
			temp=max(temp,f[i-cnt][1]);
		f[i][1]=temp+cow[i];
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&cow[i]);
	dp();
	printf("%d",max(f[n][0],f[n][1]));
}*/
//LOJ https://loj.ac/problem/10177
//DHOJ http://47.104.154.247/problem.php?cid=1100&pid=3
