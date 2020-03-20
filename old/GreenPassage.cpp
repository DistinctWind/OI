#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;
const int MAXN=5*1e4+1;
struct QUEUE{
	int num,pos;
}q[MAXN*2+1];
int n,t,a[MAXN],f[MAXN],ans;
int min(int a,int b)
{
	return a<b?a:b;
}
bool check(int len)
{
	memset(f,0,sizeof(f));
	int head=1,tail=0;
	for (int i=2;i<=n;i++)
	{
		while (head<=tail&&q[head].pos<i-len-1) head++;
		while (head<=tail&&q[tail].num>=f[i]+a[i]) tail--;
		f[i]=q[head].num;
		
	}
}
/* Force check 50
bool check(int len)
{
	memset(f,0,sizeof(f));
	for (int i=2;i<=n;i++)
	{
		int m=INT_MAX;
		for (int j=(i-len-1<1?1:i-len-1);j<=i-1;j++)
			m=min(m,f[j]);
		f[i]=m+a[i];
	}
	int min_f=INT_MAX;
	for (int i=n-len;i<=n;i++)
		min_f=min(min_f,f[i]);
	if (min_f<=t) return true;
	else return false;
}
*/
inline void div()
{
	int l=1,r=n;
	while (r-l>1)
	{
		int mid=(l+r)/2;
		if (check(mid)) ans=mid,r=r-1;
		else l=l+1;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&t);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	div();
	printf("%d",ans);
}
//LOJ https://loj.ac/problem/10181
//DHOJ http://47.104.154.247/problem.php?cid=1100&pid=7
