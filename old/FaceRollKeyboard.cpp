#include <cstdio>
#include <map>
using namespace std;
const int mod=100000007;
const int MAXN=1e6+1;
int n,q;
int a[MAXN],div[MAXN];
map <pair<int,int>,int> m;
int read()
{
	int x=0;
	char a=getchar();
	while (a<'0'||'9'<a)
	{
		a=getchar();
	}
	while ('0'<=a&&a<='9')
	{
		x=x*10+a-'0';
		a=getchar();
	}
	return x;
}
inline void solve(int l,int r)
{
	int res=0;
	for (int i=l;i<=r;i++)
	{
		for (int j=i;j<=r;j++)
		{
			int tmp;
			pair <int,int> p(i,j);
			if (tmp=m[p])
			{
				res=(long long)(tmp%mod);
				continue;
			}
			tmp=1;
			for (int k=i;k<=j;k++)
				tmp=(tmp%mod)*a[k];
			m[p]=tmp%mod;
			res=(long long)(res+tmp)%mod;
		}
	}
	printf("%d\n",res/div[r-l+1]);
}
int main()
{
	//freopen("in.txt","r",stdin);
	n=read(); q=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),div[i]=div[i-1]+i;
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		solve(l,r);
	}
}
