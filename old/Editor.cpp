#include <cstdio>
#include <stack>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=1e6+1;
stack <int> a,b;
int n;
long long sum[MAXN],f[MAXN];
long long max(long long a,long long b)
{
	return a>b?a:b;
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF)
	{
		char tmp;
		int now;
		memset(sum,0,sizeof(sum));
		memset(f,0,sizeof(f));
		while (!a.empty())
			a.pop();
		while (!b.empty())
			b.pop();
		f[0]=-0x7fffffff;
		for (int i=1;i<=n;i++)
		{
			scanf(" %c",&tmp);
			switch (tmp)
			{
				case 'I':
					scanf("%d",&now);
					a.push(now);
					sum[a.size()]=sum[a.size()-1]+a.top();
					f[a.size()]=max(f[a.size()-1],sum[a.size()]);
					break;
				case 'D':
					if (!a.empty())
						a.pop();
					break;
				case 'L':
					if (!a.empty())
					{
						b.push(a.top());
						a.pop();
					}
					break;
				case 'R':
					if (!b.empty())
					{
						a.push(b.top());
						sum[a.size()]=sum[a.size()-1]+a.top();
						f[a.size()]=max(f[a.size()-1],sum[a.size()]);
						b.pop();
					}
					break;
				case 'Q':
					scanf("%d",&now);
					printf("%lld\n",f[now]);
			}
		}
	}
}
