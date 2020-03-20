#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
const int MAXN=1002,MAXM=1002;
int t,n,m,h[MAXN][MAXM];
char map[MAXN][MAXM];
long long ans;
struct REC{
	long long h,w;
};
inline void solve(int lin)
{
	stack <REC> s;
	for (int i=1;i<=m+1;i++)
	{
		if (s.empty()||s.top().h<h[lin][i])
		{
			REC tmp;
			tmp.h=h[lin][i]; tmp.w=1;
			s.push(tmp);
		}
		else
		{
			long long width=0;
			while (!s.empty()&&h[lin][i]<s.top().h)
			{
				width+=s.top().w;
				ans=max(ans,width*s.top().h);
				s.pop();
			}
			REC tmp;
			tmp.h=h[lin][i]; tmp.w=width+1;
			s.push(tmp);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ans=0;
	memset(map,0,sizeof(map));
	memset(h,0,sizeof(h));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			cin>>map[i][j];
			if (map[i][j]=='F')
				h[i][j]=h[i-1][j]+1;
		}
	for (int i=1;i<=n;i++)
		solve(i);
	printf("%lld\n",ans*3);
}
