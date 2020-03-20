#include <cstdio>
#include <cstring>
#define MAXN 1000001
using namespace std;
int ans_max[MAXN],ans_min[MAXN];
int n,k,num[MAXN],q[MAXN],pos[MAXN];
inline void dp_max()
{
	memset(q,0,sizeof(q));
	memset(pos,0,sizeof(pos));
	int head=1,tail=0;
	for (int i=1;i<=n;i++)
	{
		while (pos[head]<i-k+1&&head<=tail)
			head++;
		while (num[i]>=q[tail]&&head<=tail)
			tail--;
		q[++tail]=num[i];
		pos[tail]=i;
		ans_max[i]=q[head];
	}
}
inline void dp_min()
{
	memset(q,0,sizeof(q));
	memset(pos,0,sizeof(pos));
	int head=1,tail=0;
	for (int i=1;i<=n;i++)
	{
		while (pos[head]<i-k+1&&head<=tail)
			head++;
		while (num[i]<=q[tail]&&head<=tail)
			tail--;
		q[++tail]=num[i];
		pos[tail]=i;
		ans_min[i]=q[head];
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	dp_max();
	dp_min();
	for (int i=k;i<=n;i++)
		printf("%d ",ans_min[i]);
	putchar('\n');
	for (int i=k;i<=n;i++)
		printf("%d ",ans_max[i]);
}
//DHOJ http://47.104.154.247/problem.php?cid=1100&pid=0
//LGOJ https://www.luogu.org/problemnew/show/P1886
