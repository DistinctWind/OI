#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
const int MAXN=20001;
const int MAXM=100002;
int read()
{
	int x=0;
	char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
int n,m,fa[MAXN*2];
struct Set{
	int a,b,val;
	bool operator < (const Set &a) const{
		return val>a.val;
	}
}s[MAXM];
int find(int x)
{
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int main()
{
	//freopen("prison.in","r",stdin);
	//freopen("prison.out","w",stdout);
	//freopen("in.txt","r",stdin);
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		s[i].a=read();
		s[i].b=read();
		s[i].val=read();
	}
	sort(s+1,s+1+m);
	for (int i=1;i<=2*n;i++)
		fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x=s[i].a,y=s[i].b;
		int ox=s[i].a+n,oy=s[i].b+n;
		if (find(x)==find(y))
		{
			printf("%d\n",s[i].val);
			return 0;
		}
		else
		{
			fa[find(x)]=find(oy);
			fa[find(ox)]=find(y);
		}
	}
	printf("0\n");
}
