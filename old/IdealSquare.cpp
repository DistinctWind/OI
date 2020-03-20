#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;
const int MAXN=1e3+1;
struct QUEUE{
	int num,pos;
	void clear(){
		num=pos=0;
	}
}q1[MAXN],q2[MAXN];
int a,b,n,maxn,minn,ans=INT_MAX;
int s[MAXN][MAXN],lin_f1[MAXN][MAXN],lin_f2[MAXN][MAXN],f1[MAXN][MAXN],f2[MAXN][MAXN];
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
inline void empty()
{
	for (int i=1;i<=MAXN-1;i++)
		q1[i].clear(),q2[i].clear();
}
inline void dp()
{
	empty();
	for (int i=1;i<=a;i++)
	{
		int head1=1,head2=1,tail1=0,tail2=0;
		for (int j=1;j<=b;j++)
		{
			while (q1[head1].pos<j-n+1&&head1<=tail1) head1++;
			while (q1[tail1].num>=s[i][j]&&head1<=tail1) tail1--;
			while (q2[head2].pos<j-n+1&&head2<=tail2) head2++;
			while (q2[tail2].num<=s[i][j]&&head2<=tail2) tail2--;
			q1[++tail1].num=s[i][j],q1[tail1].pos=j;
			q2[++tail2].num=s[i][j],q2[tail2].pos=j;
			if (j-n+1>=1) lin_f1[i][j-n+1]=q1[head1].num,lin_f2[i][j-n+1]=q2[head2].num;
		}
	}
	empty();
	for (int i=1;i<=b-n+1;i++)
	{
		int head1=1,head2=1,tail1=0,tail2=0;
		for (int j=1;j<=a;j++)
		{
			while (q1[head1].pos<j-n+1&&head1<=tail1) head1++;
			while (q1[tail1].num>=lin_f1[j][i]&&head1<=tail1) tail1--;
			while (q2[head2].pos<j-n+1&&head2<=tail2) head2++;
			while (q2[tail2].num<=lin_f2[j][i]&&head2<=tail2) tail2--;
			q1[++tail1].num=lin_f1[j][i],q1[tail1].pos=j;
			q2[++tail2].num=lin_f2[j][i],q2[tail2].pos=j;
			if (j-n+1>=1) f1[j-n+1][i]=q1[head1].num,f2[j-n+1][i]=q2[head2].num;
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&a,&b,&n);
	for (int i=1;i<=a;i++)
		for (int j=1;j<=b;j++)
			scanf("%d",&s[i][j]);
	dp();
	for (int i=1;i<=a-n+1;i++)
		for (int j=1;j<=b-n+1;j++)
			ans=min(ans,f2[i][j]-f1[i][j]);
	printf("%d",ans);
}
/* Force 20
void find(int x,int y)
{
	maxn=INT_MIN,minn=INT_MAX;
	for (int i=x;i<=x+n-1;i++)
		for (int j=y;j<=y+n-1;j++)
			maxn=max(maxn,s[i][j]),minn=min(minn,s[i][j]);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&a,&b,&n);
	for (int i=1;i<=a;i++)
		for (int j=1;j<=b;j++)
			scanf("%d",&s[i][j]);
	for (int i=1;i<=a-n+1;i++)
		for (int j=1;j<=b-n+1;j++)
		{
			find(i,j);
			ans=min(ans,maxn-minn);
		}
	printf("%d",ans);
}
*/
//LOJ https://loj.ac/problem/10182
//DHOJ http://47.104.154.247/problem.php?cid=1100&pid=6
//LGOJ https://www.luogu.org/problemnew/show/P2216
