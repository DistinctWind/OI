#include <cstdio>
#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;
const int MAXN=1e6+1;
int n;
long long p[MAXN],d[MAXN],a[MAXN*2];
bool res[MAXN];
long long sum[MAXN];
int q[MAXN*2];
inline void dp1()
{
	for (int i=1;i<=2*n;i++)
		sum[i]=sum[i-1]+a[i];
	int head=1,tail=0;
	for (int i=1;i<=2*n;i++)
	{
		while (q[head]<i-n+1&&head<=tail) head++;
		while (sum[q[tail]]>=sum[i]&&head<=tail) tail--;
		q[++tail]=i;
		if (i>=n&&sum[q[head]]>=sum[i-n]) res[i-n+1]=true;
	}
}
inline void dp2()
{
	memset(q,0,sizeof(q));
	memset(sum,0,sizeof(sum));
	for (int i=1;i<=n;i++)
		a[i]=a[i+n]=p[n-i+1]-d[n-i];
	a[n]=p[1]-d[n];
	for (int i=1;i<=2*n;i++)
		sum[i]=sum[i-1]+a[i];
	int head=1,tail=0;
	for (int i=1;i<=2*n;i++)
	{
		while (q[head]<i-n&&head<=tail) head++;
		while (sum[q[tail]]>=sum[i]&&head<=tail) tail--;
		q[++tail]=i;
		if (i>=n&&sum[q[head]]>=sum[i-n]) res[2*n-i]=true;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//clock_t start,end;
	//start=clock();
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&p[i],&d[i]);
		a[i]=a[i+n]=p[i]-d[i];
	}
	dp1();
	dp2();
	for (int i=1;i<=n;i++)
		if (res[i]) printf("TAK\n");
		else printf("NIE\n");
	//end=clock();
	//printf("%llf",(double)(end-start)/CLOCKS_PER_SEC);
}
/* Force DFS 50
struct station{
	long long p,d;
}s[MAXN];
int n;
int mov(int pos,bool dir)
{
	if (dir==true)//Right
	{
		return pos+1>n?1:pos+1;
	}
	else if (dir==false)//Left
	{
		return pos-1<1?n:pos-1;
	}
}
bool dfs(int pos,int step,long long rest,bool dir)
{
	rest+=s[pos].p;
	if (step==n) return true;
	int nxt=mov(pos,dir);
	rest-=dir?s[pos].d:s[nxt].d;
	if (rest<0) return false;
	printf("%d %d %lld \n",pos,step,rest);
	return dfs(nxt,step+1,rest,dir); 
}
int main()
{
	//clock_t start,end;
	//start=clock();
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld%lld",&s[i].p,&s[i].d);
	for (int i=1;i<=n;i++)
		if (dfs(i,0,0,true)||dfs(i,0,0,false))
			printf("TAK\n");
		else 
			printf("NIE\n");
	//end=clock();
	//printf("%f",(end-start)/CLOCKS_PER_SEC);
}
*/
//LOJ https://loj.ac/problem/10178
//DHOJ http://47.104.154.247/problem.php?cid=1100&pid=4
