#include <cstdio>
#include <stack>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=100050;
long long n;
long long h[MAXN];
long long ans;
struct REC{
	long long h,w;
}r[MAXN];
stack <REC> s;
long long read()
{
	long long x=0;
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
void write(long long x)
{
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (n=read(),n!=0)
	{
		ans=0;
		memset(h,0,sizeof(h));
		while (!s.empty())
			s.pop();
		for (int i=1;i<=n;i++)
			h[i]=read();
		h[n+1]=0;
		for (int i=1;i<=n+1;i++)
		{
			if (s.empty()||s.top().h<h[i])
			{
				REC tmp;
				tmp.h=h[i],tmp.w=1;
				s.push(tmp);
			}
			else
			{
				long long width=0;
				while (!s.empty()&&h[i]<s.top().h)
				{
					width+=s.top().w;
					ans=max(ans,width*s.top().h);
					s.pop();
				}
				REC tmp;
				tmp.h=h[i],tmp.w=width+1;
				s.push(tmp);
			}
		}
		write(ans);
		putchar('\n');
	}
}

