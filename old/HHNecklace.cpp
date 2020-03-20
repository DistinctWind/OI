#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=500000+1;
const int MAXM=500000+1;
const int MAXNUM=1000000+1;
int n,m,num[MAXN],ans[MAXM],c[MAXN],last[MAXNUM];
struct Range
{
	int l,r,pos;
	friend bool operator < (Range a,Range b)
	{
		return a.r<b.r;
	}
}ran[MAXM];
int lowbit(int x)
{
	return x&(-x);
}
void update(int pos,int x)
{
	for (int i=pos;i<=n;i+=lowbit(i))
		c[i]+=x;
}
int sum(int pos)
{
	int res=0;
	for (int i=pos;i!=0;i-=lowbit(i))
		res+=c[i];
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&ran[i].l,&ran[i].r);
		ran[i].pos=i;
	}
	sort(ran+1,ran+1+m);
	int s=1;
	for (int i=1;i<=m;i++)
	{
		for (int j=s;j<=ran[i].r;j++)
		{
			if (last[num[j]]!=0)
				update(last[num[j]],-1);
			update(j,1);
			last[num[j]]=j;
		}
		s=ran[i].r+1;
		ans[ran[i].pos]=sum(ran[i].r)-sum(ran[i].l-1);
	}
	for (int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}
