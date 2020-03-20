#include <cstdio>
#include <limits.h>
using namespace std;
const int MAXN=2*1e5+1;
struct range{
	int res,pos;
	range(){
		res=pos=0;
	}
}minq[MAXN];
int n,m,a[MAXN],sum[MAXN],ans=INT_MIN;
int max(int a,int b)
{
	return a>b?a:b;
}
inline void print(int head,int tail)
{
	for (int i=head;i<=tail;i++)
		printf("%d ",minq[i].res);
	putchar('\n');
	for (int i=head;i<=tail;i++)
		printf("%d ",minq[i].pos);
	putchar('\n');putchar('\n');
}
inline void setup()
{
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
}
inline void dp()
{
	int head=1,tail=0;
	for (int i=1;i<=n;i++)
	{
		while (minq[head].pos<i-m+1&&head<=tail) head++;
		while (minq[tail].res>=sum[i-1]&&head<=tail) tail--;
		minq[++tail].pos=i;
		minq[tail].res=sum[i-1];
		//print(head,tail);
		ans=max(ans,sum[i]-minq[head].res);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	setup();
	dp();
	printf("%d",ans);	
}
//DHOJ http://47.104.154.247/problem.php?cid=1100&pid=1
//LOJ https://loj.ac/problem/10176
