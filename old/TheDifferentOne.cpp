#include <cstdio>
using namespace std;
const int MAXN=2e5+5;
const int M=1e6+5;
const int LOGN=18;
int n,m;
int last[M<<1],mx[MAXN][LOGN+1],st[MAXN],f[MAXN],log[MAXN];
int max(int a,int b)
{
	return a>b?a:b;
}
int find(int li,int ri)
{
	if (st[li]==li) return li;
	if (st[ri]<li) return ri+1;
	int l=li,r=ri;
	while (l<=r)
	{
		int mi=l+r>>1;
		if (st[mi]<li) l=mi+1;
		else r=mi-1;
	}
	return l;
}
int q(int li,int ri)
{
	int k=log[ri-li+1];
	return max(mx[li][k],mx[ri-(1<<k)+1][k]);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m); log[0]=-1;
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		x+=M;
		st[i]=max(st[i-1],last[x]+1);
		f[i]=i-st[i]+1;
		log[i]=log[i>>1]+1;
		last[x]=i;
	}
	for (int i=1;i<=n;i++)
		mx[i][0]=f[i];
	for (int j=1;j<=LOGN;j++)
	{
		for (int i=1;i+(1<<j)-1<=n;i++)
		{
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
		}
	}
	for (int i=1;i<=m;i++)
	{
		int li,ri;
		scanf("%d%d",&li,&ri); li++,ri++;
		int mi=find(li,ri),ans=0,tmp;
		if (mi>li) ans=mi-li;
		if (mi<=ri)
		{
			tmp=q(mi,ri);
			ans=max(tmp,ans);
		}
		printf("%d\n",ans);
	}
}
//LOJ https://loj.ac/problem/10121
